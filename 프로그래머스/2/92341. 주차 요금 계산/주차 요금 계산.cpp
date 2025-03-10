#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int timeToMinutes(const string& time)
{
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    
    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> parkingTime;
    map<string, int> inTime;
    
    for (const auto& record : records)
    {
        stringstream ss(record);
        
        string time;
        string carNumber;
        string info;
        
        ss >> time >> carNumber >> info;
        
        int minutes = timeToMinutes(time);
        
        if (info == "IN")
        {
            inTime[carNumber] = minutes;
        }
        else
        {
            parkingTime[carNumber] += minutes - inTime[carNumber];
            inTime.erase(carNumber);
        }
    }
    
    for (const auto& e : inTime)
    {
        parkingTime[e.first] += timeToMinutes("23:59") - e.second;
    }
    
    for (const auto& e : parkingTime)
    {        
        int fee = 0;
        if (e.second <= fees[0])
        {
            fee = fees[1];
        }
        else
        {
            fee = fees[1] + ceil((double)(e.second - fees[0]) / fees[2]) * fees[3];
        }
        
        answer.push_back(fee);
    }
    
    return answer;
}