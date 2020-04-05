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
  glutInitWindowSize (840, 840);                          // especifica as dimensoes da janela
  glutInitWindowPosition (100, 100);                      // especifica aonde a janela aparece na tela
  glutCreateWindow ("Exemplo projecoes slide");              // cria a janela
  init();
  glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
  glutKeyboardFunc(keyboard);                             // funcoes de teclado
  glutMainLoop();                                         // mostra todas as janelas criadas
  return 0;
}

// definicao de cada funcao

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);    // cor de fundo
  glOrtho (0, 256, 0, 256, -45.0 ,45.0);     // modo de projecao ortogonal

}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
  glColor3f (0.0, 0.0, 0.0);                  // cor do ponto
  glPointSize(10.0f); // aumenta o tamanho dos pontos
  glBegin(GL_POINTS);
    glVertex3f(50.0,50.0,0); //ponto negro
    glColor3f(1.0,0.0,0.0);
    glVertex3f(100.0,100.0,-2.0); //ponto vermelho
    glColor3f(0.0,1.0,0.0);
    glVertex3f(150.0,150.0,-4.0); //ponto verde
    glColor3f(0.0,0.0,1.0);
    glVertex3f(450.0,450.0,-4.0); //ponto azul
  glEnd();

  glPushMatrix();
  glTranslatef (150.0, 150.0, 0.0);
  glutWireCube (40.0);
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



/* COMANDO PARA COMPILAR NO VSCODE DO LINUX 

Agora, dê o comando abaixo para compilar seu código com o nome do arquivo.

 g++ 2exOrtho.cpp -o firstOpenGlApp -lglut -lGLU -lGL

Agora execute o seu programa OpenGl com o seguinte comando

  ./firstOpenGlApp
*/