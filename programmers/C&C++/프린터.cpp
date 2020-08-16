#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue< pair<int,int> > list;

    for(int i=0; i<priorities.size(); ++i){
        list.push(make_pair(priorities[i], i));
    }

    sort(priorities.begin(), priorities.end());

    while(1){
        if(list.front().first == priorities.back()){
            answer++;
            if(list.front().second == location)break;
            else{
                list.pop();
                priorities.pop_back();
            }
        } else {
            list.push(list.front());
            list.pop();
        }
    }

    return answer;
}