#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> list; 

    int size = prices.size();

    for(int i=0; i<size; ++i) {
        if(list.empty()) list.push(make_pair(i, prices[i]));
        else {
            while(!list.empty() && list.top().second > prices[i]){
                answer[list.top().first] = i - list.top().first;
                list.pop();
            }
            list.push(make_pair(i, prices[i]));
        }
    }

    while(!list.empty()) {
        answer[list.top().first] =  size - list.top().first - 1;
        list.pop();
    }

    return answer;
}