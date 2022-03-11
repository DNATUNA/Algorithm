import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());

        int[] list = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i) list[i] = Integer.parseInt(st.nextToken());

        HashMap<Integer, Integer> hm = new HashMap<>();
        int start = 0, end = 0, max = 0;
        while(start < n && end < n) {
            hm.put(list[end], hm.getOrDefault(list[end], 0) + 1);
            if(hm.get(list[end]) > k) {
                while(hm.get(list[end]) > k) {
                    hm.put(list[start], hm.get(list[start]) - 1);
                    start++;
                }
                end++;
            } else {
                max = Math.max(end++ - start + 1, max);
            }
        }

        bw.write(sb.append(max).toString());
        bw.flush();
    }
}