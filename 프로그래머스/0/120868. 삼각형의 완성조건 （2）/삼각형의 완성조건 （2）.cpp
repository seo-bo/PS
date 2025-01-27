#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    for(int i =1;;++i)
    {
        vector<int>temp = {sides[0],sides[1],i};
        sort(temp.begin(),temp.end());
        if(temp[2] < temp[1] + temp[0])
        {
            answer++;
        }
        else
        {
            if(temp[2] == i)
            {
                break;
            }
        }
    }
    return answer;
}