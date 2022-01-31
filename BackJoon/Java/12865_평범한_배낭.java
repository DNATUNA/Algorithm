import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] dp = new int [n+1][k+1];
        for(int i=1; i<=n; ++i) {
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
            for(int j=1; j<=k; ++j) {
                if(j - w < 0) {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                int tmp = dp[i-1][j-w] + v;
                dp[i][j] = Math.max(tmp, dp[i-1][j]);
            }
        }
        System.out.println(dp[n][k]);
    }
}
