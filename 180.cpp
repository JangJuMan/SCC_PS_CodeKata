// 180. 에어컨 (dfs, dp) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/214289
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> dp(1001, vector<int>(51, INT_MAX));
int initTemp, _t1, _t2, _a, _b, ans=INT_MAX;

void dfs(const vector<int>& onboard, int curTemp, int curIndex, int curCost){
    if(curIndex == onboard.size()){
        ans = min(ans, curCost);
        return;
    }
    
    if(onboard[curIndex] == 1 && (curTemp < _t1 || _t2 < curTemp)) return;
    if(curCost >= dp[curIndex][curTemp]) return;
    
    dp[curIndex][curTemp] = curCost;
    
    // 에어컨을 끌 수 있는 경우를 먼저 고려해야 시간초과가 안걸리네(가지치기 - cost가 적은거 부터 해야할듯)
    dfs(onboard, min(curTemp+1, initTemp), curIndex+1, curCost);       // 에어컨 끄기(외부온도까지만 기온상승)
    dfs(onboard, curTemp, curIndex+1, curCost+_b);      // 에어컨 유지
    dfs(onboard, curTemp-1, curIndex+1, curCost+_a);    // 에어컨 켜기
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    initTemp=temperature, _t1=t1; _t2=t2; _a=a; _b=b;
    
    if(initTemp < t1){  // 온도 차이가 중요한 거라, 항상 온도를 내리는 방식으로 통일하기 위함
        initTemp = (t1 - initTemp) + t2;  // 온도 차이만큼 시작 온도를 벌려놓고 시작
    }
    
    dfs(onboard, initTemp, 0, 0);
    return ans;
}