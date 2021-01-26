#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string origin, tmp;
    int t;
    cin >> origin >> t;
    getline(cin, tmp);
    list<char> text(origin.begin(), origin.end());
    auto cursor = text.end();
    for(int i=0; i<t; ++i){
        getline(cin, tmp);
        if(tmp[0] == 'P') text.insert(cursor, tmp[2]);
        else if(tmp[0] == 'L') {if(cursor != text.begin()) cursor--;}
        else if(tmp[0] == 'D') {if(cursor != text.end()) cursor++;}
        else if(tmp[0] == 'B') {if(cursor != text.begin()) cursor = text.erase(--cursor);}
    }
    for(auto x : text) cout << x;
}
