def validBraces(string):
    y = ['(', ')', '{', '}', '[',']']
    only_parentheses = ''.join([x for x in string if x in y])
    print(only_parentheses)
    while True:
        if only_parentheses.find('()') == -1 and only_parentheses.find('[]') == -1 and only_parentheses.find('{}') == -1:
            break
        only_parentheses = only_parentheses.replace('()', '')
        only_parentheses = only_parentheses.replace('[]', '')
        only_parentheses = only_parentheses.replace('{}', '')
    
    return True if not only_parentheses else False