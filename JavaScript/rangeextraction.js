function solution(list){
    sol = []
    i = 0
    while (i < list.length - 1){
        nextrange = [list[i]];
        while (true){
            if (list[i] + 1 == list[i + 1]){
                nextrange[1] = list[i + 1];
            }else{
                i++;
                break;
            }
            i++;
        }
        if (nextrange[1] - nextrange[0] == 1 ){
            sol.push(nextrange.join());
        }
        else{
            sol.push(nextrange.join('-'));
        }
    }
    return sol.toString();
}

console.log(solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]));