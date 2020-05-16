// Tarefa 08-05 Curvas de Bezier por parte
// Fazer as seguintes curvas de Bezier por parte usando OpenGL (ver imagem)
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

GLfloat vertices[3][3] = {
  {-4.0, -4.0, 0.0},
  {-0.5, -3.5, 0.0},
  { 0.0,  0.0, 0.0}
};

GLfloat vertices2[3][3] = {
  { 0.0, 0.0, 0.0},
  {-0.5, 3.5, 0.0},
  {-4.0, 4.0, 0.0}
};

void init(void) {
    glOrtho(-5, 5, -5, 5, -1, 1);
    glEnable(GL_MAP1_VERTEX_3);
}

void display(void) {

    glPointSize(0.0);

    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &vertices[0][0]);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

    glBegin(GL_POINTS);
    for (int i = 0; i < 3; i++) {
        glVertex3fv(&vertices[i][0]);
    }
    glEnd();

    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &vertices2[0][0]);

    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

    glBegin(GL_POINTS);
    for (int i = 0; i < 3; i++) {
        glVertex3fv(&vertices2[i][0]);
    }
    glEnd();

    glFlush();
    glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Curva de Bezier Continuidade 2");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//  g++ continuidade2.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp