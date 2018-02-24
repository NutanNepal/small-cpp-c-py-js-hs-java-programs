//DOESN'T WORK!!!!

function getfibonacci(n){
    fibonacci = [0, 1, 1, 2, 3];
    if (n >= 0 && n <= 4){ return fibonacci[n]; }
    if (n % 2){
        returnval = Math.pow(getfibonacci(Math.trunc(n/2)), 2) + Math.pow(getfibonacci(Math.trunc(n/2) + 1), 2);
    }else{
        get = getfibonacci(n/2);
        returnval = Math.pow(get, 2) + 2 * get * getfibonacci(n/2 - 1);
    }
    return String(returnval);
}

console.log(getfibonacci(5000000));