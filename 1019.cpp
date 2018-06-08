#include <iostream>
#include <cstring>
using namespace std;

int num_count[10] = {0};
void cal(long long n, int place) {
	while (n != 0) { //���� ��갪�� ����� üũ�Ϸ��� ���ǹ��� ��� ���� �� ��. ��谪 üũ�� �ȵȴ�.
		num_count[n % 10] += place;
		n = n / 10;
	}

	return;
}
void page(long long n, long long m, int place) {

	if (n / 10 == 0) { //��������
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
		num_count[i] += (n / 10 - m / 10 +1) * place; // +1 �ϴ� ������ �򰥷��� ��� Ʋ��
	}

	page(n/10, m/10, place*10); // ��� ������ �ݺ��ǰ� �ִ°�
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