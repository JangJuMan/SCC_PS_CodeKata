// 37. 행렬의 덧셈
// https://school.programmers.co.kr/learn/courses/30/lessons/12950
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> ans(arr1.size(), vector<int>(arr1[0].size()));
    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr1[i].size(); j++){
            ans[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return ans;
}