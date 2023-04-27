#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int count{};
    
    for (int i = 0; i < str1.length(); ++i)
    {
        if (str1[i] == str2[0])
        {
            for(int j = 0; j < str2.length(); ++j)
            {
                if (str1[i + j] == str2[j])
                {
                    ++count;
                }
            }
            
            if (count == str2.length())
            {
                return 1;
            }
            else
            {
                count = 0;
            }
        }
    }
    return 2;
}