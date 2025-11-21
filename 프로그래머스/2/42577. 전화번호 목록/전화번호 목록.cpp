#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {    
    bool answer = true;
    
    set<string> phoneNumberSet;
    
    for (const string& phoneNumber : phone_book)
    {
        phoneNumberSet.insert(phoneNumber);
    }
    
    set<string>::iterator it = phoneNumberSet.begin();
    string previous = *it;
    ++it;
    
    while (it != phoneNumberSet.end())
    {
        string currentPhoneNumber = *it;
        
        string prefix = currentPhoneNumber.substr(0, previous.size());
        
        if (prefix == previous)
        {
            answer = false;
            break;
        }
        
        previous = currentPhoneNumber;
        ++it;
    }
    
    return answer;
}