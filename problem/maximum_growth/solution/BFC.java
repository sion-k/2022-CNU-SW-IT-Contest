import java.util.*;
import java.io.*;

public class BFC {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder bw = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        int q = Integer.parseInt(br.readLine());
        for (int t = 0; t < q; t++) {
            st = new StringTokenizer(br.readLine(), " ");
            int o = Integer.parseInt(st.nextToken());
            if (o == 1) {
                int k = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                a[k - 1] = x;
            } else {
                int l = Integer.parseInt(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
                l--; r--;
                int max = 0;
                for (int i = l; i <= r; i++) {
                    for (int j = i; j <= r; j++) {
                        max = Math.max(max, a[j] - a[i]);
                    }
                }
                bw.append(max).append("\n");
            }
        }
        System.out.print(bw);
    }

}
