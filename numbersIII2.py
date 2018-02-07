def orderpair(i, _list):
    output= []
    for x in _list:
        y = str(i)+(''.join(x))
        output.append(y)
    return output
def find_allofthem(sum, digits):
    output = []
    if digits == 1:
        output.append(str(sum))
        return output
    if digits * 9 < sum:
        return output
    i = 1
    while sum - i > 0:
        if i > 9:
            break
        j = sum - i
        if j <= (digits-1)* 9:
            x = orderpair(i, find_allofthem(j, digits - 1))
            for y in x:
                t = ''.join(sorted(y))
                if not len(t) == digits:
                    pass
                else:
                    if t not in output:
                        output.append(t)
        i+=1
    return output

def find_all(sum, digits):
    mainlist = find_allofthem(sum, digits)
    print(mainlist)
    if mainlist:
        minval = int(mainlist[0])
        maxval = int(mainlist[-1])
    else:
        return []
    return [len(mainlist) , minval, maxval]

print(find_all(30, 7))
