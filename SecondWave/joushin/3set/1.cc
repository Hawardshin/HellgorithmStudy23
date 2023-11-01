#include <iostream>
#include <vector>

using namespace std;
int n;
int a,b;
int ns;
int arr[101];
vector<pair<int,int>> first_list;
bool vis[101];

void input(){
	cin >> n >> a >> b >> ns;
	for(int i=0;i<ns;i++){
		int x,y;
		cin >> x >> y;
		arr[y] = x;
	}
}

void	parent_find(){
	vis[a] = true;
	int next = arr[a];
	int cnt = 0;
	first_list.push_back({a,cnt});
	while (next != 0){
		cnt++;
		first_list.push_back({next,cnt});
		vis[next] =true;
		next = arr[next];
	}
}

int	find_ret(){
	for(auto it : first_list){
		if (it.first == b){
			return (it.second);
		}
	}
	return -1;
}


int	find_vis(int n){
	for(auto it : first_list){
		if (n == it.first){
			return (it.second);
		}
	}
	return -1;
}




int main(){
	input();
	parent_find();

	if (vis[b] == true){
		cout << find_ret();
		// cout << "?"<< "\n";
		return 0;
	}else{
		int next = arr[b];
		int cnt = 1;
		while (next != 0){
			// cout <<"부모 : " <<next << "\n";
			if (true == vis[next]){
				// cout << "?!"<< "\n";
				cout << (cnt + find_vis(next)) << "\n";
				return 0;
			}
			next = arr[next];
			cnt++;
		}
	}
	cout << -1 << "\n";
}
