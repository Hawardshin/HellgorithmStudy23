#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,res=0,tab1[105][105]={0,},tab2[105][105]={0,};

void loop(int tab[105][105]){

    for(int i=0; i<n; i++){
        int val=0, cnt=0;
        vector<pair<int, int>> v;
		for (int j=0; j<n; j++) {
			if (j==0) {
				val = tab[i][j];
				cnt = 1;
				continue;
			}

			if (tab[i][j] == val) cnt++;
			else {
				v.push_back({val,cnt});
				val=tab[i][j];
				cnt=1;
			}
		}
		v.push_back({val,cnt});

        // 숫자 1개
		if (v.size() == 1) { res++; continue; }

        //경사로 추가해서 길을 만들 수 있는지 확인 
		int road = 1;

		for (int j=0; j<v.size() - 1; j++) {
			if (abs(v[j].first-v[j+1].first) > 1) { road = 0; break; }


			if (v[j].first < v[j+1].first) {
				if (v[j].second < m) { road = 0; break; }
			}
			else {
				if (v[j+1].second < m) { road = 0; break; }
				else v[j+1].second -= m;
			}
		}
		if (road) res++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tab1[i][j];
            tab2[j][i]=tab1[i][j];
        }
    }

    loop(tab1);
    loop(tab2);
    cout<<res;

    return 0;
}
