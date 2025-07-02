// 81. N 개의 최소공배수(lcm, gcd, numeric stl)
// https://school.programmers.co.kr/learn/courses/30/lessons/12953
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int myGcd(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int myLcm(int a, int b){
    return a * b / myGcd(a, b);
}

int solution(vector<int> arr) {
    int ans = arr[0];
    for(int i=1; i<arr.size(); i++){
        ans = lcm(ans, arr[i]);     // numeric::lcm, gcd
    }
    return ans;
}