import java.io.*;
import java.util.*;

public class Main {

    static int[] list;
    static ArrayList<ArrayList<Integer>> path;
    static boolean[] visit;
    static int[][] memo;

    public static void dp(int n) {
        for(int next : path.get(n)) {
            if(visit[next]) continue;
            visit[next] = true;
            dp(next);
            memo[n][1] += memo[next][0];
            memo[n][0] += Math.max(memo[next][1], memo[next][0]);
        }
        memo[n][1] += list[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        list = new int[n+1]; memo = new int[n+1][2]; visit = new boolean[n+1];

        path = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; ++i) list[i] = Integer.parseInt(st.nextToken());
        for(int i=0; i<=n; ++i) path.add(new ArrayList<>());

        for(int i=0; i<n-1; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
            path.get(start).add(end);
            path.get(end).add(start);
        }

        visit[1] = true;
        dp(1);
        bw.write(sb.append(Math.max(memo[1][0], memo[1][1])).toString());
        bw.flush();
    }
}