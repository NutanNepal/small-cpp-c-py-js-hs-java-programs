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
      case 6:
        return lastofstr1;
      default:
        first = listofnumbers.indexOf(0);
        if (first == -1){
            if(lastofstr1 == 4 || lastofstr1 == 9){
                modulo = getmodulus(listofnumbers[1], listofnumbers.slice(2), 2);
            }
            else{
                modulo = getmodulus(listofnumbers[1], listofnumbers.slice(2), 4);
            }
        }
        else{
            console.log("passing " + listofnumbers[1], listofnumbers.slice(2, first))
            second = listofnumbers.indexOf(0, first + 1);
            if (second - first == 1){
                console.log("pass 1");
                console.log("passing " + listofnumbers[1], listofnumbers.slice(2, first));
                if(lastofstr1 == 4 || lastofstr1 == 9){
                    console.log("1");
                    modulo = getmodulus(listofnumbers[1], listofnumbers.slice(2, first), 2);
                }
                else{
                    console.log("2");
                    modulo = getmodulus(listofnumbers[1], listofnumbers.slice(2, first), 4);
                }
            }
            else{
                if(lastofstr1 == 4 || lastofstr1 == 9){
                    console.log("3");
                    modulo = getmodulus(listofnumbers[1], listofnumbers.slice(2, first - 1), 2);
                }
                else{
                    console.log("4");
                    modulo = getmodulus(listofnumbers[1], listofnumbers.slice(2, first - 1), 4);
                }
            }
        }
        console.log(modulo);
        return last[lastofstr1][modulo];
  }
}

function getmodulus(a, b, n){
console.log(a, b, n);
    if (b.length == 0){return a % n; }
  if (b.length > 1){
      console.log("pass1");
    mod = getmodulus(b[0], b.slice(1));
  }
  else{
    console.log("pass2 "+ b[0]);
    if (b[0] >= n){ mod = b[0] % n; }
    else { mod = b[0]; }
    if (!(a % 2) && b[0] > 1){
        console.log("returning 0?");
      return 0;
    }
  }
  if (a >= n){ a %= n; }
  if (a == 0){ return 0; }
  console.log("returning " + Math.pow(a, mod) % n);
  return (Math.pow(a, mod) % n);
}

console.log(lastDigit([ 2, 1, 2, 1 ]));

