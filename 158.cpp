// 158. 인사고과(정렬 활용) / re (이런 방식을 생각하기 어렵네)
// https://school.programmers.co.kr/learn/courses/30/lessons/152995
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    auto wanho = scores[0];
    int wanhoScore = scores[0][0] + scores[0][1];
    
    sort(scores.begin(), scores.end(), [](const auto& a, const auto& b){
        if(a[0] == b[0])    return a[1] < b[1];
        return a[0] > b[0];
    });
    
    int curMax = -1;
    vector<int> incentiveList;
    for(const auto& s : scores){
        if(s[1] >= curMax){     // 인센티브 대상에 추가
            incentiveList.emplace_back(s[0] + s[1]);
            curMax = max(curMax, s[1]);
        }
        else{   // 인센티브 대상에서 탈락
            if(s == wanho)      // 탈락 대상이 완호면 바로 리턴
                return -1;
        }
    }
    
    int ans = 1;
    for(const auto& i : incentiveList){
        if(i > wanhoScore){
            ans++;
        }
    }
    return ans;
}