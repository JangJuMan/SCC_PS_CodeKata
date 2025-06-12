// 48. K 번째 수
// https://school.programmers.co.kr/learn/courses/30/lessons/42748
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;
    for(const auto& cmd : commands){
        vector<int> temp(array.begin() + cmd[0] - 1, array.begin() + cmd[1]);
        sort(temp.begin(), temp.end());
        ans.push_back(temp[cmd[2]-1]);
    }
    return ans;
}