def solution(digits):
    a = len(str(digits)) - 4
    stnum = str(digits)
    list1 = []
    for i in range(0, a):
        temp = ''
        for j in range(0, 5):
            temp += stnum[i+j]
        list1.append(temp)
    print(list1)
    max = int(list1[0])
    for i in range (1, len(list1)):
        if max < int(list1[i]):
            max = int(list1[i])
    return max
