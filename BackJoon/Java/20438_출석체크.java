import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken()), Q = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        boolean[] list = new boolean[N+3];
        int[] sumOfSection = new int[N+3];
        HashSet<Integer> sleep = new HashSet<>();
        int[] check = new int[Q];

        st = new StringTokenizer(br.readLine(), " ");
        for(int i=0; st.hasMoreTokens(); ++i) {
            sleep.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine(), " ");
        for(int i=0; st.hasMoreTokens(); ++i) {
            int tmp = Integer.parseInt(st.nextToken());
            if(sleep.contains(tmp)) check[i]=0;
            else check[i] = tmp;
        }

        // 출석체크 조집니다.
        for(int num : check) {
            if(num == 0) continue;
            int tmp = num;
            while(tmp <= N+2) {
                list[tmp] = true;
                tmp += num;
            }
        }
        // 자는 학생들은 뺍니다.
        for(int num : sleep) {
            list[num] = false;
        }
        // 구간합을 구합니다.
        for(int i=3; i<N+3; ++i) {
            if(!list[i]) sumOfSection[i] = sumOfSection[i-1] + 1;
            else sumOfSection[i] = sumOfSection[i-1];
        }

        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine(), " ");
            int[] sectoin = { Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) };
            System.out.println(sumOfSection[sectoin[1]] - sumOfSection[sectoin[0] - 1]);
        }
    }
}
