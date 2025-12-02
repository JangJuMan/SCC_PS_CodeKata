// 101. 2개 이하로 다른 비트(bitmask) / re(완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/77885
#include <string>
#include <vector>
#include <bitset>

using namespace std;

/* 2트 */
vector<long long> solution(vector<long long> numbers) {
    vector<long long> ans;
    for(long long n : numbers){
        if(n & 1){  // 끝자리 1
            long long bits = 1;
            while((n & bits) != 0){ // n의 bits 비트가 0일때까지 반복
                bits <<= 1;
            }
            // 이 시점에서 bits 비트부터 01 패턴이 됨
            ans.emplace_back(n + (bits >> 1));  // = n + bits - (bits >> 1)
        }
        else{       // 끝자리 0
            ans.emplace_back(n+1);
        }
    }
    return ans;
}

// // 이게 제일 이해 잘되긴 하네
// vector<long long> solution(vector<long long> numbers) {
//     vector<long long> ans;
//     for(long long n : numbers){
//         if(n & 1){
//             long long bits = 1;
//             while((n & bits) > 0){
//                 bits <<= 1;
//             }
//             ans.emplace_back(n + (bits >> 1));  // 짝수일 때도 동일하게 적용하기 위함(n + bits - (bits >> 1))
//         }
//         else{
//             ans.emplace_back(n+1);
//         }
//     }
//     return ans;
// }


// gpt 왈. 이게 뭔말이지..?
// vector<long long> solution(vector<long long> numbers) {
//     vector<long long> ans;
//     for(long long num : numbers){
//         if(num & 1){
//             // 홀수: f(x) = x + (x ^ (x + 1)) >> 2 + 1
//             // 1. (x ^ (x+1)) : 자리 올림이 어디까지 일어나는지 표시해주는 비트마스크
//             // 2. >> 2 : 2 비트 차이만 허용하므로 2칸 쉬프트
//             // 3. +1 : 실제로 2개 다른 수 중 최소값을 얻기 위함
//             long long t = ((num ^ (num+1)) >> 2) + 1;
//             ans.emplace_back(num + t);
//         }
//         else{
//             ans.emplace_back(num + 1);
//         }
//     }
//     return ans;
// }

// brout force
// vector<long long> solution(vector<long long> numbers) {
//     vector<long long> ans;
//     for(long long num : numbers){
//         for(long long i=num+1; i<100000000000000; ++i){
//             bitset<50> bits(num ^ i);
//             if(bits.count() == 1 || bits.count() == 2){
//                 ans.emplace_back(i);
//                 break;
//             }
//         }
//     }
//     return ans;
// }