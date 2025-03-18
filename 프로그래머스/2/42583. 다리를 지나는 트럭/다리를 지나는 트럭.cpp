#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge;
    int totalWight = 0;
    
    for (int truck : truck_weights)
    {
        while (true)
        {
            ++answer;
            
            // 다리에 있을 수 있는 트럭의 개수 확인
            if (bridge.size() == bridge_length)
            {
                totalWight -= bridge.front();
                bridge.pop();
            }
            
            if (totalWight + truck <= weight)
            {
                totalWight += truck;
                bridge.push(truck);
                break;
            }
            else
            {
                bridge.push(0);
            }
        }
    }
    
    answer += bridge_length;
    
    return answer;
}