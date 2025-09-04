// 137. 양궁대회 (최적 dfs) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/92342
#include <string>
#include <vector>

using namespace std;

vector<int> apeach(11, 0);
vector<int> ryan(11, 0);
vector<int> ans = {-1};
int maxDiff = 0;

int getDiff(){
    int ryanScore = 0, apeachScore = 0;
    for(int i=0; i<11; i++){
        if(ryan[i] == 0 && apeach[i] == 0) continue;
        if(ryan[i] > apeach[i]) ryanScore += (10-i);
        else    apeachScore += (10-i);
    }
    return ryanScore - apeachScore;
}

void dfs(int currPoint, int arrows){
    if(currPoint == 11){
        if(arrows > 0)  ryan[10] += arrows; // 남은 화살 0점에 전부 쏘기
        
        int diff = getDiff();
        if(diff > maxDiff){
            maxDiff = diff;
            ans = ryan;
        }
        else if(diff == maxDiff){
            for(int i=10; i>=0; i--){   // 낮은 점수를 더 많이 맞힌 경우를 선택
                if(ryan[i] > ans[i]){
                    ans = ryan;
                    break;
                }
                else if(ryan[i] < ans[i]){
                    break;
                }
                // 같을 경우엔 다음 점수 확인
            }
        }
        if(arrows > 0) ryan[10] -= arrows;  // 0점에 쏜 화살 있으면 회수
        return;
    }
    
    // 쏘거나(남은 화살로 점수를 얻을 수 있는 경우)
    if(arrows > apeach[currPoint]){
        ryan[currPoint] = apeach[currPoint] + 1;
        dfs(currPoint+1, arrows - ryan[currPoint]);
        ryan[currPoint] = 0;    // 복구
    }
    
    // 쏘지 않거나
    dfs(currPoint+1, arrows);
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    dfs(0, n);
    return ans;
}