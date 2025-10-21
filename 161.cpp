// 161. 미로 탈출 명령어(dfs, pruning-가지치기) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/150365
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dr[4] = {1, 0, 0, -1};  // d l r u 순서(사전순 정렬)
int dc[4] = {0, -1, 1, 0};
char dir[4] = {'d', 'l', 'r', 'u'}; // string으로 해도 될 듯
bool found = false;
string ans = "";

void dfs(int depth, int n, int m, int curR, int curC, int r, int c, int k, string& path){
    if(found)   return;
    
    int remain = k - depth;
    int dist = abs(r - curR) + abs(c - curC);
    
    if(dist > remain)   return;         // 남은 이동으로는 도달 불가능한 경우
    if((remain - dist)%2 != 0) return;  // 이동 횟수 짝이 안맞는 경우 (절대 통과 안할 듯..?)
    
    if(depth == k){
        if(curR == r && curC == c){
            ans = path;
            found = true;
        }
        return;
    }
    
    for(int i=0; i<4; i++){
        int nR = curR + dr[i];
        int nC = curC + dc[i];
        if(nR < 1 || nR > n || nC < 1 || nC > m)    continue;
        
        path.push_back(dir[i]);
        dfs(depth+1, n, m, nR, nC, r, c, k, path);
        if(found)   return;
        path.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int minDist = abs(x - r) + abs(y - c);
    if(minDist > k || (k - minDist)%2 != 0)
        return "impossible";
    
    string path = "";
    dfs(0, n, m, x, y, r, c, k, ans);
    
    if(!found)   return "impossible";   // 여기도 통과할 일이 없을건데
    return ans;
}