// 11. 짝수와 홀수
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return (num & 1) ? "Odd" : "Even";
}