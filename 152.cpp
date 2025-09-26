// 152. 가장 긴 팬린드롬 (마나커 알고리즘) / re... 와 O(n)으로 풀어진다고?
// Manacher's Algorithm : https://www.youtube.com/watch?v=gSCH1Ofd9Pg
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 최적 답 O(n) : 사실 아직 이해가 잘 안돼 */
int solution(string s) {
    int n = s.size();
    
    string t = "#"; // 전처리 : 문자 사이에 # 삽입
    for(char c : s){
        t += c;
        t += "#";
    }
    
    int m = t.size();
    vector<int> p(m, 0);    // 각 중심에서의 반지름
    int center=0, right=0, ans=0;
    
    for(int i=0; i<m; i++){
        int mirror = 2*center - i;
        if(i < right){
            p[i] = min(right - i, p[mirror]);
        }
        
        // 중심 확장
        while(i-1-p[i] >= 0 && i+1+p[i] < m &&
             t[i-1-p[i]] == t[i+1+p[i]]){
            p[i]++;
        }
        
        // 오른쪽 경계 갱신
        if(i + p[i] > right){
            center = i;
            right = i + p[i];
        }
        
        ans = max(ans, p[i]);
    }
    return ans;
}

// /* 정리된 답 O(n^2) */
// int expandFromCenter(const string& s, int l, int r){
//     while(0 <= l && r < s.size() && s[left] == s[right]){
//         l--;
//         r++;
//     }
//     return r - l - 1;   // 실제 팰린드롬 길이
// }

// int solution(string s) {
//     int n = s.size();

//     int ans = 1;
//     for(int i=0; i<n; i++){
//         ans = max(ans, expandFromCenter(s, i, i));      // 홀수길이 (i를 중심으로)
//         ans = max(ans, expandFromCenter(s, i, i+1));    // 짝수길이 (i, i+1을 중심으로)
//     }
//     return ans;
// }
    
    
// /* 빠른 제출 O(n^2) */
// int solution(string s) {
//     int ans = 0, tmp = 1, left = 0, right = 0;
//     for(int i=0; i<s.size(); i++){
//         left = i-1;
//         right = i+1;
//         tmp = 1;
//         while(0 <= left && right < s.size() && s[left] == s[right]){
//             left--;
//             right++;
//             tmp += 2;
//         }
//         ans = max(ans, tmp);
        
//         left = i-1;
//         right = i;
//         tmp = 0;
//         while(0 <= left && right < s.size() && s[left] == s[right]){
//             left--;
//             right++;
//             tmp+=2;
//         }
//         ans = max(ans, tmp);
//     }
//     return ans;
// }