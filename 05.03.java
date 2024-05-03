
import java.io.*;
import java.sql.SQLOutput;
import java.util.*;

public class Main
{
    static BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder result = new StringBuilder();
    public static void main(String[] args) throws IOException {
        int num = 10;
        Integer Num = 10; // 오토 박싱
        //-----------------------------------------------------------------------------//
        String a = "ABC";
        String b = "ABC";
        a.concat("가나다"); // 실제로 변하지는 않음
        //-----------------------------------------------------------------------------//
        StringBuffer sb = new StringBuffer("This ");
        // System.out.println(sb);
        sb.append("is Good");
        // System.out.println(sb);
        sb.insert(8, "not ");
        // System.out.println(sb);
        sb.replace(0,sb.length(), "o");
        // System.out.println(sb);
        //-----------------------------------------------------------------------------//
        StringTokenizer st = new StringTokenizer("ID=ABC&PASS=가나다&CODE=qwertyu","&");
        while(st.countTokens() != 0)
        {
            StringTokenizer id = new StringTokenizer(st.nextToken(),"=");
            id.nextToken();
            System.out.println(id.nextToken());
        }
    }

}


