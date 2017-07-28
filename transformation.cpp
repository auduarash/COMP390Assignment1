#include <GL/glut.h>
#include <iostream> 
#include <math.h>
#include "house.hpp"

using namespace std;

House h; //house containing parameters
vector<wcPt2D> rfPoints; // points for the roof
vector<wcPt2D> hbPoints; //points for the house body
wcPt2D center;


void set_house_values() {
    //setting the house parameters (height and width)
    h.body_width = 40;
    h.body_height = 40;
    h.roof_height = 10;
    h.roof_width = 50;

    //setting the house position
    h.center_x = center.x;
    h.center_y = center.y;
    h.angle = 0;

    rfPoints = get_roof_points(h);
    hbPoints = get_house_body_points(h);
}

void initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    set_house_values();
}

wcPt2D rotate(wcPt2D &point,double degree) {
    degree = (degree * M_PI / 180);
    int x1 = point.x - center.x;
    int y1 = point.y - center.y;
    wcPt2D p;
    p.x = x1 * cos(degree) - y1 * sin(degree) + center.x;
    p.y = y1 * cos(degree) + x1 * sin(degree) + center.y;
    return p;
}

void render() {
    //draw roof
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1.3);
    glBegin(GL_POLYGON);
    for (wcPt2D p: rfPoints) {
        // cout << p.x << " " << p.y << endl;
        wcPt2D p2 = rotate(p, h.angle);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

    //draw housebody
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);

    for (wcPt2D p: hbPoints) {
        // cout << p.x << " " << p.y << endl;
        wcPt2D p2 = rotate(p, h.angle);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

}

void render_houses() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 0; center.y = 20;
    set_house_values();
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

    //render centre house
    render();

    int x_dis = 80;
    int y_dis = -30;
    int z_dis = 1;
    int angle = -25;

    for (int i = -2; i <= 2; i++) {

        glPushMatrix();
        int no_transforms = abs(i);
        int multiplier = (i < 0 ? -1 : 1);
        for (int j = 0; j < no_transforms; j++) {
            glTranslatef(multiplier * x_dis, abs(multiplier)*y_dis, z_dis);
            glRotatef(multiplier*angle, 0, 0, 1);
        }
        render();
        glPopMatrix();
    }

}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render_houses();
    
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int wHandle = glutCreateWindow("Abdul-Rasheed Audu - TME 1 - Program 2");
    glutSetWindow(wHandle);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    initialize();
    glutMainLoop();

    return 0;
}