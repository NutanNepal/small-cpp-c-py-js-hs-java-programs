def sum_pairs(_list, sum):
    listolist = [[]]
    max = len(_list)
    for x in range (0, max):
        for ind2 in range (1, max):
            inst = [_list(x)]
            if (_list[ind2] + x == sum) & (ind2 < max):
                max = ind2
                inst.append(_list[ind2])
                listolist.append(inst)
    if not listolist:
        return None
    else:
        return listolist[-1]
