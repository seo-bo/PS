import java.io.*;
import java.util.*;

public class Main
{
    static void init(int start, int end, int node)
    {
        if (start == end)
        {
            mul_tree[node] = ary[start];
            return;
        }
        int mid = (start + end)/2;
        init(start, mid, node*2);
        init(mid+1, end, node*2+1);
        mul_tree[node] = mul_tree[node*2] * mul_tree[node*2+1];
    }
    static void update(int start, int end, int node, int idx, int value)
    {
        if (idx > end || idx < start)
        {
            return;
        }
        if (idx <= start && end <= idx)
        {
            mul_tree[node] = value;
            return;
        }
        int mid = (start +end)/ 2;
        update(start, mid, node*2, idx, value);
        update(mid+1, end, node*2+1, idx, value);
        mul_tree[node] = mul_tree[node*2] * mul_tree[node*2+1];
    }

    static long mul_query(int start, int end, int node, int left, int right)
    {
        if(left>end || right < start)
        {
            return 1;
        }
        if (left <= start && end <= right)
        {
            return mul_tree[node];
        }
        int mid = (start+end) / 2;
        return mul_query(start, mid, node*2, left, right) * mul_query(mid+1,end,node*2+1,left,right);
    }
    static int[] ary = new int[100010];
    static int[] mul_tree = new int[100010 * 4];
    static BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException
    {
        while(true)
        {
            String input = "";
            ary = new int[100010];
            mul_tree = new int[100010 * 4];
            StringBuilder result = new StringBuilder();
            input = scan.readLine();
            if (input == null)
            {
                break;
            }
            StringTokenizer get = new StringTokenizer(input);
            int num = Integer.parseInt(get.nextToken());
            int test = Integer.parseInt(get.nextToken());
            get = new StringTokenizer(scan.readLine());
            for (int i = 1; i <= num; ++i)
            {
                int temp = Integer.parseInt(get.nextToken());
                if (temp >0)
                {
                    ary[i] = 1;
                }
                else if (temp <0)
                {
                    ary[i] = -1;
                }
                else
                {
                    ary[i] = 0;
                }
            }
            init(1,num,1);
            while(test-->0)
            {
                get = new StringTokenizer(scan.readLine());
                String str = get.nextToken();
                int start = Integer.parseInt(get.nextToken());
                int end = Integer.parseInt(get.nextToken());
                switch(str)
                {
                    case "C":
                    {
                        if (end >0)
                        {
                            end = 1;
                        }
                        if (end <0)
                        {
                            end = -1;
                        }
                        update(1,num,1,start,end);
                        break;
                    }
                    case "P":
                    {
                        long temp = mul_query(1,num,1,start, end);
                        if (temp > 0)
                        {
                            result.append("+");
                        }
                        else if (temp < 0)
                        {
                            result.append("-");
                        }
                        else
                        {
                            result.append("0");
                        }
                        break;
                    }
                }
            }
            System.out.println(result);
        }
    }
}