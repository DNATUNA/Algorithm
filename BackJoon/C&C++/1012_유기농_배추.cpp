#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define X first
#define Y second

int t, y, x, k;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1 ,0};

int main(){
    cin >> t;
    for(t; t>0; --t){
        cin >> y >> x >> k;

        vector<vector<int>> pan(x, vector<int>(y));
        vector<vector<int>> visit(x, vector<int>(y));
        queue<pair<int, int>> Q;
        for(k;k>0;--k){
            int a, b;
            cin >>b>>a;
            pan[a][b]++;
        }

        int ans=0;
        for(int i=0; i<x; ++i){
            for(int j=0; j<y; ++j){
                if(pan[i][j] && !visit[i][j]) Q.push({i, j});
                int flag=0;
                while(!Q.empty()){
                    flag=1;
                    pair<int, int> tmp=Q.front(); Q.pop();
                    for(int a=0; a<4; ++a){
                        int nx=tmp.X+dx[a], ny=tmp.Y+dy[a];
                        if(nx<0||nx>=x||ny<0||ny>=y) continue;
                        if(!pan[nx][ny] || visit[nx][ny]) continue;
                        visit[nx][ny]++; Q.push({nx, ny});
                    }
                }
                if(flag) ans++;
            }
        }
        cout<<ans<<'\n';
    }
}