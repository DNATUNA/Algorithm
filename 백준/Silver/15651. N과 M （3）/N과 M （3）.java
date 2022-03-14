import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Integer> list = new ArrayList<>();

    public static void nm(int count) {
        if(count==m) {
            for(int tmp : list) sb.append(tmp).append(" ");
            sb.append("\n");
            return;
        }

        for(int i=1; i<=n; ++i) {
            list.add(i); nm(count+1); list.remove(list.size()-1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());

        nm(0);
        bw.write(sb.toString());
        bw.flush();
    }
}