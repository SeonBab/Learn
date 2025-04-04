#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int timeToMinutes(const string& timeStr)
{
    int hour = stoi(timeStr.substr(0, 2));
    int minute = stoi(timeStr.substr(3, 2));
    
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> bookings;
    for (const auto& time : book_time)
    {
        int inTime = timeToMinutes(time[0]);
        int outTime = timeToMinutes(time[1]) + 10;
        
        bookings.push_back({inTime, outTime});
    }
    
    sort(bookings.begin(), bookings.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (const auto& booking : bookings)
    {
        int inTime = booking.first;
        int outTime = booking.second;

        if (!pq.empty() && pq.top() <= inTime)
        {
            pq.pop();
        }
        
        pq.push(outTime);
    }
    
    return pq.size();
}