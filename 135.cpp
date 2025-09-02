// 135. 이모티콘 할인행사 (구현) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/150368
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> inUsers;
vector<int> inEmoticons;
vector<int> discounts = {10, 20, 30, 40};
pair<int, int> ans = {0, 0};

pair<int, int> simulate(const vector<int>& applied){
    int plusCnt = 0, revenue = 0;
    for(auto& user : inUsers){
        int minDiscount = user[0], limit = user[1];
        int spend = 0;
        for(int i=0; i<m; i++){
            if(applied[i] >= minDiscount){
                spend += inEmoticons[i] * (100 - applied[i]) / 100;
            }
        }
        
        if(spend >= limit){
            plusCnt++;
        }
        else{
            revenue += spend;
        }
    }
    return {plusCnt, revenue};
}

void dfs(int idx, vector<int>& applied){
    if(idx == m){
        auto [plusCnt, revenue] = simulate(applied);
        if(plusCnt > ans.first ||
           (plusCnt == ans.first && revenue > ans.second)){
            ans = {plusCnt, revenue};
        }
        return;
    }
    
    for(int d : discounts){
        applied[idx] = d;
        dfs(idx+1, applied);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    inUsers = users;
    inEmoticons = emoticons;
    n = users.size();
    m = emoticons.size();
    vector<int> applied(m);
    dfs(0, applied);
    return {ans.first, ans.second};
}