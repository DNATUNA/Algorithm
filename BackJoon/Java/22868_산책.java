import java.io.*;
import java.util.*;

public class Main {
    public static boolean[] visit;
    public static ArrayList<ArrayList<Integer>> pan;

    public static class Pair {
        int dot;
        int depth;
        String path;

        Pair(int dot, int depth) {
            this.dot = dot;
            this.depth = depth;
            this.path = Integer.toString(dot);
        }

        Pair(int dot, int depth, String path) {
            this.dot = dot;
            this.depth = depth;
            this.path = path;
        }

        public int getDot() { return this.dot; }
        public int getDepth() { return this.depth; }
        public String getPath() { return this.path; }
    }

    public static Pair bfs(int start, int end) {
        boolean flag = true;

        Pair min = new Pair(start, 0);
        Queue<Pair> q = new LinkedList<>();
        visit[start] = true;
        q.add(min);

        while(!q.isEmpty() && flag) {
            Pair now = q.poll();
            for(int next : pan.get(now.getDot())) {
                if(visit[next]) continue;
                visit[next] = true;
                //도착지 도착하면 최소값 확인하고
                if(next == end) {
                    min = new Pair(next, now.getDepth()+1, now.path.concat(",").concat(Integer.toString(next)));
                    flag = false;
                    break;
                } else {
                    q.add(new Pair(next, now.getDepth()+1, now.path.concat(",").concat(Integer.toString(next))));
                }
            }
        }
        return min;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        visit = new boolean[n+1];
        pan = new ArrayList<>();

        for(int i=0; i<n+1; ++i) {
            pan.add(new ArrayList<>());
        }

        for(int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
            pan.get(start).add(end); pan.get(end).add(start);
        }

        for(int i=0; i<n; ++i) {
            Collections.sort(pan.get(i));
        }

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());

        Pair first = bfs(start, end);

        visit = new boolean[n+1];
        String[] visitDots = first.getPath().split(",");
        for(String s : visitDots) {
            visit[Integer.parseInt(s)] = true;
        }
        visit[start] = false;

        Pair second = bfs(end, start);
        System.out.println(first.getDepth() + second.getDepth());
    }
}
