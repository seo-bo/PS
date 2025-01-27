#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = INT_MAX;
    int pivot = INT_MAX;
    for(auto & i : array)
    {
        if(abs(i - n) < pivot)
        {
            pivot = abs(i-n);
            answer = i;         
        }
        else if (abs(i-n) == pivot)
        {
            answer = min(answer, i);
        }
    }
    return answer;
}