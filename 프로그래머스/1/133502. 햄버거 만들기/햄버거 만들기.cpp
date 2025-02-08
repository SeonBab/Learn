#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    vector<int> hamburger;
    
    for(int e : ingredient)
    {
        hamburger.push_back(e);
        
        if (hamburger.size() >= 4 &&
            hamburger[hamburger.size() - 4] == 1 &&
            hamburger[hamburger.size() - 3] == 2 &&
            hamburger[hamburger.size() - 2] == 3 &&
            hamburger[hamburger.size() - 1] == 1)
        {
            hamburger.erase(hamburger.end() - 4, hamburger.end());
            ++answer;
        }
    }
    
    return answer;
}