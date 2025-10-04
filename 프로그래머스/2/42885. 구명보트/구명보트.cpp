#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater());
    
    int left = 0;
    int right = people.size() - 1;
    
    while (left <= right)
    {
        ++answer;
        
        int weight = people[left];
        
        ++left;
        
        if (weight + people[right] <= limit)
        {
            --right;
        }
    }
    
    return answer;
}