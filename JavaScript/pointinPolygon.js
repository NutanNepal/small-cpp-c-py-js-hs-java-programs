function pointInPoly(poly, point) {
    poly.sort(function(a,b){ return a[0]-b[0];});
    console.log(poly);

    
    return false;
  }

console.log(pointInPoly([[1,1],[2,-1],[4,2],[3,-2],[3,-3]], false))