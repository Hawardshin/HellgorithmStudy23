#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>  // pair
#include <tuple>
#include <stack>
// #include <map>
#include <unordered_map>
#define ll long long
#define INF 1e9
using namespace std;

int ans = 0;
int n,k;
vector<int> bd[13][13];
int map[13][13];
vector<vector<int> > pieces;
int dr[] = {0,0,0,-1,1};
int dc[] = {0,1,-1,0,0};
bool gameOver = false;

pair<int,int> white(int& r, int& c, int& d, int seq) {
	int nr,nc;
	nr = r+dr[d];
	nc = c+dc[d];

	vector<int>& v = bd[r][c];
	auto it = find(v.begin(), v.end(), seq);
	int idx = it-v.begin();

	vector<int> moving;
	int size = v.size();
	for(int i=idx;i<size;++i) {
		int s = v[i];
		pieces[s-1][0] = nr;  // int &r is changed
		pieces[s-1][1] = nc;  // int &c is changed

		moving.push_back(s);  // moving seqs
	}

	for(int i=size-1;i>=idx;--i) {
		v.pop_back();
	}
	v.resize(idx);

	for(int i=0;i<moving.size();++i) {
		bd[nr][nc].push_back(moving[i]);
	}

	return make_pair(nr,nc);
}

pair<int,int> red(int& r, int& c, int& d, int seq) {
	int nr = r+dr[d];
	int nc = c+dc[d];
	white(r,c,d,seq);
	vector<int>& v = bd[nr][nc];

	auto it = find(v.begin(), v.end(), seq);
	int idx = it-v.begin();
	reverse(v.begin()+idx, v.end());

	return make_pair(nr,nc);
}

pair<int,int> blue(int& r, int& c, int& d, int seq) {
	if(d==1) {d=2;}
	else if(d==2) {d=1;}
	else if(d==3) {d=4;}
	else if(d==4) {d=3;}


	int nr = r+dr[d];
	int nc = c+dc[d];

	if(!(1<=nr&&nr<=n && 1<=nc&&nc<=n) || (map[nr][nc]==2)) {
		return make_pair(0,0);  // out of bound
	} else {
		if(map[nr][nc] == 0) {
			white(r,c,d,seq);
		} else if(map[nr][nc] == 1) {
			red(r,c,d,seq);
		}
	}

	return make_pair(nr,nc);
}

void sol() {
	ans++;

	for(int k=0;k<pieces.size();++k) {  // pieces.size()
		int seq = k+1;
		int &r = pieces[k][0];
		int &c = pieces[k][1];
		int &d = pieces[k][2];
		int nr,nc;
		nr = r+dr[d];
		nc = c+dc[d];

		pair<int,int> p;
		// out of bound (blue) 2
		if(!(1<=nr&&nr<=n && 1<=nc&&nc<=n)) {
			p = blue(r,c,d,seq);
		}

		// white 0
		else if(map[nr][nc] == 0) {
			p = white(r,c,d,seq);
		}

		// red 1
		else if(map[nr][nc] == 1) {
			p = red(r,c,d,seq);
		}

		// blue 2
		else if(map[nr][nc] == 2) {
			p = blue(r,c,d,seq);
		}

		int a,b;
		a = p.first;
		b = p.second;
		if(a==0 && b==0) {  // out of bound
			continue;
		} else {
			if(bd[a][b].size() >= 4) {
				gameOver = true;
				break;
			}
		}
	}

	return;
}

int main(void) {
	// ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=0;i<k;++i) {
		int r,c,d;
		scanf("%d%d%d", &r,&c,&d);
		vector<int> v;
		v.push_back(r); v.push_back(c); v.push_back(d);
		pieces.push_back(v);
		bd[r][c].push_back(i+1);
	}

	while(ans <= 1000) {
		sol();
		if(gameOver) break;
	}

	if(ans > 1000) {
		ans = -1;
	}
	printf("%d\n", ans);
	
	return 0;
}