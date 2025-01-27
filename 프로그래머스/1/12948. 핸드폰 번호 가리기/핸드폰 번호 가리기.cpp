#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int len = phone_number.size();
    string answer = string(len,'*');
    for(int i = len-1; i>len-5;--i)
    {
        answer[i] = phone_number[i];
    }
    return answer;
}