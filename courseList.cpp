#include "courseList.h"

void courseList::insertCourse(int num){//inserting course into linkedlist
	Node *newNode;
	Node *nodePtr;
	
	newNode= new Node(num);
	newNode->data=num;
	newNode->next=NULL;
	
	if(!head){
	
		head= newNode;
		cout<<"\nNew course added Successfully!\n";
	}//add to head if new list
	else{
		nodePtr=head;
		
		while(nodePtr->next){
			nodePtr= nodePtr->next;
		}
		nodePtr->next=newNode;//insert at last node;
		cout<<"\nNew course added Successfully\n";
	}//insert course at last node
}


void courseList::deleteCourse(int key){//delete a course from linkedlist
	cout<<"Deleting course.....";
	int end=0;
	Node *p=head;
	Node *q=NULL;
	
	if(head->data==key){//if found at head, the head data will be deleted
		head=head->next;
		delete p;
	 cout<<"\nCourse deleted Successfully!";
	 end=1;
	}
	while(end==0){
	
	while(p->data!=key && p->next!=NULL){//traversing the list and find the key of the course
		q=p;
		p=p->next;
	}
	
	if(p->data!=key){
		cout<<"\nCourse not found\n";// if course not found in list
		end=1;
	}
	else{
		q->next=p->next;
		delete p;
		cout<<"\nCourse deleted Successfully!\n";// delete course if found
		end=1;
	}
}
}

void courseList::print(){//output list of courses
	Node *p=head;
	string courses[14];
	
	int i=0;
	string line;
 	 ifstream myfile("CourseList2.txt");
 		 if (myfile.is_open())
  		{
   		 while (getline (myfile,line)){
    	  courses[i]=line;
    	  i++;
    	}
    myfile.close();
  }

  
	while(p!=NULL){
		cout<<p->data<< ". "<<courses[p->data]<< " \n";
		p=p->next;
		
	}

}

