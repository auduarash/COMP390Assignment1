#include <GL/glut.h>
#include <iostream> 
#include <math.h>
#include "house.hpp"


HOUSE h; //house containing parameters
ROOF_POINTS rfPoints; // points for the roof
HB_POINTS hbPoints; //points for the house body
POINT2D center;


void set_house_values() {
    //setting the house parameters
    h.body.center_x = center.x;
    h.body.center_y = center.y;
    h.body.width = 40;
    h.body.height = 40;
    h.roof.roof_top_x = center.x;
    h.roof.roof_top_y = center.y + 30;
    h.roof.roof_height = 10;
    h.roof.roof_width = 50;
    h.angle = 30;

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
    for (POINT2D p: rfPoints.points) {
        cout << p.x << " " << p.y << endl;
        POINT2D p2 = rotate(p, h.angle);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

    //draw housebody
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);

    for (POINT2D p: hbPoints.points) {
        cout << p.x << " " << p.y << endl;
        POINT2D p2 = rotate(p, h.angle);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

}

void render_normal() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 20; center.y = 30;
    set_house_values();
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
    center.x = 20; center.y = -30;
    render();
}

void render_smoothed() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 20; center.y = -30;
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
    glFrustum(-1.0, 1.0, -1.0, 1.0, 0.1, 40.0);
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