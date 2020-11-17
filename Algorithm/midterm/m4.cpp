#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node_{
	int st;
	int ed;
}node;

bool comp(node i, node j){
	if(i.ed < j.ed) return 1;
	if(i.ed > j.ed) return 0;
	if(i.st < j.st) return 1;
	if(i.st > j.st) return 0;
	return 0;
}

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<node> in;
	in.resize(n);
	for(int i = 0; i < n; i++) scanf("%d%d", &in[i].st, &in[i].ed);
	
	sort(in.begin(), in.end(), comp);
	
	//printf("\n");
	//for(int i = 0; i < n; i++) printf("%d %d\n", in[i].st, in[i].ed);
	
	int s1 = 0, s2 = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		while(in[i].st < s1 && in[i].st < s2 && i < n) i++;
		if(i >= n) break;
		//printf("%d\n", i);
		
		if(s1 < s2) swap(s1, s2);
		if(in[i].st >= s1) s1 = in[i].ed;
		else s2 = in[i].ed;
		ans ++;
	}
	printf("%d\n", ans);
}