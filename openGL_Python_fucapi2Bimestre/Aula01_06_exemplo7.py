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
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

 # inicia as fontes
basicFont = pygame.font.SysFont(None, 48)

# inicia o texto
text = basicFont.render("Hello world!", True, WHITE, BLUE)
textRect = text.get_rect()
textRect.centerx = windowSurface.get_rect().centerx
textRect.centery = windowSurface.get_rect().centery

# desenha o fundo branco
windowSurface.fill(WHITE)

# desenha um poligono verde na superficie
pygame.draw.polygon(windowSurface, GREEN, ((146, 0), (291, 106), (236, 277),(56, 277), (0, 106)))

# desenha algumas linhas azuis na superficie
pygame.draw.line(windowSurface, BLUE, (60, 60), (120, 60), 4)
pygame.draw.line(windowSurface, BLUE, (120, 60), (60, 120))
pygame.draw.line(windowSurface, BLUE, (60, 120), (120, 120), 4)

# desenha um circulo azul na superficie
pygame.draw.circle(windowSurface, BLUE, (300, 50), 20, 0)

# desenha uma elipse vermelha na superficie
pygame.draw.ellipse(windowSurface, RED, (300, 250, 40, 80), 1)

# desenha o retangulo do fundo do texto na superficie
pygame.draw.rect(windowSurface, RED, (textRect.left - 20, textRect.top - 20,textRect.width + 40, textRect.height + 40))

# obtem um array de pixel da superficie
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