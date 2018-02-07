/*
function rotateclock90(matrix){
    var column = matrix.length;
    var row = (matrix[0]).length;

    var rotated =[];
    for (var i = 0; i < row; i++){
        nextrow = []
        for (var j = column - 1; j >= 0 ; j--){
            nextrow.push(matrix[j][i]);
        }
        rotated.push(nextrow);
    }
    return rotated;
}
*/

function rotateanticlock90(matrix){
    var column = matrix.length;
    if (column == 1){
        return [matrix[0].reverse()];
    }
    var row = (matrix[0]).length;

    var rotated =[];
    for (var i = row - 1; i >= 0; i--){
        nextrow = []
        for (var j = 0; j < column ; j++){
            nextrow.push(matrix[j][i]);
        }
        rotated.push(nextrow);
    }
    return rotated;
}

function snail(matrix){
    snailed = [];
    do{
        snailed = snailed.concat(matrix[0]);
        matrix.shift();
        console.log(snailed, matrix);
        if (matrix.length > 0){
            matrix = rotateanticlock90(matrix);
        }
    }while (matrix.length > 0);
    return snailed;
}

console.log(snail([[1,2,3],[4,5,6],[7,8,9]]));
//console.log(rotateanticlock90([1,2,3,4,5,6]));