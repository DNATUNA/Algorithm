#include <iostream>
using namespace std;

int tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;

    for(int i=0; i<t; ++i){
        cin >> tmp;

        if(tmp<2020) cout <<"NO\n";
        else{
            int count = tmp / 2020, flag = 0;
            for(int j=0; j<=count; ++j){
                int check = 2020 * j + 2021 * (count - j);
                if(tmp == check){
                    flag = 1;
                    break;
                }
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
