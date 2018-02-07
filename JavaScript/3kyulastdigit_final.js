function lastDigit(listofnumbers){
    if (listofnumbers.length == 0){
        return 1;
    }
    if (listofnumbers.length == 1){
        return Number(String(listofnumbers[0]).slice(-1));
    }
  lastofstr1 = Number(String(listofnumbers[0]).slice(-1));
  if (lastofstr1 && !(listofnumbers[1])){ return 1; }
  var last = {
    2 : [6,2,4,8],
    4 : [6, 4],
    3 : [1,3,9,7],
    7 : [1,7,9,3],
    8 : [6,8,4,2],
    9 : [1, 9]
  };
  switch (lastofstr1){
      case 0: if (!listofnumbers[1] && !listofnumbers[0]){ return 1; }
      case 1:
      case 5:
      case 6: return lastofstr1;
      case 4:
      case 9: n = 2;
      break;
      default: n = 4;
  }

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

