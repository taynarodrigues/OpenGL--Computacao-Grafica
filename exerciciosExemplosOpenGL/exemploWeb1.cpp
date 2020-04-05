#include <GL/glut.h>

void init(void){
  glClearColor (1.0, 1.0, 1.0, 1.0); // cor de fundo
  glOrtho (0,256, 256, 0, -40 ,40);
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:                                         
	exit(0);
	break;
  }
}
void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(6.0f);

  glBegin(GL_LINES); //Determina qual objeto será desenhado
    glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(100, 50);
	glVertex2i(100, 130);
	glVertex2i(150, 130);
  glEnd();

  /* Cubo 1 */
//   glPushMatrix();
//   glTranslatef (150, 150, 0.0);
//   glutWireCube (40);
//   glPopMatrix();

  glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256,256);
    glutInitWindowPosition(100 ,100);
    glutCreateWindow("Exemplo");
    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

/* COMANDO PARA COMPILAR NO VSCODE DO LINUX 

Agora, dê o comando abaixo para compilar seu código com o nome do arquivo.

  g++ exemploWeb1.cpp -o firstOpenGlApp -lglut -lGLU -lGL

Agora execute o seu programa OpenGl com o seguinte comando

  ./firstOpenGlApp
*/