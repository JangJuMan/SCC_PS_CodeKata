// 88. 행렬의 곱셈(구현) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/12949
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = arr1.size();
    int m = arr2[0].size();
    int k = arr1[0].size();
    
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int t=0; t<k; t++){
                ans[i][j] += arr1[i][t] * arr2[t][j];
            }
        }
    }
    return ans;
}

  