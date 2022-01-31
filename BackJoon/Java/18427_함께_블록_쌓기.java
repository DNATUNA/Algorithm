import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
        int[][] nums = new int[n+1][m];

        for(int i=1; i<=n; ++i) {
            st = new StringTokenizer(br.readLine());
            int index = 0;
            while(st.hasMoreTokens()) {
                nums[i][index++] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] dp = new int[n+1][h+1];

        Arrays.fill(dp[0], 0); dp[0][0] = 1;
        for(int i=1; i<=n; ++i) {
            for(int j=0; j<=h; ++j) {
                int tmp = 0;
                for(int now : nums[i]) {
                    if(j-now < 0 || now == 0) continue;
                    tmp += dp[i-1][j-now];
                    tmp %= 10007;
                }
                dp[i][j] = (tmp + dp[i-1][j]) % 10007;
            }
        }
        System.out.println(dp[n][h]);
    }
}
