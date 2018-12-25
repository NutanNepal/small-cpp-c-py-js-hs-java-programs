main = print (cw [1, 2, 3, 4] [2, 4, 6])

cw x y = [ z | z <- x, z `notElem` y]