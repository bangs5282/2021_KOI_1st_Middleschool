#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

int N;
vector<int> number;

int answer = -1;
int start_pos1;
int start_pos2;

int func(int st, int e) {
	int honey = 0;

	if (st > e) {
		for (int i = st - 1; i >= e; i--) {
			if (i != start_pos1 && i != start_pos2) {
				honey += number[i];
			}
		}
	}
	else if(st < e) {
		for (int i = st + 1; i <= e; i++) {
			if (i != start_pos1 && i != start_pos2) {
				honey += number[i];
			}
		}
	}
	else {
		return 0;
	}

	return honey;
}

int main()
{
	cin >> N;

	number.resize(N);

	for (int& e : number) {
		cin >> e;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				for (int k = 0; k < N; k++) {
					if (k != j && k != i) {
						start_pos1 = j;
						start_pos2 = k;
						answer = max(func(j, i) + func(k, i), answer);
					}
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}