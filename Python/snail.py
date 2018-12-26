def snail(givenArray):
    a, b = 0, 0;
    n= len(givenArray)
    print (n)
    snailed = []
    if givenArray == [[]]:
        pass
    else:
        while n>=1:
            for index in range (b, n):
                snailed.append(givenArray[a][index])
            a+=1

            for index2 in range (a, n):
                snailed.append(givenArray[index2][n-1])

            for index3 in range (n-2, b, -1):
                snailed.append(givenArray[n-1][index3])

            for index4 in range (n-1, b, -1):
                snailed.append(givenArray[index4][b])
            b+=1
            n-=1

    return snailed

#what = [[1,2,3],[4,5,6],[7,8,9]]
what = [[1]]
print(snail(what))