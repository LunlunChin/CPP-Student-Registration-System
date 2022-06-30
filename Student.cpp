#include "Student.h"

Student::Student()
 :Student{"None","null"}{
			
		}
		
Student::Student(string name_val, string matric_val)
 :name{name_val},matricNo{matric_val}{
			
		}
		
		
		
void Student::setName(string n) {
	name=n;
}

string Student::getName() {
	return name;
}

string Student::getMatric(){
	return matricNo;
}

void Student::setMatric(string m){
	matricNo=m;
}

void Student::addCourse(int n){
	 	
}




