def sum_pairs(_list, sum):
    stack = {}
    for item in _list:
        if item in stack:
            return [sum - item, item]
        stack[sum - item] = item
    return None
print(sum_pairs([20, -13, 40], -7))
