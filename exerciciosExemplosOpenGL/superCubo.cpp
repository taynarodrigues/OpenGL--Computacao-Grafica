
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __PC__

#else
#include <GL/glut.h>
#endif

// ----------------------------------------------------------
// Declarações de Funções
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Variáveis Globais
// ----------------------------------------------------------
double rotate_y=0; 
double rotate_x=0;

// ----------------------------------------------------------
// função display() 
// ----------------------------------------------------------
void display(){

  //  Limpa a tela e o Z-Buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // Reinicia transformações
  glLoadIdentity();

  // Outras Transformações
  // glTranslatef( 0.1, 0.0, 0.0 );      // Não está incluído
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Não está incluído

  // Rotaciona quando o usuário muda rotate_x e rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

  

  
 glBegin(GL_POLYGON);
 
    glVertex3f(  0.5, -0.5, -0.5 );      
    glVertex3f(  0.5,  0.5, -0.5 );      
    glVertex3f( -0.5,  0.5, -0.5 );      
    glVertex3f( -0.5, -0.5, -0.5 );      
 
  glEnd();


 glBegin(GL_POLYGON);

  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 

 glBegin(GL_POLYGON);

  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  
 glBegin(GL_POLYGON);

  glVertex3f( -0.5, -0.5, 0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 

 glBegin(GL_POLYGON);

  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
 
 glBegin(GL_POLYGON);

  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  glFlush();
  glutSwapBuffers();
 
}

// ----------------------------------------------------------
// Função specialKeys()
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
  //  Seta direita - aumenta rotação em 5 graus
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Seta para esquerda - diminui a rotação por 5 graus
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Requisitar atualização do display
  glutPostRedisplay();
 
}

// ----------------------------------------------------------
// Função main()
// ----------------------------------------------------------
int main(int argc, char* argv[]){
 
  //  Inicializa o GLUT e processa os parâmetros do usuário GLUT
  glutInit(&argc,argv);
 
  //  Requisita uma janela com buffer duplo e true color com um Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Cria a janela do programa
  glutCreateWindow("Super Cube");

  //  Habilita o teste de profundidade do Z-buffer
  glEnable(GL_DEPTH_TEST);

  // Funções
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);

  //  Passa o controle dos eventos para o GLUT
  glutMainLoop();
 
  //  Retorna para o SO
  return 0;
 
}
// g++ superCubo.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp