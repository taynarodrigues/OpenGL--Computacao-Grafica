// Curva de Bezier por parte.
// Tarefa: Aula 15-05 Tarefa
// Crias uma curva mais complexa, usando uma curva de Bezier por parte (usar três partes)
// Mostra a curva no quarto quadrante, de um sistema de coordenadas com o centro do sistema no centro da janela (ver imagem)

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoint1[4][3] = {
  {0.8, -3.0, 0.0},
  {0.8, -2.5, 0.0},
  {4.0, -2.3, 0.0},
  {1.0, -1.6, 0.0}
};

GLfloat ctrlpoint2[4][3] = {
  {1.0, -1.6, 0.0},
  {0.4, -1.2, 0.0},
  {1.3, -1.25, 0.0},
  {2.0, -1.26, 0.0}
};

GLfloat ctrlpoint3[4][3] = {
  {2.0, -1.26, 0.0},
  {2.4, -1.27, 0.0},
  {2.8, -1.28, 0.0},
  {3.1, -1.33, 0.0}
};

void eixo()
{
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(-50., 0);
    glVertex2f(50.0, 0);
    glVertex2f(0, -50.0);
    glVertex2f(0, 50.0);
    glEnd();
};

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(-5, 5, -5, 5, -1, 1);
    glEnable(GL_MAP1_VERTEX_3);
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(0.0);

    eixo();
   
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoint1[0][0]);

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++) {
        glVertex3fv(&ctrlpoint1[i][0]);
    }
    glEnd();

    //CURVA 2
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoint2[0][0]);

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++) {
        glVertex3fv(&ctrlpoint2[i][0]);
    }
    glEnd();

    //CURVA 3
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoint3[0][0]);

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++) {
        glVertex3fv(&ctrlpoint3[i][0]);
    }
    glEnd();


    glFlush();
    glutSwapBuffers();

}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w,
            5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
    else
        glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,
            5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}




int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
    glutCreateWindow("Curva de Bezier Mais Complexa");               //cria a janela
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
//  g++ curvaComplexa_Tarefa1505.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp