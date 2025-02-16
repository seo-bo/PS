#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string>ss(phone_book.begin(),phone_book.end());
    sort(phone_book.begin(),phone_book.end(), [&] (const string & a, const string & b)
         {
            return (int)a.size() < (int)b.size(); 
         });
    for(auto & i : phone_book)
    {
        string temp = "";
        ss.erase(i);
        for(auto & j : i)
        {
            temp += j;
            if(ss.find(temp) != ss.end())
            {
                return false;
            }
        }
        ss.insert(i);
    }
    return answer;
}