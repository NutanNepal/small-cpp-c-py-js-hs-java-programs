x=[x for x in range (2,20)]
print(set(x) - set(y for y in x for z in x if z < y and not y % z))