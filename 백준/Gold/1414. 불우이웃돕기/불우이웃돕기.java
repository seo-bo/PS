// 질문 게시판 코드 확인용
import java.io.*;
import java.util.*;
public class Main {

    static int[] parent;

    static class Edge implements Comparable<Edge> {
        int start;
        int end;
        int weight;

        Edge(int s, int e, int w) {
            this.start = s;
            this.end = e;
            this.weight = w;
        }

        @Override
        public int compareTo(Edge o) {
            return this.weight - o.weight;
        }
    }

    public static int find(int idx) {
        if(parent[idx] == idx)
            return idx;
        else
            return parent[idx] = find(parent[idx]);
    }

    public static void union(int s, int e) {
        if(s < e)
            parent[e] = s;
        else
            parent[s] = e;
    }

    public static int kruskal(Queue<Edge> pq, int n) {
        int sum = 0;
        int cnt = 0;

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            if(edge.start == edge.end)
                continue;

            int s = find(edge.start);
            int e = find(edge.end);

            if(s != e) {
                union(s, e);
                sum += edge.weight;
                ++cnt;
                if(cnt == n-1) //빠른탈출
                    return sum;
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringBuilder str = new StringBuilder();

        parent = new int[n];
        int total = 0;
        Queue<Edge> pq = new PriorityQueue<>();

        for(int i = 0; i < n; i++) {
            str.append(br.readLine());
            for(int j = 0; j < n; j++) {
                char ch = str.charAt(j);
                int tmp = 0;

                if (ch >= 'a' && ch <= 'z')
                    tmp = ch - 'a' + 1;
                else if (ch >= 'A' && ch <= 'Z')
                    tmp = ch - 'A' + 27;
                else //0이면
                    continue;

                pq.add(new Edge(i, j, tmp));
                total += tmp;
            }
            str.delete(0, str.length());
            parent[i] = i;
        }

        int rslt = kruskal(pq, n);

        if(n == 1) System.out.println(total);
        else if(rslt == 0) System.out.println("-1");
        else System.out.println(total - rslt);
    }
}