#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int m = 0;
    for(int i =0; i<(int)code.size();++i)
    {
        if(!m)
        {   
            if(code[i] != '1')
            {
                if(i % 2 ==0)
                {
                    answer += code[i];
                }
            }
            else 
            {
                m = (m +1) % 2;
            }
        }
        else
        {
            if(code[i] != '1')
            {
                if(i % 2)
                {
                    answer += code[i];
                }
            }
            else
            {
                m = (m+1) % 2;
            }
        }
        
    }
    if(answer.empty())
    {
        return "EMPTY";
    }
    return answer;
}