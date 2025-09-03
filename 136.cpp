// 136. 요격 시스템(Greedy) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/181188
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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