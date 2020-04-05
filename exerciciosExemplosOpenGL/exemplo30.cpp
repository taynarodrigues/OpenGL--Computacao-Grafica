#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);


//função principal
int main(int argc, char** argv){
    glutInit(&argc, argv);                                //inicia o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);         //especifica o uso d cores e buffers
    glutInitWindowSize(256,256);                         //especifica as dimensões da janela 
    glutInitWindowPosition(100,100);                     //especifica aonde a janela aparece na tela
    glutCreateWindow("Exemplo projecoes exercitando");               //cria a janela
    init();                                              
    glutDisplayFunc(display);                            //função que será redesenhada pelo GLUT          
    glutKeyboardFunc(keyboard);                          //função de teclado
    glutMainLoop();                                      //mostra todas as janelas criadas
    return 0;
}

//Definição de cada função
void init(void){
  void display(void);
  glClearColor (1.0, 1.0, 1.0, 1.0); // cor de fundo
  glOrtho (0,256, 256, 0, -40 ,3.0); //modo de projeção ortogonal
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT); //limpa a janela
  glColor3f(0.0, 0.0, 0.0);      //cor do ponto
    glPointSize(6.0f);             //aumenta o tamanho dos pontos
    glBegin(GL_POINTS);
    glVertex3f(50.0,50.0,0);
 glEnd();

  glPushMatrix();
  glTranslatef (150, 150, 0.0);
  glutWireCube (40);
  glPopMatrix();

  glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
}
}

//  g++ exemplo30.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp