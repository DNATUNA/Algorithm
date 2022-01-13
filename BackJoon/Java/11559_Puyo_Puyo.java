import java.io.*;
import java.util.*;

public class Main {
    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return this.x;
        }

        public int getY() {
            return this.y;
        }
    }


    static int[] dx = {0, 0, -1 , 1};
    static int[] dy = {1, -1, 0 , 0};
    static String[][] pan = new String[12][6];
    static Queue<Pair> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        //먼저 뿌요뿌요를 입력받는다.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int i=0; i<12; ++i) {
            String tmp = br.readLine();
            for(int a=0; a<tmp.length(); ++a) {
                pan[i][a] =  Character.toString(tmp.charAt(a));
            }
        }

        int answer = 0;
        //터트릴 수 있는 친구가 있는지 확인한다.
        while(true) {
            boolean flag = true;
            boolean[][] visit = new boolean[12][6];
            for(int y=0; y<12; ++y) {
                for(int x=0; x<6; ++x) {
                    if(Objects.equals(pan[y][x], ".")) continue;
                    int count = 1; String tmp = pan[y][x];
                    ArrayList<Pair> list = new ArrayList<>();
                    q.offer(new Pair(x, y)); visit[y][x] = true; list.add(new Pair(x, y));
                    while(!q.isEmpty()) {
                        Pair now = q.poll();
                        for(int a=0; a<4; ++a) {
                            int nx = now.getX() + dx[a], ny = now.getY() + dy[a];
                            if(nx < 0 || nx >= 6 || ny < 0 || ny >= 12) continue;
                            if(visit[ny][nx] || Objects.equals(pan[ny][nx], ".") || !Objects.equals(pan[ny][nx], tmp)) continue;
                            count++; q.offer(new Pair(nx, ny)); visit[ny][nx] = true; list.add(new Pair(nx, ny));
                        }
                    }
                    if(count>=4) {
                        flag = false;
                        for(Pair location : list) {
                            pan[location.getY()][location.getX()] = ".";
                        }
                    }
                }
            }
            if(flag) break;
            answer++;
            grabity();
        }
        //답 +1 후 중력 적용
        //반복 이후 터트릴게 없으면 답을 출력한다.
        System.out.println(answer);
    }

    public static void grabity() {
        for(int x=5; x>=0; --x) {
            // 먼저 가장 아래 부분으 찾아준다.
            for(int y=11; y>=0; --y) {
                if(!Objects.equals(pan[y][x], ".")) continue;
                boolean flag = true;
                // 그 다음 위에 블록이 있는지 검사하고 있으면 자리를 바꿔준다.
                for(int tmp=y-1; tmp>=0; --tmp){
                    if(Objects.equals(pan[tmp][x], ".")) continue;
                    String swap = "";
                    swap = pan[y][x];
                    pan[y][x] = pan[tmp][x];
                    pan[tmp][x] = swap;
                    flag = false;
                    break;
                }
                // 만약 그 위에 블록이 없다면 끝낸다.
                if(flag) continue;
            }
        }
    }
}
