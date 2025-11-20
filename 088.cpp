// 88. 행렬의 곱셈(구현) / re(완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/12949
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = arr1.size();
    int m = arr1[0].size();
    int l = arr2[0].size();
    vector<vector<int>> ans(n, vector<int>(l, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<l; j++){
            for(int k=0; k<m; k++){
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return ans;
    
}