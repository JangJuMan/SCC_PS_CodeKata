// 105. 쿼드압축 후 개수 세기(Devide & Conquer) / re(re)
// https://school.programmers.co.kr/learn/courses/30/lessons/68936
#include <string>
#include <vector>

using namespace std;

/*2트 실패*/
bool isSame(vector<vector<int>>& arr, int r, int c, int size){
    for(int i=r; i<r+size; ++i){
        for(int j=c; j<c+size; ++j){
            if(arr[r][c] != arr[i][j]) return false;
        }
    }
    return true;
}

pair<int, int> dnc(vector<vector<int>>& arr, int rs, int cs, int size){
    if(isSame(arr, rs, cs, size)){
        if(arr[rs][cs] == 0) return {1, 0};
        else return {0, 1};
    }
    
    int half = size/2;
    pair<int, int> q1 = dnc(arr, rs, cs, half);
    pair<int, int> q2 = dnc(arr, rs+half, cs, half);
    pair<int, int> q3 = dnc(arr, rs, cs+half, half);
    pair<int, int> q4 = dnc(arr, rs+half, cs+half, half);
    
    return {q1.first + q2.first + q3.first + q4.first,
            q1.second + q2.second + q3.second + q4.second};
}

vector<int> solution(vector<vector<int>> arr) {
    pair<int, int> ans = dnc(arr, 0, 0, arr.size());
    return {ans.first, ans.second};
}

/* 1트 실패 */
// pair<int, int> dfs(const vector<vector<int>>& arr, int r, int c, int size){
//     int value = arr[r][c];
//     bool isAllSame = true;
    
//     for(int i=r; i<r+size; i++){
//         for(int j=c; j<c+size; j++){
//             if(arr[i][j] != value){
//                 isAllSame = false;
//                 break;
//             }
//         }
//         if(!isAllSame){
//             break;
//         }
//     }
    
//     if(isAllSame){
//         if(value == 0) return {1, 0};
//         else return {0, 1};
//     }
    
//     int half = size/2;
//     pair<int, int> q1 = dfs(arr, r, c, half);
//     pair<int, int> q2 = dfs(arr, r, c+half, half);
//     pair<int, int> q3 = dfs(arr, r+half, c, half);
//     pair<int, int> q4 = dfs(arr, r+half, c+half, half);
    
//     return {q1.first + q2.first + q3.first + q4.first,
//             q1.second + q2.second + q3.second + q4.second};
// }

// vector<int> solution(vector<vector<int>> arr) {
//     pair<int, int> ans = dfs(arr, 0, 0, arr.size());
//     return {ans.first, ans.second};
// }