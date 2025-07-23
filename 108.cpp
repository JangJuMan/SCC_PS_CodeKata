// 108. 삼각 달팽이(3방향 direction, 대입구현) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/68645#
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> vec(n, vector<int>(n, 0));
    
    int num = 1, row = -1, col = 0, direction = 0; // 0 : 아래 / 1 : 오른쪽 / 2: 왼쪽 대각
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(direction == 0){
                row++;
            }
            else if(direction == 1){
                col++;
            }
            else if(direction == 2){
                row--;
                col--;
            }
            vec[row][col] = num++;
        }
        direction = (direction + 1) % 3;
    }
    
    vector<int> ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            ans.emplace_back(vec[i][j]);
        }
    }
    
    return ans;
}