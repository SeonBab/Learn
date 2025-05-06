#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deliveryCap = 0;
    int pickupCap = 0;
    
    for (int i = n - 1; i >= 0; --i)
    {
        deliveryCap += deliveries[i];
        pickupCap += pickups[i];
        
        while (deliveryCap > 0 || pickupCap > 0)
        {
            deliveryCap -= cap;
            pickupCap -= cap;
            
            answer += static_cast<long long>(i + 1) * 2;
        }
    }
    
    return answer;
}