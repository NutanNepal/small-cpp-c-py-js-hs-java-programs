a = 'lumana'
print(a)
print(a[::-1])
i, j = 5, 0
c, b = 2, 1
for lumey in a:
    if i >= 1:
        x, y = ''.join(['\t'] * i), ''.join(['\t'] * j)
        print (y + lumey + x + lumey)
        i-=2
        j+=1
    else:
        x, y = ''.join(['\t'] * c), ''.join(['\t'] * b)
        print (x + lumey + y + lumey)
        c -= 1
        b+= 2

    
