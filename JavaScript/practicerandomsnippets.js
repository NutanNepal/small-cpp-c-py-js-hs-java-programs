numbers = [1,2,3,6,5,7,8,3,9,0,2];
checkRange=(a,x,y,t=0)=>a.map(z=>z<x|z>y||++t)|t;
console.log(checkRange(numbers, 2, 8));
//multiply by 2 and add all of them
getresult=(a,t=0)=>a.map(z=>t+=2*z)|t;
console.log(getresult(numbers));
x = true
x += 2<3|3>5
console.log(x)
myownrange=(a,x,y,t=0)=>a.map(z=>t+=z<x^z<=y)|t;
console.log(myownrange(numbers, 2, 8));

//modulus4;
/*
checkRange=(a,x,y)=>a.filter(z=>x<=z&z<=y).length
checkRange=(a,x,y)=>a.filter(z=>!(x>z|z>y)).length
checkRange=(a,x,y)=>a.reduce((z,c)=>x<=z&z<=y?c+1:c,0)
*/
//2<3? console.log('yay'):;