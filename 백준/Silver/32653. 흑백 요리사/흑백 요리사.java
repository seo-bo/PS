import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;

public final class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Queue<Long> q = new ArrayDeque<>();
        for (String e : br.readLine().split(" ")) {
            q.offer(2 * Long.parseLong(e));
        }

        long b, a;
        while (q.size() > 1) {
            b = q.poll();
            a = q.poll();

            q.offer(lcm(a, b));
        }

        bw.write(q.poll() + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    private static long gcd(long a, long b) {
        if (a < b) {
            long tmp = a;
            a = b;
            b = tmp;
        }

        long n = 0;
        while (b != 0) {
            n = a % b;
            a = b;
            b = n;
        }

        return a;
    }

    private static long lcm(long a, long b) {
        //return a * b / gcd(a, b);
        return a / gcd(a,b) * b ;
    }
}