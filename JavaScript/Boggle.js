function checkWord (inputboard, word, position){
    if (typeof position == 'undefined'){
        var currentcharlist = forfirstletter(inputboard, word[0]);}
    else {var currentcharlist = getMoore(inputboard, position[0], position[1], word[0]);}
    if (currentcharlist.length == 0){ return false; }
    if (word.length == 1){ return true; }
    var returnval = false;
    var word = word.slice(1);
    for (var i = 0; i < currentcharlist.length; i++){
        var board = JSON.parse(JSON.stringify(inputboard));
        if (typeof position != 'undefined'){ board[position[0]][position[1]] = 0; }
        returnval = checkWord(board, word, currentcharlist[i]);
        if (returnval){ break; }
    }
    return returnval;
}
function forfirstletter(inputboard, letter){
    var indexoffirstchar = [];
    for (var i = 0; i < board.length; i++){
        for (var j = 0; j < board[0].length; j++){
            if (letter==board[i][j]){
                indexoffirstchar.push([i, j]);
            }
        }
    }
    return indexoffirstchar;
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
    return nextcharlist;
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
