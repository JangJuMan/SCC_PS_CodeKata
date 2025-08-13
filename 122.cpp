// 122. 테이블 해시 함수(구현, 정렬기준 정의)
// https://school.programmers.co.kr/learn/courses/30/lessons/147354
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int colToSort;

bool comp(const vector<int>& a, const vector<int>& b){
    if(a[colToSort] != b[colToSort]){
        return a[colToSort] < b[colToSort];
    }
    return a[0] > b[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    colToSort = col-1;

    sort(data.begin(), data.end(), comp);
    // sort(data.begin(), data.end(), [col](auto a, auto b){
    //    return (a[col-1] != b[col-1]) ? a[col-1] < b[col-1] : a[0] > b[0];
    // });  // Lambda (느리네)
    
    int ans = 0;
    for(int i=row_begin; i<=row_end; i++){
        int s_i = 0;
        for(int elem : data[i-1]){
            s_i += (elem % (i));
        }
        ans = ans ^ s_i;
    }
    return ans;
}