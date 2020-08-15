#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge;
    int bridgeWeight = 0;
    int truckIndex = 0;
    while(1){
        answer++;
        if(bridge.size() == bridge_length){
            bridgeWeight -= bridge.front();
            bridge.pop();
        }
        if(bridgeWeight + truck_weights[truckIndex] <= weight) {
            bridge.push(truck_weights[truckIndex]);
            bridgeWeight += bridge.back();
            truckIndex++;
            if(truckIndex == truck_weights.size()) break;
        } else {
            bridge.push(0);
        }
    }

    return answer + bridge_length;
}