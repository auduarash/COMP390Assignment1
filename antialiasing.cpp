#include <GL/glut.h>
#include <iostream> 
#include <math.h>
#include "house.hpp"

using namespace std;

HOUSE h; //house containing parameters
vector<POINT2D> rfPoints; // points for the roof
vector<POINT2D> hbPoints; //points for the house body
POINT2D center;


void set_house_values() {
    //setting the house parameters (height and width)
    h.body_width = 30;
    h.body_height = 50;
    h.roof_height = 10;
    h.roof_width = 60;

    //setting the house position
    h.center_x = center.x;
    h.center_y = center.y;
    h.angle = 25;

    rfPoints = get_roof_points(h);
    hbPoints = get_house_body_points(h);
}

void initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    set_house_values();
}

POINT2D rotate(POINT2D &point,double degree) {
    degree = (degree * M_PI / 180);
    int x1 = point.x - center.x;
    int y1 = point.y - center.y;
    POINT2D p;
    p.x = x1 * cos(degree) - y1 * sin(degree) + center.x;
    p.y = y1 * cos(degree) + x1 * sin(degree) + center.y;
    return p;
}

void render() {
    //draw roof
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1.3);
    glBegin(GL_POLYGON);
    for (POINT2D p: rfPoints) {
        // cout << p.x << " " << p.y << endl;
        POINT2D p2 = rotate(p, h.angle);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

    //draw housebody
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);

    for (POINT2D p: hbPoints) {
        // cout << p.x << " " << p.y << endl;
        POINT2D p2 = rotate(p, h.angle);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

}

void render_normal() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 100; center.y = 120;
    set_house_values();
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
    center.x = 80; center.y = 40;
    render();
}

void render_smoothed() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 100; center.y = 40;
    set_house_values();
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    render();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render_smoothed();
    render_normal();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(0.0, 1.0, 0.0, 1.0, 0.05, 40.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int wHandle = glutCreateWindow("Abdul-Rasheed Audu - TME 1 - Program 1");
    glutSetWindow(wHandle);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    initialize();
    glutMainLoop();

    return 0;
}