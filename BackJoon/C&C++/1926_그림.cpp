#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(queue<pair<int, int>> &check, vector<vector<int>> &visit, vector<vector<int>> &pan){
    int size = 1;
    while(!check.empty()){
        pair<int, int> tmp = check.front(); check.pop();
        for(int i=0; i<4; ++i){
            int nx = tmp.X + dx[i];
            int ny = tmp.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= x || ny >= y) continue;
            if(visit[nx][ny] || !pan[nx][ny]) continue;

            check.push({nx, ny});
            visit[nx][ny] = 1;
            size++;
        }
    }
    return size;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x>>y;

    vector<vector<int>> pan(x, vector<int>(y));
    for(int i=0; i<x; ++i) {
        for(int j=0; j<y; ++j) {
            cin >> pan[i][j];
        }
    }

    vector<vector<int>> visit(x, vector<int>(y));
    queue<pair<int, int>> check;

    int max = 0, count = 0;
    for(int a=0; a<x; ++a) {
        for (int b = 0; b < y; ++b) {
            if (!visit[a][b] && pan[a][b]){
                check.push({a, b}); visit[a][b] = 1;
                int size = bfs(check, visit, pan);
                count++;
                max = max < size ? size : max;
            }
        }
    }
    cout << count << '\n' << max;
}
