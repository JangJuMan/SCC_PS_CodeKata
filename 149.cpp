// 149. 여행경로 (DFS) / 뭐랄까... 전형적인 dfs인데, 다 찾는건 아니고 탈출조건 연습? (풀었음)
// https://school.programmers.co.kr/learn/courses/30/lessons/43164
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

/* 내 풀이 정리 */
int maxDepth;
vector<string> ans;
vector<string> path;

bool dfs(const string& now, int depth, unordered_map<string, vector<pair<string, bool>>>& ticketList){
    if(depth == maxDepth){
        ans = path;
        return true;
    }
    
    for(int i=0; i<ticketList[now].size(); i++){
        auto& next = ticketList[now][i];
        if(!next.second){
            next.second = true;
            path.emplace_back(next.first);
            if(dfs(next.first, depth+1, ticketList))
                return true;
            next.second = false;
            path.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    maxDepth = tickets.size();
    sort(tickets.begin(), tickets.end());
    
    unordered_map<string, vector<pair<string, bool>>> ticketList;
    for(const auto& t : tickets){
        ticketList[t[0]].push_back({t[1], false});
    }
    
    path.emplace_back("ICN");
    dfs("ICN", 0, ticketList);
    
    return ans;
}


// // gpt 버전
// vector<string> ans;
// vector<bool> used;

// bool dfs(const string& cur, vector<vector<string>>& tickets, vector<string>& path, int depth){
//     if(depth == tickets.size()){    // 모든 티켓을 다 사용했으면 답 확정
//         ans = path;
//         return true;
//     }
    
//     for(int i=0; i<tickets.size(); i++){        // 흠... 모든 티켓을 돌면서 선형적으로 검색한다..? 비효율인데
//         if(!used[i] && tickets[i][0] == cur){    
//             used[i] = true;
//             path.push_back(tickets[i][1]);
            
//             if(dfs(tickets[i][1], tickets, path, depth+1))  // 첫 해답이 사전순 최소
//                 return true;
            
//             path.pop_back();
//             used[i] = false;
//         }
//     }
//     return false;
    
// }

// vector<string> solution(vector<vector<string>> tickets) {
//     sort(tickets.begin(), tickets.end());   // 2차원 벡터도 이렇게 정렬이 되네;;;
    
//     used.assign(tickets.size(), false);      // 아 ticket을 1차원으로 해석하는 느낌스..!
    
//     vector<string> path;
//     path.emplace_back("ICN");               // 무조건 출발은 ICN부터
    
//     dfs("ICN", tickets, path, 0);
//     return ans;
// }
