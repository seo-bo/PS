import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair>
{
    int first, second;
    public Pair(int first, int second)
    {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair o)
    {
        return this.first - o.first;
    }
}

class topo
{
    private int vertex;
    private int degree[] = new int[3001];
    private int ary[] = new int[3001];
    private Vector<Integer>[] graph = new Vector[3001];
    private StringBuilder result = new StringBuilder();
    topo(int vertex)
    {
        this.vertex = vertex;
        for(int i = 0; i < this.graph.length; i++)
        {
            this.graph[i] = new Vector<>();
        }
    }
    public void cycle(int i, int num) throws IOException
    {
        this.ary[i] = num;
    }
    public static int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    public void make_graph()
    {
        for (int i =1; i<=this.vertex;++i)
        {
            for (int j =i+1; j<=this.vertex;++j)
            {
                if((gcd(this.ary[i], this.ary[j]) != 1))
                {
                    this.graph[i].add(j);
                    this.degree[j]++;
                }
            }
        }
    }
    public void topo_sort()
    {
        PriorityQueue<Pair>pq = new PriorityQueue<>();
        for (int i =1; i<=this.vertex;++i)
        {
            if(degree[i] == 0)
            {
                pq.add(new Pair(this.ary[i],i));
            }
        }
        while(!pq.isEmpty())
        {
            int current = pq.poll().second;
            this.result.append(this.ary[current] + " ");
            for (int i : this.graph[current])
            {
                if((--degree[i]) == 0)
                {
                    pq.add(new Pair(this.ary[i],i));
                }
            }
        }
    }
    public void print()
    {
        System.out.print(result);
    }
}

public class Main
{
    static BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException
    {
        int num = Integer.parseInt(scan.readLine());
        topo sort = new topo(num);
        StringTokenizer str = new StringTokenizer(scan.readLine());
        for (int i =1;i<=num;++i)
        {
            sort.cycle(i,Integer.parseInt(str.nextToken()));
        }
        sort.make_graph();
        sort.topo_sort();
        sort.print();
    }
}
