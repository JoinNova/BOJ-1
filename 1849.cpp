#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100000; // N�� �ִ�
const int ST_MAX = 262144; // ���׸�ƮƮ�� �迭�� �ִ�

// ���׸�Ʈ Ʈ�� ����ü
struct SegTree{
	int size, start;
	int arr[ST_MAX];
	// ������: size=n���� �ʱ�ȭ
	SegTree(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
	}
	// i�� ���Ҹ� 1 ������Ŵ
	void inc(int i){
		i += start;
		while(i > 0){
			arr[i]++;
			i /= 2;
		}
	}
	// s �̻� e �̸� �ε����� ���� �� ����
	int sum(int s, int e){ return sum(s, e, 1, 0, start); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	// filled: ������� �˷���, seq���� ó�� �����ϴ� �� ä���� �ε���
	int N, seq[100000] = {0}, filled = 0;
	scanf("%d", &N);
	SegTree ST(N);

	// A[i] �Է¹ޱ� ����
	for(int i=1; i<=N; i++){
		int A;
		scanf("%d", &A);

		// A=0�� ��� ���� ������ �� ĭ�� ã�� ����
		if(A == 0){
			while(seq[filled] != 0) filled++;
			seq[filled] = i;
			ST.inc(filled++);
		}
		// A�� 0�� �ƴ� ���
		else{
			// ���� Ž��
			int lo = 0, hi = N;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				if(mid - ST.sum(0, mid+1) < A) lo = mid;
				else hi = mid;
			}
			// lo�� �Ұ����� ���� ū �ε���, hi�� ������ ���� ���� �ε���
			seq[lo+1] = i;
			ST.inc(lo+1);
		}
	}

	// ���� ���
	for(int i=0; i<N; i++)
		printf("%d\n", seq[i]);
}