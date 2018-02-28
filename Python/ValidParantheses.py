def valid_parentheses(string):
    only_parentheses = ''.join([x for x in string if x== '(' or x== ')'])
    while True:
        if only_parentheses.find('()') == -1:
            break
        only_parentheses = only_parentheses.replace('()', '')
    
    return True if not only_parentheses else False
print(valid_parentheses("hi(hi)()"))