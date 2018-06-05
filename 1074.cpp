#include <iostream>
#include <cmath>
using namespace std;

int t_x;
int t_y;
unsigned long long c = 0;

void zet(unsigned long long f_x, unsigned long long f_y, unsigned long long level) {


	if (level == 1) {
		c++;
		return;

	}
	else {
		if (t_x < f_x + level / 2 && t_y < f_y + level / 2) {
			zet(f_x, f_y, level / 2);

		}
		else if (t_x < f_x + level / 2 && t_y >= f_y + level / 2) {
			c += (level*level) / 4;
			zet(f_x, f_y + level / 2, level / 2);
		}
		else if (t_x >= f_x + level / 2 && t_y < f_y + level / 2) {
			c += 2 * (level*level) / 4;
			zet(f_x + level / 2, f_y, level / 2);
		}
		else if (t_x >= f_x + level / 2 && t_y >= f_y + level / 2) {
			c += 3 * (level*level) / 4;
			zet(f_x + level / 2, f_y + level / 2, level / 2);
		}

	}
	return;
}

int main() {
	int level = 0;
	int count = 0;
	unsigned long long len = 0;
	while (cin >> level >> t_x >> t_y) {
		c = 0;
		len = pow(2, level);
		zet(0, 0, len);
		cout << c - 1<< endl;
	}

	return 0;

}