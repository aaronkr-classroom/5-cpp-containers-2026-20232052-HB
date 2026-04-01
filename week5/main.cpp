//main_old.cpp
//중간고사, 기말고사, 과제 점수 몇점 받고
// 마지막 평균 결과 점수를 계산하기
#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"


using namespace std;

typedef vector<double>::size_type vec_sz;
typedef vector<Student_info>::size_type si_sz;

int main(void) {
	//새로운 구조 자료형 선언
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;


	// 프로그램 설명하기
	cout << "For every student, enter: " << endl <<
		"Name Midterm Final Hw1 Hw2...." << endl;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);

	}

	//학생 정보를 알파벳순으로 정렬
	sort(students.begin(), students.end(), compare);


	// 모든 학생의 결과를 출력
	for (si_sz i = 0; i != students.size(); ++i) {
		//이름과 오른쪽 공백을 포함하여 maxlen + 1개의 문자를 출력
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		//최종점수를 계산하여 출력
		try {
			double final_grade = grade(students[i]); //New 계산하는 함수 grade()
			streamsize prec = cout.precision();
			cout << "Final grade: " << setprecision(3) <<
				final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
