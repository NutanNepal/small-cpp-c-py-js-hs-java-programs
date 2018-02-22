function bernoulli(depth){
    pascal = pascalsTriangle(depth);
    
}

function pascalsTriangle(depth){
    start = [1];
    using = [1];
    for (i = 1; i <= depth; i++){
        for_i = [1];
        for (j = 0; j < i - 1; j++){
            for_i.push(using[j] + using[j+1]);
        }
        start.push(for_i);
        using = for_i.slice();
        using.push(1);
    }
    return start;
}

console.log(bernoulli(5));
console.log(pascalsTriangle(5));