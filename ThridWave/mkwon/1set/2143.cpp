#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2147483647

using namespace std;

int t,n,m;
int a[1005]={0,},b[1005]={0,};
vector <int> asum,bsum;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    cin>>m;
    for (int i=0; i<m; i++) cin>>b[i];

    // 배열의 모든 누적합
    for (int i=0; i<n; i++){
		int sum = a[i];
		asum.push_back(sum);

		for(int j=i+1; j<n; j++) {
			sum += a[j];
			asum.push_back(sum);
		}
	}

	for (int i=0; i<m; i++){
		int sum = b[i];
		bsum.push_back(sum);

		for(int j=i+1; j<m; j++) {
			sum += b[j];
			bsum.push_back(sum);
		}
	}

    sort(bsum.begin(), bsum.end());
    long long res = 0;

    for(int i=0; i<asum.size(); i++){
        int target = t-asum[i];
        // target보다 크거나 같은거
        int lower = lower_bound(bsum.begin(), bsum.end(), target) - bsum.begin();
        // target보다 큰 거
		int upper = upper_bound(bsum.begin(), bsum.end(), target) - bsum.begin();
		res += (upper - lower);
    }
    cout<<res;

    return 0;
}
