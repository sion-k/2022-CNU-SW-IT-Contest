import java.util.*;
import java.io.*;

public class BegachuWrong2 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder bw = new StringBuilder();
		int N = Integer.parseInt(br.readLine())+1;
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		int[] arr = new int[N];
		for(int i=0; i<N; i++){
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);

		if(arr[1]/arr[0]==2 || arr[2]/arr[0]==2){
			for(int i=2; i<=N; i++){
				if(arr[0]*i==arr[i-1]) continue;
				if(arr[i-1]%arr[0]==0) {
					bw.append(arr[0]);
				} else{
					bw.append(arr[i-1]);
				}
				break;
			}
		}else {
			bw.append(arr[0]);
		}

		System.out.print(bw);
	}

}
