//*********************
//                   HEADER FILE USED IN PROJECT
//**********************

#include<iostream>
#include<fstream>
#include<iomanip>
#include <iterator> 
#include <map> 
using namespace std;
//*********************
//                   CLASS USED IN PROJECT
//**********************

class student
{
  int std;	
	char div;
	int rollno;
	char name[50];
	int ss_marks, h_marks, m_marks, e_marks, s_marks;
	double per;
	char grade;
	void calculate();	//function to calculate grade
public:
	void getdata();		//function to accept data from user
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
	int retrollno() const;
	int retstd() const;
	char retdiv() const;
}; //class ends here


void student::calculate()
{
	per=(ss_marks+h_marks+m_marks+e_marks+s_marks)/5.0;
	if(per>=60)
		grade='A';
	else if(per>=50)
		grade='B';
	else if(per>=33)
		grade='C';
	else
		grade='F';
}

void student::getdata()
{
	cout<<"\nEnter The STD  of student :";
	cin>>std;
	cout<<"\nEnter The DIV  of student :";
	cin>>div;
	cout<<"\nEnter The roll number of student: ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student: ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The marks in social science out of 100 : ";
	cin>>ss_marks;
	cout<<"\nEnter The marks in hindi out of 100 : ";
	cin>>h_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in  science out of 100 : ";
	cin>>s_marks;
	calculate();
}

void student::showdata() const
{
	cout<<"\nSTD  of student : "<<std;
	cout<<"\nDIV  of student : "<<div;
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in social science : "<<ss_marks;
	cout<<"\nMarks in hindi : "<<h_marks;
	cout<<"\nMarks in Maths : "<<m_marks;
	cout<<"\nMarks in English : "<<e_marks;
	cout<<"\nMarks in  Science :"<<s_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}

void student::show_tabular() const
{
	cout<<"  "<<std<<setw(4)<<"   "<<div<<setw(10)<<""<<rollno<<setw(6)<<"    "<<name<<setw(10)<<ss_marks<<setw(4)<<h_marks<<setw(4)<<m_marks<<setw(4)
		<<e_marks<<setw(4)<<s_marks<<setw(8)<<per<<setw(6)<<grade<<endl;
}

int  student::retrollno() const
{
	return rollno;
}
int  student::retstd() const
{
	return std;
}
char  student::retdiv() const
{
	return div;
}

//*********************
//    	function declaration
//**********************

void write_student();	//write the record in binary file
void display_all();	//read all records from binary file
void display_sp(int);	//accept rollno and read record from binary file
void modify_student(int,char,int);	//accept rollno and update record of binary file
void delete_student(int);	//accept rollno and delete selected records from binary file
void class_result();	//display all records in tabular format from binary file
void result();		//display result menu
void intro();		//display welcome screen
void entry_menu();	//display entry menu on screen


//*********************
//    	THE MAIN FUNCTION OF PROGRAM
//**********************

void login()
{
string user , pass;
map<string , string> mp;
//   register :
//   ... get username and password into "user" and "pass"
mp.insert(pair<string,string>("priyankayadav","priy@123"));
mp.insert(pair<string,string>("Shubhamdhanwat","shub@123"));
mp.insert(pair<string,string>("Rajahire","raj@123"));
mp.insert(pair<string,string>("kushalpatil","kush@123"));
mp[user]=pass;
cout<<"============LOGIN========="<<endl;
cout<<"username :";
cin>>user;
cout<<"pasword :";
cin>>pass;
//  login :
//  ... get username and password into "user" and "pass"
if ( (mp.find(user)==mp.end()) || (mp[user]!=pass) ) 
    {cout<<"LOGIN FAILED!!!!!!!"; 
     cout<<"\nEnter new password: ";
     cin>>mp[pass];
    
    }
else cout<<"LOGIN SUCCESS!!!!!!\n";


}

int main()
{
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	intro();
  login();
	do
	{

		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		switch(ch)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}
    }while(ch!='3');
	return 0;
}

//*********************
//    	function to write in file
//**********************

void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}

//*********************
//    	function to read all records from file
//**********************

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

//*********************
//    	function to read specific record from file
//**********************

void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

//*********************
//    	function to modify record of file
//**********************

void modify_student(int n)
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
    	while(!File.eof() && found==false)
	{

		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    	cout<<"\n\n\t Record Updated!!";
		    	found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found--- ";
	cin.ignore();
	cin.get();
}

//*********************
//    	function to delete record of file
//**********************

void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ......";
	cin.ignore();
	cin.get();
}

//*********************
//    	function to display all students grade report
//**********************

void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\t\t\t\tALL STUDENTS RESULT \n\n";
	cout<<"============================================================================\n";
	cout<<" STD   DIV       R.No     Name        SS   H   M   E   S   %age   Grade"<<endl;
	cout<<"===========================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}

//*********************
//    	function to display result menu
//**********************

void result()
{
	char ch;
	int rno;
  int std;
  char div;
	cout<<"\n\n\n\t*RESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>ch;

	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter  STD Of Student : "; cin>>std;
				display_sp(std);
				cout<<"\n\n\tEnter DIV Of Student : "; cin>>div;
				display_sp(div);
				cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
				display_sp(rno); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}

void intro()
{
  cout<<"\t\t\t\tGIRL SCRIPT :C++ COURSE\n ";
  cout<<"\t\t\t***STUDENT RECORD SYSTEM**** \n";
  cout<<"\t\tPROJECT BY:-Shubham Rajesh Dhanwat";
	cin.get();
}

//*********************
//    	ENTRY / EDIT MENU FUNCTION
//**********************

void entry_menu()
{
	char ch;
	int num;
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) :";
	cin>>ch;

	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			delete_student(num);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
}

//*********************
//    			END OF PROJECT
//*********************
