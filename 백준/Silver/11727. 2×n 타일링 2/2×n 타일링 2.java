import java.io.*;
import java.util.*;

class Main {
    
    static int[] memo = new int[10001];

    public static int dp(int x) {
        if(memo[x]!=0) return memo[x];
        return memo[x] = (dp(x-1) + dp(x-2) * 2) % 10007;
    }
    
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        memo[1] = 1; memo[2] = 3;
        dp(n);
        bw.write(sb.append(memo[n]).toString());
        bw.flush();
    }
}