#include <iostream>
#include <queue>

using namespace std;

int n, k;
int dx[2] = {1, -1};
int pan[100001];
int main() {
    cin >> n >> k;

    pan[k]--;
    queue<int> Q;
    Q.push(n);

    if(n==k){
        cout << 0;
        return 0;
    }
    while(!Q.empty()){
        int tmp = Q.front(); Q.pop();
        for(int i : dx){
            int nx = tmp + i;
            if(nx<0||nx>100000) continue;
            if(pan[nx]&&pan[nx]!=-1)continue;
            if(pan[nx]==-1){
                cout << pan[tmp] + 1;
                return 0;
            }
            pan[nx] = pan[tmp] + 1;
            Q.push(nx);
        }
        int nx = tmp * 2;
        if(nx<0||nx>100000) continue;
        if(pan[nx]&&pan[nx]!=-1)continue;
        if(pan[nx]==-1){
            cout << pan[tmp] + 1;
            return 0;
        }
        pan[nx] = pan[tmp] + 1;
        Q.push(nx);
    }
}