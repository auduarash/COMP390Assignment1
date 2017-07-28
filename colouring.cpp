#include <GL/glut.h>
#include <iostream> 
#include <math.h>

using namespace std;

void initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);

}


void render() {
    glEnable(GL_BLEND);
    glBegin(GL_QUADS);
    //upper left
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 1);
    //upper right
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1);
    //lower right
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 1);
    //lower left
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, -1.0, 1);
    glEnd();


}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render();
    
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
    int wHandle = glutCreateWindow("Abdul-Rasheed Audu - TME 1 - Program 3");
    glutSetWindow(wHandle);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    initialize();
    glutMainLoop();

    return 0;
}