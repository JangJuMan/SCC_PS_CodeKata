// 129. 우박수열 정적분 (구현) / 품
// https://school.programmers.co.kr/learn/courses/30/lessons/134239
#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> collatz;
    int current_k = k;
    collatz.emplace_back(current_k);
    
    // 우박수열 생성
    while(current_k != 1){
        if(current_k & 1){  // 홀수라면
            current_k = current_k * 3 + 1;
        }
        else{               // 짝수라면
            current_k /= 2;
        }
        collatz.emplace_back(current_k);
    }
    
    int n = collatz.size() - 1;
    
    // 사다리꼴 넓이 미리 계산 ((밑별 + 윗변) * 높이 / 2)
    vector<double> areas(n, 0.0);
    for(int i=0; i<n; i++){
        areas[i] = static_cast<double>(collatz[i] + collatz[i+1]) * 1.0 / 2.0;
    }
    
    // range에 따라 정적분 결과 계산
    vector<double> ans;
    for(const auto& range : ranges){
        int from = range[0];
        int to = n + range[1];  // 조건 : -200 < b <= 0
        
        if(from > to){
            ans.emplace_back(-1.0);
        }
        else if(from == to){
            ans.emplace_back(0.0);
        }
        else{
            double res = accumulate(areas.begin() + from, areas.begin() + to, 0.0);
            ans.emplace_back(res);
        }
    }
    
    return ans;
}