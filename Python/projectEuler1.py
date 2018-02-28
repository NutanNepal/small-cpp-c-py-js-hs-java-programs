_list = list(set([i for i in range(1, 1000) if not i % 5 or not i % 3]))
sum1 = 0
for x in _list:
    sum1 += x
print(sum1)