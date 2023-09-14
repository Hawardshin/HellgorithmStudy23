#include <stdio.h>
#include <iostream>
 
using namespace std; 
int main() {

    int target;
    int cnt = 0;
    cin >> target;

    for (int i = 0; i <= 6; i++)
    {
        if ((target & 1) == 1)
            cnt ++;
        target >>= 1;
    }

    cout << cnt;
}
