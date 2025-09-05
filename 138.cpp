// 138. 교점에 별 만들기(계산식, 구현) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/87377
// unordered_set은 pair<long long> 지원 안함. 따로 정의해줘야함
#include <string>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;

vector<string> solution(vector<vector<int>> line){
    set<pair<long long, long long>> points;
    
    for(int i=0; i<line.size(); i++){
        long long A = line[i][0], B = line[i][1], E = line[i][2];
        for(int j=i+1; j<line.size(); j++){
            long long C = line[j][0], D = line[j][1], F = line[j][2];
            long long det = A*D - B*C;
            if(det == 0) continue;  // 평행인 경우 생략
            
            long long xNumerator = B*F - E*D;
            long long yNumerator = E*C - A*F;
            
            if(xNumerator % det == 0 && yNumerator % det == 0){ // 정수인 경우 추가
                long long x = xNumerator / det;
                long long y = yNumerator / det;
                points.insert({x, y});
            }
        }
    }
    
    long long minX = LLONG_MAX, maxX = LLONG_MIN;   // limits.h
    long long minY = LLONG_MAX, maxY = LLONG_MIN;
    for(auto [x, y] : points){
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }
    
    int width = static_cast<int>(maxX - minX + 1);
    int height = static_cast<int>(maxY - minY + 1);
    
    vector<string> ans(height, string(width, '.'));
    
    for(auto [x, y] : points){
        int row = static_cast<int>(maxY - y);   // y가 클수록 윗쪽
        int col = static_cast<int>(x - minX);
        ans[row][col] = '*';
    }
    return ans;
}