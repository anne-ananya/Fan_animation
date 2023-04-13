#include <GL/glut.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
GLfloat angle = 0.0f; // Angle of rotation

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the display window
    glLoadIdentity(); // Reset the modelview matrix

    // Draw the fan blades
    int i;
    glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
    for (i = 0; i < 3; i++) {
        glPushMatrix();
        glRotatef(angle + i * 120.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.2f, 0.6f);
        glVertex2f(-0.2f, 0.6f);
        glEnd();
        glPopMatrix();
    }

    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glBegin(GL_POLYGON);
    for ( i = 0; i < 360; i += 10) {
        float theta = i * 3.14159 / 180.0;
        float x = 0.1 * cos(theta);
        float y = 0.1 * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glutSwapBuffers(); // Swap the buffers
}

void update(int value) {
    angle += 4.0f; // Update the rotation angle
    if (angle > 360.0f) {
        angle -= 360.0f;
    }
    glutPostRedisplay(); // Mark the window for redrawing
    glutTimerFunc(16, update, 0); // Call update() every 16ms (60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("Rotating Fan"); // Create window
    glutDisplayFunc(display); // Register display callback
    glutTimerFunc(0, update, 0); // Call update() immediately
    glutMainLoop(); // Start the main loop
    return 0;
}