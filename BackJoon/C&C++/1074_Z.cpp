#include <iostream>
#include <cmath>

using namespace std;

int find(int n, int r, int c){
    if(n==0){
        if(r==0 && c==0) return 0;
        else if(r==0 && c==1) return 1;
        else if(r==1 && c==0) return 2;
        else return 3;
    }
    int tmp = (int)pow(2, n-1);
    if(r+1<=tmp && c+1<=tmp) return find(n-1, r, c);
    else if(r+1<=tmp && c+1>tmp) return tmp*tmp + find(n-1, r, c - tmp);
    else if(r+1>tmp && c+1<=tmp) return tmp*tmp*2 + find(n-1, r-tmp, c);
    else return tmp*tmp*3 + find(n-1, r-tmp, c-tmp);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r, c;
    cin >> n >> r >> c;

    cout << find(n, r, c);
}