import pygame, sys, time
from pygame.locals import *

# set up pygame
pygame.init()

# set up the window
WINDOWWIDTH = 400
WINDOWHEIGHT = 400
windowSurface = pygame.display.set_mode((WINDOWWIDTH, WINDOWHEIGHT), 0, 32)
pygame.display.set_caption('Animation')

# set up direction variables - Alterado
DOWNLEFT = 2
DOWNRIGHT = 5
UPLEFT = 8
UPRIGHT = 6

#MOVESPEED = 4 - A velocidade será definida em cada elemento do bloco


# set up the colors 
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)
GRAY = (128, 128, 128)
YELLOW = (255, 255, 0)


# set up the block data structure - Figuras geométricas que já estavam no código original, tendo sido alterados apenas os seus tamanhos e suas velocidades, conforme pedido no enunciado do exercício
b1 = {'rect':pygame.Rect(100, 150, 60, 60), 'color':RED, 'dir':UPRIGHT, 'speed': 1}
b2 = {'rect':pygame.Rect(300, 80, 50, 100), 'color':GREEN, 'dir':UPLEFT, 'speed': 3}
b3 = {'rect':pygame.Rect(200, 200, 20, 20), 'color':BLUE, 'dir':DOWNLEFT, 'speed': 2}


# Insere as novas formas geométricas - com diferentes velocidades
b4 = {'rect':pygame.Rect(146, 0, 40, 40), 'color':WHITE, 'dir':UPLEFT, 'speed': 2}
b5 = {'rect':pygame.Rect(300, 50, 10, 10), 'color':GRAY, 'dir':DOWNLEFT, 'speed': 3}
b6 = {'rect':pygame.Rect(300, 200, 80, 40), 'color':YELLOW, 'dir':UPRIGHT, 'speed': 5}

blocks = [b1, b2, b3, b4, b5, b6]


# run the game loop
while True:
    # check for the QUIT event
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()


    # draw the black background onto the surface
    windowSurface.fill(BLACK)

    for b in blocks:
        # move the block data structure
        if b['dir'] == DOWNLEFT:
            b['rect'].left -= b['speed']
            b['rect'].top += b['speed']
        if b['dir'] == DOWNRIGHT:
            b['rect'].left += b['speed']
            b['rect'].top += b['speed']
        if b['dir'] == UPLEFT:
            b['rect'].left -= b['speed']
            b['rect'].top -= b['speed']
        if b['dir'] == UPRIGHT:
            b['rect'].left += b['speed']
            b['rect'].top -= b['speed']

        # check if the block has move out of the window
        if b['rect'].top < 0:
            # block has moved past the top
            if b['dir'] == UPLEFT:
                b['dir'] = DOWNLEFT
            if b['dir'] == UPRIGHT:
                b['dir'] = DOWNRIGHT
        if b['rect'].bottom > WINDOWHEIGHT:
            # block has moved past the bottom
            if b['dir'] == DOWNLEFT:
                b['dir'] = UPLEFT
            if b['dir'] == DOWNRIGHT:
                b['dir'] = UPRIGHT
        if b['rect'].left < 0:
            # block has moved past the left side
            if b['dir'] == DOWNLEFT:
                b['dir'] = DOWNRIGHT
            if b['dir'] == UPLEFT:
                b['dir'] = UPRIGHT
        if b['rect'].right > WINDOWWIDTH:
            # block has moved past the right side
            if b['dir'] == DOWNRIGHT:
                b['dir'] = DOWNLEFT
            if b['dir'] == UPRIGHT:
                b['dir'] = UPLEFT


        # draw the block onto the surface
       
        # Formas geométricas - retangulares - que já estavam no código original
        pygame.draw.rect(windowSurface, b1['color'], b1['rect'])
        pygame.draw.rect(windowSurface, b2['color'], b2['rect'])
        pygame.draw.rect(windowSurface, b3['color'], b3['rect'])

        # Novas formas geométricas
         
        # triângulo
        pygame.draw.polygon(windowSurface, b4['color'], ((b4['rect'].topleft),(b4['rect'].topright),(b4['rect'].bottomleft)))

        # circunferência
        pygame.draw.circle(windowSurface, b5['color'], b5['rect'].topleft, 20, 0)

        # elipse
        pygame.draw.ellipse(windowSurface, b6['color'], b6['rect'])


    # draw the window onto the screen
    pygame.display.update()
    time.sleep(0.02)
