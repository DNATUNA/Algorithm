import java.io.*;
import java.util.*;

class Main {

    static class Pair {
        int x;
        int y;
        boolean flag;

        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }

        public Pair(int x, int y, boolean flag){
            this.x = x;
            this.y = y;
            this.flag = flag;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public boolean isFlag() {
            return flag;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), gunWo = Integer.parseInt(st.nextToken());
        int[] visit = new int[n+1]; Arrays.fill(visit, Integer.MAX_VALUE);
        ArrayList<ArrayList<Pair>> edge = new ArrayList<>();
        for(int i=0; i<=n; ++i) edge.add(new ArrayList<>());
        for(int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            edge.get(start).add(new Pair(end, cost)); edge.get(end).add(new Pair(start, cost));
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> x.getY() - y.getY());
        boolean isGunWoFirst = gunWo == 1;
        pq.add(new Pair(1, 0, isGunWoFirst)); visit[1] = 0;

        boolean flag = isGunWoFirst;

        while(!pq.isEmpty()) {
            Pair now = pq.poll();
            if(now.getY() > visit[now.getX()]) continue;
            if(now.isFlag() && now.getX() == n) flag = true;
            for(Pair next : edge.get(now.getX())) {
                int nextVisit = next.getY() + now.getY();
                if(nextVisit > visit[next.getX()]) continue;
                boolean isFound = next.getX() == gunWo;
                pq.add(new Pair(next.getX(), nextVisit, isFound || now.isFlag())); visit[next.getX()] = nextVisit;
            }
        }

        if(flag) sb.append("SAVE HIM");
        else sb.append("GOOD BYE");
        bw.write(sb.toString());
        bw.flush();
    }
}