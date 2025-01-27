#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i =1; i<(int)food.size();++i)
    {
        food[i] /= 2;
        for(int j = 0; j<food[i];++j)
        {
            answer += to_string(i);
        }
    }
    string tt = answer;
    answer += "0";
    reverse(tt.begin(),tt.end());
    return answer + tt;
}