#include <iostream>

using namespace std;

int x;
void top(int a, int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    top(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    top(6-a-b, b, n-1);
}

int main(){
    cin >> x;
    cout << (1<<x) - 1 << '\n';
    top(1, 3, x);
}