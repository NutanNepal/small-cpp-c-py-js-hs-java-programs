// Your new function as given to you by me, your boss.
var cutLog = function(p, n) {
    // Some array to store calculated values
    price = [0];
    for (j = 1; j <= n; j++) {
        q = -1;
        for (i = 1; i <= j; i++) { // Two nested loops = Θ(n^2)
            // Magic
            q = Math.max(q, p[i]+price[j-i]);
        }
        price.push(q);
    }
    solution = price[n];
    return solution; // Good luck intern!
}

console.log(cutLog([0,1,2], 2))