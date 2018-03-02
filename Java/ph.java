import java.util.Arrays;

class Shell{
    public static void main(String [] args){
        System.out.println("Hi!!");
        System.out.print(middlepermutation("What is this!!"));
    }
    public static String middlepermutation(String input){
        char inputstrArray[] = input.toCharArray();
        Arrays.sort(inputstrArray);
        String inputString = new String(inputstrArray);

        int length = input.length();

        if(length % 2 == 1){

        }
        return inputString;
    }
}