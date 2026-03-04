// 136. 요격 시스템(Greedy) / re (2트 실패)
// https://school.programmers.co.kr/learn/courses/30/lessons/181188
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 2트(시작점 정렬 방법도 있긴 함)*/
int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](const auto& a, const auto& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    int ans = 1, start = targets[0][0], end = targets[0][1];
    for(int i=1; i<targets.size(); i++){
        int s = targets[i][0], e = targets[i][1];
        if(end <= s){
            ans++;
            start = s;
            end = e;
        }
        else if(e < end){
            end = e;
        }
    }
    return ans;
}

/* 1트 */
int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](auto& a, auto& b){
        return a[1] < b[1];
    });
    
    int ans = 0;
    int last = -1;
    
    for(const auto& t : targets){
        int s = t[0], e = t[1];
        if(last <= s){
            ans++;
            last = e;
        }
    }
    return ans;
}