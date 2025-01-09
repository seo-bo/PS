import java.io.*;
import java.util.*;

public class Main
{
    static int ary[] = new int[1500];
    static long dp[][] = new long[16][1500]; // 갯수, 목표 수
    static Vector<Integer>primes = new Vector<>();
    static BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder result = new StringBuilder();

    public static void prime(int num)
    {
        ary[0] = 1;
        ary[1] = 1;
        for (int i =2; i*i <= num; ++i)
        {
            if(ary[i] == 0)
            {
                for (int j = i*i; j<=num;j+=i)
                {
                    ary[j] = 1;
                }
            }
        }
        for (int i =2; i<=num;++i)
        {
            if(ary[i] == 0)
            {
                primes.add(i);
            }
        }
        dp[0][0] = 1;
        int size = primes.size();
        for (int i =0; i<size;++i) // 벡터에 들어있는 소수 순회
        {
            for (int j = 1121; j >=primes.get(i); --j) // 역으로 채워나가기 (정방향 채우면 나는 안되더라)
            {
                for (int z = 1; z<=14 ;++z) // z는 몇개 소수를 썼냐고, 0개를 쓰면 당연히 불가하니 1 ~ 14의 범위
                {
                    dp[z][j] += dp[z-1][j-primes.get(i)];
                }
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        prime(1120); // 1120은 내 생일인디..
        int test = 0;
        test = Integer.parseInt(scan.readLine());
        while(test-->0)
        {
            int MAX =0, Pcs = 0;
            StringTokenizer get = new StringTokenizer(scan.readLine());
            MAX = Integer.parseInt(get.nextToken());
            Pcs = Integer.parseInt(get.nextToken());
            result.append(dp[Pcs][MAX] + "\n");
        }
        scan.close();
        System.out.print(result);
    }
}