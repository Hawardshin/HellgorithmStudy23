#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,ja=0,mo=0;
char res[20];
vector <char> v;

struct myclass {
    bool operator() (char i, char j) { return (i<j);}
} compare;

void loop(int x, int cnt){

    if (cnt == n){
        if (mo<=0 || ja<=1) return ;
        for (int i=0; i<n; i++) 
            cout<<res[i];
        cout<<"\n";
        return ;
    }

    for (int i=x; i<m; i++){
        res[cnt] = v[i];
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') mo++;
        else ja++;
        loop(i+1,cnt+1);
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') mo--;
        else ja--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        char c; cin>>c;
        v.push_back(c);
    }

    sort(v.begin(), v.end(), compare);
    loop(0,0);

    return 0;
}
