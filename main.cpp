#include <iostream>
#include <fstream>
#include <string.h>
#include "Student.h"

using namespace std;

Student login();
void registr();
void displayMainMenu();
void buildCourse();
void selectCourse(int);
int main(){
	Student student1;
	buildCourse();
	
	int choice;
	cout<<"****************************\n";
	cout<<"************WELCOME*********\n";
	cout<<"Menu\n";
	cout<<"1.Login\n";
	cout<<"2.Register\n";
	cout<<"Enter Your Choice:\n";
	cin>> choice;
	cout<<endl;
	
	switch(choice){
		case 1:	
			student1=login();
			cout<<"****Welcome: "<<student1.getName();
			displayMainMenu();
			break;
		case 2:
			registr();
			break;
		
	}
	
	int mainMenuChoice;
		
	
	do {
		
			cin >> mainMenuChoice;
		
			//Loop when input is not an integer or not within the range from 1 to 6
			while(!cin || mainMenuChoice < 1 || mainMenuChoice > 6 ) {
			
				//Error Message
				cout << "\nInvalid integer value!\n"
				     << "Enter an integer from 1 to 6: ";
			     
				//Clear the error of previous input
				cin.clear(); 
			
				//Ignore INT_MAX characters of the previous input until '\n' is met
				cin.ignore(INT_MAX,'\n'); 
				cin >> mainMenuChoice;
			}
			
		} while(mainMenuChoice < 1 || mainMenuChoice > 6);
		
			switch(mainMenuChoice){
				case 1:
						
				case 2:
					//student1.addCourse(selectCourse(mainMenuChoice));
					selectCourse(mainMenuChoice);
					break;
				case 3:
					cout<<"coreect";
					break;
				case 4:
					cout<<"coreect";
					break;
				case 5:
					cout<<"coreect";
					break;
				case 6:
					cout<<"coreect";
					break;
			}
}
	
	Student login(){
		int count;
		string user,pass,u,p;
		system("cls");
		cout<<"Enter your username: ";
		cin>> user;
		cout<<"Enter your password: ";
		cin>> pass;
		
		ifstream input("database.txt");
		while(input>>u>>p){	
			if(user==u && pass==p){
				count=1;
				system("cls");
				
				
			}
		}
		input.close();
		if(count== 1 ){
			Student student;
			student.setName(user);
			student.setMatric(pass);
			cout<<"Hello"<<"null"<<"\n <LOGIN SUCCESSFUL> \n";
			cin.get();
			
			return student;
		}
		else{
			cout<<"login error";
			main();
		}
		}
	
	
	void registr(){
		string reguser,regpass,ru,pu;
		system("cls");
		cout<<"Enter your username: ";
		cin>> reguser;
		cout<<"Enter your password: ";
		cin>> regpass;
		
		ofstream reg("database.txt",ios::app);
		reg<<reguser<<" "<<regpass<<endl;
		system("cls");
		cout<<"\n Registration Completed!";
		main();
	}
	
	void displayMainMenu(){
		
	
		
		cout << "\n  << Course Registration System >>\n\n"
	     << " 1)  Register a Course\n"
	     << " 2)  Search Course\n" 
	     << " 3)  List of Courses & Requirement\n"
	     << " 4)  View summary my course\n"
	     << " 5)  View activity log\n"
	     << " 6)  Exit Program\n\n"
	     << "Enter an option: ";
	}
	
		void displayCourse(){
		
	
		
		cout << "\n  << Course Registration System >>\n\n"
	     << " 1)  Register a Course\n"
	     << " 2)  Search Course\n" 
	     << " 3)  List of Courses & Requirement\n"
	     << " 4)  View summary my course\n"
	     << " 5)  View activity log\n"
	     << " 6)  Exit Program\n\n"
	     << "Enter an option: ";
	}
	
	
	void buildCourse(){
		
    char fileName[]=".\\data\\CourseList.dat";
	ifstream ifile(fileName);
	int catalog, credit;
	string cname;
	int ocNum=0;
	int ecNum=0;
	
	while(ifile>>catalog>>cname>>credit){
		switch (catalog){
		case 1:
			oc[ocNum++]=new ObligatoryCourse(cname, credit);
			break;
		case 2:
			ec[ecNum++]=new ElectiveCourse(cname, credit);
			break;
		}
	}
	ifile.close();

	
}

void selectCourse(int op){
	int i, choice=-1;
    switch(op)
    {
        case 1: 
            cout<<"Please Choose 1 Major:\n";
            while((choice>ocNum)||(choice<0)){
                for(i=0;i<ocNum;i++){
                    cout<<"\t"<<i+1<<"."<<*oc[i];
                }
                cout<<"\tCancelling Add Course\n";
                cout<<"Your Choices are:";
                cin>>choice;
            }
            if (choice!=0) return oc[choice-1];
            break;
        case 2: 
            cout<<"Please Choose 1 Minor:\n";
            while((choice>ecNum)||(choice<0)){
                for(i=0;i<ecNum;i++){
                    cout<<"\t"<<i+1<<"."<<*ec[i];
                }
                cout<<"\tCancelling Add Course\n";
                cout<<"Your Choices are:";
                cin>>choice;
            }
            if (choice!=0) return ec[choice-1];
            break;
    }
    
}
	
	
	
	
	//Student lun;
	//lun.setName("LUN");
	//lun.getName();
	//lun.setMatric(12111);
//	cout<< lun.getMatric();

