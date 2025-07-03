// 84. 괄호 회전하기(스택)
// https://school.programmers.co.kr/learn/courses/30/lessons/76502
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s){
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else{
            if(st.empty())  return false;
            char t = st.top();
            if(c == ')' && st.top() != '(' ||
               c == '}' && st.top() != '{' ||
               c == ']' && st.top() != '[' ){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int solution(string s) {
    int ans=0;
    for(int i=0; i<s.size(); i++){
        string rotated = s.substr(i) + s.substr(0, i);
        if(isValid(rotated)){
            ans++;
        }
    }
    return ans;
}