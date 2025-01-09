import java.io.*;
import java.util.*;


public class Main
{
    static long ary[] = new long[1000001];
    static long tree[] = new long[1000001*4];
    static BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder result = new StringBuilder();

    public static void update(int start, int end, int node, int idx , int value)
    {
        if(idx > end || idx < start)
        {
            return;
        }
        if (idx <= start && end <= idx)
        {
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, node*2, idx, value);
        update(mid+1, end, node*2+1, idx, value);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    public static long query(int start, int end, int node, int left, int right)
    {
        if(left > end || right < start)
        {
            return 0;
        }
        if (left <= start && end <= right)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return query(start, mid, node*2, left, right) + query(mid+1, end, node*2+1, left, right);
    }

    public static void main(String[] args) throws IOException
    {
        int num =0, test = 0, start = 0, end = 0, temp = 0;
        StringTokenizer get = new StringTokenizer(scan.readLine());
        num = Integer.parseInt(get.nextToken());
        test = Integer.parseInt(get.nextToken());
        while(test-->0)
        {
            get = new StringTokenizer(scan.readLine());
            temp = Integer.parseInt(get.nextToken());
            start = Integer.parseInt(get.nextToken());
            end = Integer.parseInt(get.nextToken());
            switch(temp)
            {
                case 0:
                {
                    result.append(query(1,num,1,Math.min(start,end),Math.max(start,end)) + "\n");
                    break;

                }
                case 1:
                {
                    update(1,num,1,start,end);
                    break;
                }
            }
        }
        scan.close();
        System.out.print(result);
    }
}