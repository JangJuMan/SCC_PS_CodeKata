// 137. 양궁대회 (최적 dfs) / re (2트 실패)
// https://school.programmers.co.kr/learn/courses/30/lessons/92342
#include <string>
#include <vector>

using namespace std;

/* 2트 */
constexpr int N = 11;

vector<int> apeach(N, 0);
vector<int> ryan(N, 0);
vector<int> ans = {-1};
int maxDiff = 0;

void calcScore(){
    int rScore = 0, aScore = 0, diff = 0;
    for(int i=0; i<N; i++){
        if(ryan[i] == 0 && apeach[i] == 0) continue;    // 둘 다 0점이면 아무도 점수 획득 X
        else if(ryan[i] > apeach[i])        // ryan이 이기는 경우
            rScore += (10-i);
        else        // apeach가 이기는 경우
            aScore += (10-i);
    }
    
    diff = rScore - aScore;
    if(diff > maxDiff){     // 점수차이가 가장 크게 벌어지는 상황찾기
        maxDiff = diff;
        ans = ryan;
    }
    else if(diff == maxDiff){    // 점수차이가 같으면, 낮은 점수에 더 많은 화살을 쓴 경우를 선택
        for(int i=10; i>=0; i--){
            if(ryan[i] > ans[i]){
                ans = ryan;
                break;
            }
            else if(ans[i] > ryan[i]){
                break;
            }
            // ans[i] == ryan[i]인 경우엔 다음 점수 확인
        }
    }
}

void dfs(int cur, int arrows){
    if(cur == N){
        if(arrows > 0) ryan[10] += arrows;  // 남은 화살이 있다면 전부 0점에 쏘기 (화살 전부 써야함 + 낮은 점수 우선)
        calcScore();
        ryan[10] -= arrows; // 백트래킹을 위한 복구
        return;
    }
    
    if(arrows > apeach[cur]){       // ryan이 cur의 점수를 획득할 경우(apeach보다 화살 1개 더 쏨)
        ryan[cur] = apeach[cur] + 1;
        dfs(cur + 1, arrows - ryan[cur]);
        ryan[cur] = 0;  // 백트래킹을 위한 복구
    }
    dfs(cur + 1, arrows); // ryan이 cur의 점수를 획득하지 못하는 경우(화살 안 쏨)
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    dfs(0, n);
    return ans;
}

/* 1트 */
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