// 38. 직사각형 별찍기
// https://school.programmers.co.kr/learn/courses/30/lessons/12969
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    string s(a, '*');
    
    for(int i=0; i<b; i++){
        cout << s << "\n";
    }
    return 0;
}