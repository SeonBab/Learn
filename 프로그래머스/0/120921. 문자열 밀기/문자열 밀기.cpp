#include <string>

using namespace std;

int solution(string A, string B) {
    for (int i = 0; i < A.size(); ++i)
    {
        if (A == B)
        {
            return i;
        }
        
        char lastChar = A.back();
        A = lastChar + A.substr(0, A.size() - 1);
    }
    
    return -1;
}