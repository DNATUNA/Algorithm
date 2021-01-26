#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;

    int tmp, n;
    for(int i=0; i<t; ++i){
        priority_queue<int> max;
        priority_queue<int, vector<int>, greater<>> min;
        cin >> n;
        cout << n / 2 + 1 << '\n';
        for(int j=1; j<n+1; ++j) {
            cin >> tmp;
            if (max.size() == min.size()) max.push(tmp);
            else min.push(tmp);

            if (!min.empty() && !max.empty() && min.top() < max.top()) {
                int a = max.top(); max.pop();
                int b = min.top(); min.pop();

                min.push(a); max.push(b);
            }
            if(j % 2){
                cout << max.top() << ' ';
                if(!(j%10)) cout << '\n';
            }
        }
        cout << '\n';
    }
}
