import java.io.*;
import java.util.*;

class Main {

    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
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
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int v = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Pair>> edge = new ArrayList<>();
        for(int i=0; i<=v; ++i) edge.add(new ArrayList<>());
        for(int i=0; i<e; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            edge.get(start).add(new Pair(end, cost));
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> x.getY() - y.getY());
        int[] cost = new int[v+1]; Arrays.fill(cost, Integer.MAX_VALUE);
        pq.add(new Pair(k, 0)); cost[k] = 0;
        while(!pq.isEmpty()) {
            Pair now = pq.poll();
            if(cost[now.getX()] < now.getY()) continue;
            for(Pair tmp : edge.get(now.getX())) {
                int nextCost = now.getY() + tmp.getY();
                if(nextCost > cost[tmp.getX()]) continue;
                pq.add(new Pair(tmp.getX(), nextCost)); cost[tmp.getX()] = nextCost;
            }
        }

        for(int i=1; i<=v; ++i) {
            if(cost[i] == Integer.MAX_VALUE) sb.append("INF\n");
            else sb.append(cost[i]).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}