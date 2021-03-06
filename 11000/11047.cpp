#include <cstdio>
using namespace std;

int main(){
	int N, K, cost[10], result = 0;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", cost+i);
	// 가장 큰 액수의 동전부터 최대한 사용
	for(int i=N-1; i>=0; i--){
		result += K/cost[i];
		K %= cost[i];
	}
	printf("%d\n", result);
}