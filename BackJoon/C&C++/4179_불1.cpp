#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define X first
#define Y second

int x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    cin >> x >> y;
    vector<string> pan(x);
    vector<vector<int>> fire(x, vector<int>(y));
    vector<vector<int>> J(x, vector<int>(y));

    queue<pair<int, int>> JQ;
    queue<pair<int, int>> fireQ;
    for(int i=0; i<x; ++i){
        cin >> pan[i];
        for(int j=0; j<y; ++j){
            if(pan[i][j]=='F'){
                fire[i][j] = 1;
                fireQ.push({i, j});
            } else if(pan[i][j] =='J'){
                J[i][j] = 1;
                JQ.push({i, j});
            }
        }
    }

    while(!fireQ.empty()){
        pair<int, int> tmp = fireQ.front(); fireQ.pop();
        for(int i=0; i<4; ++i){
            int nx = tmp.X + dx[i];
            int ny = tmp.Y + dy[i];

            if(nx<0 || nx >= x || ny<0 || ny>=y) continue;
            if(pan[nx][ny] == '#' || fire[nx][ny]) continue;
            fire[nx][ny] = fire[tmp.X][tmp.Y] + 1;
            fireQ.push({nx, ny});
        }
    }
    while(!JQ.empty()){
        pair<int, int> tmp = JQ.front(); JQ.pop();
        for(int i=0; i<4; ++i){
            int nx = tmp.X + dx[i];
            int ny = tmp.Y + dy[i];

            if(nx<0 || nx >= x || ny<0 || ny>=y){
                cout << J[tmp.X][tmp.Y];
                return 0;
            }
            if(pan[nx][ny] == '#' || (fire[nx][ny] && fire[nx][ny] <= J[tmp.X][tmp.Y]+1) || J[nx][ny]) continue;
            J[nx][ny] = J[tmp.X][tmp.Y] + 1;
            JQ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}