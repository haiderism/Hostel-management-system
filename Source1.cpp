#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
class node {
public:
	string f_name;
	string l_name;
	string roll;
	string room;
	string dept;
	string contact;
	int bill;
	int laundary;
	int internet;
	int security;
	node* next;
	node* prev;
	node()
	{
		f_name = "0";
		l_name = "0";
		roll = "0";
		room = "0";
		dept = "0";
		contact = "0";
		bill = 0;
		laundary = 0;
		internet = 0;
		security = 0;

	}
};

class hostel {
	node* head;
	node* tail;
public:
	hostel()
	{

		head = NULL;
		tail = NULL;

	}

	void insert()
	{
		node* newstd = new node();
		ofstream write;
		write.open("hostel.dat", ios::app);

		string nam1;
		cout << "Enter First Name: " << endl;
		cout << "\t";
		cin >> nam1;

		string nam2;
		cout << "Enter Second Name: " << endl;
		cout << "\t";
		cin >> nam2;
		cin.ignore();
		newstd->f_name = nam1;
		newstd->l_name = nam1;

		write << nam1 << " " << nam2 << endl;
		


		string rol;
		cout << "Enter roll number: " << endl;
		cout << "\t";
		cin >> rol;
		newstd->roll = rol;
		write << rol << endl;

		string rome;
		cout << "Enter Alloted Room No.: " << endl;
		cout << "\t";
		cin >> rome;
		newstd->room = rome;
		write << rome << endl;

		string dep;
		cout << "Enter Department: " << endl;
		cout << "\t";
		cin >> dep;
		newstd->dept = dep;
		write << dep << endl;

		string contct;
		cout << "Enter contact number: " << endl;
		cout << "\t";
		cin >> contct;
		newstd->contact = contct;
		write << contct << endl;

		int bil;
		bil = 0;
		newstd->bill = bil;
		write << bil << endl;

		int lon;
		lon = 0;
		newstd->laundary = lon;
		write << lon << endl;

		int inter;
		inter = 2500;
		newstd->internet = inter;
		write << inter << endl;

		int sec;
		sec = 5000;
		newstd->security = sec;
		write << sec << endl;

		write.close();

		if (tail != NULL)
		{
			newstd->prev = tail;
			tail->next = newstd;
			tail = newstd;
		}
		else
		{
			head = newstd;
			tail = newstd;
		}

		cout << " Student added Sucessfully" << endl << endl << endl;
		string k;
		cout << "press any key to exit......";
		cin >> k;
	}

	void mess_manejo()
	{
		cout << "      Mess Manejo welcomes you  " << endl << endl;
		int y;

		cout << "   Enter price of today's meal " << endl;
		cin >> y;
		string rool;
		cout << "enter roll number: " << endl;
		cin >> rool;

		ifstream write1;

		write1.open("hostel.dat");

		while (!write1.eof())
		{
			node* newstu = new node();

			write1 >> newstu->f_name >> newstu->l_name;

			write1 >> newstu->roll;

			write1 >> newstu->room;

			write1 >> newstu->dept;

			write1 >> newstu->contact;
			if (newstu->roll == rool)
			{
				int bil;
				write1 >> bil;
				bil = bil + y;
				newstu->bill = bil;
			}
			else
			{
				write1 >> newstu->bill;
			}

			write1 >> newstu->laundary;


			write1 >> newstu->internet;


			write1 >> newstu->security;


			if (tail != NULL)
			{
				newstu->prev = tail;
				tail->next = newstu;
				tail = newstu;
			}
			else
			{
				head = newstu;
				tail = newstu;
			}
		}
		write1.close();

		node* temp = head;
		ofstream writedata;
		writedata.open("hostel.dat");
		while (temp->next != NULL)
		{

			writedata << temp->f_name << " " << temp->l_name << endl;
			writedata << temp->roll << endl;
			writedata << temp->room << endl;
			writedata << temp->dept << endl;
			writedata << temp->contact << endl;
			writedata << temp->bill << endl;
			writedata << temp->laundary << endl;
			writedata << temp->internet << endl;
			writedata << temp->security << endl;
			temp = temp->next;
		}
		writedata.close();

		string k;
		cout << "press any key to exit......";
		cin >> k;

	}
	void billing()
	{
		cout << "        Welcome to Billing Section     " << endl << endl;

		string rool;
		cout << "enter roll number: " << endl;
		cin >> rool;

		ifstream write1;

		write1.open("hostel.dat");

		while (!write1.eof())
		{
			node* newstu = new node();

			write1 >> newstu->f_name >> newstu->l_name;

			write1 >> newstu->roll;

			write1 >> newstu->room;

			write1 >> newstu->dept;

			write1 >> newstu->contact;

			write1 >> newstu->bill;

			write1 >> newstu->laundary;

			write1 >> newstu->internet;

			write1 >> newstu->security;

			if (tail != NULL)
			{
				newstu->prev = tail;
				tail->next = newstu;
				tail = newstu;
			}
			else
			{
				head = newstu;
				tail = newstu;
			}
		}
		write1.close();

		node* temp = head;
		node* temp1 = temp;
		while (temp1->next != NULL)
		{
			if (temp1->roll == rool)
			{
				int total;
				cout << "      Mess Bill is =" << temp1->bill << endl;
				cout << "      Laundary Bill is =" << temp1->laundary << endl;
				cout << "      Internet Bill is =" << temp1->internet << endl;
				total = temp1->bill + temp1->laundary + temp1->internet;
				cout << "      Your Total Bill is = " << total << endl << endl << endl;
				int p;
				cout << "            Press 1 if you want to Pay Bill   " << endl;
				cout << "\t";
				cout << "            Press 2 to exit   " << endl;
				cout << "\t";
				cin >> p;
				if (p == 1)
				{
					temp1->bill = 0;
					temp1->laundary = 0;
					cout << "Bill Paid" << endl;
				}
				else if (p == 2)
				{
					goto i;
				}


			}
			temp1 = temp1->next;
		}
	i:
		ofstream writedata;
		writedata.open("hostel.dat");
		while (temp->next != NULL)
		{
			writedata << temp->f_name << " " << temp->l_name << endl;
			writedata << temp->roll << endl;
			writedata << temp->room << endl;
			writedata << temp->dept << endl;
			writedata << temp->contact << endl;
			writedata << temp->bill << endl;
			writedata << temp->laundary << endl;
			writedata << temp->internet << endl;
			writedata << temp->security << endl;
			temp = temp->next;
		}
		writedata.close();

		string k;
		cout << "press any key to exit......";
		cin >> k;
	}


	void search()
	{
		cout << "        Welcome to Search Section     " << endl << endl;

		string rool;
		cout << "enter roll number: " << endl;
		cin >> rool;

		ifstream write1;

		write1.open("hostel.dat");

		while (!write1.eof())
		{
			node* newstu = new node();

			write1 >> newstu->f_name >> newstu->l_name;

			write1 >> newstu->roll;

			write1 >> newstu->room;

			write1 >> newstu->dept;

			write1 >> newstu->contact;

			write1 >> newstu->bill;

			write1 >> newstu->laundary;

			write1 >> newstu->internet;

			write1 >> newstu->security;

			if (tail != NULL)
			{
				newstu->prev = tail;
				tail->next = newstu;
				tail = newstu;
			}
			else
			{
				head = newstu;
				tail = newstu;
			}
		}
		write1.close();

		node* temp = head;
		node* temp1 = temp;
		while (temp1->next != NULL)
		{
			if (temp1->roll == rool)
			{
				cout << " name =" << temp1->f_name << " " << temp1->l_name << endl;
				cout << " Room No =" << temp1->room << endl;
				cout << " Department =" << temp1->dept << endl;
				cout << " Contact No =" << temp1->contact << endl;
				cout << " Mess Bill  =" << temp1->bill << endl;
				cout << " Laundry Bill =" << temp1->laundary << endl;
				cout << " Security Fee Paid =" << temp1->security << endl;

			}
			temp1 = temp1->next;
		}
	i:
		ofstream writedata;
		writedata.open("hostel.dat");
		while (temp->next != NULL)
		{
			writedata << temp->f_name << " " << temp->l_name << endl;
			writedata << temp->roll << endl;
			writedata << temp->room << endl;
			writedata << temp->dept << endl;
			writedata << temp->contact << endl;
			writedata << temp->bill << endl;
			writedata << temp->laundary << endl;
			writedata << temp->internet << endl;
			writedata << temp->security << endl;
			temp = temp->next;
		}
		writedata.close();
		string k;
		cout << "press any key to exit......";
		cin >> k;
	}

	void bill_clearance()
	{
		cout << "        Bill Clearance Section    " << endl << endl;

		cout << "        lists of Students who donot Pay Bill " << endl;


		ifstream write1;

		write1.open("hostel.dat");

		while (!write1.eof())
		{
			node* newstu = new node();

			write1 >> newstu->f_name >> newstu->l_name;

			write1 >> newstu->roll;

			write1 >> newstu->room;

			write1 >> newstu->dept;

			write1 >> newstu->contact;

			write1 >> newstu->bill;

			write1 >> newstu->laundary;

			write1 >> newstu->internet;

			write1 >> newstu->security;

			if (tail != NULL)
			{
				newstu->prev = tail;
				tail->next = newstu;
				tail = newstu;
			}
			else
			{
				head = newstu;
				tail = newstu;
			}
		}
		write1.close();

		node* temp = head;
		node* temp1 = temp;
		int v = 0;
		while (temp1->next != NULL)
		{
			if (temp1->bill != 0 || temp1->laundary != 0)
			{
				cout << " Name =" << temp1->f_name << " " << temp1->l_name << endl;
				cout << " Room No =" << temp1->room << endl;
				cout << " Department =" << temp1->dept << endl;
				cout << " Contact No =" << temp1->contact << endl;
				cout << " Mess Bill  =" << temp1->bill << endl;
				cout << " Laundry Bill =" << temp1->laundary << endl;
				cout << " Internet Bill =" << temp1->internet << endl;
				cout << " Security Fee Paid =" << temp1->security << endl;
				int amount;
				amount = temp1->bill + temp1->laundary + temp1->internet;
				cout << " Total Payable Bill is =" << amount << endl;
				cout << endl << endl;
				v++;

			}





			temp1 = temp1->next;
		}
		if (v == 0)
		{
			cout << " All Student paid their Bill" << endl;
		}
	i:
		ofstream writedata;
		writedata.open("hostel.dat");
		while (temp->next != NULL)
		{
			writedata << temp->f_name << " " << temp->l_name << endl;
			writedata << temp->roll << endl;
			writedata << temp->room << endl;
			writedata << temp->dept << endl;
			writedata << temp->contact << endl;
			writedata << temp->bill << endl;
			writedata << temp->laundary << endl;
			writedata << temp->internet << endl;
			writedata << temp->security << endl;
			temp = temp->next;
		}
		writedata.close();
		string k;
		cout << "press any key to exit......";
		cin >> k;
	}

	void update()
	{
		cout << "        Welcome to Update Section     " << endl << endl;

		string rool;
		cout << "enter roll number: " << endl;
		cin >> rool;

		ifstream write1;

		write1.open("hostel.dat");

		while (!write1.eof())
		{

			node* newstu = new node();

			write1 >> newstu->f_name >> newstu->l_name;

			write1 >> newstu->roll;

			write1 >> newstu->room;

			write1 >> newstu->dept;

			write1 >> newstu->contact;

			write1 >> newstu->bill;

			write1 >> newstu->laundary;

			write1 >> newstu->internet;

			write1 >> newstu->security;

			if (tail != NULL)
			{
				newstu->prev = tail;
				tail->next = newstu;
				tail = newstu;
			}
			else
			{
				head = newstu;
				tail = newstu;
			}
		}
		write1.close();

		node* temp = head;
		node* temp1 = temp;
		while (temp1->next != NULL)
		{


			if (temp1->roll == rool)
			{

			hl:
				int d;
				cout << "      Choose which you want to update: " << endl;
				cout << "      1-  Name " << endl;
				cout << "      2-  Roll No. " << endl;
				cout << "      3-  Room " << endl;
				cout << "      4-  Department " << endl;
				cout << "      5-  Contact " << endl;


				cin >> d;
				if (d == 1)
				{
					string j;
					cout << "Enter updated Name = " << endl;

					cout << " First Name= " << endl;
					cin >> j;
					string k;
					cout << " Second Name= " << endl;
					cin >> k;
					temp1->f_name = j;
					temp1->l_name = k;
				}
				else if (d == 2)
				{
					string k;
					cout << "Enter updated Roll No. = " << endl;
					cin >> k;
					temp1->roll = k;
				}
				else if (d == 3)
				{
					string p;
					cout << "Enter updated Room No. = " << endl;
					cin >> p;
					temp1->room = p;
				}
				else if (d == 4)
				{
					string l;
					cout << "Enter updated Department = " << endl;
					cin >> l;
					temp1->dept = l;
				}
				else if (d == 5)
				{
					string m;
					cout << "Enter updated Contact = " << endl;
					cin >> m;
					temp1->contact = m;
				}
				else
				{
					cout << "invalid Input Try again" << endl;
					goto hl;
				}
			}
			temp1 = temp1->next;
		}
		ofstream writedata;
		writedata.open("hostel.dat");
		while (temp->next != NULL)
		{

			writedata << temp->f_name << " " << temp->l_name << endl;
			writedata << temp->roll << endl;
			writedata << temp->room << endl;
			writedata << temp->dept << endl;
			writedata << temp->contact << endl;
			writedata << temp->bill << endl;
			writedata << temp->laundary << endl;
			writedata << temp->internet << endl;
			writedata << temp->security << endl;
			temp = temp->next;
		}
		writedata.close();

		string k;
		cout << "press any key to exit......";
		cin >> k;
	}

	void laundary()
	{
		cout << "      Laundary Manejo Welcomes you  " << endl << endl;
		int y;
		cout << "   Enter Laundary Amount " << endl;
		cin >> y;
		string rool;
		cout << "enter roll number: " << endl;
		cin >> rool;


		ifstream write1;

		write1.open("hostel.dat");

		while (!write1.eof())
		{
			node* newstu = new node();

			write1 >> newstu->f_name >> newstu->l_name;

			write1 >> newstu->roll;

			write1 >> newstu->room;

			write1 >> newstu->dept;

			write1 >> newstu->contact;

			write1 >> newstu->bill;


			if (newstu->roll == rool)
			{

				int lon;
				write1 >> lon;
				lon = lon + y;

				newstu->laundary = lon;
			}
			else
			{
				write1 >> newstu->laundary;

			}

			write1 >> newstu->internet;


			write1 >> newstu->security;


			if (tail != NULL)
			{

				newstu->prev = tail;
				tail->next = newstu;
				tail = newstu;
			}
			else
			{
				head = newstu;
				tail = newstu;
			}
		}
		write1.close();

		node* temp = head;

		ofstream writedata;
		writedata.open("hostel.dat");
		while (temp->next != NULL)
		{
			writedata << temp->f_name << " " << temp->l_name << endl;
			writedata << temp->roll << endl;
			writedata << temp->room << endl;
			writedata << temp->dept << endl;
			writedata << temp->contact << endl;
			writedata << temp->bill << endl;
			writedata << temp->laundary << endl;
			writedata << temp->internet << endl;
			writedata << temp->security << endl;
			temp = temp->next;
		}
		writedata.close();

		string k;
		cout << "press any key to exit......";
		cin >> k;
	}

	void delete_Data()
	{
		cout << "        Welcome to Delete Section     " << endl << endl;

		string rool;
		cout << "enter roll number: " << endl;
		cin >> rool;

		ifstream write1;

		write1.open("hostel.dat");

		while (!write1.eof())
		{


			node* newstu = new node();

			write1 >> newstu->f_name >> newstu->l_name;

			write1 >> newstu->roll;

			write1 >> newstu->room;

			write1 >> newstu->dept;

			write1 >> newstu->contact;

			write1 >> newstu->bill;

			write1 >> newstu->laundary;


			write1 >> newstu->internet;


			write1 >> newstu->security;


			if (tail != NULL)
			{

				newstu->prev = tail;
				tail->next = newstu;
				tail = newstu;
			}
			else
			{
				head = newstu;
				tail = newstu;
			}
		}
		write1.close();



		node* temp = head;
		node* temp1 = head;
		while (temp1->next != NULL)
		{
			if (temp1->roll == rool)
			{
				if (temp1 == head)
				{
					temp1->next->prev = NULL;
					head = head->next;
					temp1->next = NULL;
					delete temp1;
					temp = head;
					goto g;
				}
				else if (temp1 != head && temp1 != tail)
				{

					temp1->next->prev = temp1->prev;
					temp1->prev->next = temp1->next;
					temp1->next = NULL;
					temp1->prev = NULL;
					delete temp1;
					goto g;

				}
				else if (temp1 == tail)
				{
					temp1->prev->next = NULL;
					tail = tail->prev;
					temp1->prev = NULL;
					delete temp1;
					goto g;
				}
			}
			temp1 = temp1->next;
		}
	g:

		ofstream writedata;
		writedata.open("hostel.dat");
		while (temp->next != NULL)
		{

			writedata << temp->f_name << " " << temp->l_name << endl;
			writedata << temp->roll << endl;
			writedata << temp->room << endl;
			writedata << temp->dept << endl;
			writedata << temp->contact << endl;
			writedata << temp->bill << endl;
			writedata << temp->laundary << endl;
			writedata << temp->internet << endl;
			writedata << temp->security << endl;
			temp = temp->next;
		}
		writedata.close();

		string k;
		cout << "press any key to exit......";
		cin >> k;
	}
};





void main()
{
	cout << "          ~~ Hostel Manejo ~~         " << endl;
	cout << "                 v6.889                    " << endl << endl << endl << endl;
k:
j:
	int m;

	hostel b;
	cout << "          Select any one of the following option   " << endl << endl;
	cout << "      1-  New Student " << endl;
	cout << "      2-  Daily Mess Manejo " << endl;
	cout << "      3-  Laundary Manejo " << endl;
	cout << "      4-  Billing " << endl;
	cout << "      5-  Update " << endl;
	cout << "      6-  Search " << endl;
	cout << "      7-  Bill Clearance " << endl;
	cout << "      8-  Delete " << endl;
	cout << "      9-  Exit " << endl;
	cin >> m;
	system("CLS");
	switch (m)
	{
	case 1:

		b.insert();
		system("CLS");
		break;
	case 2:
		b.mess_manejo();
		system("CLS");
		break;
	case 3:
		b.laundary();
		system("CLS");
		break;
	case 4:
		b.billing();
		system("CLS");
		break;
	case 5:
		b.update();
		system("CLS");
		break;
	case 6:
		b.search();
		system("CLS");
		break;
	case 7:
		b.bill_clearance();
		system("CLS");
		break;
	case 8:
		b.delete_Data();
		system("CLS");
		break;
	case 9:
		goto p;
		system("CLS");
		break;
	default:
		cout << "Invalid input try again" << endl;
		system("CLS");
		goto k;

	}
	goto j;
p:
	cout << "    Thanks for using Hostel Manejo ";




}