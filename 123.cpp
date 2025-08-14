// 123. 하노이의 탑 (재귀, Divide & Conquer) / 풀긴 했다만, 괜찮은 접근이었
// https://school.programmers.co.kr/learn/courses/30/lessons/12946#
#include <string>
#include <vector>

using namespace std;

void dfs(int n, int from, int to, int another, vector<vector<int>>& ans){
    if(n == 1){
        ans.push_back({from, to});
        return;
    }
    
    dfs(n-1, from, another, to, ans);
    ans.push_back({from, to});
    dfs(n-1, another, to, from, ans);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> ans(0);    
    dfs(n, 1, 3, 2, ans);
    return ans;
}