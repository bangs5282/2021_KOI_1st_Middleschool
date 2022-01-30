#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <limits>

using namespace std;

int answer = INT_MIN;

int n;
vector<int> number;
vector<int> sum;


int main()
{
	cin >> n;

	number.resize(n + 1);
	sum.resize(n + 1);

	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
		sum[i] = sum[i - 1] + number[i];
	}

	for (int i = 2; i < n; i++) {
		answer = max(answer, sum[n] - number[1] - number[i] + sum[n] - sum[i]); // s1 s2 e
	}

	for (int i = 2; i < n; i++) {
		answer = max(answer, sum[n] - number[n] - number[i] + sum[i - 1]); // e s1 s2
	}

	for (int i = 2; i < n; i++) {
		answer = max(answer, sum[i] - number[1] + sum[n] - sum[i - 1] - number[n]); // s1 e s2
	}

	cout << answer << endl;

	return 0;
}