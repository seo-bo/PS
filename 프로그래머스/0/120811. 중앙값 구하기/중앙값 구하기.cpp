#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    int n = array.size();
    sort(array.begin(),array.end());
    return array[n/2];
}