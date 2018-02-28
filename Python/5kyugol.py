def next_gen(matrix):
    nextgen = []
    for rowindex, row in enumerate(matrix):
        nextgenrow = []
        for colindex in range (len(row)):
            currentcell = 0
            neighbours = countmoore(matrix, rowindex, colindex)
            if neighbours < 2 or neighbours > 3:
                pass
            elif neighbours == 2:
                currentcell = matrix[rowindex][colindex]
            else:
                currentcell = 1
            nextgenrow.append(currentcell)
        nextgen.append(nextgenrow)
    return nextgen

            
def countmoore(matrix, i, j):
    count = 0
    z = [-1, 0, 1]
    for x in z:
        for y in z:
            try:
                if i + x < 0 or j + y < 0:
                    pass
                else:
                    if matrix[i+x][j+y] and not (x == 0 and y == 0):
                        count += 1
            except IndexError:
                pass
    return count

print(next_gen([[0,1,1,1,0,1], [0,0,0,1,0,0], [1,0,0,1,0,1], [1,1,1,0,1,1]]))
#print([1,2,3,4][1])
