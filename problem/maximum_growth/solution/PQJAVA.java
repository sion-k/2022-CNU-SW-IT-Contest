import java.util.*;
import java.io.*;

public class PQJAVA {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder bw = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int max = 0;
        for (int i = 0; i < n; i++) {
            pq.offer(a[i]);
            max = Math.max(max, a[i] - pq.peek());
        }
        System.out.println(max);
    }

}
