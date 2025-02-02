#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, target = nums.size() / 2;
    set<int>s(nums.begin(),nums.end());
    return min(target,(int)s.size());
}