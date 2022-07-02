#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

using namespace std;
class Student
{
	
	private:
	
		string name;
		string matricNo;
	public:
		Student();//constructor
		Student(string name_val, string matric_val);
		
		string getName();	  
		void setName(string);
		string getMatric();
		void setMatric(string);
		
		
	protected:
};

#endif
