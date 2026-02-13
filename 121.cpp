// 121. 시소 짝꿍(구현, 수학계산) / re (2트 실패)
// https://school.programmers.co.kr/learn/courses/30/lessons/152996
#include <string>
#include <vector>
#include <map>

using namespace std;

// 시간복잡도 안될거같으면 바로 다른 풀이로 변경하기 (N^2를 더 팔 필요가 없음)
/* 2트 */
long long solution(vector<int> weights) {
    // vector<long long> w_counts(1001, 0);    // 고정크기 배열이라 array가 더 빠름
    array<long long, 1001> w_counts{0};
    
    for(const auto& w : weights){
        w_counts[w]++;
    }
    
    long long ans = 0;
    for(int i=100; i<=1000; i++){
        if(w_counts[i] == 0) continue;
        
        long long count = w_counts[i];
        if(count > 1){    // 1:1 비율 -> 자기 자신과의 조합 (nC2 = n(n-1) / 2)
            ans += count * (count-1) / 2;
        }
        
        if(i%2 == 0 && i*3/2 <= 1000){      // 2:3 비율
            ans += count * w_counts[i*3/2];
        }
        
        if(i%3 == 0 && i*4/3 <= 1000){      // 3:4 비율
            ans += count * w_counts[i*4/3];
        }
        
        if(i*2 <= 1000){        // 2:4 비율
            ans += count * w_counts[i*2];
        }
    }
    return ans;
}

/* 1트 */
// long long solution(vector<int> weights) {
//     long long ans = 0;
//     map<int, int> weight_counts;
    
//     for(int weight : weights){
//         weight_counts[weight]++;
//     }
    
//     for(const auto& [weight, count] : weight_counts){
//         if(count > 1){          // 1:1 비율일 경우
//             ans += (long long)count * (count - 1) / 2;  // nC2
//         }
        
//         if(weight % 2 == 0){    // 2:3 비율일 경우 
//             int target_weight = weight/2*3;
//             if(weight_counts.count(target_weight)){
//                 ans += (long long)count * weight_counts[target_weight];
//             }
//         }
        
//         if(weight % 3 == 0){    // 3:4 비율일 경우
//             int target_weight = weight/3*4;
//             if(weight_counts.count(target_weight)){
//                 ans += (long long)count * weight_counts[target_weight];
//             }
//         }
        
//         int target_weight = weight * 2; // 1:2 비율일 경우
//         if(weight_counts.count(target_weight)){
//             ans += (long long)count * weight_counts[target_weight];
//         }
//     }
//     return ans;
// }