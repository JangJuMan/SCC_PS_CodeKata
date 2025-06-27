// 73. 공원산책, dr dc 테크닉, 범위초과 및 장애물 판별
// https://school.programmers.co.kr/learn/courses/30/lessons/172928
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int dr[4] = {-1, 1, 0, 0};    // N, S, W, E
const int dc[4] = {0, 0, -1, 1};
const string dirs = "NSWE";

vector<int> solution(vector<string> park, vector<string> routes){
    int H = park.size(), W = park[0].size();
    int r = 0, c= 0;

    for(int i=0; i<H; i++){     // 시작위치('S') 찾기
        for(int j=0; j<W; ++j){
            if(park[i][j] == 'S'){
                r = i; c = j;
            }
        }
    }

    for(const string& route : routes){
        char op;
        int n;
        stringstream ss(route);
        ss >> op >> n;

        int d = dirs.find(op);
        int nr = r, nc = c;
        bool canGo = true;

        int tr = r + dr[d] * n, tc = c + dc[d] * n;
        if(tr < 0 || tr >= H || tc < 0 || tc >= W){     // 범위초과
            canGo = false;
            continue;
        }
        for(int step = 1; step <= n; ++step){
            tr = r + dr[d] * step;
            tc = c + dc[d] * step;
            if(park[tr][tc] == 'X'){
                canGo = false;
                break;
            }
        }
        if(canGo){
            r += dr[d] * n;
            c += dc[d] * n;
        }
    }
    return {r, c};
}