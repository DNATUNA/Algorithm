import java.io.*;
import java.util.*;

public class Main {
    static int INF = 2100000000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken()) + 1, m = Integer.parseInt(st.nextToken());

        int[][] graph = new int[n][n];
        for(int[] tmp : graph) {
            Arrays.fill(tmp, 101);
        }

        for(int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            graph[a][b] = c; graph[b][a] = c;
        }

        int[] cost = new int[n]; Arrays.fill(cost, INF);

        st = new StringTokenizer(br.readLine(), " ");
        Queue<Integer> q = new LinkedList<>();

        q.offer(Integer.valueOf(st.nextToken()));
        int end= Integer.parseInt(st.nextToken());
        while(!q.isEmpty()) {
            int now = q.poll();
            for(int i=1; i<n; ++i) {
                if(i==now) continue;
                if(graph[now][i] == 101) continue;
                int tmp = graph[now][i] + (cost[now] == INF ? 0 : cost[now]);
                if(tmp < cost[i]) {
                    cost[i] = tmp;
                    q.offer(i);
                }
            }
        }
        System.out.println(cost[end]);
    }
}
