import pygame, sys
from pygame.locals import *

# inicia o pygame
pygame.init()
# inicia a janela
windowSurface = pygame.display.set_mode((500, 400), 0, 32)
pygame.display.set_caption("SPFC")

# inicia as cores utilizadas
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
BEIGE = (180, 166, 150)


# inicia as fontes
basicFont = pygame.font.SysFont(None, 100)

#parte 4
# inicia o texto
text = basicFont.render("S P F C", True, WHITE, BLACK)
textRect = pygame.Rect(115, 100, 277, 40)

# desenha o fundo Bege
windowSurface.fill(BEIGE)

#parte 1
# desenha o polígono branco que corresponde ao escudo
pygame.draw.polygon(windowSurface, WHITE, ((97, 207),(97, 97),(357, 97),(357, 207),(225, 357)))

#parte 2
# desenha os triângulos do escudo
pygame.draw.polygon(windowSurface, RED, ((135, 210),(220, 210),(220, 320))) #Triângulo vermelho
pygame.draw.polygon(windowSurface, BLACK, ((330, 210),(250, 210),(250, 317))) #Triângulo preto

#parte 5
# desenha as linhas pretas que contornam o escudo
pygame.draw.line(windowSurface, BLACK, (100, 210),(100, 100), 6) #esquerda
pygame.draw.line(windowSurface, BLACK, (100, 100),(361, 100), 6) #teto
pygame.draw.line(windowSurface, BLACK, (360, 100),(360, 210), 6) #direita
pygame.draw.line(windowSurface, BLACK, (360, 210),(220, 369), 6) #direita-baixo
pygame.draw.line(windowSurface, BLACK, (220, 369),(100, 210), 6) #esquerda-baixo

#parte 3
# desenha o retângulo do fundo do texto na superfície
pygame.draw.rect(windowSurface, BLACK, (textRect.left -1, textRect.top -1,textRect.width - 36, textRect.height + 35))

# obtem um array de pixel da superfície
pixArray = pygame.PixelArray(windowSurface)
pixArray[480][380] = BLACK
del pixArray

# desenha o texto na janela
windowSurface.blit(text, textRect)

# desenha a janela na tela
pygame.display.update()

# roda o loop do jogo
while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
