// 91. 기능개발(ceil 구현, vec.back()) / RE(완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


/* 2회차 풀이. 근데 저번에 풀었던게 더 좋은듯? */
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    for(int i=0; i<progresses.size(); i++){
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];
        if(remain % speeds[i] > 0){
            day++;
        }
        q.emplace(day);
    }
    
    vector<int> ans;
    while(!q.empty()){
        int cur = q.front();
        int res = 1;
        q.pop();
        while(!q.empty() && cur >= q.front()){
            q.pop();
            res++;
        }
        ans.emplace_back(res);
    }
    return ans;
}


/* 1회차 풀이 */
// vector<int> solution(vector<int> progresses, vector<int> speeds){
//     vector<int> ans;
//     int day=0, max_day=0;
//     const float DONE = 100.0f;
//     for(int i=0; i<progresses.size(); i++){
//         day = static_cast<int>(ceil((DONE - progresses[i])/speeds[i]));
//         if(max_day < day){
//             ans.push_back(1);
//             max_day = day;
//         }
//         else{
//             ++ans.back();
//         }
//     }
//     return ans;
// }


// #include <string>
// #include <vector>
// #include <cmath>
// #include <iostream>

// using namespace std;
// constexpr float DONE = 100.0f;

// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     int n = progresses.size();
//     vector<int> days(n);
    
//     for(int i=0; i<n; ++i){
//         days[i] = static_cast<int>(ceil((DONE - progresses[i]) / speeds[i]));
//     }
    
//     vector<int> ans;
//     int prev = days[0], count=1;
//     for(int i=1; i<n; ++i){
//         if(days[i] <= prev){
//             count++;
//             continue;
//         }
//         ans.emplace_back(count);
//         count = 1;
//         prev = days[i];
//     }
//     ans.emplace_back(count);
//     return ans;
// }