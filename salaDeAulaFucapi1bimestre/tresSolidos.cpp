/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

// prototipos das funcoes
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

// funcao principal
int main(int argc, char** argv){
  glutInit(&argc, argv);                              // inicializa o glut
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);           // especifica o uso de cores e buffers
  glutInitWindowSize (800, 800);                          // especifica as dimensoes da janela
  glutInitWindowPosition (100, 100);                      // especifica aonde a janela aparece na tela
  glutCreateWindow ("Tres Solidos");              // cria a janela
  init();
  glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
  glutKeyboardFunc(keyboard);                             // funcoes de teclado
  glutMainLoop();                                         // mostra todas as janelas criadas
  return 0;
}

// definicao de cada funcao

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);    // cor de fundo
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho (0, 256, 0, 256, -500.0 ,500.0);     // modo de projecao ortogonal
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();


  glTranslatef(0.0,60.0,0.0);
  glRotatef(90.0, 1.0, 0.0, 0.0);
  glRotatef(10.0, 0.0, 0.0, 1.0);
  glRotatef(10.0, 1.0, 0.0, 0.0);
}


void display(void){
  glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
  glColor3f (0.0, 0.0, 0.0);                  // cor do ponto

  glPushMatrix();
  glTranslatef (150.0, 150.0, 0.0);
  glutSolidCube(40.0);
  glPopMatrix();

  glColor3f (1.0, 0.0, 0.0);
  glPushMatrix();
  glTranslatef (150.0, 150.0, -60.0);
  glutSolidCone(40.0,60.0,20,20);
  glPopMatrix();

  glColor3f (0.0, 1.0, 0.0);
  glPushMatrix();
  glTranslatef (150.0, 150.0, -120.0);
  glutSolidTorus(20,40,20,20);
  glPopMatrix();

  glFlush();
}

void keyboard(unsigned char key, int x, int y){

  switch (key) {
  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

//  g++ tresSolidos.cpp -o firstOpenGlApp -lglut -lGLU -lGL
//  ./firstOpenGlApp