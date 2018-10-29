import static java.lang.Character.*;

class FatFingers{
    public static void main(String [] args){
        String str1 = "The end of the institution, maintenance, and administration of government, is to secure the existence of the body politic, to protect it, and to furnish the individuals who compose it with the power of enjoying in safety and tranquillity their natural rights, and the blessings of life: and whenever these great objects are not obtained, the people have a right to alter the government, and to take measures necessary for their safety, prosperity and happiness.";
        System.out.print(fatFingers(str1));
    }
    public static String fatFingers(String str) {
        if(str == null){
            return null;
        }
        boolean flag = false;
        String newstr = "";
        for (int i = 0; i < str.length(); i++){
            if (Character.toUpperCase(str.charAt(i)) == 'A'){
                flag = !flag;
            }
            else{
                if(flag){
                    if(Character.toUpperCase(str.charAt(i)) == str.charAt(i)){
                        newstr += Character.toLowerCase(str.charAt(i));
                    }else{
                        newstr += Character.toUpperCase(str.charAt(i));
                    }
                }
                else{
                    newstr += str.charAt(i);
                }
            }
        }
        return newstr;
    }
};