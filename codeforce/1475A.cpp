#include <iostream>

using namespace std;

long long tmp;

bool hasOdd(long long num){
    int flag = 0;
    for(long long i=1; i*i<=num; i++){
        if(num % i == 0){
            if(i==1){
                if((num/i)%2) flag = 1;
            }
            else if((i%2) || ((num/i) % 2)) flag = 1;
        }
    }
    if(flag) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;

    for(int i=0; i<t; ++i){
        cin >> tmp;
        if(tmp == 1 || tmp == 2) cout << "NO\n";
        else if(hasOdd(tmp)) cout << "YES\n";
        else cout <<"NO\n";
    }
}
