def last_digit(n1, n2):
    if not n2: return 1
    givenlast = n1 % 10
    if givenlast == 0 or givenlast == 1 or givenlast == 5 or givenlast == 6: 
        return givenlast
    if givenlast == 2:
        return [6,2,4,8][n2 % 4]
    if givenlast == 3:
        return [1,3,9,7][n2 % 4]
    if givenlast ==4:
        return [6,4][n2 % 2]
    if givenlast == 7:
        return [1,7,9,3][n2 % 4]
    if givenlast == 8:
        return ([6,8,4,2])[n2 % 4]
    if givenlast == 9:
        return [1,9][n2 % 2]

print(last_digit(20567, 30415671))

import sys
try:
        import setuptools
except ImportError:
    print("sad")
    sys.exit(1)
else:
    print("good")
    sys.exit(0)