#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    float f;

    // n = 2;
    // f = 7.625;
    // // 정수 -> 고정소수점
    // n = n << 8;
    // cout << n << endl;
    // // 고정소수점 -> 정수
    // n = n >> 8;
    // cout << n << endl;
    // // 실수 -> 고정소수점
    // f = roundf(f * (1 << 8));
    // cout << f << endl;
    // // 고정소수점 -> 실수
    // f = (float)f / (1 << 8);
    // cout << f << endl;

    int num = 1;
    num = num << 8;
    float num2 = 7.625;
    num2 = (num2 * (1 << 8));
    cout << num2 << endl;
    for (int i = 15; i >= 0; i--)
    {
        int result = (int)num2 >> i & 1;
        cout << result;
    }
    cout << endl;
}