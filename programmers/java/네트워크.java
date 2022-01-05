import java.util.LinkedList;
import java.util.Queue;

public int solution(int n, int[][] computers) {
    int answer = 0;
    int[] pan =  new int[n];
    Queue<Integer> q = new LinkedList<>();
    for(int y=0; y<n; ++y){
        if(pan[y] == 1) continue;
        for(int x=0; x<n; ++x){
            if(computers[y][x] == 0 || pan[x] == 1) continue;
            q.offer(x); pan[x]=1;
        }
        answer++;
        while (!q.isEmpty()){
            int now = q.poll();
            out.print(now);
            for(int x=0; x<n; ++x) {
                if (computers[now][x] == 0 || pan[x] == 1) continue;
                q.offer(x);
                pan[x] = 1;
            }
        }
    }
    return answer;
}
