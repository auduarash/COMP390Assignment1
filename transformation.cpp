/*
Name: Abdul-Rasheed Audu
Student#: 3253834
Course: COMP390
Assignment: 1
Problem: 2

Purpose: Draw a number of houses using translations
    and rotations. Only one method is used without changing
    any values but the rotations and translations set up before
    help with the results
*/

#include <GL/glut.h>
#include <iostream> 
#include <math.h>
#include "house.hpp"

using namespace std;

const float ROTATION_ANGLE = 10;
House *house; //house containing parameters
wcPt2D center;


void set_house_values() {
    //setting the house parameters (height and width)
    house->set_center(center.x, center.y);
}

void initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    house = new House(0, 0);
    house->set_body_dimensions(1.0, 1.0);
    house->set_roof_dimensions(0.5, 1.5);
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
    for (wcPt2D p: house->get_roof_points()) {
        glVertex2f(p.x, p.y);
    }
    glEnd();

    //draw housebody
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);

    for (wcPt2D p: house->get_body_points()) {
        glVertex2f(p.x, p.y);
    }
    glEnd();

}

void render_houses() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 0; center.y = 2.0;
    set_house_values();
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

    //render centre house
    render();

    float x_dis = 0.9;
    float y_dis = -0.3;
    int z_dis = 1;
    float angle = -30;

    for (int i = -2; i <= 2; i++) {

        glPushMatrix();
        int no_transforms = abs(i);
        int multiplier = (i < 0 ? -1 : 1);
        for (int j = 0; j < no_transforms; j++) {
            glTranslatef(multiplier * x_dis, abs(multiplier)*y_dis, 0);
            glRotatef(multiplier*angle, 0, 0, 1);
        }
        render();
        glPopMatrix();
    }

}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 12.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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