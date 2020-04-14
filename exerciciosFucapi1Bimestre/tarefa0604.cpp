// Exercício 1
// 1. Utilizando o programa de exemplo como referência, implemente um novo programa. 
// Este programa deverá desenhar dois polígonos em uma janela com fundo branco de dimensões 256x256 pixels. 
// Todos os polígonos devem estar inicialmente preenchidos com cores diferentes. A cada vez que o usuário clicar
//  com o mouse (botão direito) sob um polígono, deverá aparecer um ponto de cor aleatória no local clicado.
//   Essa cor deverá ser impressa na janela Terminal (as componentes R,G,B), juntamente com as coordenadas (x,y) do ponto clicado.

#include <GL/glut.h>
#include <stdlib.h>

GLubyte tux[] = {
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x7f,  0xfe,  0x0,
 0x0,  0xc4,  0x23,  0x0,
 0x1,  0x83,  0x21,  0x80,
 0x1,  0x7,  0xe0,  0x80,
 0x1,  0x7,  0xf0,  0x80,
 0x1,  0x8f,  0xf9,  0x80,
 0x0,  0xff,  0xff,  0x0,
 0x0,  0x4f,  0xf1,  0x0,
 0x0,  0x6f,  0xf1,  0x0,
 0x0,  0x2f,  0xf3,  0x0,
 0x0,  0x27,  0xe2,  0x0,
 0x0,  0x30,  0x66,  0x0,
 0x0,  0x1b,  0x1c,  0x0,
 0x0,  0xb,  0x88,  0x0,
 0x0,  0xb,  0x98,  0x0,
 0x0,  0x8,  0x18,  0x0,
 0x0,  0xa,  0x90,  0x0,
 0x0,  0x8,  0x10,  0x0,
 0x0,  0xc,  0x30,  0x0,
 0x0,  0x6,  0x60,  0x0,
 0x0,  0x3,  0xc0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0
};

GLfloat r,g,b,d,e; 

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Preenchendo regioes");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
  r=0; g=1; b=0;
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_POLYGON_STIPPLE);

  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(1,0,0.2);
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex2i(143,226); glVertex2i(226,226); 
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();

  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2i(30,226); glVertex2i(113,226); 
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();

   glPointSize(9.0f);
  glBegin(GL_POINTS);
  glColor3f(r,g,b);
  glVertex2f(d,256 - e); 
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:

	if (state == GLUT_DOWN) {
	  r=(GLfloat)rand()/(RAND_MAX+1.0);
	  g=(GLfloat)rand()/(RAND_MAX+1.0);
	  b=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
       d = x; 
	     e = y; 
	}
	break;
  }
}


// COMANDO PARA COMPILAR NO VSCODE DO LINUX 
//  g++ tarefa0604.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp
