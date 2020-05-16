// Tarefa 08-05 Curvas de Bezier por parte
// Fazer as seguintes curvas de Bezier por parte usando OpenGL (ver imagem)
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoints[3][3] = {
  {-3.8, -3.8, 0.0},
  {-3.6, -0.6, 0.0},
  { 0.0,  0.0, 0.0}
};

GLfloat ctrlpoints2[3][3] = {
  {0.0, 0.0, 0.0},
  {3.6, 0.6, 0.0},
  {3.8, 3.8, 0.0}
};
void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0); //cor fundo preto
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);
}

void display(void)
{
   int i;

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);

   //CURVA 1
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints[0][0]);  
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();

   glPointSize(0.0f); //tamanho do ponto verde

   glColor3f(0.0, 1.0, 0.0);
   glBegin(GL_POINTS);
      for (i = 0; i < 3; i++) 
         glVertex3fv(&ctrlpoints[i][0]);
   glEnd();

   //CURVA 2
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints2[0][0]);

    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_LINE_STRIP);
      for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

    glBegin(GL_POINTS);
      for (int i = 0; i < 3; i++) {
        glVertex3fv(&ctrlpoints2[i][0]);
    }
    glEnd();
   glFlush();
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w, 
               5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
   else
      glOrtho(-5.0*(GLfloat)w/(GLfloat)h, 
               5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
    glutCreateWindow("Curva Bezier Continuidade 1");               //cria a janela
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
//  g++ curvaContinuidade1.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp