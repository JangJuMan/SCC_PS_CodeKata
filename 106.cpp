// 106. 택배상자(스택) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/131704
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int idx=0;
    stack<int> st;
    
    for(int i=1; i<=order.size(); i++){
        st.emplace(i);
        
        while(!st.empty() && st.top() == order[idx]){
            st.pop();
            idx++;
        }
    }
    return idx;
}