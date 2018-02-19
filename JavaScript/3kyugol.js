function getGeneration(cells, generations){
        next_generation = cells.slice();                                                                //not trying to modify the input
        new_next_generation = [];                                                                       //new matrix for the new generation
        for (i = 0; i < generations; i++){
            if (checkBoundaries(next_generation)){ next_generation = addBoundaries(next_generation); }       //if boundary is alive, add dead boundaries
            
            //console.log(next_generation);
            //index = 0;
            
            for (row_index = 0; row_index < next_generation.length; row_index ++){                          //looping over the rows
                next_generationrow = [];                                                                    //creating new row to add to the new generation matrix
                for (column_index = 0; column_index < next_generation[0].length; column_index ++){          //looping over the columns
                    currentcell = 0;                                                                        //new cell value
                    neighbours = countmoore(next_generation, row_index, column_index);                      //counting the moore neighbourhoods
                    
                    if (neighbours < 2 || neighbours > 3){ ; }                                              //if neighbours<2 or >3, stay dead
                    else if (neighbours == 2){ currentcell = next_generation[row_index][column_index]; }    //if ==2, stay the way it is
                    else { currentcell = 1; }                                                               //else, get a life
    
                    //console.log("neighbours at " + (++index) + " = " + neighbours + " so currentcell = " + currentcell);
    
                    next_generationrow.push(currentcell);                                                   //add currentcell to the row
                    }
                new_next_generation.push(next_generationrow);                                               //add the row to the matrix
            }
            next_generation = new_next_generation;                                   //change the current matrix so you can loop over the new generation
        }
    
        /* ******** ********** STARTING TO CROP ********** ******** */
    
        while (true){
            if (!(next_generation[0].includes(1))){ next_generation.shift(); }                              //if first row is all dead, remove it
            if (!(next_generation[next_generation.length - 1].includes(1))){ next_generation.pop(); }       //if last row is all dead, remove it
            else{
                if (next_generation[0].includes(1)){ break; }                           //if both first and last have alive cells, break the loop
            }
        }
        while (true){
            flag = false;
            for (i = 0; i < next_generation.length; i++){
                if (next_generation[i][0]){ flag = true; }                              //check if the first elements of each row is dead
            }
            if (!flag){
                for (i = 0; i < next_generation.length; i ++){
                    next_generation[i].shift();                                         //remove the first elements if all of them are zero
                }
            }
            else{ break; }                                                              //loop until the first elements contain 1
        }
        while (true){
            flag = false;
            for (i = 0; i < next_generation.length; i++){
                if (next_generation[i][next_generation[0].length - 1]){ flag = true; }  //check if the last elements of each row is dead
            }
            if (!flag){
                for (i = 0; i < next_generation.length; i ++){
                    next_generation[i].pop();                                           //remove the last elements if all of them are dead
                }
            }
            else{ break; }                                                              //loop until the last elements contain 1
        }
        /* ******** ********** DONE CROPPING ********** ******** */
    
        return next_generation;                                                         //return the cropped matrix
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
                        if (cells[x + z[i]][y + z[j]] && !(z[i] == 0 && z[j] == 0)){ count ++ ; }
                    }
                }
                catch(RangeError){ ; }
            }
        }
        return count;
    }

console.log(getGeneration([ [1,0,0],         //expected [[0,1,0],[0,0,1],[1,1,1]]
                            [0,1,1],
                            [1,1,0]], 1));

console.log(getGeneration([ [ 0, 1, 0, 0, 0 ], [ 0, 0, 1, 1, 0 ], [ 0, 1, 1, 0, 0 ] ], 2));