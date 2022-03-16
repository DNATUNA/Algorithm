import java.io.*;
import java.util.*;

class Main {

    static ArrayList<ArrayList<Integer>> edge = new ArrayList<>();
    static boolean[] visit;

    public static void dp(int n) {
        for(int next : edge.get(n)) {
            if(visit[next]) continue;
            visit[next] = true; dp(next);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        visit = new boolean[n+1];
        for(int i=0; i<=n; ++i) edge.add(new ArrayList<>());

        for(int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
            edge.get(start).add(end); edge.get(end).add(start);
        }

        int ans = 0;
        for(int i=1; i<=n; ++i) {
            if(visit[i]) continue;
            ans++; dp(i);
        }

        bw.write(sb.append(ans).toString());
        bw.flush();
    }
}