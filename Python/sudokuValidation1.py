class Sudoku(object):
    def __init__(self, matrix):
        self.matrix = matrix

    def is_valid(self):
        def getSmallsq(k, l, matrix):
            a = int(math.sqrt(len(matrix)))
            output = []
            for i in range (0 + k * a, a * (k + 1)):
                for j in range (0 + l * a, a * (l + 1)):
                    output.append(matrix[i][j])
            return output

        n = len(self.matrix)
        a = int(n ** 0.5)
        if not a ** 2 == n:
            return False
        sudoku = set(i for i in range (1, n+1))
        for row in self.matrix:
            for i in row:
                try:
                    int(str(i))
                except ValueError:
                    return False
            if not (len(row) == n and set(row) == sudoku):
                return False
        for column in zip(*self.matrix[::-1]):
            if not (len(column) == n and set(column) == sudoku):
                return False
        for k in range (0, a):
            for l in range (0, a):
                smallsq = getSmallsq(k, l, self.matrix)
                if not set(smallsq) == sudoku:
                    return False
        return True
