#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long n,m,k;
vector<long long> vec;
vector<long long> FenwickTree;
vector<pair<int, pair<int, long long>>> cmd;
 
void Make_PenwickTree()
{
    for (int i=1; i<=n; i++)
    {
        int idx=i;
        while (idx < FenwickTree.size()){
            FenwickTree[idx] = FenwickTree[idx] + vec[i];
            idx = idx + (idx & -idx);
        }
    }
}

long long Sum(int Idx)
{
    long long Result = 0;
    while (Idx > 0){
        Result = Result + FenwickTree[Idx];
        Idx = Idx - (Idx & -Idx);
    }
    return Result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m>>k;
    vec.resize(n + 1);
    FenwickTree.resize(n+1);
    
    for (int i=1; i<=n; i++){
        long long  a; cin>>a;
        vec[i]=a;
    }
    for (int i = 0; i < m+k; i++){
        int a, b; long long c;
        cin>>a>>b>>c;
        cmd.push_back({a,{b, c}});
    }

    Make_PenwickTree();

    for (int i = 0; i < cmd.size(); i++)
    {
        int Num = cmd[i].first;
        if (Num == 1) {
            int Index = cmd[i].second.first;
            long Value = cmd[i].second.second;
            long Diff = Value - vec[Index];
            vec[Index] = Value;
            int idx=Index;
            while (idx < FenwickTree.size()){
                FenwickTree[idx] = FenwickTree[idx] + Diff;
                idx = idx + (idx & -idx);
            }
        }
        else {
            int Index = cmd[i].second.first;
            int Index2 = cmd[i].second.second;
            cout << Sum(Index2) - Sum(Index - 1) << endl;
        }
    }

    return 0;
}
