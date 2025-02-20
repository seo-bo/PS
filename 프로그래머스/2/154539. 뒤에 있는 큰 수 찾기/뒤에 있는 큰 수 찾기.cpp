#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int>s;
    int n = (int)numbers.size();
    vector<int> answer(n);
    for(int i = n-1; i>=0;--i)
    {
        while(!s.empty() && numbers[i] >= s.back())
        {
            s.pop_back();
        }
        if(s.empty())
        {
            answer[i] = -1;
        }
        else
        {
            answer[i] = s.back();
        }
        s.push_back(numbers[i]);
    }
    return answer;
}