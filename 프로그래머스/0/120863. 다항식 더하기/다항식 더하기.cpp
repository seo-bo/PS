#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "", temp = "";
    int a = 0, b = 0;
    for(auto & i : polynomial)
    {
        if('0' <= i && i <= '9')
        {
            temp += i;
        }
        else if(i == '+')
        {
            if(temp.empty())
            {
                continue;
            }
            b += stoi(temp);
            temp = "";
        }
        else if(i == 'x')
        {
            if(temp.empty())
            {
                a++;
                continue;
            }
            a += stoi(temp);
            temp = "";
        }
    }
    if(!temp.empty())
    {
        b += stoi(temp);
    }
    if(a > 0)
    {
        if(a > 1)
        {
            answer += to_string(a);
        }
        answer += "x";
    }
    if(b > 0)
    {
        if(!answer.empty())
        {
            answer += " + ";
        }
        answer += to_string(b);
    }
    if(answer.empty())
    {
        return "0";
    }
    return answer;
}