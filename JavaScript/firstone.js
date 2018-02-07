console.log(getLengthOfMissingArray([[1, 2], [6, 5, 1, 1], [1], [5, 6, 7, 8, 9]]));
//console.log(getLengthOfMissingArray(null))
console.log(getLengthOfMissingArray([[ 'a', 'a', 'a' ], [ 'a', 'a' ], [ 'a', 'a', 'a', 'a' ], [ 'a' ], [ 'a', 'a', 'a', 'a', 'a', 'a' ]]));
function getLengthOfMissingArray( _array){
    if (_array === null){
        return 0;
    }
    if (_array.length === 0){
        return 0;
    }
    for (var j=0; j<_array.length; j++){
        if (_array[j]=== null){
            return 0;
        }
        if ((_array[j]).length === 0){
            return 0;
        }
    }
    var thelist = _array.sort(function(a, b){return a.length - b.length});
    //var thelist = _array.sort();
    i = (thelist[0]).length;
    for (var j=0; j<thelist.length; j++){
        if (i+thelist.indexOf(thelist[j]) !== (thelist[j]).length){
            return i + thelist.indexOf(thelist[j]);
        }
    }
}