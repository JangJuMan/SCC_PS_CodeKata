// 100. 숫자 변환하기(dfs X, bfs O, dp) / re(완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/154538
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/* 2트 : dp로 풀기 */
int solution(int x, int y, int n) {
    vector<int> dp(y+1, INT_MAX);
    
    dp[x] = 0;
    for(int i=x; i<=y; ++i){
        if(dp[i] == INT_MAX) continue;
        if(i+n <= y) dp[i+n] = min(dp[i+n], dp[i]+1);
        if(i*2 <= y) dp[i*2] = min(dp[i*2], dp[i]+1);
        if(i*3 <= y) dp[i*3] = min(dp[i*3], dp[i]+1);
    }
    return (dp[y] == INT_MAX) ? -1 : dp[y]; 
}

/* 1트 : bfs로 풀기 */
int solution(int x, int y, int n) {
    vector<int> dist(y+1, -1);
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == y){
            return dist[cur];
        }
        for(int next : {cur * 2, cur * 3, cur + n}){    // for each를 이렇게 쓰는군
            if(next > y) continue;          // y를 넘어가면 스킵
            if(dist[next] != -1) continue;  // 방문한 적이 있다면 스킵
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
    return -1;
}