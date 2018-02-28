"""def validBraces(string):
    y = ['(', ')', '{', '}', '[',']']
    only_braces = ''.join([x for x in string if x in y])
    while True:
        if only_braces.find('()') == -1 and only_braces.find('[]') == -1 and only_braces.find('{}') == -1:
            break
        only_braces = only_braces.replace('()', '')
        only_braces = only_braces.replace('[]', '')
        only_braces = only_braces.replace('{}', '')
    
    return True if not only_braces else False

print(validBraces("[[{({}{}[])}]]"))"""

def validBraces(string):
    y = ['(', ')', '{', '}', '[',']']
    only_braces = ''.join([x for x in string if x in y])
    while True:
        if '()' not in only_braces and '[]' not in only_braces and '{}' not in only_braces:
            break
        only_braces = only_braces.replace('()', '').replace('[]', '').replace('{}', '')
    
    return not only_braces

print(validBraces("[[{({}{}[])}]]"))