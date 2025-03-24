#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> numberStack;
    int kCount = k;
        
    for (char num : number)
    {
        while(!numberStack.empty() && kCount > 0 && numberStack.top() < num)
        {
            numberStack.pop();
            --kCount;
        }
        
        numberStack.push(num);
    }
    
    while(numberStack.size() > number.length() - k)
    {
        numberStack.pop();
    }
    
    for (int i = 0; i < number.length() - k; ++i)
    {
        answer = numberStack.top() + answer;
        numberStack.pop();
    }
    
    return answer;
}