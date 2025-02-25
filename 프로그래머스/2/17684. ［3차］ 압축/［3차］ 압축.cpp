#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int>mm;
    char base = 'A';
    int n = 1;
    while(base < 'Z' + 1)
    {
        string str = "";
        str += base;
        mm[str] = n++;
        base++;
    }
    int idx = 0;
    while(idx < (int)msg.size())
    {
        string temp = "";
        while(idx < (int)msg.size())
        {
            temp += msg[idx];
            if(mm.find(temp) == mm.end())
            {
                temp.pop_back();
                break;
            }
            idx++;
        }
        answer.push_back(mm[temp]);
        if(idx < (int)msg.size())
        {
            temp += msg[idx];
        }
        mm[temp] = n++;
    }
    return answer;
}