import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
        int[] list = new int[n+1];

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; ++i) list[i] = Integer.parseInt(st.nextToken()) + list[i-1];

        int start = 0, end = x, max = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        while(end <= n) {
            int tmp = list[end] - list[start];
            hm.put(tmp, hm.getOrDefault(tmp, 0) + 1);
            max = Math.max(tmp, max);
            start++; end++;
        }

        if(max == 0) bw.write("SAD");
        else bw.write(sb.append(max).append("\n").append(hm.get(max)).toString());
        bw.flush();
    }
}