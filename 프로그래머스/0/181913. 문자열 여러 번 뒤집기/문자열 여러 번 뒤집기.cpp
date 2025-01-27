#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    for(auto & i : queries)
    {
        int left = i[0], right = i[1];
        while(left < right)
        {
            swap(my_string[left++],my_string[right--]);
        }
    }
    return my_string;
}