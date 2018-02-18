function hamming(n){
    console.log("returning for " + n);
    if (n == 1 ){ return 1;}
    var x = y = z = 0;
    hammers = [1];
    index = 0;
    x2 = hammers[index] * 2;
    x3 = hammers[index] * 3;
    x5 = hammers[index] * 5;
    while (index < n){
        hammers[++index] = Math.min(x2, x3, x5);
        if (x2 == hammers[index]){ x2 = 2* hammers[++x];}
        if (x3 == hammers[index]){ x3 = 3* hammers[++y];}
        if (x5 == hammers[index]){ x5 = 5* hammers[++z];}
    }
    return hammers[n - 1]
}
for (i=1; i<5001; i++){
console.log(hamming(i));
}