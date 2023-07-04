#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
class student
{
	char name[20],fname[20],add[50];
	int enroll;
	long contact;
	public:
		void addstudent()
		{
			fstream f1("student.dat",ios::binary|ios::app);
			student s1;
			s1.setdata();
			f1.write((char*)&s1,sizeof(s1));
			f1.close();
		}
		void setdata()
		{
			cout<<"enter name=";
			cin>>name;
			cout<<"enter father name=";
			cin>>fname;
			cout<<"enter enroll no.=";
			cin>>enroll;
			cout<<"enter contact=";
			cin>>contact;
			cout<<"enter address=";
			cin>>add;
		}
		void showstudent()
		{
			student s1;
			fstream f2("student.dat",ios::binary|ios::in);
			cout<<"\n--------------------------------------------------------------------------";
			cout<<endl<<setiosflags(ios::left)<<setw(10)<<"Name"<<setw(10)<<"F.name"<<setw(10)<<"enroll"<<setw(10)<<"contact"<<setw(15)<<"address";
			cout<<"\n--------------------------------------------------------------------------";
			while(f2.read((char*)&s1,sizeof(s1)))
			{
				cout<<endl<<setiosflags(ios::left)<<setw(10)<<s1.name<<setw(10)<<s1.fname<<setw(10)<<s1.enroll<<setw(10)<<s1.contact<<setw(15)<<s1.add;
			}
			cout<<"\n---------------------------------------------------------------------------";
			f2.close();
		}
		void deletestudent()
		{
			int r;
			cout<<"enter a enroll no to delete=";
			cin>>r;
			fstream f1("student.dat",ios::binary|ios::in);
			fstream f2("temp.dat",ios::binary|ios::out);
			student s1;
			while(f1.read((char*)&s1,sizeof(s1)))
			{

				if(s1.enroll!=r)
				{
					f2.write((char*)&s1,sizeof(s1));
				}
			}
			f1.close();
			f2.close();
			remove("student.dat");
			rename("temp.dat","student.dat");
		}
		void searchstudent()
		{
			int r,flag=0;
			cout<<"enter no. to be searched=";
			cin>>r;
			fstream f1("student.dat",ios::binary|ios::in);
			student s1;
			while(f1.read((char*)&s1,sizeof(s1)))
			{
				if(s1.enroll==r)
				{
					cout<<"\nrecord found";
					cout<<endl<<setiosflags(ios::left)<<setw(10)<<s1.name<<setw(10)<<s1.fname<<setw(10)<<s1.enroll<<setw(10)<<s1.contact<<setw(15)<<s1.add;
					flag=1;
				}
			 }
			if(flag==0)
			{
				cout<<endl<<"result not found";
			}
		}
		void updatestudent()
		{
			int r;
			cout<<"enter a enroll no to update=";
			cin>>r;
			fstream f1("student.dat",ios::binary|ios::in);
			fstream f2("temp.dat",ios::binary|ios::out);
			student s1;
			while(f1.read((char*)&s1,sizeof(s1)))
			{

				if(s1.enroll!=r)
				{
					f2.write((char*)&s1,sizeof(s1));
				}
				else
				{
					s1.setdata();
					f2.write((char*)&s1,sizeof(s1));
				}
			}
			f1.close();
			f2.close();
			remove("student.dat");
			rename("temp.dat","student.dat");
		}
};
class fee
{
	char date[20];
	int recipt;
	long amount;
	public:
		int getmaxreciptno()
		{
			fstream f1("fee.dat",ios::binary|ios::in);
			fee a1;
			int max=0;
			while(f1.read((char*)&a1,sizeof(a1)))
			{
				if(a1.recipt>max)
				{
					max=a1.recipt;
				}
			}

			return max;
			f1.close();
		}
		void addfee()
		{
			fstream f1("fee.dat",ios::binary|ios::app);
			fee a1;
			a1.setfee();
			f1.write((char*)&a1,sizeof(a1));
			f1.close();
		}
		void setfee()
		{
			cout<<endl<<"enter following details:";
			cout<<"enter reciept num=";
			cin>>recipt;
			cout<<"enter amount=";
			cin>>amount;
			cout<<"enter date=";
			cin>>date;
		}
		void showfee()
		{
			fee a1;
			fstream f2("fee.dat",ios::binary|ios::in);
			cout<<"\n--------------------------------------------------------------------------";
			cout<<endl<<setiosflags(ios::left)<<setw(10)<<"recipt"<<setw(10)<<"amount"<<setw(10)<<"date";
			cout<<"\n--------------------------------------------------------------------------";
			while(f2.read((char*)&a1,sizeof(a1)))
			{
				cout<<endl<<setiosflags(ios::left)<<setw(10)<<a1.recipt<<setw(10)<<a1.amount<<setw(15)<<a1.date;
			}
			cout<<"\n---------------------------------------------------------------------------";
			f2.close();
		}
		void deletefee()
		{
			int r;
			cout<<"enter a recipt no. to delete=";
			cin>>r;
			fstream f1("fee.dat",ios::binary|ios::in);
			fstream f2("ment.dat",ios::binary|ios::out);
			fee a1;
			while(f1.read((char*)&a1,sizeof(a1)))
			{

				if(a1.recipt!=r)
				{
					f2.write((char*)&a1,sizeof(a1));
				}
			}
			f1.close();
			f2.close();
			remove("fee.dat");
			rename("ment.dat","fee.dat");
		}
		void searchfee()
		{
			int r,flag=0;
			cout<<"enter recipt no. to be searched=";
			cin>>r;
			fstream f1("fee.dat",ios::binary|ios::in);
			fee a1;
			while(f1.read((char*)&a1,sizeof(a1)))
			{
				if(a1.recipt==r)
				{
					cout<<"\nr2ecord found";
					cout<<endl<<setiosflags(ios::left)<<setw(10)<<a1.recipt<<setw(10)<<a1.amount<<setw(10)<<a1.date;
					flag=1;
				}

			}
			if(flag==0)
			{
				cout<<endl<<"result not found";
			}
		}
		void updatefee()
		{

			int r;
			cout<<"enter a recipt no to update=";
			cin>>r;
			fstream f1("fee.dat",ios::binary|ios::in);
			fstream f2("ment.dat",ios::binary|ios::out);
			fee a1;
			while(f1.read((char*)&a1,sizeof(a1)))
			{

				if(a1.recipt!=r)
				{
					f2.write((char*)&a1,sizeof(a1));
				}
				else
				{
					a1.setfee();
					f2.write((char*)&a1,sizeof(a1));
				}
			}
			f1.close();
			f2.close();
			remove("fee.dat");
			rename("ment.dat","fee.dat");
		}

};
main()
{
	student s1;
	fee a1;
	int choice;
	clrscr();
	while(1)
	{
		START:
		cout<<"\nWelcome to STUDENT FEE MANAGEMENT SYSTEM"<<endl<<"MAIN MENU";
		cout<<"\n1.Student Master";
		cout<<"\n2.Fee Master";
		cout<<"\n3.Exit";
		cout<<"\nenter your choice=";
		cin>>choice;
		switch(choice)
		{
			case 1:
				while(1)
				{
					cout<<"STUDENT MASTER";
					cout<<"\n1.Add student";
					cout<<"\n2.Show Record";
					cout<<"\n3.Delete Record";
					cout<<"\n4.Search record";
					cout<<"\n5.Update record";
					cout<<"\n6.Back to MAIN MENU";
					cout<<"\nEnter your choice";
					cin>>choice;
					switch(choice)
					{
						case 1:
							s1.addstudent();
							break;
						case 2:
							s1.showstudent();
							break;
						case 3:
							s1.deletestudent();
							break;
						case 4:
							s1.searchstudent();
							break;
						case 5:
							s1.updatestudent();
							break;
						default:
							goto START;

					}

				}
				break;
			case 2:
				while(1)
				{
					cout<<"FEE MASTER";
					cout<<"\n1.add fee";
					cout<<"\n2.show fee";
					cout<<"\n3.delete fee";
					cout<<"\n 4.search fee";
					cout<<"\n 5.update fee";
					cout<<"\n6.show max recipt num";
					cout<<"\n7.Back to MAIN MENU";

					cout<<"\nEnter your choice";
					cin>>choice;
					switch(choice)
					{
						case 1:
							a1.addfee();
							break;
						case 2:
							a1.showfee();
							break;
						case 3:
							a1.deletefee();
							break;
						case 4:
							a1.searchfee();
							break;
						case 5:
							a1.updatefee();
							break;
						case 6:
						       cout<<a1.getmaxreciptno();
							break;

						default:
							goto START;
					}
				}
				break;

			default:
				exit(1);
				break;
		}

	}
	getch();

}