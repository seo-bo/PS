#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    set<int>s;
    for(int i =0; i<n;++i)
    {
        for(int j = i+1; j < n;++j)
        {
            s.insert(numbers[i] + numbers[j]);
        }
    }
    answer = vector<int>(s.begin(),s.end());
    return answer;
}