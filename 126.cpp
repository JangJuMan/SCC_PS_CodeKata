// 126. 광물캐기 (greedy) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/172927
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MineralChunk{
    int dia, iron, stone;
};

bool compareChunks(const MineralChunk& a, const MineralChunk& b){   // 내림차순 정렬
    if(a.dia != b.dia){
        return a.dia > b.dia;
    }
    if(a.iron != b.iron){
        return a.iron > b.iron;
    }
    return a.stone > b.stone;
}

int solution(vector<int> picks, vector<string> minerals) {
    int total_fatigue = 0;
    int total_picks = picks[0] + picks[1] + picks[2];
    
    vector<MineralChunk> chunks;
    
    // 1. 광물 묶음(chunk) 생성 
    for(int i=0; i<minerals.size() && total_picks > 0; i+=5){
        MineralChunk chunk = {0, 0, 0};
        
        for(int j=0; j<5 && i+j < minerals.size(); j++){
            string mineral = minerals[i+j];
            if(mineral == "diamond")    chunk.dia++;
            else if(mineral == "iron")  chunk.iron++;
            else if(mineral == "stone") chunk.stone++;
        }
        
        chunks.emplace_back(chunk);
        total_picks--;
    }
    
    // 2. 비싼 광물 순으로 정렬
    sort(chunks.begin(), chunks.end(), compareChunks);
    
    // 3. 곡괭이 배정 및 피로도 계산
    for(const auto& chunk : chunks){
        if(picks[0] > 0){   // 다이아 곡괭이
            total_fatigue += chunk.dia * 1 + chunk.iron * 1 + chunk.stone * 1;
            picks[0]--;
        }
        else if(picks[1] > 0){  // 철 곡괭이
            total_fatigue += chunk.dia * 5 + chunk.iron * 1 + chunk.stone * 1;
            picks[1]--;
        }
        else if(picks[2] > 0){
            total_fatigue += chunk.dia * 25 + chunk.iron * 5 + chunk.stone * 1;
            picks[2]--;
        }
    }
    
    return total_fatigue;
}