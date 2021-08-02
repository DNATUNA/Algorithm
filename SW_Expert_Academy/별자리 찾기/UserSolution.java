package com.company;

public class UserSolution {
    private final static int MAX_N	= 1000;

    int N, M;
    int[][] Map = new int[MAX_N][MAX_N];

    public static class Distance {
        int y, x;
    }

    public void init(int N, int M, int[][] Map){
        this.N=N; this.M=M;

        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                this.Map[j][i] = Map[j][i];
    }

    public Solution.Result findConstellation(int[][] Star){
        int count = 0;
        Distance[] main = new Distance[4];
        Distance[][] starList = new Distance[4][20];
        Solution.Result answer = new Solution.Result();

        // 별자리에서 기준 별 및 다른 별들 찾기
        for(int i=0; i<M; ++i){
            for(int j=0; j<M; ++j){
                if(Star[j][i] == 9){
                    main[0] = new Distance();
                    main[0].y = j;
                    main[0].x = i;
                } else if(Star[j][i] == 1) {
                    starList[0][count] = new Distance();
                    starList[0][count].y = j;
                    starList[0][count++].x = i;
                }
            }
        }

        // 별자리에서 기준 별 기준으로 다른 별들 거리재기
        for(int i=0; i<count; ++i){
            starList[0][i].x -= main[0].x; starList[0][i].y -= main[0].y;
        }

        // 90도 돌렸을 때의 값 계산
        for(int i=1; i<4; ++i){
            main[i] = new Distance();
            main[i].x = main[i-1].y;
            main[i].y = main[i-1].x;
            main[i].y = M-main[i].y-1;

            for(int j=0; j<count; ++j){
                starList[i][j] = new Distance();
                starList[i][j].x = starList[i-1][j].y;
                starList[i][j].y = -starList[i-1][j].x;
            }
        }

        // 별자리 지도에서 별자리 찾기
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(Map[j][i]==0) continue;                      // 별 아니면 넘기고
                for(int direction=0; direction<4; direction++){ // 별 찾으면 기준별인지 4방향에 대해서
                    int up = j - main[direction].y, down = j + (M - main[direction].y - 1);
                    int left = i - main[direction].x, right = i + (M - main[direction].x - 1);
                    if(up < 0 || up >= N || down < 0 || down >= N || left < 0 || left >= N || right < 0 || right >= N)
                        continue;

                    int flag=1;
                    for(int k=0; k<count; ++k){                 // List 보면서 별자리에 맞는 기준별인지 검사
                        int x = i + (starList[direction][k].x);
                        int y = j + (starList[direction][k].y);
                        if(x<0 || x>=N || y<0 || y>=N){ flag=0; break; }
                        if(Map[y][x]==0){ flag=0; break; }
                    }
                    if(flag==1) {
                        answer.x=i; answer.y=j;
                    }
                }
            }
        }
        return answer;
    }
}