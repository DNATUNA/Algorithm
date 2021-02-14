#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define X first
#define Y second
int x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
int main(){
    cin >> x >> y;

    vector<vector<int>> pan(x);
    vector<vector<int>> score(x, vector<int>(y));
    queue<pair<int, int>> Q;

    for(int i=0; i<x; ++i){
        string line;
        cin >> line;
        for(auto piece: line) pan[i].push_back(piece - '0');
    }

    Q.push({0,0});
    score[0][0]= 1;
    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            if(!pan[i][j]) continue;
            while(!Q.empty()){
                pair<int, int> tmp = Q.front(); Q.pop();
                for(int a=0; a<4; ++a){
                    int nx = tmp.X+dx[a];
                    int ny = tmp.Y+dy[a];

                    if(nx<0 || ny<0 || nx>=x || ny>=y) continue;
                    if(score[nx][ny] || !pan[nx][ny]) continue;
                    score[nx][ny] = score[tmp.first][tmp.second]+1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << score[x-1][y-1];
}