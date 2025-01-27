#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    for(int i = -1000; i<=1000;++i)
    {
        int sum = 0;
        vector<int>temp;
        for(int j = i; j < i + num;++j)
        {
            temp.push_back(j);
            sum += j;
        }
        if(sum == total)
        {
            return temp;
        }
    }
    return answer;
}