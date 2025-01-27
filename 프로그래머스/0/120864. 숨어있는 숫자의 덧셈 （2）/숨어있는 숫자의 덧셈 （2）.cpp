#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string temp= "";
    for(auto & i : my_string)
    {
        if('0' <= i && i <= '9')
        {
            temp += i;
        }
        else
        {
            if(temp.empty())
            {
                continue;
            }
            answer += stoi(temp);
            temp = "";
        }
    }
    if(!temp.empty())
    {
         answer += stoi(temp);
        temp = "";    
    }
    return answer;
}