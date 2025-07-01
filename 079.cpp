// 79. 카펫(근의공식, 숫자 하나씩 대입)
// https://school.programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {       // 근의 공식을 이용한 풀이
    int A = 1, B = -(brown/2 + 2), C = brown + yellow;
    int height = (-B + sqrt(B*B - 4*A*C)) / 2;
    int width = brown/2 + 2 - height;
    return {max(width, height), min(width, height)};
}


// vector<int> solution(int brown, int yellow) {
//     // w >= h
//     for (int h = 3; h <= yellow + 2; ++h) {
//         if ((yellow % (h - 2)) != 0) continue;  // yellow는 (h-2)의 배수이어야 함
//         int w = yellow / (h - 2) + 2;           
//         if (w < h) continue;                    // 가로가 세로보다 짧으면 패스
//         if (2 * w + 2 * h - 4 == brown) {       // (w * h) = yellow + brown 전개(yellow = (w-2)*(h-2))
//             return {w, h};
//         }
//     }
//     return {}; // 문제 조건상 여기에 도달하지 않음
// }