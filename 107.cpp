// 107. 큰 수 만들기(스택(벡터), 그리디) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/42883#
#include <string>
#include <vector>

using namespace std;

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