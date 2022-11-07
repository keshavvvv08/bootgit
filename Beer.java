import java.util.Scanner;
public class Beer {
    public static void main(String[] args){
        String word = "bottles";
        int beerNum = 99;
        Scanner input = new Scanner(System.in);
        System.out.println(input.next());
        while(beerNum>0){
            if(beerNum==1){
                word="bottle";
            }
            System.out.println(beerNum+" "+word+" of beer on the wall.");
            System.out.println(beerNum+" "+word+" of beer.");
            System.out.println("Take one down.");
            System.out.println("Pass it around.");
            beerNum=beerNum-1;
            
            if (beerNum==0){
                System.out.println("No more bottles of beer on the wall.");
            } 
        }       
    
    }//1:21:00,pg 60
}

//
