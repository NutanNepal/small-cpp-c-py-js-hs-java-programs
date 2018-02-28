class Vector(object):
    def __init__(self, vector1):
        self.vector1 = vector1

    def subtract(self, vector2):
        x=[]
        upperbound = max(len(self.vector1), len(vector2))
        try:
            for i in range (upperbound):
                x.append(self.vector1[i] - vector2[i])
            return x
        except (IndexError, TypeError) as error:
            print ("wtf, bro")

    def add(self, vector2):
        x=[]
        upperbound = max(len(self.vector1), len(vector2))
        try:
            for i in range (upperbound):
                x.append(self.vector1[i] + vector2[i])
            return x
        except (IndexError, TypeError) as error:
            print ("wtf, bro")

    def dot(self, vector2):
        z = 0
        try:
            for i in range (len(self.vector1)):
                z += self.vector1[i] * vector2[i]
            return z
        except TypeError:
            pass

    def norm(self):
        y = 0
        try:
            for i in self.vector1:
                y += i ** 2
            return y**(0.5)
        except TypeError:
            pass

    def toString(self):
        return __str__(self.vector1)

    def equals(self, vector2):
        upperbound = max(len(self.vector1), len(vector2))
        flag = True
        try:
            for i in range (upperbound):
                if not self.vector1[i] == vector2[i]:
                    flag = False
            return flag
        except (IndexError, TypeError) as error:
            return False

a = Vector([1, 2])
b = Vector([3, 4])
print(a.add(b))
