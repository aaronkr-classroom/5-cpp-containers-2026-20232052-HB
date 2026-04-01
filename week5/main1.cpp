//main_split_str.cpp


#include <iostream>
#include <string>
#include <vector>
#include "split_str.h"
using namespace std;

int main(void) {
	string s;
	cout << "enter anything E0F to quit:";
//문자열을 한 행씩 입력받아 분할
	while(getline(cin, s)) {
		vector<string> v = split(s);
		for (vector<string>::size_type i = 0;
			i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}
	return 0;
}
