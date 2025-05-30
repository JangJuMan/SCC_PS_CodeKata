// 22. 두 정수 사이의 합 O(1)
// 등차수열의 합공식
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    return (long long)(abs(a-b)+1)*(a+b)/2;
}