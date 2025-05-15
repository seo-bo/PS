#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size();
    int l = 0, r = n-1;
    int left = 0, sum =0;
    for(int i =0; i<n;++i)
    {
        sum += sequence[i];
        while(left <= i && sum > k)
        {
            sum -= sequence[left++];
        }
        if(sum == k)
        {
            if(r - l > i - left)
            {
                l = left;
                r = i;
            }
        }
    }
    answer.push_back(l);
    answer.push_back(r);
    return answer;
}