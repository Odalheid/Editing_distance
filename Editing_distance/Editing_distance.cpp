#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(const int &a, const int &b, const int &c) {
	int result = (a < b ? a : b);
	result = (result < c ? result : c);
	return result;
}

int main()
{
	string a, b;
	cin >> a >> b;

	vector<int> previous(a.size() + 1);
	for (int i = 0; i < previous.size(); ++i) previous[i] = i;

	vector<int> current(a.size() + 1);
	current[0] = 1;

	for (int i = 1; i < b.size() + 1; ++i) {
		for (int j = 1; j < current.size(); ++j) {
			bool replacement_cost = (a[j - 1] != b[i - 1]);
			current[j] = min(current[j - 1] + 1, previous[j] + 1, previous[j - 1] + replacement_cost);
		}
		current.swap(previous);
		current[0] = i + 1;
	}
	cout << previous[previous.size() - 1];
    return 0;
}

