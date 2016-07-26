#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	long long fact1 = 1, power5;

	for(int i=2; i<=N; i++){
		power5 = i;
		while(power5 % 5 == 0){
			power5 /= 5;
			fact1 /= 2;
		}
		fact1 *= power5;
		fact1 %= 100000000000;
	}
	printf("%lld\n", fact1%10);
}