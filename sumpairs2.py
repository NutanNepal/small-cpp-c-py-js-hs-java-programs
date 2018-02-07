

def sum_pairs(_list, sum):
    listolist = [[]]
    max = len(_list)
    _list2 = []
    _list2[:] = [sum-x for x in list1]
    print (_list2)
    for i in range (0, max):
        list1 = [a[:i]+a[i+1:] for a in _list]
        list2 = [a[:i]+a[i+1:] for a in _list2]
        x = [i for i, j in zip()]
    if not listolist:
        return None
    else:
        return listolist[-1]
