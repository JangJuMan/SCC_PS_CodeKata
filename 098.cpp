// 98. 뒤에 있는 큰 수 찾기(오큰수, stack) / (re/re)
// https://school.programmers.co.kr/learn/courses/30/lessons/154539
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> ans(n, -1);
    stack<int> st;
    
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && numbers[i] >= st.top()){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(numbers[i]);
    }
    return ans;
}