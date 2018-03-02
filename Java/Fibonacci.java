import java.math.BigInteger;

class Fibonacci{
    public static void main(String [] args){
        System.out.print(fib(BigInteger.valueOf(300)));
    }
    public static BigInteger fib(BigInteger n) {
        long absoluteValue = n.abs().longValue();
        BigInteger returnval;
        if (absoluteValue == 0 || absoluteValue == 1){
            returnval = BigInteger.valueOf(absoluteValue);
        }
        else{
            if (absoluteValue % 2 == 1){
                returnval = (fib(BigInteger.valueOf(absoluteValue/2)).pow(2)).add((fib(BigInteger.valueOf(absoluteValue/2 + 1)).pow(2)));
            }
            else{
                BigInteger get = fib(BigInteger.valueOf(absoluteValue/2));
                returnval = (get.pow(2)).add(get.multiply(fib(BigInteger.valueOf(absoluteValue/2 - 1))).multiply(BigInteger.valueOf(2)));
            }
        }
        if (n.signum() != 1 && absoluteValue % 2 == 0){
            return returnval.multiply(BigInteger.valueOf(-1));
        }
        return returnval;
    }
};