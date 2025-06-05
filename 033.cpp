// 33. 약수의 개수와 덧셈
// https://school.programmers.co.kr/learn/courses/30/lessons/77884
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int sum = 0, root=0;
    for(int i=left; i<=right; i++){
        root = (int)sqrt(i);
        if(root * root == i){
            sum -= i;
            continue;
        }
        sum += i;
    }
    return sum;
}