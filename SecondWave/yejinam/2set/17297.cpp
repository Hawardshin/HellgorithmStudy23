#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> messi; 

//(1)     m
//(N-2)   m  g       
//(N-1)   m  g /m 
//(N)     m  g  m /m  g

int dp(int N, int index) 
{ 
    if (index <= messi[1]) 
        return index; 
    if (index <= messi[N - 1]) // N - 1 구간 안
        return dp(N - 1, index); 
    else if (index == messi[N - 1] + 1) // 공백 
        return -1; 
    else 
        return dp(N - 2, index - messi[N - 1] - 1); // N - 2 구간 안
}

int main() 
{ 
    int M;
    cin >> M; 
    messi.push_back(5); // "Messi"
    messi.push_back(13); // "Messi Gimossi"
    int a = 5;
    int b = 13;
    
    int next = 0;
    while (next < M)
    { 
        next = a + b + 1; 
        a = b;
        b = next;
        messi.push_back(next);
    }
    
    int size = messi.size();
    int answer = dp(size, M);
    
    if (answer == -1 || answer == 6) //공백
        cout << "Messi Messi Gimossi" << endl; 
    else 
        cout << "Messi Gimossi"[answer - 1]; 
} 