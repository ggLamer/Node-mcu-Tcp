import pygame
import random
from threading import Thread
import requests
import time

WIDTH = 800
HEIGHT = 200
FPS = 30

ip = "http://192.168.1.16"

# Задаем цвета
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
x= WIDTH /2 

class Player(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((20, 20))
        self.image.fill(GREEN)
        self.rect = self.image.get_rect()
        self.rect.center = (WIDTH / 2, HEIGHT / 2)
        
        
    def update(self):
        self.rect.x = x 
        


# Создаем игру и окно
pygame.init()
pygame.mixer.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Coords")
clock = pygame.time.Clock()
all_sprites = pygame.sprite.Group()
player = Player()
all_sprites.add(player)
def up():
    print("connect")
    while True:
        global x
        xx = requests.get(f"{ip}/dist").text
        x = float(requests.get(f"{ip}/dist").text) * 6
        print(f"Coord: {xx}")
        
        


# Цикл игры
a = Thread(target=up)
a.start()
running = True
while running:
    # Держим цикл на правильной скорости
    clock.tick(FPS)
    # Ввод процесса (события)
    for event in pygame.event.get():
        # check for closing window
        if event.type == pygame.QUIT:
            running = False

    # Обновление
    all_sprites.update()
    
    # Рендеринг
    screen.fill(BLACK)
    all_sprites.draw(screen)
    
    # После отрисовки всего, переворачиваем экран
    pygame.display.flip()

pygame.quit()