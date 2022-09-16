// import java.math.BigInteger;
import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner((System.in));
        long n = sc.nextLong();
        long ret = -1;
        HashMap<Long, Long> map1 = new HashMap<>();
        for (int i = 0;i<n;i++){
            long tmp = sc.nextLong();
            if (map1.get(tmp)==null)
            {
                // System.out.println(tmp);
                map1.put(tmp,(long)1);
            }
            else{
                map1.put(tmp,map1.get(tmp)+1);
            }
            if (map1.get(tmp)>=ret){
                ret = map1.get(tmp);
            }
        }
        sc.close();
        System.out.println(ret);
    }
}