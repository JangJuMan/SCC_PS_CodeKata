// 93. 피로도 (backtraking)
// https://school.programmers.co.kr/learn/courses/30/lessons/87946
#include <string>
#include <vector>

using namespace std;

int ans = 0;
vector<bool> isVisited;

void dfs(int remainK, const vector<vector<int>>& dungeons, int cnt){
    ans = max(ans, cnt);
    
    for(int i=0; i<dungeons.size(); i++){
        if(!isVisited[i] && (remainK >= dungeons[i][0])){
            isVisited[i] = true;
            dfs(remainK - dungeons[i][1], dungeons, cnt+1);
            isVisited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    isVisited.resize(dungeons.size(), false);
    dfs(k, dungeons, 0);
    return ans;
}