def collatz_steps(n, steps):
    key = ''
    for vals in steps:
        if vals == 'U':
            key += '1'
        else:
            key+= '0'
    d = 1
    while temp != key:
        temp = ''
        a = d
        index = 0
        while a >=1:
            if a%2  == 1:
                a = int((3 * a + 1) / 2)
            else:
                a = int(a/ 2)
            temp += str(a%2)
            if (temp[0:index] != key[0:index]) | (len(temp) >= len(key)):
                break
            if (temp == key):
                break
        d+=1
    ans = d-1
    print(n,ans)
    if n <= ans:
        return ans
    f= int(2**(len(key)))
    if len(str(n)) > len(key):
        b = n - 10**(len(str(n)) - 1)
        print(b)
        if b <= ans:
            return ans + 10**(len(str(n)) - 1)
        else:
            e= int((b-ans)/f)
            return 10**((len(str(n)))-1) + ans + ((e+1)*f)
    else:
        
        e= int((n-ans)/f)
        return ans+((e+1)*f)