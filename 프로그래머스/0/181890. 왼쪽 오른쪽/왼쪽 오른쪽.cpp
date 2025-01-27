#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    for(int i =0; i<(int)str_list.size();++i)
    {
        if(str_list[i] == "l")
        {
            return vector<string>(str_list.begin(), str_list.begin() + i);
        }
        else if(str_list[i] == "r")
        {
             return vector<string>(str_list.begin()+ i + 1, str_list.end());
        }
    }
    return answer;
}