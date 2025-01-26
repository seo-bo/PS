#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int n = numbers.size();
    int answer = 0;
    for(int i =0; i<n;++i)
    {
        for(int j =i+1; j<n;++j)
        {
            answer = max(answer, numbers[i] * numbers[j]);
        }
    }
    return answer;
}