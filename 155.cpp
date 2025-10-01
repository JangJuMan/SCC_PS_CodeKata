// 155. 다단계 칫솔 판매 (단순 시뮬) / 품 (근데 코드가 좀 더러움)
// https://school.programmers.co.kr/learn/courses/30/lessons/77486
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/* 인덱스 매핑 방식(빠름) */
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    vector<int> ans(n, 0);
    
    unordered_map<string, int> idx;
    for(int i=0; i<n; i++){
        idx[enroll[i]] = i;
    }
    
    vector<int> parent(n, -1);
    for(int i=0; i<n; i++){
        if(referral[i] != "-"){
            parent[i] = idx[referral[i]];
        }
    }
    
    for(int i=0; i<seller.size(); i++){
        int cur = idx[seller[i]];
        int profit = amount[i] * 100;
        
        while(cur != -1 && profit > 0){
            int give = profit / 10;
            int keep = profit - give;
            ans[cur] += keep;
            cur = parent[cur];
            profit = give;
        }
    }
    return ans;
}

/* 내 답 정리 버전(조금 느림) */
// vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
//     unordered_map<string, pair<string, int>> member;    // {parent, earn}
    
//     member["-"] = {"", 0};
//     for(int i=0; i<enroll.size(); i++){
//         member[enroll[i]] = {referral[i], 0};
//     }
    
//     for(int i=0; i<seller.size(); i++){
//         int sellAmount = amount[i] * 100;
//         string now = seller[i];
        
//         while(sellAmount > 0 && now != "-"){
//             int give = sellAmount / 10;
//             int keep = sellAmount - give;   // 남은 돈은 자기가 가짐(절사)
            
//             member[now].second += keep;
//             sellAmount = give;
//             now = member[now].first;
//         }
//     }
    
//     vector<int> ans;
//     for(string& name : enroll){
//         ans.emplace_back(member[name].second);
//     }
//     return ans;
// }


/* 내 답 */
// vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
//     unordered_map<string, pair<string, int>> member;    // first : parent, second : sell_res
    
//     member["-"].first = "";
//     member["-"].second = 0;
//     for(int i=0; i<enroll.size(); i++){
//         member[enroll[i]].first = referral[i];
//         member[enroll[i]].second = 0;
//     }
    
//     for(int i=0; i<seller.size(); i++){
//         int sellAmount = amount[i] * 100;
//         string now = seller[i];
//         do{
//             if(sellAmount < 10){
//                 member[now].second += (sellAmount);
//                 // cout << "now : " << now << " / +" << (int)sellAmount << " => " << member[now].second << endl;
//             }
//             else{
//                 member[now].second += (sellAmount - (int)(sellAmount * 0.1));
//                 // cout << "now : " << now << " / +" << (int)sellAmount * 0.9 << " => " << member[now].second << endl;
//             }
//             sellAmount -= (sellAmount*0.9);
//             now = member[now].first;        // 부모
//         }while(sellAmount > 0 && now != "-");
        
//     }
    
//     vector<int> ans;
//     for(int i=0; i<enroll.size(); i++){
//         ans.emplace_back(member[enroll[i]].second);
//     }
//     return ans;
// }