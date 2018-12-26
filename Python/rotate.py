def rotate_in_place(matrix):
  ind= 0
  n= len(matrix)
  w = n-1
  if matrix==[[]]:
        pass
  else:
      while ind<=w:
        a, b = ind, ind
        p, q = w, w
        while q>a:
            temp = matrix[a][b] 
            matrix[a][b]= matrix[q][a]
            matrix[q][a]= matrix[p][q]
            matrix[p][q]= matrix[b][p]
            matrix[b][p]= temp
            a+=1
            p-=1
        ind+=1
        w-=1
  return matrix
#print([[1]])
#print(rotate_in_place([[1,2,3],[4,5,6], [7,8,9]]))
#print(rotate_in_place([[13,2,5,1],[14,6,7,8],[9,10,11,3],[16,12,15,4]]))
print(rotate_in_place([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]))