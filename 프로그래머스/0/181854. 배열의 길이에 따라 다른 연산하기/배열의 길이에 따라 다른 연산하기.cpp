#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    int len = arr.size();
    for(int i =0; i <len;++i)
    {
        if(len %2 && i %2 == 0)
        {
            arr[i] += n;
        }
        else if (len %2 == 0 && i % 2)
        {
            arr[i] += n;
        }
    }
    return arr;
}