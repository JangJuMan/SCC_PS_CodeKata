// 19. 정수 제곱근 판별
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    double root = sqrt(static_cast<double>(n));
    long long intRoot = static_cast<long long>(floor(root));
    if(intRoot*intRoot == n){
        return (intRoot+1)*(intRoot+1);
    }
    else if((intRoot+1)*(intRoot+1) == n){
        return (intRoot+2)*(intRoot+2);
    }
    return -1;
    // long long intRoot = static_cast<long long>(round(root));
    // return (intRoot * intRoot == n) ? (intRoot+1) * (intRoot+1) : -1;
}