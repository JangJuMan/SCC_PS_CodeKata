// 107. 큰 수 만들기(스택(벡터), 그리디) / re(re..? 풀긴했어)
// https://school.programmers.co.kr/learn/courses/30/lessons/42883#
#include <string>
#include <vector>

using namespace std;


/* 2트 코드정리 */
string solution(string number, int k) {
    string ans = "";
    int toRemove = k;
    
    for(const char& c : number){
        while(!ans.empty() && toRemove > 0 && ans.back() < c){
            ans.pop_back();
            toRemove--;
        }
        ans += c;
    }
    
    while(toRemove > 0){
        ans.pop_back();
        toRemove--;
    }
    return ans;
}

/* 2트 성공... 인데 코드 더러움 */
string solution(string number, int k) {
    string ans = "";
    int cnt = k, i=1;
    
    ans += number[0];
    while(cnt > 0){
        if(ans.size() > 0 && ans.back() < number[i]){
            cnt--;
            ans.pop_back();
            if(cnt == 0) break;
        }
        else{
            ans += number[i];
            i++;    
        }
    }
    if(i < number.size()){
        ans += number.substr(i);
    }
    return ans.substr(0, number.size() - k);
}

/* 1트 */
string solution(string number, int k) {
    vector<char> st;
    int toRemove = k;
    for(char c : number){
        while(!st.empty() && toRemove > 0 && st.back() < c){
            st.pop_back();
            toRemove--;
        }
        st.emplace_back(c);
    }
    while(toRemove > 0){
        st.pop_back();
        toRemove--;
    }
    return string(st.begin(), st.end());
}