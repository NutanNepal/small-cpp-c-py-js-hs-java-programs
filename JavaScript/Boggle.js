function checkWord (inputboard, word){
    var board = JSON.parse(JSON.stringify(inputboard));                 //deep copy the board since it'll be changed when running
    var returnval = false;
    indexoffirstchar = [];
    for (var i = 0; i < board.length; i++){
        for (var j = 0; j < board[0].length; j++){
            if (word[0]==board[i][j]){
                indexoffirstchar.push([i, j]);
            }
        }
    }
    if (indexoffirstchar.length == 0){                              //return false if the first letter doesn't exist
        return false;
    }
    //if length is one, return true because it exists in the matrix
    if (word.length == 1){ return true; }
    for (var i = 0; i < indexoffirstchar.length; i++){
            var _board2 = JSON.parse(JSON.stringify(inputboard));
            _board2[indexoffirstchar[i][0]][indexoffirstchar[i][1]] = 0;
            returnval = torecurse(_board2, word.slice(1), indexoffirstchar[i]);
            if (returnval){ break; }
        }
    return returnval;
}
function torecurse(inputboard, word, position){
    var currentcharlist = getMoore(inputboard, position[0], position[1], word[0]);
    if (currentcharlist.length == 0){
        return false; }
    if (word.length == 1){ return true; }
    var returnval = false;
    var word = word.slice(1);
    for (var i = 0; i < currentcharlist.length; i++){
        var board = JSON.parse(JSON.stringify(inputboard));
        board[position[0]][position[1]] = 0;
        returnval = torecurse(board, word, currentcharlist[i]);
        if (returnval == true){ break; }
    }
    return returnval;
}

function getMoore(theboard, x, y, nextchar){
    nextcharlist = [];
    for (var i = -1; i <=1 ; i++){
        for (var j = -1; j <= 1; j++){
            try{
                if (!(x + i < 0 || y + j < 0)){
                    if (theboard[x + i][y + j] == nextchar && !(i == 0 && j == 0)){
                        nextcharlist.push([x+i, y+j]); }
                }
            }
            catch(RangeError){ ; }
        }
    }
    return nextcharlist.slice();
}

theboard = [
    ["E","A","R","A"],
    ["N","L","E","C"],
    ["I","A","I","S"],
    ["B","Y","O","R"]
  ];

//console.log(getMoore(theboard, 1, 3, 'I'));
console.log(checkWord(theboard, 'BAILER'));
console.log(checkWord(theboard, 'EARS'));
console.log(checkWord(theboard, 'RSCAREIOYBAILNEA'));
//console.log(theboard);
