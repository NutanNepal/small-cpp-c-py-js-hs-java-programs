function validBraces(string_){
    braces = {
        '(':')',
        '{':'}',
        '[':']'
    };
    stack = []
    for (i = 0; i < string_.length; i++){
        if (string_[i] in braces){
            stack.push(string_[i]);
        }
        else{
            if (stack.length == 0 || braces[stack.pop()] != string_[i]){
                return false
            }
        }
    }
    if (stack.length == 0){
        return true
    }
    return false
}
