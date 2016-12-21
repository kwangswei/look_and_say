#include <iostream>
#include <string>
#include <regex>

using namespace std;

string next(string s);
string replace(string s, regex pattern, function<string(const smatch&)> func);

string ant(int n) {
	string s = "1";
	cout << s << endl;
	for (int line = 0; line < n; ++line) {
		s = next(s);
		cout << s << endl;
	}
	return s;
}

string next(string s) {
	return replace(s, regex("(.)\\1*"), [](const smatch& sm) { 
			return to_string(sm.str().size()) +  sm.str()[0];});
}

string replace(string s, regex pattern, function<string(const smatch&)> func) {
	string ret = "";
	smatch sm;
	while (regex_search(s, sm, pattern)) {
		ret += func(sm);
		s = sm.suffix();
	}
	return ret;
}

int main() {
	cout << ant(3) << endl;
}



