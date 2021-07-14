#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int t, w, h;
int main(){
    cin >> t;
    for(t;t>0;--t){
        cin >> w >> h;

        vector<string> pan(h);
        vector<vector<int>> fire(h, vector<int>(w));
        vector<vector<int>> visit(h, vector<int>(w));

        queue<pair<int, int>> fQ;
        queue<pair<int, int>> vQ;

        for(int i=0; i<h; ++i){
            cin >> pan[i];
            for(int j=0; j<w; ++j){
                if(pan[i][j] == '*'){fire[i][j]=1; fQ.push({i, j});}
                else if(pan[i][j] == '@'){visit[i][j]=1; vQ.push({i, j});}
            }
        }

        while(!fQ.empty()){
            pair<int, int> tmp = fQ.front(); fQ.pop();
            for(int i=0; i<4; ++i){
                int nx = tmp.X + dx[i], ny = tmp.Y + dy[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if(fire[nx][ny] || pan[nx][ny]=='#') continue;
                fire[nx][ny]=fire[tmp.X][tmp.Y]+1; fQ.push({nx, ny});
            }
        }

        int flag=0;
        while(!vQ.empty()){
            pair<int, int> tmp = vQ.front(); vQ.pop();
            for(int i=0; i<4; ++i){
                int nx = tmp.X + dx[i], ny = tmp.Y + dy[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w){flag=visit[tmp.X][tmp.Y]; break;}
                if((fire[nx][ny] && fire[nx][ny]<=visit[tmp.X][tmp.Y]+1) || pan[nx][ny]=='#' || visit[nx][ny]) continue;
                visit[nx][ny]=visit[tmp.X][tmp.Y]+1; vQ.push({nx, ny});
            }
            if(flag) break;
        }
        if(flag) cout<<flag<<'\n';
        else cout<<"IMPOSSIBLE\n";
    }
}