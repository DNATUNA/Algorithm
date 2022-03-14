import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Integer> list = new ArrayList<>();
    static boolean[] check;

    public static void nm(int count) {
        if(count == m) {
            for(int n : list) sb.append(n).append(" ");
            sb.append("\n");
            return;
        }

        for(int i=1; i<=n; ++i) {
            if(check[i]) continue;
            check[i] = true;
            list.add(i); nm(count+1); list.remove(list.size()-1);
            check[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        check = new boolean[n+1];

        nm(0);
        bw.write(sb.toString());
        bw.flush();
    }
}