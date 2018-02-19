function dblLinear(n){
    x = y = index = 0;
    sequence = [1];
    x2 = 2 * sequence[0] + 1;
    x3 = 3 * sequence[0] + 1;
    while (index < n){
        sequence[++index] = Math.min(x2, x3);
        if (sequence[index] == x2){ x2 = 2 * sequence[++x] + 1; }
        if (sequence[index] == x3){ x3 = 3 * sequence[++y] + 1; }
    }
    return sequence[n];
}
console.log(dblLinear(20));