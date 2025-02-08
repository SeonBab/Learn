#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> hamburger{0};
        
    for (int e : ingredient)
    {
        if (hamburger.back() == 1 && e == 2)
        {
            hamburger.back() = 12;
        }
        else if (hamburger.back() == 12 && e == 3)
        {
            hamburger.back() = 123;
        }
        else if (hamburger.back() == 123 && e == 1)
        {
            answer++;
            hamburger.pop_back();
        }
        else
        {
            hamburger.push_back(e);
        }
    }
    
    return answer;
}