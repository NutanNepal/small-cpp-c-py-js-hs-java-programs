function isValidIP(string){
    if (string.length != string.trim().length){ return false; }

    function check(substring){
        console.log(substring);
        if (String((Number(substring))) == 'NaN'){ return true; }
        if (Number(substring) > 255 || Number(substring) < 0){ return true; }
        if (substring[0] == 0 && Number(substring) !== 0){ return true; }
        return false;
    }

    for (i=0; i<3; i++){
        dot = string.indexOf('.');
        if (dot == -1){ return false; }
        part = string.slice(0, dot);
        if (check(part)){ return false; }
        string = string.slice(dot + 1)
    }
    if (string.indexOf('.') != -1){ return false; }
    if (check(string)){ return false; }
    return true;
}

console.log(isValidIP("abc.def.ghi.jkl"))