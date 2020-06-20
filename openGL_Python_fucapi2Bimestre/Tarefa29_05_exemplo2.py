import pygame
from pygame.locals import *


from OpenGL.GL import GL_TRIANGLES


# from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GL import *


left = -50.0;
right = 50.0;
bottom = -50.0;
top = 50.0;


def desenhaEixos():
    glLineWidth(1); # Determina a espessura da linha que será desenhada
    glBegin(GL_LINES);
    glVertex2d(left, 0);
    glVertex2d(right,0);
    glVertex2d( 0, bottom);
    glVertex2d( 0, top);
    glEnd();


def main():
    pygame.init()
    display = (800,600)
    largura=800
    altura=600
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)
    

    glClearColor(1.0, 1.0, 1.0, 1.0);

    # Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(left, right, bottom, top);
    glMatrixMode(GL_MODELVIEW);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    # Estabelece a janela de seleção (esquerda, direita, inferior,
    # superior) mantendo a proporção com a janela de visualização
    if (largura <= altura):
       gluOrtho2D (left, right, bottom*altura/largura, top*altura/largura);
    else:
       gluOrtho2D (left*largura/altura, right*largura/altura, bottom, top);
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glLoadIdentity();
    glColor3f(1.0,0.0,0.0);
    desenhaEixos();
    pygame.display.flip()
    pygame.time.wait(10)



main()
