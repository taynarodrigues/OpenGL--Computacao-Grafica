//Desenhar duas curvas, uma usando uma representação analítica paramétrica
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
    glutCreateWindow("Curva Parametrica");               //cria a janela
    init();                                              
    glutDisplayFunc(display);                            //função que será redesenhada pelo GLUT          
    glutKeyboardFunc(keyboard);                          //função de teclado
    glutMainLoop();                                      //mostra todas as janelas criadas
    return 0;
}

//Definição de cada função
void init(void){
  void display(void);
//   glClearColor (1.0, 1.0, 1.0, 1.0); // cor de fundo
//   glOrtho (0,256, 256, 0, -40 ,3.0); //modo de projeção ortogonal
}

float funcao(float x){
    return(x*x);
}

void display(){
    float x,y;
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa a janela
  glColor3f(1.0, 0.0, 0.0);      //cor do ponto vermelho
    glPointSize(6.0f);             //aumenta o tamanho dos pontos

    for(x=-1; x<1; x+=0.01){

        y = funcao(x);
        glBegin(GL_POINTS);
            glVertex2f(x,y);
        glEnd();  
    }

  glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
}
}

//    g++ curvaParametrica.cpp -o firstOpenGlApp -lglut -lGLU -lGL
//   ./firstOpenGlApp