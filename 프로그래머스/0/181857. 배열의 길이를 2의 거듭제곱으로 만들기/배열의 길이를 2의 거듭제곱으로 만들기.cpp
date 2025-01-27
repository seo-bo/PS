#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int n = arr.size();
    int pivot = 1;
    while(pivot < n)
    {
        pivot <<= 1;
    }
    while(arr.size() < pivot)
    {
        arr.push_back(0);
    }
    return arr;
}