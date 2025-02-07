#include <string>
#include <vector>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    auto sv = [&] (string str) 
    {
        string temp;
        vector<int>v;
        for(auto & i : str)
        {
            if(i == ':')
            {
                v.push_back(stoi(temp));
                temp = "";
                continue;
            }
            temp += i;
        }
        v.push_back(stoi(temp));
        return v[0] * 60 + v[1];
    };
    int ed = sv(video_len), now = sv(pos), os = sv(op_start), oe = sv(op_end);
    if(os <= now && now <= oe)
    {
        now = oe;
    }
    for(auto & i : commands)
    {
        if(i == "next")
        {
            now = min(now+10,ed);
        }
        else
        {
            now = max(0,now-10);
        }
        if(os <= now && now <= oe)
        {
            now = oe;
        }
    }
    int h = now / 60, mm = now % 60;
    if(h / 10 == 0)
    {
        answer += '0';
    }
    answer += to_string(h);
    answer += ":";
    if(mm / 10 == 0)
    {
        answer += '0';
    }
    answer += to_string(mm);
    return answer;
}