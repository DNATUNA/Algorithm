#include <iostream>
#include <utility>
#include <stack>
#include <vector>

using namespace std;

#define N first
#define S second

int plusMinus[2] = {1, -1};



int solution(vector<int> &numbers, int target) {
    int answer = 0;

    stack<pair<int, int>> ST;

    ST.push({1, numbers[0]});
    ST.push({1, -numbers[0]});

    while(!ST.empty()){
        pair<int, int> tmp = ST.top(); ST.pop();
        for(int pm : plusMinus){
            if(tmp.N == numbers.size() && tmp.S == target){answer++; continue;}
            if(tmp.N == numbers.size())continue;
            ST.push({tmp.N+1, tmp.S + (numbers[tmp.N] * pm)});
        }
    }

    return answer/2;
}

int main(){
    vector<int> list = {1, 1, 1, 1, 1};
    cout << solution(list, 3);
}