// 100. 숫자 변환하기(dfs X, bfs O) : 최단경로 / re
// https://school.programmers.co.kr/learn/courses/30/lessons/154538
#include <string>
#include <vector>
#include <queue>

using namespace std;

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