#include <iostream>
#include <string>

using namespace std;

string ant(int n) {
	string s = "1";
	for (int line = 0; line < n; ++line) {
		s = next(s);
	}
	return s;
}

string next(string s) {
	char curr = s[0];
	int length = 0;
	string result = "";
	for (auto c: s) {
		if (c == curr) {
			length++;
			continue;
		}
		result += to_string(length);
		result += curr;
		length = 1;
		curr = c;
	}
	result += to_string(length);
	result += curr;
	return result;
}

int main() {
	cout << ant(10) << endl;
}

