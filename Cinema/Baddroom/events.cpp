#include "glut.h"
#include "events.h"

float seatAngle = 0.0f;
bool isFolding = false;

void keyboard(unsigned char key, int x, int y) {
    if (key == 'f') isFolding = true;
    if (key == 'u') isFolding = false;
}

void idle() {
    if (isFolding && seatAngle < 90.0f) seatAngle += 1.0f;
    else if (!isFolding && seatAngle > 0.0f) seatAngle -= 1.0f;
    glutPostRedisplay();
}

void initGL() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
}

