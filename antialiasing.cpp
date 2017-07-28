/*
Name: Abdul-Rasheed Audu
Student#: 3253834
Course: COMP390
Assignment: 1
Problem: 1

Purpose: Draw 2 houses using OpenGL functions. One of the 
    house is drawn normally while the other is drawn/rendered
    using OpenGL's antialiasing functions.
*/

#include <GL/glut.h>
#include <iostream> 
#include <math.h>
#include "house.hpp"

using namespace std;


const float ROTATION_ANGLE = 30;
House *house; //house parameters
wcPt2D center;

/*
    The center variable is updated to the centre of the next house
    to render. This method uses the center's x and y values to
    assign points locations to the vertices of the house and it's roof.
*/
void set_house_values() {
    //setting the house parameters (height and width)
    house->set_center(center.x, center.y);
}

/*
    Initialize the OpenGL display window
*/
void initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    house = new House(center.x, center.y);
    house->set_body_dimensions(1.0, 1.0);
    house->set_roof_dimensions(0.5, 1.5);
}

/*
    Rotate a point about the center. Note that the center does
    not need to be passed to this method since it is a global
    variable.
*/
wcPt2D rotate(wcPt2D &point,double degree) {
    degree = (degree * M_PI / 180);
    float x1 = point.x - center.x;
    float y1 = point.y - center.y;
    wcPt2D p;
    p.x = x1 * cos(degree) - y1 * sin(degree) + center.x;
    p.y = y1 * cos(degree) + x1 * sin(degree) + center.y;
    return p;
}

/*
    function: render
        renders a house using the stored parameters in 
        the global house variable
*/
void render() {
    //draw roof
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1.3);
    glBegin(GL_POLYGON);
    for (wcPt2D p: house->get_roof_points()) {
        wcPt2D p2 = rotate(p, ROTATION_ANGLE);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

    //draw house body
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);

    for (wcPt2D p: house->get_body_points()) {
        wcPt2D p2 = rotate(p, ROTATION_ANGLE);
        glVertex2f(p2.x, p2.y);
    }
    glEnd();

}

/*
    Disables antialiasing and calls the render
        function to render as OpenGL would normally
*/
void render_normal() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 1.0; center.y = 1.0;
    set_house_values();
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
    center.x = 1.0; center.y = -1.0;
    render();
}

/*
    Enables antialiasing and renders a house using 
        OpenGL's antialiasing techniques.
*/
void render_smoothed() {
	// points color
    glColor3f(0.0, 0.0, 0.0);
    center.x = 1.0; center.y = -1.0;
    set_house_values();
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    render();
}

/*
    Makes calls to separate house rendering methods to render
        items onto the screen.
*/
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render_smoothed();
    render_normal();
    glutSwapBuffers();
}

/*
    Adapts the display when the window is resized.
*/
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
    glMatrixMode(GL_MODELVIEW);
}

/*
    Sets up windows and rendering functions.
*/
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