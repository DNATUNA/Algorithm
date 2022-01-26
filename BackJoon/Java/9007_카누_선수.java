import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());

        for(; T>0; --T) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            int[][] c = new int[4][n];

            for(int i=0; i<4; ++i) {
                int index = 0;
                st = new StringTokenizer(br.readLine());
                while(st.hasMoreTokens()) {
                    c[i][index++] = Integer.parseInt(st.nextToken());
                }
            }

            PriorityQueue<Integer> pq1 = new PriorityQueue<>(), pq2 = new PriorityQueue<>(Collections.reverseOrder());
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    pq1.offer(c[0][i] + c[1][j]);
                    pq2.offer(c[2][i] + c[3][j]);
                }
            }

            int answer = 123456780;
            boolean flag = true;
            while(!pq1.isEmpty() && !pq2.isEmpty()) {
                int tmp = pq1.peek() + pq2.peek();
                if(tmp == k) {
                    answer = tmp;
                    break;
                } else if (tmp > k) {
                    pq2.poll();
                } else {
                    pq1.poll();
                }
                if(flag) {
                    answer = tmp;
                    flag = false;
                } else if(Math.abs(answer - k) == Math.abs(tmp - k)) {
                    answer = Math.min(answer, tmp);
                } else if(Math.abs(answer - k) > Math.abs(tmp - k)) {
                    answer = tmp;
                }
            }
            System.out.println(answer);
        }
    }
}
