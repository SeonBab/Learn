#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { 0 };
        
    for (auto i : ingredient) {
        if (v.back() == 1 && i == 2)
            v.back() = 12;
        else if (v.back() == 12 && i == 3)
            v.back() = 123;
        else if (v.back() == 123 && i == 1) {
            answer++;
            v.pop_back();
        }
        else
            v.push_back(i);
    }
    
    return answer;
}