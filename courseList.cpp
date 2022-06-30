#include "courseList.h"

void courseList::insertCourse(int num){
	Node *newNode;
	Node *nodePtr;
	
	newNode= new Node(num);
	newNode->data=num;
	newNode->next=NULL;
	
	if(!head){
	
		head= newNode;
		//cout<<"new added";
	}
	else{
		nodePtr=head;
		
		while(nodePtr->next){
			nodePtr= nodePtr->next;
		}
		nodePtr->next=newNode;//insert at last node;
		//cout<<"lastnode added";
	}
}

void courseList::print(){
	Node *p=head;
	while(p!=NULL){
		cout<<p->data<< " ";
		p=p->next;
		
	}

}

