def get_length_of_missing_array(_list):
    if not _list:
        return 0
    for x in _list:
        if not x:
            return 0
    thelist = sorted(_list)
    i = len(thelist[0])
    for x in thelist:
        if not i + thelist.index(x) == len(x):
            return i + thelist.index(x)
    return 0
