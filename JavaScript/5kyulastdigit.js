function modulo(divident, divisor) {
    var partLength = 10;
    while (divident.length > partLength) {
        var part = divident.substring(0, partLength);
        divident = (part % divisor) +  divident.substring(partLength);
    }
    return divident % divisor;
}

var lastDigit = function(str1, str2){
    if (!Number(str2)){
        return 1;
    }
    var lastofstr1 = Number(str1.slice(-1));
    switch (lastofstr1){
        case 0:
        case 1:
        case 5:
        case 6: return lastofstr1;
        break;
        case 2: return ([6,2,4,8])[modulo(str2, 4)];
        break;
        case 3: return ([1,3,9,7])[modulo(str2, 4)];
        break;
        case 4: return ([6,4])[modulo(str2, 2)];
        break;
        case 7: return ([1,7,9,3])[modulo(str2, 4)];
        break;
        case 8: return ([6,8,4,2])[modulo(str2, 4)];
        break;
        case 9: return ([1,9)[modulo(str2, 2)];
        break;
    }
  }
  console.log(lastDigit("95703607011311258589650632633836380049074852167197452062414091006547213360971833025375933422", "44553912182509015694104479959210132"));
