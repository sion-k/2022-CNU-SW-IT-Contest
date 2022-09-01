import java.util.*;
import java.io.*;

public class Begachu {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));        
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for(int i=0; i<N; i++){
            arr[i] =  Integer.parseInt(st.nextToken());
        }
        System.out.print(dp(0, 0, N, arr));
    }

    static int dp(int i, int b, int N, int[] arr){
        if(i>=N) return 0;
        int result = dp(i+1, b, N, arr);
        if(b==0) result = Math.max(result, 1 + dp(i+1, arr[i], N, arr));
        else if(b>=arr[i]) result = Math.max(result, 1 + dp(i+1, b+arr[i], N, arr));
        return result;
    }

}
