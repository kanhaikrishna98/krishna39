public class printrev {
    public static void revstr(String str, int index){
        if (index==0){
            System.out.println(str.charAt(index));
            return;
        }
        System.out.print(str.charAt(index));
            revstr(str,index-1);
        }
    
    public static void main(String[] args) {
        String name = "abcd";
        revstr(name,name.length()-1);
    }
}
