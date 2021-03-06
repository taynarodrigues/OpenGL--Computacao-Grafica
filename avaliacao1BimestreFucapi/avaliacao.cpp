#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

static int rua = 0, coluna= 0, coluna1 = 0, cinta1 = 0, cinta2 = 0;
GLUquadricObj *carro;
GLfloat r,g,b,d,e; 

void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void init(void){

    glClearColor (255, 255, 255, 0.0);
    glOrtho (0, 256, 0, 256, -1 ,1);
    r=0; g=1; b=0;
}
void display(void){


    int i;
    glClear (GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);
    glPushMatrix();
    glTranslatef (0.5, -6.0, -6.0);
    glRotatef ((GLfloat) rua, 0.0, 1.0, 0.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (-25.0, 1.0, 4.0); //comprimento da rua
    glColor3f(0.0,0.0,0.0);
    glutSolidCube(1.0);
    glPopMatrix();


    glColor3f (255.0, 255.0, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex3f(11.3,1, 1);
    glVertex3f(-11.4,1, 1); //Linhas de divisão de fluxos opostos (AMARELA)
    glEnd();

    glTranslatef (3.0, 3.0, 5.0); //largura da coluna
    glRotatef ((GLfloat) coluna, 1.0, 1.0, 1.0);
    glTranslatef (0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (1.0, 5.0, 1.0);
    glColor3f (0.98, 0.93,0.36); //amarelo 
    glutSolidCube(1);
    glPopMatrix();

    glTranslatef (0.0, 0.0, -10.0);
    glRotatef ((GLfloat) coluna1, 0.0, 0.0, 1.0);
    glTranslatef (0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (1.0, 5.0, 1.0);
    glColor3f (0.98, 0.93,0.36); //amarelo 
    glutSolidCube(1);;
    glPopMatrix();
    

    //cinta parte 1
    glTranslatef (0.0, 0.0, -3.0);
    glRotatef ((GLfloat) cinta1, 0.0, 0.0, 1.0);
    glTranslatef (0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (1.0, 5.0, 2.5);
    glColor3f (0.98, 0.93,0.36);
    glutSolidCube(1);;
    glPopMatrix();

    //cinta parte 2
    glTranslatef (0.0, 0.0, 8.5);
    glRotatef ((GLfloat) cinta2, 0.0, 0.0, 1.0);
    glTranslatef (0.0, 2.0, -2.5);
    glPushMatrix();
    glScalef (1.0, 3.0, 17.0); // largura da cinta
    glColor3f (0.0, 255.0, 0.0); //cor da cinta
    glutSolidCube(1);
    glPopMatrix();

    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glColor3f(r,g,b);
    glVertex2f(d,256 - e); 
    glEnd();

    //carro esquerdo
    carro = gluNewQuadric ();
    glColor3f(1,0.5,1);
    glRotated(70,1,0,0);
    glTranslatef (-0.5, 0.5, 3.0);

    gluCylinder(carro,0.7,1.2,1.2,20,5); //largura carro
    glTranslatef (0.0, -4.0, -4.0);
    glScalef (0.5, 1.0, 1.0);
    glPopMatrix();

    //carro direito
    carro = gluNewQuadric ();
    glColor3f(1,0.5,1);
    glRotated(119,1,0,0);
    glTranslatef (-0.5, 0.5, 3.0);
    gluCylinder(carro,0.7,0.2,1.1,4,5);
    glTranslatef (0.0, -4.0, -4.0);
    glScalef (-3.0, 5.0, -4.0);
    glPopMatrix();


    glPopMatrix();
    glutSwapBuffers();

}

/*A função reshape() é chamada cada vez que o tamanho da tela é alterado pelo usuário,
 atribuindo às variáveis largura e altura as novas dimensões da janela.
Estas duas variáveis são utilizadas juntamente com a função glViewport() 
para tornar o cubo proporcional ao tamanho da janela.*/
void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION); 
    glLoadIdentity (); //A função glLoadIdentity() inicia a matriz de projeção corrente como a matriz identidade.
    gluPerspective(100.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW); //A função glMatrixMode() especifica a pilha de matrizes que será o alvo das operações matriciais subseqüentes;
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0); //espaço entre as colunas
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


// funcao principal
int main(int argc, char** argv){
  glutInit(&argc, argv);                              // inicializa o glut
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);           // especifica o uso de cores e buffers
  glutInitWindowSize (1110, 800);                          // especifica as dimensoes da janela
  glutInitWindowPosition (100, 100);                      // especifica aonde a janela aparece na tela
  glutCreateWindow ("Avaliacao 1 Bimestre");              // cria a janela
  init();
  glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);                             // funcoes de teclado
//   glutMouseFunc(mouse);
  glutMainLoop();                                         // mostra todas as janelas criadas
  return 0;
}

/* COMANDO PARA COMPILAR NO VSCODE DO LINUX 

Agora, dê o comando abaixo para compilar seu código com o nome do arquivo.

g++ avaliacao.cpp -o firstOpenGlApp -lglut -lGLU -lGL

Agora execute o seu programa OpenGl com o seguinte comando

  ./firstOpenGlApp
*/