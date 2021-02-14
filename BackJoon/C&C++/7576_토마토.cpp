#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
#define X first
#define Y second

int x, y;
int raw, day;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main(){
    cin >> y>>x;

    vector<vector<int>> pan(x, vector<int>(y));
    vector<vector<int>> visit(x, vector<int>(y, -1));
    queue<pair<int, int>> Q;

    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            cin >> pan[i][j];
            if(pan[i][j] == 1){Q.push({i, j});visit[i][j]++;}
            else if(pan[i][j] == 0) raw++;
        }
    }
    while(!Q.empty()){
        pair<int, int> tmp = Q.front(); Q.pop();
        for(int i=0; i<4; ++i){
            int nx = tmp.X + dx[i];
            int ny = tmp.Y + dy[i];

            if(nx<0 || ny<0 || nx>=x || ny>=y) continue;
            if(pan[nx][ny]==-1 || visit[nx][ny]!=-1) continue;
            visit[nx][ny] = visit[tmp.X][tmp.Y] + 1;
            Q.push({nx, ny});
            raw--;
            day = day < visit[nx][ny] ? visit[nx][ny] : day;
        }
    }
    if(raw) cout<<-1;
    else cout<<day;
}