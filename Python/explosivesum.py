def getpentagonal(n):
    j, k = 2, 1
    sequence = [[1, 1]]
    while n >= sequence[len(sequence)-1][1]:
        k += (-1)**((j % 2) +1) * j
        sequence.append([k, int((3*k**2-k)/2)])
        j += 1
    return sequence

def exp_sum(n):
    if n< 0: return 0
    partitions = [1, 1, 2]
    nextnum = 3
    pentagonal = getpentagonal(n)
    while nextnum <= n:
        sum_i, i = 0, 0
        while nextnum - pentagonal[i][1] > -1:
            sum_i += ((-1)**(abs(pentagonal[i][0])-1) * partitions[nextnum - pentagonal[i][1]])
            i += 1
        partitions.append(sum_i)
        nextnum += 1
    return partitions[n]

print(exp_sum(1000))