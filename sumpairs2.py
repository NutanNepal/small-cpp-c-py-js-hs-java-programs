def sum_pairs(_list, sum):
    dict_ = dict(zip(_list,[sum-x for x in _list]))
    index = len(_list) - 1
    while True:
        try:
            return [_list[index], _list[_list.index(dict_[_list[index]], index + 1)]]
        except ValueError:
            index -= 1
        except IndexError:
            break
    return None

print(sum_pairs([1, 2, 3, 4, 1, 0] , 2))