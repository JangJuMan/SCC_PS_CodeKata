// 168. 카운트 다운 (dp) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/131129
// map으로 중복제거도 좋지만, vector로 빠르게 접근하는 게 더 빠르데
#include <string>
#include <vector>
#include <map>

using namespace std;

constexpr int maxScore = 20;
constexpr int INF = 100'001;

vector<int> solution(int target) {
    vector<pair<int, int>> dp(target+1, {INF, 0});  // {최소 다트 횟수, 싱글/볼 횟수}
    vector<pair<int, int>> validScore;
    
    for(int i=1; i<=maxScore; i++) {
        validScore.emplace_back(i, 1);
        validScore.emplace_back(i*2, 0);
        validScore.emplace_back(i*3, 0);
    }
    validScore.emplace_back(50, 1);
    
    dp[0] = {0, 0};
    for(int i=1; i<=target; i++){
        for(const auto& [score, sbSum] : validScore){
            int j = i - score;
            if(j >= 0){
                if(dp[j].first != INF){         // 안전코드
                    int newDart = dp[j].first + 1;
                    int newSb = dp[j].second + sbSum;
                    
                    if(newDart < dp[i].first){
                        dp[i] = {newDart, newSb};
                    }
                    else if(newDart == dp[i].first){
                        dp[i].second = max(dp[i].second, newSb);
                    }
                }
            }
        }
    }
    
    return {dp[target].first, dp[target].second};
}