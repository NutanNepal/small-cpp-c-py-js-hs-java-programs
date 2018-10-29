function findDigit(n){
    var regular = '1';
    var square = '1'
    for (var i = 2; i < n+3; i++){
        regular += i;
        square += i*i;
    }
    square = square.substr(0, regular.length);
    var addition = Number(regular) + Number(square);
    console.log(regular);
    console.log(square);
    console.log(addition);
    return Number(addition.toString()[n])
  }
  console.log(findDigit(15));