#include <iostream>
#include <algorithm>

using namespace std;

int n,h;
int tab1[200005]={0,},tab2[200005]={0,};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>h;
    for (int i=0; i<n/2; i++)
        cin>>tab1[i]>>tab2[i];

    sort(tab1, tab1+n/2);
    sort(tab2, tab2+n/2);

    cout<<"\n tab1 : ";
    for (int i=0; i<n/2; i++)
        cout<<tab1[i]<<" ";
    cout<<"\n tab2 : ";
    for (int i=0; i<n/2; i++)
        cout<<tab2[i]<<" ";

    return 0;
}
