#include <GL/glut.h>
#include "CarPart.h"

CarPart currentPart;

void drawPart3D() {
    glPushMatrix();

    glScalef(
        currentPart.length / 10.0f,
        currentPart.height / 10.0f,
        currentPart.width / 10.0f
    );

    glutWireCube(1.0);   // Draw cube scaled to dimensions
    glPopMatrix();
}

void renderDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(30, 1, 1, 0);

    drawPart3D();
    glutSwapBuffers();
}

void preview3D(CarPart p) {
    currentPart = p;

    int argc = 1;
    char* argv[] = { (char*)"start" };

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);

    glutCreateWindow("Car Part 3D Preview");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(renderDisplay);
    glutMainLoop();
}
