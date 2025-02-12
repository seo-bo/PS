#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2,0);
    int pivot = brown + yellow;
    for(int i =1; i<=brown;++i)
    {
        for(int j =1; j<=i;++j)
        {
            if((i-2) * (j -2) == yellow)
            {
                if(i * j - yellow == brown)
                {
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
        }
    }
    return answer;
}