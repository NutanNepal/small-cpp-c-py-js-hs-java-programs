//incomplete

function lastDigit(listofnumbers){
    if (listofnumbers.length == 0){
        return 1;
    }
    lastofstr1 = Number(String(listofnumbers[0]).slice(-1));
    if (listofnumbers.length == 1){
        return lastofstr1;
    }
  var last = {
    2 : [6,2,4,8],
    4 : [6, 4],
    3 : [1,3,9,7],
    7 : [1,7,9,3],
    8 : [6,8,4,2],
    9 : [1, 9]
  };

check_with = checkzeroes(listofnumbers[-2], listofnumbers[-1]);
for (i = 1; i < listofnumbers.length; i++){
    x, y = listofnumbers[-2-i], listofnumbers[-1-i];
    
    if (check_with == -1){
        currentmodulus = 1;
    }
    else if (check_with == 0){
        currentmodulus = 0;
    }
    else{
        if (!(x % 2) && y > 1){
            currentmodulus = 0;
        }
        else if (!(x % n)){
            currentmodulus = 0;
        }
        else{
            currentmodulus = Math.pow(x, currentmodulus) % n;
        }
    }
    check_with = checkzeroes(listofnumbers[-1-i], check_with);
    }
}


function checkzeroes(x, y){
    if (!x && !y){ return -1;}
    if (!x){ return 0;}
    return 1;
}