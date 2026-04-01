#include <iostream>
#include <string>
#include <vector>
#include <cctype> //자료형의 함수 여러개 
//isstpace(a) 함수는 공백이면 참 값을 반환

using namespace std;

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type str_sz;
	str_sz i = 0;
	//불변성: 지금까지 [원래의 i , 현재의 i) 범위에 있는
	//문자들을 처리
	while (i != s.size()){
		while (i != s.size() && isspace(s[i])) {
			++i;
		}
		//순서상 다음 단어의 끝을 찾음
		str_sz j = i;
		//불변성: 지금까지 [원래의 i , 현재의 i) 범위에 있는
		//문자들은 공백이 x
		while (j != s.size() && !isspace(s[j])) {
			j++;
		}

		//공백이 아닌 문자들을 찾았을때
		if (i != j) {
			ret.push_back(s.substr(i, j - 1));
			i = j;
		}
	}
	return ret;
}
int main(void) {
	return 0;
}
