function getGeneration(cells, generations){
    input_matrix = cells.slice();
    next_generation = [];
    for (i = 0; i < generations; i++){
        if (checkBoundaries(input_matrix)){ input_matrix = addBoundaries(input_matrix); }       //if boundary is alive, add dead boundaries
        
        console.log(input_matrix);
        index = 0;
        
        for (row_index = 0; row_index < input_matrix.length; row_index ++){
            next_generationrow = [];
            for (column_index = 0; column_index < input_matrix[0].length; column_index ++){
                currentcell = 0;
                neighbours = countmoore(input_matrix, row_index, column_index);
                
                if (neighbours < 2 || neighbours > 3){ ; }
                else if (neighbours == 2){ currentcell = input_matrix[row_index][column_index]; }
                else { currentcell = 1; }

                console.log("neighbours at " + (++index) + " = " + neighbours + " so currentcell = " + currentcell);

                next_generationrow.push(currentcell);

                }
            next_generation.push(next_generationrow);
        }
    }
    while (true){
        if (!(next_generation[0].includes(1))){ next_generation.shift(); }
        if (!(next_generation[next_generation.length - 1].includes(1))){ next_generation.pop(); }
        else{
            if (next_generation[0].includes(1)){ break; }
        }
    }
    while (true){
        flag = false;
        for (i = 0; i < next_generation.length; i++){
            if (next_generation[i][0]){ flag = true; }
        }
        if (!flag){
            for (i = 0; i < next_generation.length; i ++){
                next_generation[i].shift();
            }
        }
        else{ break; }
    }
    while (true){
        flag = false;
        for (i = 0; i < next_generation.length; i++){
            if (next_generation[i][next_generation[0].length - 1]){ flag = true; }
        }
        if (!flag){
            for (i = 0; i < next_generation.length; i ++){
                next_generation[i].pop();
            }
        }
        else{ break; }
    }
    return next_generation;
}

function checkBoundaries(cells){

    if (cells[0].includes(1) || cells[cells.length - 1].includes(1)){ return true; }      //check alive cells at top and bottom
    for (i = 1; i < cells.length - 1; i++){
        if(cells[i][0] == 1 || cells[i][cells.length - 1] == 1){ return true; }           //check alive cells at the sides
    }
    return false;                                                           //return false if boundary is dead
}

function addBoundaries(cells){
    //add 0 to the boundaries
    for (i = 0; i < cells.length; i++){
        cells[i].unshift(0);                            //0s at the beginning of each row
        cells[i].push(0);                               //0s at the end of each row
    }
    top_bottom = new Array(cells[0].length).fill(0);    //0s filled row of length equal to the cells
    cells.unshift(top_bottom);                          //0s at the top
    cells.push(top_bottom);                             //0s at the bottom

    return cells;
}

function countmoore(cells, x, y){
    /* count moore neighborhoods */
    count = 0;
    z = [-1, 0, 1];
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            try{
                if (!(x + z[i] < 0 || y + z[j] < 0)){
                    if (cells[x + z[i]][y + z[j]] && !(i == 0 && j == 0)){
                        count ++ ;
                    }
                }
            }
            catch(RangeError){
                ;
            }
        }
    }
    return count;
}

console.log(getGeneration([[1,0,0],         //expected [[0,1,0],[0,0,1],[1,1,1]]
    [0,1,1],
    [1,1,0]], 1));