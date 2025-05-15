#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, vector<pair<int, int>>> genrePlayList;
    unordered_map<string, int> genrePlayCount;
    
    for (int i = 0; i < genres.size(); ++i)
    {
        genrePlayList[genres[i]].push_back({i, plays[i]});
        genrePlayCount[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> sortGenre(genrePlayCount.begin(), genrePlayCount.end());
    sort(sortGenre.begin(), sortGenre.end(),
        [](const pair<string, int>& a, const pair<string, int> b)
         {
             return a.second > b.second;
         });
    
    for (const auto& e : sortGenre)
    {
        const string& genre = e.first;
        auto& songs = genrePlayList[genre];
        
        sort(songs.begin(), songs.end(),
            [](const pair<int, int>& a, const pair<int, int>& b)
             {
                if (a.second == b.second) 
                {
                    return a.first < b.first;
                }
                 return a.second > b.second;
             });
        
        for (int i = 0; i < songs.size(); ++i)
        {
            if (i >= 2)
            {
                break;
            }
            
            answer.push_back(songs[i].first);
        }
    }
    
    return answer;
}