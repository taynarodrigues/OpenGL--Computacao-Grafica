// #include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

//função principal
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256,256);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Avaliacao");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
}

void display(void){
glClear (GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0);
 glBegin(GL_LINES);

//quadrado 1
 glVertex2i(50, 50); glVertex2i(50, 100);
 glVertex2i(100, 50); glVertex2i(100, 100);
 glVertex2i(50, 50); glVertex2i(100, 50);
 glVertex2i(50, 100); glVertex2i(100, 100);

//quadrado 2
 glVertex2i(70, 120); glVertex2i(70, 170);
 glVertex2i(120, 120); glVertex2i(120, 170);
 glVertex2i(70, 120); glVertex2i(120, 120);
 glVertex2i(70, 170); glVertex2i(120, 170);

//linha ligacao 1
 glVertex2i(50, 100); glVertex2i(70, 120);
 glVertex2i(100, 100); glVertex2i(120, 120);

//linha ligacao 2
 glVertex2i(70, 170); glVertex2i(90, 190);
 glVertex2i(120, 170); glVertex2i(140, 190);

//fecha o teto
 glVertex2i(90, 190); glVertex2i(140, 190);

//fecha parede
  glVertex2i(140, 190); glVertex2i(140, 90);

//fecha o chao
   glVertex2i(100, 50); glVertex2i(140, 90);

    glEnd();
    glFlush();

}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
    }
}


/* COMANDO PARA COMPILAR NO VSCODE DO LINUX 

Agora, dê o comando abaixo para compilar seu código com o nome do arquivo.

g++ atividade13.cpp -o firstOpenGlApp -lglut -lGLU -lGL

Agora execute o seu programa OpenGl com o seguinte comando

  ./firstOpenGlApp
*/