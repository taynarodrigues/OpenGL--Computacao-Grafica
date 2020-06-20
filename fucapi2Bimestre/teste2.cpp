// Fazer código OpenGL para gerar pelo menos duas das seguintes curvas de Bezier (ver imagem).

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoints2[4][3]={
      { 0.0, 0.0, 0.0},
      {-2.0, 0.3, 0.0},
      {-3.0,-1.0, 0.0},
      {-4.0, 4.0, 0.0}
};

GLfloat ctrlpoints6[4][3]={
      { 0.0, 0.0, 0.0},
      {-2.0,-0.3, 0.0},
      {-3.0, 1.0, 0.0},
      {-4.0,-4.0, 0.0}
}; 



void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);

/*A forma de trabalhar com curvas por partes de forma geral é a seguinte
1. Você define os pontos de controle
2. Define as funções paramétricas da  curva usando  glMap1f()
3. Desenha a curva usando glEvalCoord1f() para avaliar os parâmetros nas funções paramétricas previamente criadas com glMap1f()

Este processo se deve repetir para cada curva, primeiro glMap1f() depois glEvalCoord1f() para a primeira curva, depois glMap1f() e 
glEvalCoord1f() para a segunda e assim
*/

   glEnable(GL_MAP1_VERTEX_3);
}

void display(void)
{
   int i;

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
    glMap1f(GL_MAP1_VERTEX_3, 0.0,1.0,3,4, &ctrlpoints2[0][0]);
   glEnable(GL_MAP1_VERTEX_3);//
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
    
   glPointSize(6.0f); //tamanho do ponto verde O código a seguir exibe os pontos de controle como pontos /
   // glColor3f(0.0, 1.0, 0.0);
   glBegin(GL_POINTS);
      for (i = 0; i < 4; i++) 
         glVertex3fv(&ctrlpoints2[i][0]);
   glEnd();

   //CURVA 2
   //O grau da curva têm que ser 3, pelo que a quantidade de pontos de controle é 4.
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints6[0][0]);

    glColor3f(0.0, 1.0, 0.0); //COR VERDE
    glBegin(GL_LINE_STRIP);
      for (int j = 0; j <= 30; j++) {
        glEvalCoord1f((GLfloat)j / 30.0);
    }
    glEnd();

   glBegin(GL_POINTS);
      for (int i = 0; i < 6; i++) {
        glVertex3fv(&ctrlpoints6[i][0]);
    }
    glEnd();
   glFlush();
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
    glutCreateWindow("Curva de Bezier ");               //cria a janela
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
//  g++ teste2.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp