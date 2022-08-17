import java.io.*;
import java.util.*;

public class linak {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int bread=Integer.parseInt(bf.readLine());
        int[][] happy=new int[bread][2];
        String[] s=bf.readLine().split(" ");
        int a=Integer.parseInt(s[0]),b=Integer.parseInt(s[1]);

        for(int i=0; i<bread; i++){
            s=bf.readLine().split(" ");
            happy[i][0]=Integer.parseInt(s[0]);
            happy[i][1]=Integer.parseInt(s[1]);
        }
        Arrays.sort(happy,(o1, o2) -> (o2[0]-o2[1])-(o1[0]-o1[1]));
        int i=0;
        long sum=0;
        for(; i<a; i++) sum+=happy[i][0];
        for(; i<bread; i++) sum+=happy[i][1];
        System.out.println(sum);
    }
}