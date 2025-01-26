#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = INT_MIN, n =numbers.size();
    for(int i =0; i<n;++i)
    {
        for(int j =i+1; j<n;++j)
        {
            answer = max(answer, numbers[i] * numbers[j]);
        }
    }
    return answer;
}