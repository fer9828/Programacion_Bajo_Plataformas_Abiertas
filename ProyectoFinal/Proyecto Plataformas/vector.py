import math

class Vector2(object):
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
        self.thresh = 0.000001
#Aritmética utilizada
    def __add__(self, other):
        return Vector2(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector2(self.x - other.x, self.y - other.y)

    def __neg__(self):
        return Vector2(-self.x, -self.y)

    def __mul__(self, scalar):
        return Vector2(self.x * scalar, self.y * scalar)

    def __div__(self, scalar):
        if scalar != 0:
            return Vector2(self.x / float(scalar), self.y / float(scalar))
        return None

    def __truediv__(self, scalar):
        return self.__div__(scalar)
#Equivalencia hecha para que el sistema interprete 3.6=3.0008
    def __eq__(self, other):
        if abs(self.x - other.x) < self.thresh:
            if abs(self.y - other.y) < self.thresh:
                return True
        return False

    def magnitudeSquared(self):
        return self.x**2 + self.y**2
#Magnitud del vector hecho
    def magnitude(self):
        return math.sqrt(self.magnitudeSquared())
#Se copia el vector para obtener uno nuevo debido a como python usa la memoria. De esta manera:
#Se modifica el neuvo vector sin cambiar el original
    def copy(self):
        return Vector2(self.x, self.y)

    def asTuple(self):
        return self.x, self.y

    def asInt(self):
        return int(self.x), int(self.y)
#Utilizando el método string se indica la ubicación del vector en la memoria
    def __str__(self):
        return "<"+str(self.x)+", "+str(self.y)+">"