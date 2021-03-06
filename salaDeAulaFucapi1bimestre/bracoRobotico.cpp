#include <GL/glut.h>
#include <stdlib.h>

/*As variáveis shoulder e elbow guardam o ângulo de rotação do ombro e o ângulo formado entre o braço e o antebraço do robô, respectivamente.*/
static int shoulder = 0, elbow = 0; 

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  /*Uma vez que as transformações geométricas no espaço são representadas por matrizes, 
  o uso de uma pilha de matrizes de transformação ajuda a lembrar a seqüência de transformações realizadas. 
  No OpenGL, esta facilidade é provida pelas funções glPushMatrix(), 
  que insere a matriz de transformação corrente na pilha, e glPopMatrix(), 
  que retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente. 
  Neste exemplo, a função glPushMatrix() serve para lembrar os parâmetros de translação, 
  rotação e escalamento no início das operações de desenho.*/

  /* origem posicionada no ombro */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

  /* origem posicionada no centro do braço */ 
  glTranslatef (1.0, 0.0, 0.0);
  
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();
   
  /* origem posicionada no cotovelo */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();

  /* origem volta para o sistema de coordenadas original */
  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  glutCreateWindow("Braco Robotico");
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
//Movimentar o braço: comando:  shift + E

/* COMANDO PARA COMPILAR NO VSCODE DO LINUX 

Agora, dê o comando abaixo para compilar seu código com o nome do arquivo.

 g++ bracoRobotico.cpp -o firstOpenGlApp -lglut -lGLU -lGL

Agora execute o seu programa OpenGl com o seguinte comando

  ./firstOpenGlApp
*/