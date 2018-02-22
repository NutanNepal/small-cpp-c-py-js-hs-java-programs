def sum_pairs(_list, sum):
    listolist = []
    max, x = len(_list), 0
    while x < max:
        find = sum - _list[x]
        try:
            get = (_list).index(find, x + 1, max)
            max = get
            listolist.append([_list[x], _list[get]])
        except ValueError:
            pass
        x+=1
    if not listolist:
        return None

    else:
        return listolist[-1]

print(sum_pairs([20, -13, 40], -7))

"""
def sum_pairs(_list, sum):
    stack = []
    for index in range (0, len(_list) - 1):
        stack.append(sum - _list[index])
        for i in range (index, -1, -1):
            if (_list[index + 1] == stack[i]):
                return [_list[i],_list[index + 1]]
    return None
"""