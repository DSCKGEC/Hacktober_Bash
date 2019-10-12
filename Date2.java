import java.util.*;
//_  _ _ _  _ _ _  _ _ _
//0  1 2 3  4 5 6  7 8 9
public class Date2
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner (System.in);
        String s = sc.nextLine();
        System.out.print("Output : ");
        if (s.equals("0"))
        {
            System.out.println("Zero");
            return;
        }
        int len = s.length();
        String digits[] = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fiveteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        String tens[] = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        while (len != 10)
        {
            len++;
            s = "0" + s;
        }
        String temp = "";
        String ans = "";
        if (s.charAt(0) != '0')
            System.out.print(digits[Integer.parseInt(s.substring(0,1)) - 1] + " Billion ");
        for (int i = 1; i < len;i+=3)
        {
            temp = s.substring(i,i+3);
            String store = "";
            if(temp.charAt(0)!='0')
                store = digits[Integer.parseInt(temp.substring(0,1)) - 1]  + " Hundred";
            if (temp.charAt(1)!='0' && temp.charAt(1) < '2' && temp.charAt(0) != 0)
                store = store + " " + digits[Integer.parseInt(temp.substring(2,3)) + 9];
            if (temp.charAt(1) >= '2')
            {
                store = store + " " + tens[Integer.parseInt(temp.substring(1,2)) - 2];    
                if (temp.charAt(2) != '0')
                    store = store + " " + digits[Integer.parseInt(temp.substring(2,3)) - 1];
            }
            if (temp.charAt(1) == '0' && temp.charAt(2) != '0')
            {
                store = store + " " + digits[Integer.parseInt(temp.substring(2,3)) - 1];
            }
            if (i < 4 && store != "")
                System.out.print(store + " Million ");
            else if (i < 7 && store != "")
                System.out.print(store + " Thousand ");
            else
                System.out.print(store);
        }
    }
}

