// 121. 시소 짝꿍(구현, 수학계산) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/152996
#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long ans = 0;
    map<int, int> weight_counts;
    
    for(int weight : weights){
        weight_counts[weight]++;
    }
    
    for(const auto& [weight, count] : weight_counts){
        if(count > 1){          // 1:1 비율일 경우
            ans += (long long)count * (count - 1) / 2;  // nC2
        }
        
        if(weight % 2 == 0){    // 2:3 비율일 경우 
            int target_weight = weight/2*3;
            if(weight_counts.count(target_weight)){
                ans += (long long)count * weight_counts[target_weight];
            }
        }
        
        if(weight % 3 == 0){    // 3:4 비율일 경우
            int target_weight = weight/3*4;
            if(weight_counts.count(target_weight)){
                ans += (long long)count * weight_counts[target_weight];
            }
        }
        
        int target_weight = weight * 2; // 1:2 비율일 경우
        if(weight_counts.count(target_weight)){
            ans += (long long)count * weight_counts[target_weight];
        }
    }
    return ans;
}