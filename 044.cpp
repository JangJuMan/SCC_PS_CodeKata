// 44. 최소직사각형(완전탐색) O(n)
// https://school.programmers.co.kr/learn/courses/30/lessons/86491
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxRow = 0, maxCol = 0;
    for(size_t i=0; i<sizes.size(); ++i){
        if(sizes[i][0] >= sizes[i][1]){
            maxRow = max(maxRow, sizes[i][0]);
            maxCol = max(maxCol, sizes[i][1]);
        }
        else{
            maxRow = max(maxRow, sizes[i][1]);
            maxCol = max(maxCol, sizes[i][0]);
        }
    }
    return maxRow * maxCol;
}