#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    stack<char> tmp;
    for(int i=0; i<n; ++i){
        string text;
        getline(cin, text);
        for(char s : text){
            if(s == ' '){
                while(!tmp.empty()){
                    cout << tmp.top();
                    tmp.pop();
                }
                cout << ' ';
            }
            else tmp.push(s);
        }
        while(!tmp.empty()){
            cout << tmp.top();
            tmp.pop();
        }
        cout << '\n';
    }
}