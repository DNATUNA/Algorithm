import java.io.*;
import java.util.*;

public class Main {

    static int[] parent;

    public static int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int x, int y) {
        x = find(x);
        y = find(y);

        if(x!=y) {
            if(x>=y) parent[x] = y;
            else parent[y]= x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        parent = new int[n+1];
        for(int i=1; i<=n; ++i) parent[i] = i;

        // 진실을 아는 자들
        st = new StringTokenizer(br.readLine());
        int knowCount = Integer.parseInt(st.nextToken());
        for(int i=0; i<knowCount; ++i) parent[Integer.parseInt(st.nextToken())] = 0;

        // 파티 시작
        int[][] list = new int[m][];
        for(int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());
            list[i] = new int[count];
            for(int a=0; a<count; ++a) list[i][a] = Integer.parseInt(st.nextToken());
            Arrays.sort(list[i]);
            if(count <= 1) continue;
            for(int a=1; a<count; ++a) union(list[i][a-1], list[i][a]);
        }

        // 파티에서 세기
        int ans = 0;
        for(int i=0; i<m; ++i) {
            boolean flag = true;
            for(int tmp : list[i]) if(find(tmp) == 0) flag = false;
            if(flag) ans++;
        }

        bw.write(sb.append(ans).toString());
        bw.flush();
    }
}