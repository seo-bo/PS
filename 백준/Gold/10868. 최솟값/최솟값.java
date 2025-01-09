import java.io.*;
import java.util.*;

public class Main
{
    static long ary[] = new long[100001];
    static long tree[] = new long[100001*4];
    static BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder result = new StringBuilder();

    public static long init(int start, int end, int node)
    {
        if (start == end)
        {
           return tree[node] = ary[start];
        }
        int mid = (start + end) / 2;
        return tree[node] = Math.min(init(start,mid,node*2),init(mid+1,end,node*2+1));
    }

    public static long query(int start, int end, int node, int left, int right)
    {
        if(left > end || right < start)
        {
            return Integer.MAX_VALUE;
        }
        if (left <= start && end <= right)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return Math.min(query(start, mid, node*2, left, right), query(mid+1,end,node*2+1,left,right));
    }

    public static void main(String[] args) throws IOException
    {
        int num =0, test = 0, start = 0, end = 0;
        StringTokenizer get = new StringTokenizer(scan.readLine());
        num = Integer.parseInt(get.nextToken());
        test = Integer.parseInt(get.nextToken());
        for (int i =1; i<=num; ++i)
        {
            ary[i] = Long.parseLong(scan.readLine());
        }
        init(1,num,1);
        while(test-->0)
        {
            get = new StringTokenizer(scan.readLine());
            start = Integer.parseInt(get.nextToken());
            end = Integer.parseInt(get.nextToken());
            result.append(query(1,num,1,start,end) + "\n");
        }
        scan.close();
        System.out.print(result);
    }
}