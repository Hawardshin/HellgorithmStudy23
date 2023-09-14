#include <stdio.h>
#include <iostream>
 
using namespace std; 
int main() { // 이진법으로 나타냈을때 1 갯수세:w기

    int target;
    int cnt = 0;
    cin >> target;

    for (int i = 0; i <= 6; i++) // 64 까지 왼쪽으로 밀면서 확인
    {
        if ((target & 1) == 1)
            cnt ++;
        target >>= 1;
    }

    cout << cnt;
}
