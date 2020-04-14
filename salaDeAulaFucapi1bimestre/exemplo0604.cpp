#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

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

GLfloat r,g,b;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
    /*
  A função glutInitDisplayMode() avisa GLUT para utilizar dois buffers no desenho de cenas: 
  um principal e outro auxiliar. Todos os objetos deverão desenhados no buffer auxiliar.
  */
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Preenchendo regioes");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  /*
  glutMouseFunc(mouse);
  Define que função GLUT deverá chamar quando ocorrerem eventos de mouse. 
  Quando o usuário pressiona ou solta uma dos botões do mouse, 
  cada pressionamento ou soltura gera uma chamada de mouse.
  */
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

  /*
  A função glDisable() permitem habilitar diversas habilidades do OpenGL. 
  O parâmetro <parameter>GL_POLYGON_STIPPLE` 
  passado para essa função desabilita o desenho de polígonos utilizando padrões de desenho.
  */
  glDisable(GL_POLYGON_STIPPLE);


  /*
  Neste trecho, a função glPolygonMode() 
  indica que a parte de trás dos polígonos (GL_BACK) 
  será desenhada apenas com a linha de contorno externo (GL_LINE), 
  de cor vermelha, conforme especificado pela função glColor3f(). 
  */
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(1.0, 0.0, 0.0);


  /*
   A função glBegin() são usadas agora para iniciar
    o traçado de um polígono (GL_POLYGON) de coordenadas
     especificadas pela função glVertex2i(). 
  */
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143);
  glEnd();



  /*
  A função glPolygonMode() indica agora que a parte de trás dos polígonos
   será desenhada apenas com preenchimento sólido (GL_FULL). 
   A cor de desenho agora é (R, G, B) = (0, 1, 0), 
   de modo que o resultado da execução desse trecho
    de código é o retângulo verde mostrado na Figura
  */
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(r, g, b);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143);
  glEnd();


  /*
  Este trecho de código demonstra uma característica peculiar de preenchimento. 
  Como cada vértice é desenhado com uma cor diferente, 
  OpenGL interpola estas cores para compor as tonalidades do interior do polígono, 
  gerando um preenchimento bastante colorido.
  */
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);  glVertex2i(30,113);
  glColor3f(0.0, 1.0, 0.0);  glVertex2i(113,113);
  glColor3f(0.0, 0.0, 1.0);  glVertex2i(113,30);
  glColor3f(1.0, 1.0, 0.0);  glVertex2i(30,30);
  glEnd();


  /*
  A função glEnable() permitem habilitar diversas habilidades do OpenGL. 
  O parâmetro <parameter>GL_POLYGON_STIPPLE` 
  Quando GL_POLYGON_STIPPLE é habilitado, OpenGL usa o padrão corrente para desenhar.
  */
  glEnable(GL_POLYGON_STIPPLE); //O preenchimento com padrões é agora habilitado pela função glEnable()
  glColor3f(1.0, 0.0, 1.0); //A função glColor3f() define magenta, combinação das tonalidades puras vermelho (R=1) e azul (B=1), como a nova cor de desenho.
  
  

  /*
  A função glPolygonStipple() define o novo padrão de preenchimento de polígonos, 
  representado pelo vetor <varname>tux[]. 
  Em seguida, o par `glBegin()/glEnd() desenha o último polígono, preenchindo com o padrão "tux".
  */
  glPolygonStipple(tux);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30);
  glEnd();
  
  /*A função glFlush() faz com que qualquer comando OpenGL ainda não executado seja executado 
  o mais rápido possível pelo mecanismo de exibição. OpenGL freqüentemente executa 
  comandos aos lotes, de modo a tornar mais eficiente o processo de exibição, 
  principalmente quando os programas são executados via rede. Neste caso, quando os 
  comandos executados um a um, o programa pode se tornar ineficiente, considerando as sobrecargas 
  existentes em um barramento de rede. Caso o programa desenvolvido seja destinado 
  ao uso somente local, a função glFlush() torna-se desnecessária. Entretanto, 
  se o programa é feito para funcionar bem tanto localmente quanto em rede, deve ser incluída 
  uma chamada à função glFlush() no final de cada quadro ou cena.*/
  glFlush();


  /*
  Quando a função glutSwapBuffers() for chamada, o buffer auxiliar passa a ser o principal, 
  e o principal toma o lugar do auxiliar. Assim, a imagem gerada é apresentada de uma só vez na tela, 
  evitando cintilações e a visualização do processo de desenho, efeitos indesejáveis principalmente em animações.
  */
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

/*
A função de chamada passada como argumento para glutMouseFunc() deve possuir o seguinte protótipo:
        void funcao(int button, int state, int x, int y);
*/
void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:
  /*
  A função de tratamento de eventos de mouse verifica se algum botão é pressionado. 
  Caso o botão esquerdo (GLUT_LEFT_BUTTON) 
  seja pressionado 
  (GLUT_DOWN), serão gerados três valores aleatórios para as variáveis r, g e b, na faixa [0,1]. 
  */
	if (state == GLUT_DOWN) {
	  r=(GLfloat)rand()/(RAND_MAX+1.0);
	  g=(GLfloat)rand()/(RAND_MAX+1.0);
	  b=(GLfloat)rand()/(RAND_MAX+1.0);


    /*Quando a função glutPostRedisplay() é executada, 
    a função display é chamada novamente, fazendo com que a janela corrente seja 
    redesenhada e o polígono no canto superior esquerdo dessa janela mude de cor.*/
	  glutPostRedisplay();
	}
	break;
  }
}

//  g++ exemplo0604.cpp -o firstOpenGlApp -lglut -lGLU -lGL
//  ./firstOpenGlApp