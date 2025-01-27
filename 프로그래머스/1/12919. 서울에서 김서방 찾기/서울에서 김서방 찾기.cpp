#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    string temp = "에 있다";
    for(int i =0; i<(int)seoul.size();++i)
    {
        if(seoul[i] == "Kim")
        {
            return answer + to_string(i) + temp;
        }
    }
    return answer;
}