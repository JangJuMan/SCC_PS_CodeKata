// 141. 당구연습 / re.. 반사는 생각 못했네,, 중점 좌표 찾았었는데
// https://school.programmers.co.kr/learn/courses/30/lessons/169198
#include <string>
#include <vector>
#include <limits>

using namespace std;

int dist_2(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> ans;
    for(auto& ball : balls){
        int targetX = ball[0], targetY = ball[1];
        int res = numeric_limits<int>::max();
        
        // 윗쪽 벽 반사
        if(!(startX == targetX && startY < targetY)){   // 윗쪽벽 가는 길에 타겟 공이 있는 경우는 제외
            res = min(res, dist_2(startX, startY, targetX, 2*n-targetY));   // 윗벽 기준으로 대칭이동 시킨 좌표와 거리
        }
        
        // 아래쪽 벽 반사
        if(!(startX == targetX && startY > targetY)){   // 아래쪽벽 가는 길에 타겟 공이 있는 경우는 제외
            res = min(res, dist_2(startX, startY, targetX, -targetY));      // 아래벽 기준으로 대칭이동 시킨 좌표와 거리
        }
        
        // 오른쪽 벽 반사
        if(!(startY == targetY && startX < targetX)){   // 오른쪽벽 가는 길에 타겟 공이 있는 경우는 제외
            res = min(res, dist_2(startX, startY, 2 * m - targetX, targetY));   // 아래벽 기준으로 대칭이동 시킨 좌표와 거리
        }
        
        // 왼쪽 벽 반사
        if(!(startY == targetY && startX > targetX)){   // 왼쪽벽 가는 길에 타겟 공이 있는 경우는 제외
            res = min(res, dist_2(startX, startY, -targetX, targetY));   // 왼쪽벽 기준으로 대칭이동 시킨 좌표와 거리
        }
        ans.push_back(res);
    }
    return ans;    
}