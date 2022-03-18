import java.io.*;
import java.util.*;

class Main {

    static class Pair {
        int x;
        int y;

        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] cost = new int[n+1]; Arrays.fill(cost, Integer.MAX_VALUE);
        boolean[] visit = new boolean[n+1];

        ArrayList<ArrayList<Pair>> edge = new ArrayList<>();
        for(int i=0; i<=n; ++i) edge.add(new ArrayList<>());

        for(int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken()), count = Integer.parseInt(st.nextToken());
            edge.get(start).add(new Pair(end, count)); edge.get(end).add(new Pair(start, count));
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> x.getY() - y.getY());
        pq.add(new Pair(1, 0)); cost[1] = 0;

        while(!pq.isEmpty()) {
            Pair now = pq.poll();
            if(now.getY() > cost[now.getX()]) continue;
            if(visit[now.getX()]) continue;
            visit[now.getX()] = true;
            for(Pair next : edge.get(now.getX())) {
                int nextVisit = now.getY() + next.getY();
                if(nextVisit > cost[next.getX()]) continue;
                if(visit[next.getX()]) continue;
                pq.add(new Pair(next.getX(), nextVisit)); cost[next.getX()] = nextVisit;
            }
        }

        bw.write(sb.append(cost[n]).toString());
        bw.flush();
    }
}