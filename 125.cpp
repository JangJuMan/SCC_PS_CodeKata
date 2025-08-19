// 125. 혼자 놀기의 달인 (dfs, 구현, 최대값 2개, priority_queue) / 깔끔하게 잘 푼듯?
// https://school.programmers.co.kr/learn/courses/30/lessons/131130
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dfs(const vector<int>& cards, vector<bool>& visited, int index, int count){
    if(visited[index]){
        return count;
    }
    visited[index] = true;
    int nextIndex = cards[index] - 1;
    return dfs(cards, visited, nextIndex, count+1);
}

int solution(vector<int> cards) {
    int n = cards.size();
    vector<bool> visited(n, false);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.emplace(0);  // 사이클이 1개만 나올 경우 대비
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int groupElemCnt = dfs(cards, visited, i, 0);
            pq.emplace(groupElemCnt);
        }
        if(pq.size() > 2){
            pq.pop();
        }
    }
    
    int max1 = pq.top(); pq.pop();
    int max2 = pq.top();
    return max1 * max2;
}