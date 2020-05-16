//Desenhar duas curvas, uma usando uma representação analítica não paramétrica

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);


//função principal
int main(int argc, char** argv){
    glutInit(&argc, argv);                                //inicia o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);         //especifica o uso d cores e buffers
    glutInitWindowSize(256,256);                         //especifica as dimensões da janela 
    glutInitWindowPosition(100,100);                     //especifica aonde a janela aparece na tela
    glutCreateWindow("Curva Nao Parametrica");               //cria a janela
    init();                                              
    glutDisplayFunc(display);                            //função que será redesenhada pelo GLUT          
    glutKeyboardFunc(keyboard);                          //função de teclado
    glutMainLoop();                                      //mostra todas as janelas criadas
    return 0;
}

//Definição de cada função
void init(void){
void display(void);
}


//CURVA NÃO PARAMÉTRICO

void curva(float t, float *x, float *y){

    double a = cos(t);
    double b = sin(t); 

    *x = a;
    *y = b;


    // *x = t*t;
    // *y=t;
}

void plota_curva(){

   
    float x, y, t;

    float incremento = 0.1;

    glColor3f(1.0, 0.0, 0.0);
    for(t=-2*PI; t < 2*PI; t+=incremento){

        curva(t, &x, &y);
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
    }
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    plota_curva();
    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
}
}

//  g++ curvaNaoParametrica.cpp -o firstOpenGlApp -lglut -lGLU -lGL
// ./firstOpenGlApp