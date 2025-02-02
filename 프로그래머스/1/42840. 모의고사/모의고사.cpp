#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>p1 = {1,2,3,4,5}, p2 = {2,1,2,3,2,4,2,5}, p3 = {3,3,1,1,2,2,4,4,5,5};
    int i =0, j = 0, k = 0;
    vector<int>score(3);
    for(auto & _ : answers)
    {
        if(p1[i] == _)
        {
            score[0]++;
        }
        if(p2[j] == _)
        {
            score[1]++;
        }
        if(p3[k] == _)
        {
            score[2]++;
        }
        i = (i+1) % (int)p1.size(); 
        j = (j+1) % (int)p2.size(); 
        k = (k+1) % (int)p3.size(); 
    }
    int maxi = *max_element(score.begin(),score.end());
    for(int i =0; i<3;++i)
    {
        if(maxi == score[i])
        {
            answer.push_back(i+1);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}