// 132. 과제 진행하기 (스택, 시뮬레이션) / 풀긴했는데, 음 다시?
// https://school.programmers.co.kr/learn/courses/30/lessons/176962
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

// /* 다른 풀이 */
// struct Plan{
//     string name;
//     int start;
//     int play;
// };

// int toMinutes(const string& t){
//     int h = stoi(t.substr(0, 2));
//     int m = stoi(t.substr(3, 2));
//     return h * 60 + m;
// }

// vector<string> solution(vector<vector<string>> plans) {
//     vector<Plan> arr;
//     for(const auto& plan : plans){
//         arr.push_back({plan[0], toMinutes(plan[1]), stoi(plan[2])});
//     }
    
//     sort(arr.begin(), arr.end(), [](const Plan& a, const Plan& b){
//         return a.start < b.start;
//     });
    
//     vector<string> ans;
//     stack<pair<string, int>> st;
    
//     for(int i=0; i<arr.size()-1; i++){
//         auto [name, start, play] = arr[i];
//         int nextStart = arr[i+1].start;
//         int available = nextStart - start;
        
//         if(play <= available){  // 과제를 다 끝냄
//             ans.push_back(name);
//             available -= play;
            
//             while(available > 0 && !st.empty()){    // 스택에 있는 중단 과제 처리
//                 auto [prevName, remain] = st.top();
//                 st.pop();
                
//                 if(remain <= available){    // 남은 과제도 처리할 수 있는 경우
//                     ans.push_back(prevName);
//                     available -= remain;
//                 }
//                 else{   // 남은 과제를 처리하지 못하는 경우
//                     st.push({prevName, remain - available});
//                     break;
//                 }
//             }
//         }
//         else{   // 과제를 다 못끝냄 -> 남은시간 저장
//             st.push({name, play - available});
//         }
//     }
    
//     ans.push_back(arr.back().name); // 마지막 과제는 무조건 완료
    
//     while(!st.empty()){     // 스택에 남은 과제 모두 처리
//         ans.push_back(st.top().first);
//         st.pop();
//     }
//     return ans;
// }

/* 나의 풀이(개선) */
struct Plan{
    string name;
    int start, play;
    Plan(string n, int s, int p) : name(n), start(s), play(p){}   // emplace_back을 위해
};

int time_to_int(const string& time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<Plan> sorted_plans;
    for(const auto& plan : plans){
        sorted_plans.emplace_back(plan[0], time_to_int(plan[1]), stoi(plan[2]));
    }
    sort(sorted_plans.begin(), sorted_plans.end(), [](const Plan& a, const Plan& b){
        return a.start < b.start;
    });
    
    stack<Plan> st;
    vector<string> ans;
    for(const auto& plan : sorted_plans){
        if(st.empty()){
            st.emplace(plan);
            continue;
        }
        Plan curr = st.top(); st.pop();
        int diff_time = plan.start - curr.start;
        
        while(!st.empty() && (diff_time > curr.play)){
            diff_time -= curr.play;
            ans.emplace_back(curr.name);    // 정답 추가
            curr = st.top(); st.pop();
        }
        
        curr.play -= diff_time;
        if(curr.play > 0)  st.emplace(curr);
        else    ans.emplace_back(curr.name);
        
        st.emplace(plan);
    }
    
    while(!st.empty()){
        Plan curr = st.top(); st.pop();
        ans.emplace_back(curr.name);
    }
    return ans;
}