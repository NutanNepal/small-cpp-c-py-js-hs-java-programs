"""def middle_permutation(string):
    import itertools
    permutations_ = list(itertools.permutations(string))
    permutations_.sort()
    return ''.join(permutations_[len(permutations_)//2 - 1])
"""

def middle_permutation(string):
    string_list = sorted(list(string))
    length = len(string_list)

    if length % 2:
        first = string_list[length//2] + string_list[length//2 - 1]
        del string_list[length//2 -1 : length//2 +1]
    else:
        first = string_list[length//2 - 1]
        del string_list[length//2 - 1]

    string_list.sort(reverse = True)
    last = ''.join(string_list)
    return first + last


print(middle_permutation("1234567"))

