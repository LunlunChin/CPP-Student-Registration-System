#ifndef COURSELIST_H
#define COURSELIST_H
#include <iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		
		//constructor
		Node(int data){
			this->data=data;
			this->next=NULL;
		};
		
		//structure for the list of (nodes)
		 
	
};

class courseList{
	private:
		Node *head; //head pointer
		
	public:
		//constructor
		courseList(){
			head=NULL;
		}
		
		~courseList();
		
		void insertCourse(int);
		void print();
};

#endif
