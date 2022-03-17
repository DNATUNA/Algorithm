import java.io.*;
import java.util.*;

class Main {

    static boolean[] visit;
    static int[] list;
    static int n, m;
    static ArrayList<Integer> buffer = new ArrayList<>();
    static TreeSet<String> check = new TreeSet<>();
    static StringBuilder sb = new StringBuilder();
    public static void dp(int count) {
        if(count == m) {
            StringBuilder sbTmp = new StringBuilder();
            for(int tmp : buffer) sbTmp.append(tmp).append(" ");
            if(!check.contains(sbTmp.toString())) {
                sb.append(sbTmp).append("\n");
                check.add(sbTmp.toString());
            }
            return;
        }

        for(int i=1; i<=n; ++i) {
            if(visit[i]) continue;
            visit[i] = true;
            buffer.add(list[i]); dp(count+1); buffer.remove(buffer.size()-1);
            visit[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        list = new int[n+1]; visit = new boolean[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; ++i) list[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(list);
        dp(0);

        bw.write(sb.toString());
        bw.flush();
    }
}