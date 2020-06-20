import pygame, sys
from pygame.locals import *

# inicia o pygame
pygame.init()
# inicia a janela
windowSurface = pygame.display.set_mode((700, 620), 0, 32)
pygame.display.set_caption("SPFC")

# inicia as cores utilizadas
# BLACK = (0, 0, 0) #Triangulo Preto
WHITE = (255, 255, 255)
# RED = (255, 0, 0) #Triangulo vermelho
GRAY = (128, 128, 128)

# inicia as fontes
basicFont = pygame.font.SysFont(None, 180)

# inicia o texto
# text = basicFont.render("S P F C", True, WHITE, BLACK)
# text = basicFont.render("S P F C", True)
textRect = pygame.Rect(135, 150, 300, 80)

# desenha o fundo cinza
windowSurface.fill(GRAY)


# desenha o polígono branco que corresponde ao escudo
pygame.draw.polygon(windowSurface, WHITE, ((100, 300),(100, 100),(600, 100),(600, 300),(350, 600)))

# desenha os triângulos do escudo
# pygame.draw.polygon(windowSurface, RED, ((135, 300),(320, 300),(320, 520))) #Triangulo vermelho
# pygame.draw.polygon(windowSurface, BLACK, ((565, 300),(380, 300),(380, 520))) #Triangulo Preto

# desenha as linhas pretas que contornam o escudo
# pygame.draw.line(windowSurface, BLACK, (100, 300),(100, 100), 4)
# pygame.draw.line(windowSurface, BLACK, (100, 100),(600, 100), 4)
# pygame.draw.line(windowSurface, BLACK, (600, 100),(600, 300), 4)
# pygame.draw.line(windowSurface, BLACK, (600, 300),(350, 600), 4)
# pygame.draw.line(windowSurface, BLACK, (350, 600),(100, 300), 4)

# desenha o retângulo do fundo do texto na superfície
# pygame.draw.rect(windowSurface, BLACK, (textRect.left -10, textRect.top -15,textRect.width + 150, textRect.height + 60))

# obtem um array de pixel da superficie
# pixArray = pygame.PixelArray(windowSurface)
# pixArray[480][380] = BLACK
# del pixArray

# desenha o texto na janela
# windowSurface.blit(text, textRect)

# desenha a janela na tela
pygame.display.update()

# roda o loop do jogo
while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
