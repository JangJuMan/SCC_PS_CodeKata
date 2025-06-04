// 32. 내적
// https://school.programmers.co.kr/learn/courses/30/lessons/70128
#include <string>
#include <vector>
#include <numeric> // inner_product

using namespace std;

int solution(vector<int> a, vector<int> b) {
    // int dotProduct = 0;
    // for(int i=0; i<a.size(); i++){
    //     dotProduct += a[i] * b[i];
    // }
    // return dotProduct;
    return inner_product(a.begin(), a.end(), b.begin(), 0);
}