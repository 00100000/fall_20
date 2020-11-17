#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char s1[5005];
	char s2[5005];
	scanf("%s", s1);
	int l1 = strlen(s1);
	scanf("%s", s2);
	int l2 = strlen(s2);
	int dp[2][5005] = {0};
	for(int i = 0; i < l1; i++){
		for(int j = 0; j < l2; j++){
			if(s1[i] == s2[j]) dp[(i+1)%2][j+1] = dp[i%2][j] + 1;
			else dp[(i+1)%2][j+1] = dp[(i)%2][j+1] > dp[(i+1)%2][j] ? dp[(i)%2][j+1] : dp[(i+1)%2][j];
		}
	}
	printf("%d\n", dp[l1%2][l2]);
}