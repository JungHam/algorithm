#include <iostream>
#include <cstring>
using namespace std;

int num_count[10] = {0};
void cal(long long n, int place) {
	while (n != 0) { //이전 계산값의 결과로 체크하려면 조건문에 계산 하지 말 것. 경계값 체크가 안된다.
		num_count[n % 10] += place;
		n = n / 10;
	}

	return;
}
void page(long long n, long long m, int place) {

	if (n / 10 == 0) { //기저조건
		for (int i = m; i <= n; i++) {
			num_count[i] += place;
		}
		return;
	}
	
	while (n % 10 != 9) { //upper bound
		cal(n, place);
		n--;
	}

	while (m % 10 != 0) {//lower bound
		cal(m, place);
		m++;
	}
	for (int i = 0; i < 10; i++) {
		num_count[i] += (n / 10 - m / 10 +1) * place; // +1 하는 데에서 헷갈려서 계속 틀림
	}

	page(n/10, m/10, place*10); // 어느 동작이 반복되고 있는가
	return;
}

int main() {
	int n = 0;
	while (cin >> n) {
		memset(num_count,0,sizeof(num_count));
		page(n, 1, 1);
		for (int i : num_count)
			cout << i << " ";
		cout << endl;

	}
}