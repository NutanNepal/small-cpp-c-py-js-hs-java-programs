def determinant(matrix):
    n = len(matrix)
    det = 0
    if n>2:
        for index in range (0, n):
            modmat = [i[:index]+i[index+1:] for i in matrix[1:]]
            det += (-1)**(index)* matrix[0][index] * determinant(modmat)
        return det
    elif n == 2:
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]
    elif n == 0:
        return 0
    else:
        return matrix[0][0]
a = [[3,2,0,1],[4,0,1,2],[3,0,2,1],[9,2,3,1]]
print(determinant(a))