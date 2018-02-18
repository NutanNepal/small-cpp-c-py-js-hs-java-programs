def trans(array):
    print("to transpose ", array)
    # Do an inverse transpose (i.e. rotate left by 90 degrees
    return [[row[-i-1] for row in array] for i in range(len(array[0]))] if len(array) > 0 else array


def shiftbyR(array, r):
    from collections import deque

    row, column = len(array), len(array[0])

    boundaries = []
    while len(array) > 0:
        nextlist = []
        for _ in range(4):
            if len(array) == 0:
                break
            # Add the 1st ro of the array
            nextlist += array[0]
            # Chop off the 1st row and transpose
            array = trans(array[1:])
        boundaries.append(nextlist)
    pre_output = []
    for x in boundaries:
        items = deque(x)
        items.rotate(-r)
        pre_output += list(items)
    
    print(pre_output)
    output = [[]]
    while len(pre_output) > 0:
        output[0] += pre_output[:column]
        print(output)
        pre_output = pre_output[column:]
        clean = []
        for _row in output:
            for i in range(len(_row)):
                clean.append([_row[-i-1]])

        output = clean
        print (output)
        if len(pre_output) < 1:
            break
        output[0] += pre_output[:(row - 1)]
        pre_output = pre_output [row -1:]

        clean = []
        for _row in output:
            for i in range(len(_row)):
                clean.append([_row[-i-1]])

        output = clean
        
        column -= 1
        row -= 1
    """a, b, c = 0, 0, 0
    n, n1 = row, column
    while n >= 1 or n1 >=1:
        for index in range(b, column):
            output[a][index] = pre_output[c + index]
        a += 1
        c += 1

        for index2 in range(a, row):
            output[index2][n-1] = pre_output[c+ index]
        c += 1

        for index3 in range(column-2, b, -1):
            output[n-1][index3] = pre_output[c+ index]
        c += 1

        for index4 in range(row-1, b, -1):
            output[index4][b] = pre_output[c+ index]
        c += 1
        b += 1
        n -= 1
        n1 -= 1
        print(output)"""

    return output


print(shiftbyR([[1, 2, 3, 4], [5, 6,7, 8], [9, 10, 11, 12],[13,14,15,16]], 1))
