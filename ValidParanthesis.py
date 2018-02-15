def valid_parentheses(string):
    only_parentheses = ''.join([x for x in string if x== '(' or x== ')'])
    while True:
        try:
            if only_parentheses.index('()') == -1:
                break
            only_parentheses = only_parentheses.replace('()', '')
        except:
            break
        if not only_parentheses:
            return True
    
    return True if not only_parentheses else False
print(valid_parentheses("()"))