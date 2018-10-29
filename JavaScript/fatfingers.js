function fatfingers(str){
    flag = false;
    newstr = '';
    for (var i = 0; i < str.length; i++){
        if (toLowerCase(str[i]) == 'a'){
            flag = !flag;
        }
        else{
            if(flag){
                newstr += toUpperCase(str[i]);
            }
            else{
                newstr += str[i];
            }
        }
    }
    return newstr;
}