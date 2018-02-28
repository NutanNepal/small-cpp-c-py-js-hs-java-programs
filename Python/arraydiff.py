def array_diff(a, b):
    if b == []: return a
    return [x for x in a for y in b if not x == y]

print(array_diff([1,2,2], []))