// 135. 이모티콘 할인행사 (구현) / re (2트 실패)
// https://school.programmers.co.kr/learn/courses/30/lessons/150368
#include <string>
#include <vector>

using namespace std;

/* 2트 (실패) */
array<int, 4> discounts = {10, 20, 30, 40};
vector<int> appliedDiscount;
pair<int, int> ans = {0, 0};

pair<int ,int> calcUserAndPrice(const vector<vector<int>>& users, const vector<int>& emoticons){
    int emoticonPlusUser = 0, totalPrice = 0;
    for(const auto& u : users){
        int userSpend = 0;
        for(int i=0; i<emoticons.size(); i++){
            if(appliedDiscount[i] >= u[0]){
                userSpend += emoticons[i] * (100 - appliedDiscount[i]) / 100;
            }
        }
        if(userSpend >= u[1]){
            emoticonPlusUser++;
        }
        else{
            totalPrice += userSpend;
        }
    }
    return {emoticonPlusUser, totalPrice};
}

void dfs(const vector<vector<int>>& users, const vector<int>& emoticons, int depth){
    if(depth == emoticons.size()){
        pair<int, int> res = calcUserAndPrice(users, emoticons);
        ans = max(ans, res);    // pair는 first -> second 순서로 비교함
        return;
    }
    
    for(const auto d : discounts){
        appliedDiscount[depth] = d;
        dfs(users, emoticons, depth+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons){
    // appliedDiscount.resize(emoticons.size(), 0);     // 빈 공간만 0으로 초기화 (기존값은 그대로 남아있음!)
    appliedDiscount.assign(emoticons.size(), 0);        // 기존내용 삭제 후 0으로 초기화
    dfs(users, emoticons, 0);
    return {ans.first, ans.second};
}

/* 1트 */
// int n, m;
// vector<vector<int>> inUsers;
// vector<int> inEmoticons;
// vector<int> discounts = {10, 20, 30, 40};
// pair<int, int> ans = {0, 0};

// pair<int, int> simulate(const vector<int>& applied){
//     int plusCnt = 0, revenue = 0;
//     for(auto& user : inUsers){
//         int minDiscount = user[0], limit = user[1];
//         int spend = 0;
//         for(int i=0; i<m; i++){
//             if(applied[i] >= minDiscount){
//                 spend += inEmoticons[i] * (100 - applied[i]) / 100;
//             }
//         }
        
//         if(spend >= limit){
//             plusCnt++;
//         }
//         else{
//             revenue += spend;
//         }
//     }
//     return {plusCnt, revenue};
// }

// void dfs(int idx, vector<int>& applied){
//     if(idx == m){
//         auto [plusCnt, revenue] = simulate(applied);
//         if(plusCnt > ans.first ||
//            (plusCnt == ans.first && revenue > ans.second)){
//             ans = {plusCnt, revenue};
//         }
//         return;
//     }
    
//     for(int d : discounts){
//         applied[idx] = d;
//         dfs(idx+1, applied);
//     }
// }

// vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
//     inUsers = users;
//     inEmoticons = emoticons;
//     n = users.size();
//     m = emoticons.size();
//     vector<int> applied(m);
//     dfs(0, applied);
//     return {ans.first, ans.second};
// }