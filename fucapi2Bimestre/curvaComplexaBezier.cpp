// Curva de Bezier por parte.
// Tarefa: Aula 15-05 Tarefa
// Crias uma curva mais complexa, usando uma curva de Bezier por parte (usar três partes)
// Mostra a curva no quarto quadrante, de um sistema de coordenadas com o centro do sistema no centro da janela (ver imagem)

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoints2[4][3] = {
  {1.8, -3.0, 0.0},
  {1.8, -2.5, 0.0},
  {4.0, -2.3, 0.0},
  {1.0, -1.6, 0.0}
};

GLfloat ctrlpoints6[4][3] = {
  {1.0, -1.6, 0.0},
  {0.4, -1.2, 0.0},
  {1.3, -1.25, 0.0},
  {2.0, -1.26, 0.0}
};



void init(void) {
   glClearColor(0.0, 0.0, 0.0, 0.0); //cor fundo preto
    glOrtho(-5, 5, -5, 5, -1, 1);
    glEnable(GL_MAP1_VERTEX_3);
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(0.0);

   
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints2[0][0]);

    glColor3f(0.0, 1.0, 0.0); //cor verde

    glEvalMesh1(GL_LINE_STRIP,0,30); 
    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0); //gera um vertice usando o parámetro
    }
    glEnd();

    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++) {
        glVertex3fv(&ctrlpoints2[i][0]);
    }
    glEnd();

    //CURVA 2
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints6[0][0]);

    glColor3f(0.0, 0.0, 1.0); //cor azul

    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++) {
        glVertex3fv(&ctrlpoints6[i][0]);
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
    glutCreateWindow("Curva Complexa Bezier Continuidade");               //cria a janela
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
//  g++ curvaComplexaBezier.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp