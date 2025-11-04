// 170. 공 이동 시뮬레이션 (역시뮬레이션) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/87391
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    ll rowMin = x, rowMax = x;
    ll colMin = y, colMax = y;
    
    for(int i=queries.size()-1; i>=0; i--){
        int cmd = queries[i][0];
        ll dx = queries[i][1];
        
        if(cmd == 0){                           // ← 방향 이동
            if(colMin != 0)                     // colMin이 하한인 경우는 0이 최소
                colMin += dx;
            colMax = min((ll)m-1, colMax + dx);     // 상한선 m-1보다 커지지 않도록
        }
        else if(cmd == 1){                      // → 방향 이동
            if(colMax != m-1)                   // colMax가 상한인 경우는 m-1이 최대
                colMax -= dx;
            colMin = max(0LL, colMin - dx);       // 하한선 0보다 작아지지 않도록
        }
        else if(cmd == 2){                      // ↑ 방향 이동
            if(rowMin != 0)                     // colMax가 상한인 경우는 m-1이 최대    
                rowMin += dx;
            rowMax = min((ll)n-1, rowMax + dx);     // 하한선 0보다 작아지지 않도록
        }
        else if(cmd == 3){                      // ↓ 방향 이동
            if(rowMax != n-1)                   // rowMax가 상한인 경우는 n-1이 최대
                rowMax -= dx;
            rowMin = max(0LL, rowMin - dx);       // 하한선 0보다 작아지지 않도록
        }
        
        if(rowMin > rowMax || colMin > colMax) return 0;
    }
    return (rowMax - rowMin + 1) * (colMax - colMin + 1);
}