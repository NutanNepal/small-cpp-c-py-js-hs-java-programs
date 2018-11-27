var sumbyfactors = function(arr){
    var final = [];
    var primes_ = [];
    for (var i = 0; i < arr.length; i++){
        primes_ = primes_.concat(getprimes(Math.abs(arr[i])));
    }
    var primes = Array.from(new Set(primes_));
    console.log(primes);
    sum = Array(primes.length).fill(0);
    for (var i = 0; i < primes.length; i++){
        for (var j = 0; j < arr.length; j++){
            if (!(arr[j] % primes[i])){
                sum[i] += arr[j];
            }
        }
    }
    arr_ = sum.map((z, k)=>[primes[k], z]);
    return arr_.sort(function(a,b){ return a[0] - b[0]});
};

var getprimes = function(denom){
    factors = new Set();
    if (!(denom % 2)){
        factors.add(2);
        factors.add(Math.floor(denom/2));
    }
    divisor = 3
    j = denom / 2;
    while (divisor <= j){
        if (!(denom % divisor)){
            j = Math.floor(denom/divisor);
            factors.add(divisor);
            factors.add(j);
        }
        divisor += 2;
    }
    var composite = new Set();
    factors = Array.from(factors)
    for (i = 0; i < factors.length; i++){
        for (j = 0; j < factors.length; j++){
            if (factors[i] < factors[j] && !(factors[j] % factors[i])){
                composite.add(factors[j]);
            }
        }
    }
    primes = factors.filter(x=>Array.from(composite).indexOf(x) < 0);
    return Array.from(primes);
};