// 160. 110 옮기기(string, 구현) / re. 멍청한 gpt
// https://school.programmers.co.kr/learn/courses/30/lessons/77886
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> s){
    vector<string> ans;
    
    for(const auto& str : s){
        string insertStr = "";
        string remain = "";
        
        for(int i=0; i<str.size(); i++){
            remain += str[i];
            if(remain.size() >= 3){
                if(remain.substr(remain.size() - 3) == "110"){
                    remain.erase(remain.size() - 3, 3);
                    insertStr += "110";
                }
            }
        }
        
        int pos = 0;
        for(int i=remain.size()-1; i>=0; i--){
            if(remain[i] == '0'){
                pos = i+1;
                break;
            }
        }
        
        ans.emplace_back(remain.substr(0, pos) + insertStr + remain.substr(pos));
    }
    return ans;
}


// gpt왈 성능우선 (근데 이건너무 에바인듯)
// string process(const string& s){
//     stack<char> st;
//     int cnt110 = 0;
    
//     for(char ch : s){    // 110 패턴 제거
//         st.push(ch);
//         int len = st.size();
//         if(len >= 3){
//             char a = st.top();  st.pop();
//             char b = st.top();  st.pop();
//             char c = st.top();  st.pop();
//             if(c == '1' && b == '1' && a == '0'){
//                 cnt110++;
//             }
//             else{   // 110패턴 아니라면 복구
//                 st.push(c);
//                 st.push(b);
//                 st.push(a);
//             }
//         }
//     }
    
//     string remain;
//     while(!st.empty()){ // 남은 문자열 복원
//         remain += st.top();
//         st.pop();
//     }
//     reverse(remain.begin(), remain.end());
    
//     int pos = 0;
//     for(int i=remain.size()-1; i>=0; i--){  // 110 삽입 위치 찾기 (마지막 연속된 1 뒤)
//         if(remain[i] == '0'){
//             pos = i+1;
//             break;
//         }
//     }
    
//     // 결과 문자열 생성
//     string insertStr = "";
//     while(cnt110--){
//         insertStr += "110";
//     }
    
//     return remain.substr(0, pos) + insertStr + remain.substr(pos);   
// }

// vector<string> solution(vector<string> s) {
//     vector<string> ans;
//     ans.reserve(s.size());
//     for(const auto& str : s){
//         ans.push_back(process(str));
//     }
//     return ans;
// }