// 35. 부족한 금액 계산하기
// https://school.programmers.co.kr/learn/courses/30/lessons/82612
using namespace std;

long long solution(int price, int money, int count)
{
    long long totalPrice = price * (long long)(count * (count+1)/2);
    long long ans = totalPrice - money;
    return (ans <= 0) ? 0 : ans;
}