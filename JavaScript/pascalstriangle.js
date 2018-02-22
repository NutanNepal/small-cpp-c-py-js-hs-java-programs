function pascalsTriangle(depth){
    start = [1];
    using = [1];
    for (i = 1; i < depth; i++){
        for_i = [1];
        for (j = 0; j < i - 1; j++){
            for_i.push(using[j] + using[j+1]);
        }
        for_i.push(1);
        start = start.concat(for_i);
        using = for_i;
    }
    return start;
}

console.log(pascalsTriangle(5));