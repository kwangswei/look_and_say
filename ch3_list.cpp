#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> next(vector<int> as);

void print(vector<int> s) {
	for (auto x: s)
		cout << x << " ";
	cout << endl;
}

vector<int> ant(int n) {
	vector<int> s = {1};
	print(s);
	for (int line = 0; line < n; ++line) {
		s = next(s);
		print(s);
	}
	return s;
}

vector<int> concat(vector<vector<int>> ass) {
	vector<int> ret;
	for (auto x: ass)
		ret.insert(ret.end(), x.begin(), x.end());
	return ret;
}

vector<vector<int>> map(function<vector<int>(vector<int>&)> func, vector<vector<int>> gs) {
	vector<vector<int>> ret;
	for (auto x: gs)
		ret.push_back(func(x));
	return ret;
}

vector<vector<int>> group(vector<int> s) {
	vector<vector<int>> ret;
	for (auto x: s) {
		if (ret.size() == 0 || ret.back().front() != x)
			ret.push_back({});
		ret.back().push_back(x);
	}
	return ret;
}

vector<int> next(vector<int> s) {
	return concat(map([](vector<int>& s) {  return vector<int>{s.size(), s[0]}; }, group(s)));
}

int main() {
    print(ant(3));
}





