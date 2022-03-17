import java.io.*;
import java.util.*;

class Main {

    static boolean[] visit;
    static int[] list;
    static int n, m, ans = 0;
    static StringBuilder sb = new StringBuilder();

    public static void dp(int count) {
        if(count == n) {
            int isAns = 0, visitCount = 0;
            for(int i=1; i<=n; ++i) {
                if(visit[i]) {
                    isAns += list[i];
                    visitCount++;
                }
            }
            if(visitCount>0 && isAns == m) ans++;
            return;
        }

        visit[count+1] = true; dp(count+1);
        visit[count+1] = false; dp(count+1);

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        visit = new boolean[n+1]; list = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; ++i) list[i] = Integer.parseInt(st.nextToken());

        visit = new boolean[n+1];
        dp(0);
        bw.write(sb.append(ans).toString());
        bw.flush();
    }
}