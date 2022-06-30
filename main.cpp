#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h> 
#include "Student.h"
#include "courseList.h"

using namespace std;

Student login();
void registr();
void displayMainMenu();
void buildCourse(string[], int[]);
int selectCourse(string[]);


int main(){
	HANDLE  hConsole;
	  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 
	  SetConsoleTextAttribute(hConsole, 10);
	string course[14];
	int unit[14];
	courseList * courseList1=new courseList;
	Student student1;
	buildCourse(course,unit);
	
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
		
	int i=0;
	while(i==0) {
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
					
					courseList1->insertCourse(selectCourse(course));
					//system("cls");
					courseList1->print();
					displayMainMenu();
					
		
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
					i=1;
					cout<< "\n\n\n\n\t\t=========================================================";
					cout<< "\n\n\n\n\t\t===Thank you for using our program! Have a nice day!===";
					cout<< "\n\n\n\n\t\t=========================================================";
					break;
			}
			
			
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
			cout<<"\n <LOGIN SUCCESSFUL> \n";
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
		HANDLE  hConsole;
	  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);

		
		cout << "\n  << Course Registration System >>\n\n"
	     << " 1)  Register a Course\n"
	     << " 2)  Search Course\n" 
	     << " 3)  List of Courses & Requirement\n"
	     << " 4)  View summary my course\n"
	     << " 5)  View activity log\n"
	     << " 6)  Exit Program\n\n"
	     << "Enter an option: ";
	}
	

	
	void buildCourse(string course[], int unit[]){
		
	ifstream ifile("CourseList.txt");
	int catalog, credit;
	string cname;
	int ocNum=0;
	int ecNum=0;	
	
	while(ifile>>catalog>>cname>>credit){
		switch (catalog){
		case 1:
			course[ocNum++]=cname;
			unit[ecNum++]=credit;
		
			break;
		}
	}
	
	
	ifile.close();

	
}

int selectCourse(string course[]){
	int k=14;
	int choice=-1;

            cout<<"Please Choose A Course:\n";
            while((choice>k)||(choice<0)){
                for(int i=0;i<k;i++){
                    cout<<"\t"<<i+1<<"."<<course[i]<<endl;
                }
                cout<<"\tCancelling Add Course\n";
                cout<<"Your Choices are:";
                cin>>choice;
            }
            if (choice!=0) return choice-1;
            
      
    
    
}
	
	
	
	
	//Student lun;
	//lun.setName("LUN");
	//lun.getName();
	//lun.setMatric(12111);
//	cout<< lun.getMatric();

