#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer{ strings };
    
    sort(answer.begin(), answer.end(), [n](const string& a, const string& b)
        { return (a[n] == b[n]) ? a < b : a[n] < b[n]; });
    
    return answer;
}