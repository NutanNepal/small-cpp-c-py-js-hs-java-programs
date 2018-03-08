
palindrome=(n,c)=>c+c[0].repeat(n-2*c.length)+c.split('').reverse().join('')
//console.log(palindrome(10, 'abc'));
astring= 'abcdef'
sum10=(s,k=0,t=false)=>s.split('').map(z=>t=(z&1)&(s[k+4]==(10-z)), k++)|t;
//console.log(sum10('abc1???9bvd'));
x=[0,0,1,2,3,0,0]
//console.log(x.lastIndexOf(true|0));

removeZeros=a=>a;

circleIntersection=(a,b,r)=>a;


snailCoordinate=n=>[,-n,2,n][n%4]+1>>1;
reverse=(a)=>a.reduce((z,t)=>t+=z)
random=(a,b,c=b)=>c;
var omnibool = true << omnibool;
console.log(omnibool);
console.log(omnibool == true);
console.log(omnibool == false);
//console.log(random(2,3));

//snailCoordinate=n=>[,-n,2,-~n][n%4]/2|0
//var promise = Promise.reject(function(){ return true;});


/*numbers = [1,2,3,6,5,7,8,3,9,0,2];
checkRange=(a,x,y,t=0)=>a.map(z=>z<x|z>y||++t)|t;
console.log(checkRange(numbers, 2, 8));
myownrange=(a,x,y,t=0)=>a.map(z=>t+=z<x^z<=y)|t;
console.log(myownrange(numbers, 2, 8));*/

//modulus4;
/*
checkRange=(a,x,y)=>a.filter(z=>x<=z&z<=y).length
checkRange=(a,x,y)=>a.filter(z=>!(x>z|z>y)).length
checkRange=(a,x,y)=>a.reduce((z,c)=>x<=z&z<=y?c+1:c,0)
*/
//console.log("what");
