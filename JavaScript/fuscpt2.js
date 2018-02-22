function fusc(n){
    the_list = new Array(n+2).fill(0);
    the_list[1] = 1;
    for (i = 1; i <= n/2; i++){
        the_list[2*i] = the_list[i];
        the_list[2*i + 1] = the_list[i] + the_list[i+1];
    }
    return the_list[n+1];
}

console.log(fusc(100));