#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day = 0;
    while(day < progresses.size()){
        int stack = 0;
        int data = (100 - progresses[day]) / speeds[day];
        if((100 - progresses[day]) % speeds[day] > 0) data++;
        stack++; day++;
        if(day == progresses.size()){
            answer.push_back(stack);
            break;
        }
        while(1){
            if(day == progresses.size()){
                break;
            }
            int check = (100 - progresses[day]) / speeds[day];
            if((100 - progresses[day]) % speeds[day] > 0) check++;
            
            if(data >= check){
                stack++; day++;
            } else {
                break;
            }
        }
        answer.push_back(stack);
    }

    return answer;
}