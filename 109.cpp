// 109. 연속된 부분 수열의 합(슬라이딩 윈도우, 투포인터) / re(완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/178870#
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 2트 */
vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0, right = 0, sum = sequence[0];
    vector<int> ans = {0, n-1};
    
    while(left <= right && right < n){
        if(sum == k){
            if((ans[1] - ans[0]) > (right - left)){
                ans[0] = left;
                ans[1] = right;
            }
            sum -= sequence[left++];
        }
        else if(sum < k){
            if(++right < n){    // out of range 방지
                sum += sequence[right];
            }
        }
        else if(sum > k){
            sum -= sequence[left++];
        }
    }
    return ans;   
}

/* 1트 */
vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0, right = 0;
    int sum = sequence[0];
    vector<int> ans = {0, n-1};
    
    while(left <= right && right < n){
        if(sum < k){
            right++;
            if(right < n){
                sum += sequence[right];
            }
        }
        else if(sum > k){
            sum -= sequence[left];
            left++;
            if(right < left && left < n){
                right = left;
                sum = sequence[left];
            }
        }
        else if(sum == k){
            if((right - left) < (ans[1] - ans[0])){
                ans[0] = left;
                ans[1] = right;
            }
            
            sum -= sequence[left++];
            if(right < left && left < n){
                right = left;
                sum = sequence[left];
            }
        }
    }
    return ans;
}

// 역순 풀이
// vector<int> solution(vector<int> sequence, int k) {
//     int n = sequence.size();
//     int l = n-1, r = n-1;
//     long long sum = sequence[r];
//     vector<int> ans = {-1, n};
//     while(0 <= l && l <= r){
//         // cout << "l / r / sum / ans : " << l << " " << r << " " << sum << " " << ans[0] << " " << ans[1] << endl;
//         if(sum == k){
//             // cout << "SUM == K\n";
//             if(r - l <= ans[1] - ans[0]){
//                 ans[0] = l;
//                 ans[1] = r;
//             }
//         }
//         if(sum <= k){
//             l--;
//             if(l >= 0){
//                 sum += sequence[l];
//             }
//         }
//         else if(sum > k){
//             if(l == r){
//                 sum += sequence[--l];
//             }
//             sum -= sequence[r--];
//         }
//     }
//     return ans;
// }