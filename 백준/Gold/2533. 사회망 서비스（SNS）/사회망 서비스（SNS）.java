import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<ArrayList<Integer>> edge = new ArrayList<>();
    static int[][] memo;
    static boolean[] visit;

    public static void find(int n) {
        for(int child : edge.get(n)) {
            if(visit[child]) continue;
            visit[child] = true;
            find(child);
            memo[n][0] += memo[child][1];
            memo[n][1] += Math.min(memo[child][0], memo[child][1]);
        }
        memo[n][1] += 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        for(int i=0; i<=n; ++i) edge.add(new ArrayList<>());
        memo = new int[n+1][2];
        visit = new boolean[n+1];

        for(int i=0; i<n-1; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
            edge.get(start).add(end); edge.get(end).add(start);
        }

        visit[1] = true;
        find(1);
        bw.write(sb.append(Math.min(memo[1][0], memo[1][1])).toString());
        bw.flush();
    }
}