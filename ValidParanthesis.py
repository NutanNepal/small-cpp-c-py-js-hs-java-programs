def valid_parentheses(string):
    y = ['(', ')', '{', '}', '[',']']
    only_parentheses = ''.join([x for x in string if x in y])
    print(only_parentheses)
    while True:
        try:
            if only_parentheses.index('()') == -1 or only_parentheses.index('[]') == -1 or only_parentheses.index('{}') == -1:
                break
            print (only_parentheses.index('()'))
            only_parentheses = only_parentheses.replace('()', '')
            only_parentheses = only_parentheses.replace('[]', '')
            only_parentheses = only_parentheses.replace('{}', '')
        except:
            break
        if not only_parentheses:
            return True
    
    return True if not only_parentheses else False
print(valid_parentheses("()"))