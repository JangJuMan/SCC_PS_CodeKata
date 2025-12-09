// 106. 택배상자(스택) / re(re..?코드안이쁨)
// https://school.programmers.co.kr/learn/courses/30/lessons/131704
#include <string>
#include <vector>
#include <stack>

using namespace std;

/* 2트.. 더 못생기게 풀었네.. 다시 풀어야하나? */
int solution(vector<int> order) {
    int ans=0, boxIdx=1, orderIdx=0;
    stack<int> st;
    for(int boxIdx=1; boxIdx<=order.size(); boxIdx++){
        if(boxIdx == order[orderIdx]){
            ++ans;
            ++orderIdx;
            continue;
        }
        
        while(!st.empty() && st.top() == order[orderIdx]){
            ++ans;
            ++orderIdx;
            st.pop();
        }
        st.emplace(boxIdx);
    }
    
    while(!st.empty() && st.top() == order[orderIdx]){
        ++ans;
        ++orderIdx;
        st.pop();
    }
    return ans;   
}

int solution(vector<int> order) {
    int orderIdx=0;
    stack<int> st;
    
    for(int boxIdx=1; boxIdx<=order.size(); boxIdx++){
        st.emplace(boxIdx);
        while(!st.empty() && st.top() == order[orderIdx]){
            st.pop();
            ++orderIdx;
        }
    }
    return orderIdx;
}