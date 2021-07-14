#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define X first
#define Y second

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<vector<int>> check(n, vector<int>(n));
    queue<pair<int, int>> Q;

    for(int i=0; i<n; ++i){
        if(check[i][i])continue;
        answer++; Q.push({i, i});
        while(!Q.empty()){
            pair<int, int> tmp = Q.front(); Q.pop();
            for(int a=0; a<n; ++a){
                if(computers[tmp.X][a] || computers[a][tmp.Y]) {
                    if(check[tmp.X][a] || check[a][tmp.Y] || check[a][a]) continue;
                    check[tmp.X][a]++; check[a][tmp.Y]++; check[a][a]++;
                    Q.push({a, a});
                }
            }
        }
    }

    return answer;
}

int main(){
    vector<vector<int>> list = {{1, 1, 0}, {1, 1, 1},{0, 1, 1}};
    cout << solution(3, list);
}