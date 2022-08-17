import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] s=bf.readLine().split(" ");
        int a=Integer.parseInt(s[0]),p=Integer.parseInt(s[1]),q=Integer.parseInt(s[2]);
        int[][] k=new int[a][2];
        for(int i=0; i<a; i++){
            s=bf.readLine().split(" ");
            k[i][0]=Integer.parseInt(s[0]);
            k[i][1]=Integer.parseInt(s[1]);
        }
        Arrays.sort(k,(o1, o2) -> {
            if(Math.max(o1[0],o1[1])==Math.max(o2[0],o2[1])) return Math.min(o2[0],o2[1])-Math.min(o1[0],o1[1]);
            else return Math.max(o2[0],o2[1])-Math.max(o1[0],o1[1]);
        });
        int[][] ka=new int[p+q][2];
        System.arraycopy(k, 0, ka, 0, p + q);
        Arrays.sort(ka,(o1, o2) -> (o2[0]-o2[1])-(o1[0]-o1[1]));
        int i=0;
        long sum=0;
        for(; i<p; i++) sum+=ka[i][0];
        for(; i<p+q; i++) sum+=ka[i][1];
        System.out.println(sum);
    }
}