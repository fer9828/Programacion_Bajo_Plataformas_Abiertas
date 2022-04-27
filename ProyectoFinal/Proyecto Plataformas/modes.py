from constants import *

#Esta clase se encarga de definir los diferentes cuatro modos de las TortiRicas en ele juego
class MainMode(object):
    def __init__(self):
        self.timer = 0
        self.scatter()

    def update(self, dt):
        self.timer += dt
        if self.timer >= self.time:
            if self.mode is SCATTER:
                self.chase()
            elif self.mode is CHASE:
                self.scatter()
                
	#Define el tiempo de 7s para el modo Scatter
    def scatter(self):
        self.mode = SCATTER
        self.time = 7
        self.timer = 0
        
	#Define el tiempo de 20s el modo Chase
    def chase(self):
        self.mode = CHASE
        self.time = 20
        self.timer = 0

#Esta clase controla en cual modo deben estar los personajes en un momento especifico 
class ModeController(object):
    def __init__(self, entity):
        self.timer = 0
        self.time = None
        self.mainmode = MainMode()
        self.current = self.mainmode.mode
        self.entity = entity 

    def update(self, dt):
        self.mainmode.update(dt)
        if self.current is FREIGHT:
            self.timer += dt
            if self.timer >= self.time:
                self.time = None
                self.entity.normalMode()
                self.current = self.mainmode.mode
        elif self.current in [SCATTER, CHASE]:
            self.current = self.mainmode.mode

        if self.current is SPAWN:
            if self.entity.node == self.entity.spawnNode:
                self.entity.normalMode()
                self.current = self.mainmode.mode

    def setFreightMode(self):
        if self.current in [SCATTER, CHASE]:
            self.timer = 0
            self.time = 7
            self.current = FREIGHT
        elif self.current is FREIGHT:
            self.timer = 0

    def setSpawnMode(self):
        if self.current is FREIGHT:
            self.current = SPAWN