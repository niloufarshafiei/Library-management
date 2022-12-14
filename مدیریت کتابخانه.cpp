// مدیریت کتابخانه.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Date.h"
#include <conio.h>
using namespace std;
class Bad_melli_Exception {};
class Person {
public:

	Person() {};
	Person(string N, string F, string N_code, int id, int d, int m, int y)
		:Name(N), Family(F), National_code(N_code), Id(id), birthDate(d, m, y) {}

	void set_Name(string Name);
	void set_Family(string Family);
	void set_Nationalcode(string National_code);
	void set_Id(int Id);
	string get_Name()const;
	string get_Family()const;
	string get_Nationalcode()const;
	string writing();
	string writenationalcode();
	int get_Id()const;
	void setBDate(int d, int m, int y)
	{
		birthDate.setDate(d, m, y);
	}
	virtual void Enter() {};
	virtual void Delet(int id) {};
	virtual void Show() {};
	virtual void Edit(int id) {};
	virtual void Search(int id) {};
	virtual void report() {};
	Date getBDate()
	{
		return birthDate;
	}
protected:
	string Name;
	string Family;
	string National_code;
	int Id;
	Date birthDate;
};
void Person::set_Name(string N) {
	Name = N; 
}
void Person::set_Family(string F) { Family = F; }
void Person::set_Nationalcode(string N_code) { National_code = N_code; }
void Person::set_Id(int id) { Id = id; }
string Person::get_Name()const {
	return Name;
}
string Person::get_Family()const {
	return Family;
}
string Person::get_Nationalcode()const {
	return National_code;
}
int Person::get_Id()const {
	return Id;
}
string Person::writing() {
	char Massage[] = "The txt has number,Try again!";

	string NF;


	try {
		cin >> NF;

		for (int i = 0; i < NF.length(); i++) {
			
			if (!isalpha(NF[i])) {
				throw Massage;
			}
		}
	
	}
	catch (char Massage[]) {
		cout << Massage << endl;
		for (int i = 0; i < NF.length(); i++) {

			while (!isalpha(NF[i])) {
			
				cin >> NF;
			}
		}

	}
	return NF;

}
string Person::writenationalcode() {
	char Massage1[] = "The Code is not true digis, Tray again!";
	
	
	
	try {
		cin >> National_code;
		for (int i = 0; i < National_code.length(); i++) {
			if (National_code.length() > 10 || National_code.length() < 10) {
				throw Massage1;
			}
		}
		for (int i = 0; i < National_code.length(); i++) {
			if (isalpha(National_code[i])) {

				throw Massage1;

			}
		}
	}
	catch (char Massage[]) {
		for (int i = 0; i < National_code.length(); i++) {


			while (National_code.length() > 10 || National_code.length() < 10 || isalpha(National_code[i])) {
				cout << Massage << endl;
				cin >> National_code;

			}
		}


		return National_code;
	}
}

class Member : public Person {
public:
	friend class Amanat;
	Member() {};
	Member(string N, string F, string N_code, int id, int d, int m, int y, string T, string Idnum, int P)
		:Person(N, F, N_code, id, d, m, y), Type(T), Idnumber(Idnum), Penalty(P) {}
	void set_Type(string Type);
	void set_Idnumber(string Idnumber);
	void set_Penalty(int Penalty);
	string get_Type()const;
	string get_Idnumber()const;
	int get_Penalty()const;
	void Enter();
	void Delet(int id);
	void Show();
	void Search(int id);
	void Edit(int id);
	void Payment(int id);
	void Jarime(int id, int jarime);
	void report() {
		birthDate.printDate();
		cout << Name << "   " << Family << "   " << National_code << "   " << Id << "   " << Type << "  " << Idnumber << "   " << Penalty << endl;
	}
private:
	string Type;
	string Idnumber;
	int Penalty;
};
void Member::set_Type(string T) {
	Type = T;
}
void Member::set_Idnumber(string Idnum) {
	Idnumber = Idnum;
}
void Member::set_Penalty(int P) {
	Penalty = P;
}
string Member::get_Type()const {
	return Type;
}
string Member::get_Idnumber()const {
	return Idnumber;
}
int Member::get_Penalty()const {
	return Penalty;
}
vector <Member> member, member1;
void Member::Enter() {


	ofstream Memberfile("Member.txt", ios::app);
	if (!Memberfile) {
		cout << " The file could not be opened!";
		return;
	}

	int i = 0;
	cout << "\n Please  Enter the name of member: ";
	Person N;
	Name = N.writing();
	cout << "\n Enter the family of member: ";
	Person F;
	Family = F.writing();
	cout << "\n Enter the national code of member: ";
	Person nat;
	National_code = nat.writenationalcode();
	int d, m, y;
	cout << "\n Enter the brithday of member:\n";
	try {
		cin >> d >> m >> y;
		birthDate.setDate(d, m, y);
	}
	catch (Bad_Date_Exception ex)
	{
		cout << "The entered data is out of range, Try again";
		cin >> d >> m >> y;
		birthDate.setDate(d, m, y);
	}
	cout << "\n Enter the ID of member: ";
	cin >> Id;
	cout << "\n Enter the member is student OR staff : ";
	Person T;
	Type = T.writing();
	cout << "\n Enter the Idnumber member: ";
	Person nat1;
	Idnumber = nat1.writenationalcode();
	cout << "\n Enter the Penalty of member: ";
	cin >> Penalty;

	member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));

	Memberfile << Name << "\t" << Family << "\t" << National_code << "\t" << Id << "\t" << d << "    " << m << "    " << y

		<< "\t" << Type << "\t" << Idnumber << "\t" << Penalty << "\t" << endl;
	i++;
	Memberfile.close();

}
void Member::Delet(int id) {
	int d, m, y;
	for (int i = 0; i < member.size(); i++) {
		if (member[i].get_Id() == id) {
			member1.push_back(member[i]);
		}
	}
	member = member1;
	vector<Member>().swap(member1);
	ofstream outMemberfile("Memberback.txt", ios::trunc);
	if (!outMemberfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Memberfile("Member.txt", ios::in);
	if (!Memberfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Memberfile >> Name) {
		Memberfile >> Family;
		Memberfile >> National_code;
		Memberfile >> Id;
		Memberfile >> d;
		Memberfile >> m;
		Memberfile >> y;
		Memberfile >> Type;
		Memberfile >> Idnumber;
		Memberfile >> Penalty;
		member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));
		if (member[i].Id == id) {
			;


		}
		else
		{
			outMemberfile << member[i].Name << "\t" << member[i].Family << "\t" << member[i].National_code << "\t" << member[i].Id << "\t" <<
				d << "  " << m << "  " << y << "\t" << member[i].Type << "\t" << member[i].Idnumber << "\t" << member[i].Penalty << "\t" << endl;
		}
		i++;
	}

	outMemberfile.close();
	Memberfile.close();
	remove("Member.txt");
	rename("Memberback.txt", "Member.txt");
}
void Member::Show() {
	int d, m, y;
	ifstream Memberfile("Member.txt", ios::in);
	if (!Memberfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;

	while (Memberfile >> Name) {
		Memberfile >> Family;
		Memberfile >> National_code;
		Memberfile >> Id;
		Memberfile >> d;
		Memberfile >> m;
		Memberfile >> y;
		Memberfile >> Type;
		Memberfile >> Idnumber;
		Memberfile >> Penalty;
		member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));

		cout << member[i].Name << "     " << member[i].Family << "     " << member[i].National_code << "     " << member[i].Id << "    "

			<< d << "/" << m << "/" << y << "     " << member[i].Type << "     " << member[i].Idnumber << "     " << member[i].Penalty << endl;


		i++;
	}
	Memberfile.close();
}
void Member::Edit(int id) {
	int d, m, y;
	ofstream outMemberfile("Memberback.txt", ios::trunc);
	if (!outMemberfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Memberfile("Member.txt", ios::in);
	if (!Memberfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	Person N1;
	Person N;
	while (Memberfile >> Name) {
		Memberfile >> Family;
		Memberfile >> National_code;
		Memberfile >> Id;
		Memberfile >> d;
		Memberfile >> m;
		Memberfile >> y;
		Memberfile >> Type;
		Memberfile >> Idnumber;
		Memberfile >> Penalty;
		member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));
		if (member[i].Id == id) {
			cout << "\n 1.Edit name of member.";
			cout << "\n 2.Edit family of member.";
			cout << "\n 3.Edit national code of member.";
			cout << "\n 4.Edit brithday of member.";
			cout << "\n 5.Edit ID of member.";
			cout << "\n 6.Edite member is student OR staff.";
			cout << "\n 7.Edite Idnumber member.";
			cout << "\n 8.Edite Penalty of member.\n";
			int a;
			
			cout << "\n Which part you want to do?";
			cin >> a;
			system("cls");
			switch (a)
			{
			case 1:cout << "\n Please  Enter the name of member: "; Name = N.writing(); system("cls"); break;
			case 2:cout << "\n Enter the family of member: "; Family = N.writing(); system("cls"); break;
			case 3:cout << "\n Enter the national code of member: "; National_code = N1.writenationalcode(); system("cls"); break;
			case 4:cout << "\n Enter the brithday of member:\n";
				try {
					cin >> d >> m >> y;
					birthDate.setDate(d, m, y);
				}
				catch (Bad_Date_Exception ex)
				{
					cout << "The entered data is out of range, Try again";
					cin >> d >> m >> y;
					birthDate.setDate(d, m, y);
				}break; system("cls");
			case 5:cout << "\n Enter the ID of member: "; cin >> Id; system("cls"); break;
			case 6:cout << "\n Enter the member is student OR staff : "; Type = N.writing(); system("cls"); break;
			case 7:cout << "\n Enter the Idnumber member: "; Idnumber = N1.writenationalcode(); system("cls"); break;
			case 8:cout << "\n Enter the Penalty of member: "; cin >> Penalty; system("cls"); break;

			}
		}
		outMemberfile << Name << "\t" << Family << "\t" << National_code << "\t" << Id << "\t" << d

			<< "   " << m << "  " << y << "\t" << Type << "\t" << Idnumber << "\t" << Penalty << "\t" << endl;
		i++;

	}
	Memberfile.close();
	outMemberfile.close();
	remove("Member.txt");
	rename("Memberback.txt", "Member.txt");
}
void Member::Search(int id) {

	cout << " Name:" << setw(12) << "Family:" << setw(16) << "Nationa_Code:" << setw(15) << "ID Member:" << setw(15)

		<< "Brithdate:" << setw(11) << "Type:" << setw(15) << "Idnumber:" << setw(15) << "Penalty:\n\n";

	int d, m, y;

	ifstream Memberfile("Member.txt", ios::in);
	if (!Memberfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Memberfile >> Name) {
		Memberfile >> Family;
		Memberfile >> National_code;
		Memberfile >> Id;
		Memberfile >> d;
		Memberfile >> m;
		Memberfile >> y;
		Memberfile >> Type;
		Memberfile >> Idnumber;
		Memberfile >> Penalty;
		member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));
		if (member[i].Id == id) {

			cout << member[i].Name << "     " << member[i].Family << "     " << member[i].National_code << "     " << member[i].Id << "     "

				<< d << "/" << m << "/" << y << "     " << member[i].Type << "     " << member[i].Idnumber << "     " << member[i].Penalty << endl;

		}
		i++;

	}
	Memberfile.close();
}
void Member::Payment(int id) {

	int d, m, y;
	ofstream outMemberfile("Memberback.txt", ios::trunc);
	if (!outMemberfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Memberfile("Member.txt", ios::in);
	if (!Memberfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	int p;
	while (Memberfile >> Name) {
		Memberfile >> Family;
		Memberfile >> National_code;
		Memberfile >> Id;
		Memberfile >> d;
		Memberfile >> m;
		Memberfile >> y;
		Memberfile >> Type;
		Memberfile >> Idnumber;
		Memberfile >> Penalty;
		member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));
		if (member[i].Id == id) {
			cout << "penalty of memberis:" << member[i].Penalty << "\n\n";
			cout << "Dear user,pay your fine=";
			cin >> p;
			member[i].Penalty = p - member[i].Penalty;

			cout << member[i].Name << "\t" << member[i].Family << "\t" << member[i].National_code << "\t" << member[i].Id << "\t" <<

				d << "  " << m << "  " << y << "\t" << member[i].Type << "\t" << member[i].Idnumber << "\t" << member[i].Penalty << "\t" << endl;

		}
		outMemberfile << member[i].Name << "\t" << member[i].Family << "\t" << member[i].National_code << "\t" << member[i].Id << "\t" <<

			d << "  " << m << "  " << y << "\t" << member[i].Type << "\t" << member[i].Idnumber << "\t" << member[i].Penalty << "\t" << endl;
		i++;
	}
	Memberfile.close();
	outMemberfile.close();
	remove("Member.txt");
	rename("Memberback.txt", "Member.txt");
}
void Member::Jarime(int id, int jarime) {

	int d, m, y;
	ofstream outMemberfile("Memberback.txt", ios::out);
	if (!outMemberfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Memberfile("Member.txt", ios::in);
	if (!Memberfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	int p;
	while (Memberfile >> Name) {
		Memberfile >> Family;
		Memberfile >> National_code;
		Memberfile >> Id;
		Memberfile >> d;
		Memberfile >> m;
		Memberfile >> y;
		Memberfile >> Type;
		Memberfile >> Idnumber;
		Memberfile >> Penalty;
		member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));
		if (member[i].Id == id) {
			cout << "penalty of memberis:" << member[i].Penalty << "\n\n";
			cout << "Dear user,pay your fine=";

			member[i].Penalty = jarime + member[i].Penalty;

			cout << member[i].Name << "\t" << member[i].Family << "\t" << member[i].National_code << "\t" << member[i].Id << "\t" <<

				d << "  " << m << "  " << y << "\t" << member[i].Type << "\t" << member[i].Idnumber << "\t" << member[i].Penalty << "\t" << endl;

		}
		outMemberfile << member[i].Name << "\t" << member[i].Family << "\t" << member[i].National_code << "\t" << member[i].Id << "\t" <<

			d << "  " << m << "  " << y << "\t" << member[i].Type << "\t" << member[i].Idnumber << "\t" << member[i].Penalty << "\t" << endl;
		i++;
	}
	Memberfile.close();
	outMemberfile.close();
	remove("Member.txt");
	rename("Memberback.txt", "Member.txt");






}



class Librarian : public Person {
public:
	Librarian() {};
	Librarian(string N, string F, string N_code, int id, int d, int m, int y, string E, string S)
		:Person(N, F, N_code, id, d, m, y), Evidence(E), Semat(S) {}

	void set_Evidence(string Evidence);
	void set_Semat(string Semat);
	string get_Evidence();
	string get_Semat();
	void Enter();
	void Delet(int id);
	void Show();
	void Edit(int id);
	void Search(int id);
	void report() {
		birthDate.printDate();
		cout << Name << "   " << Family << "   " << National_code << "   " << Id << "   " << Evidence << "  " << Semat << endl;
	}
private:
	string Evidence;
	string Semat;
};
void Librarian::set_Evidence(string E) {
	Evidence = E;
}
void Librarian::set_Semat(string S) {
	Semat = S;
}
string Librarian::get_Evidence() {
	return Evidence;
}
string Librarian::get_Semat() {
	return Semat;
}
vector <Librarian> librarian, librarian1;
void Librarian::Enter() {

	ofstream Librarianfile("Librarian.txt", ios::app);
	if (!Librarianfile) {
		cout << " The file could not be opened!";
		return;
	}
	int  d, m, y;
	cout << "\n Please  Enter the name of librarian: ";
	Person N;
	Name = N.writing();
	cout << "\n Enter the family of librarian: ";
	Person F;
	Family = F.writing();
	cout << "\n Enter the national code of librarian: ";
	Person nat;
	National_code = nat.writenationalcode();
	cout << "\n Enter the brithday of librarian:\n";
	try {
		cin >> d >> m >> y;
		birthDate.setDate(d, m, y);
	}
	catch (Bad_Date_Exception ex)
	{
		cout << "The entered data is out of range, Try again";
		cin >> d >> m >> y;
		birthDate.setDate(d, m, y);
	}

	cout << "\n Enter the ID of librarian: ";
	cin >> Id;
	cout << "\n Enter the Evidence of librarian: ";
	Person E;
	Evidence = E.writing();
	cout << "\n Enter the Semat of librarian: ";
	Person S;
	Semat = S.writing();
	librarian.push_back(Librarian(Name, Family, National_code, Id, d, m, y, Evidence, Semat));

	Librarianfile << Name << "\t" << Family << "\t" << National_code << "\t" << Id

		<< "\t" << d << "  " << m << "  " << y << "\t" << Evidence << "\t" << Semat << endl;

	Librarianfile.close();
}
void Librarian::Delet(int id) {

	int d, m, y;
	for (int i = 0; i < librarian.size(); i++) {
		if (librarian[i].get_Id() == id) {
			librarian1.push_back(librarian[i]);
		}
	}
	librarian = librarian1;
	vector<Librarian>().swap(librarian1);
	ofstream outLibrarianfile("Librarianback.txt", ios::trunc);
	if (!outLibrarianfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Librarianfile("Librarian.txt", ios::in);
	if (!Librarianfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Librarianfile >> Name) {
		Librarianfile >> Family;
		Librarianfile >> National_code;
		Librarianfile >> Id;
		Librarianfile >> d;
		Librarianfile >> m;
		Librarianfile >> y;
		Librarianfile >> Evidence;
		Librarianfile >> Semat;
		librarian.push_back(Librarian(Name, Family, National_code, Id, d, m, y, Evidence, Semat));
		if (librarian[i].Id == id) {

			;
		}
		else
		{
			outLibrarianfile << librarian[i].Name << "\t" << librarian[i].Family << "\t" << librarian[i].National_code << "\t"

				<< librarian[i].Id << "\t" << d << "  " << m << "  " << y << "\t" << librarian[i].Evidence << "\t" << librarian[i].Semat << endl;

		}
		i++;
	}
	Librarianfile.close();
	outLibrarianfile.close();
	remove("Librarian.txt");
	rename("Librarianback.txt", "Librarian.txt");
}
void Librarian::Show() {
	ifstream Librarianfile("Librarian.txt", ios::in);
	if (!Librarianfile) {
		cout << " The file could not be opened!";
		return;
	}
	int  d, m, y;
	int i = 0;
	while (Librarianfile >> Name) {
		Librarianfile >> Family;
		Librarianfile >> National_code;
		Librarianfile >> Id;
		Librarianfile >> d;
		Librarianfile >> m;
		Librarianfile >> y;
		Librarianfile >> Evidence;
		Librarianfile >> Semat;
		librarian.push_back(Librarian(Name, Family, National_code, Id, d, m, y, Evidence, Semat));

		cout << librarian[i].Name << "     " << librarian[i].Family << "    " << librarian[i].National_code << "     " << librarian[i].Id

			<< "    " << d << "/" << m << " /" << y << "     " << librarian[i].Evidence << "    " << librarian[i].Semat << endl;
		i++;
	}
	Librarianfile.close();
}
void Librarian::Edit(int id) {
	int  d, m, y;
	int a;


	ofstream outLibrarianfile("Librarianback.txt", ios::out);
	if (!outLibrarianfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Librarianfile("Librarian.txt", ios::in);
	if (!Librarianfile) {
		cout << " The file could not be opened!";
		return;
	}
	Person N1;
	Person N;
	int i = 0;
	while (Librarianfile >> Name) {
		Librarianfile >> Family;
		Librarianfile >> National_code;
		Librarianfile >> Id;
		Librarianfile >> d;
		Librarianfile >> m;
		Librarianfile >> y;
		Librarianfile >> Evidence;
		Librarianfile >> Semat;
		librarian.push_back(Librarian(Name, Family, National_code, Id, d, m, y, Evidence, Semat));
		if (librarian[i].get_Id() == id) {
			cout << "\n 1.Edit name of librarian.";
			cout << "\n 2.Edit family of librarian.";
			cout << "\n 3.Edit national code of librarian.";
			cout << "\n 4.Edit brithday of librarian.";
			cout << "\n 5.Edit ID of librarian.";
			cout << "\n 6.Edite Evidence of librarian.";
			cout << "\n 7.Edite Semat of librarian.\n";

			int a;
			cout << "\n Which part you want to do?";
			cin >> a;
			system("cls");
			switch (a)
			{
			case 1:cout << "\n Please  Enter the name of librarian: "; Name = N.writing(); system("cls"); break;
			case 2:cout << "\n Enter the family of librarian: "; Family = N.writing(); system("cls"); break;
			case 3:cout << "\n Enter the national code of librarian: "; National_code = N1.writenationalcode(); system("cls"); break;
			case 4:cout << "\n Enter the brithday of librarian:\n";
				try {
					cin >> d >> m >> y;
					birthDate.setDate(d, m, y);
				}
				catch (Bad_Date_Exception ex)
				{
					cout << "The entered data is out of range, Try again";
					cin >> d >> m >> y;
					birthDate.setDate(d, m, y);
				}break; system("cls");
			case 5:cout << "\n Enter the ID of librarian: "; cin >> Id; break;
			case 6:cout << "\n Enter the Evidence of librarian: "; Evidence = N.writing(); system("cls"); break;
			case 7:cout << "\n Enter the Semat of librarian: "; Semat = N.writing(); system("cls"); break;
			}
		}

		outLibrarianfile << Name << "\t" << Family << "\t" << National_code << "\t" << Id

			<< d << "  " << m << "  " << y << "\t" << Evidence << "\t" << Semat << endl;
		i++;
	}
	Librarianfile.close();
	outLibrarianfile.close();
	remove("Librarian.txt");
	rename("Librarianback.txt", "Librarian.txt");
}
void Librarian::Search(int id) {
	int  d, m, y;
	ifstream Librarianfile("Librarian.txt", ios::in);
	if (!Librarianfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Librarianfile >> Name) {
		Librarianfile >> Family;
		Librarianfile >> National_code;
		Librarianfile >> Id;
		Librarianfile >> d;
		Librarianfile >> m;
		Librarianfile >> y;
		Librarianfile >> Evidence;
		Librarianfile >> Semat;
		librarian.push_back(Librarian(Name, Family, National_code, Id, d, m, y, Evidence, Semat));
		if (librarian[i].get_Id() == id) {

			cout << librarian[i].Name << "     " << librarian[i].Family << "    " << librarian[i].National_code << "     " << librarian[i].Id

				<< "  " << d << "/" << m << "/" << y << "     " << librarian[i].Evidence << "    " << librarian[i].Semat << endl;
		}
		i++;

	}
	Librarianfile.close();
}


class Library {
public:
	Library() {}
	Library(int id, string T, int PNumber, int Inv)
		:ID(id), Title(T), Page_Number(PNumber), Inventory(Inv) {}
	void set_ID(int ID);
	void set_Title(string Title);
	void set_Pagenumber(int Page_Number);
	void set_Inventory(int Inventory);
	int get_ID()const;
	string get_Title()const;
	int get_Pagenumber()const;
	int get_Inventory()const;
	virtual void Enter(int id) {};
	virtual void Delet(int id) {};
	virtual void Edit(int id) {};
	virtual void Search(int id) {};
	virtual void Show() {};
protected:
	int ID;
	string Title;
	int Page_Number;
	int Inventory;
};
void Library::set_ID(int id) {
	ID = id;
}
void Library::set_Title(string T) {
	Title = T;
}
void Library::set_Pagenumber(int PNumber) {
	Page_Number = PNumber;
}
void Library::set_Inventory(int Inv) {
	Inventory = Inv;
}
int Library::get_ID()const {
	return ID;
}
string Library::get_Title()const {
	return Title;
}
int Library::get_Pagenumber()const {
	return Page_Number;
}
int Library::get_Inventory()const {
	return Inventory;
}





class Book :public Library {
	friend class Amanat;
public:
	Book() {}
	Book(int id, string T, int PNumber, int Inv, int Number_B, string C)
		:Library(id, T, PNumber, Inv), Number_book(Number_B), Category(C) {}
	void set_Number_book(int Number_B);
	void set_Category(string C);
	int get_Number_book()const;
	string get_Category()const;
	string WritCategory();
	void Enter(int id);
	void Delet(int id);
	void Edit(int id);
	void Search(int id);
	void Show();
private:
	int Number_book;
	string Category;
};
void Book::set_Number_book(int Number_B) {
	Number_book = Number_B;
}
void Book::set_Category(string C) {
	Category = C;
}
int Book::get_Number_book()const {
	return Number_book;
}
string Book::get_Category()const {
	return Category;
}
string Book::WritCategory() {
	char Massage[] = "The Category  is false,Try again!";
	
	try {
		cin >> Category;
		if (!(Category == "mohandesi" || Category == "paye" || Category == "adabiyat" || Category == "elahiyat" || Category == "motefareghe")) {
			throw Massage;
		}
	}

	catch (char Massage[]) {

		cout << Massage << endl;
		cin >> Category;
	}
	return Category;
}
vector<Book>book, book1;
void Book::Enter(int id) {

	Book c;
	ofstream outBookfile("Bookback.txt", ios::out);
	if (!outBookfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Bookfile("Book.txt", ios::in);
	if (!Bookfile) {
		cout << " The file could not be opened!";
		return;
	}

	int t = 0;
	int i = 0;
	while (Bookfile >> ID) {
		Bookfile >> Title;
		Bookfile >> Page_Number;
		Bookfile >> Inventory;
		Bookfile >> Number_book;
		Bookfile >> Category;
		book.push_back(Book(ID, Title, Page_Number, Inventory, Number_book, Category));
		if (book[i].get_ID() == id) {
			t = 1;
			cout << " \n This Book whit  this ID   is available in the library" << endl;

			cout << "\n Enter the desired number of Book: ";
			int N_book;
			cin >> Number_book;
			N_book = Number_book + book[i].Number_book;
			book[i].Inventory = book[i].Inventory + Number_book;

			book[i].Number_book = N_book;


		}
		outBookfile << book[i].ID << "\t" << book[i].Title << "\t" << book[i].Page_Number << "\t" << book[i].Inventory

			<< "\t" << book[i].Number_book << "\t" << book[i].Category << endl;
		i++;
	}
	if (t == 0) {
		ID = id;
		cout << "\n Enter the Title of book: ";
		cin >> Title;
		cout << "\n Enter the Page_Number of book: ";
		cin >> Page_Number;
		cout << "\n Enter the Inventory of book: ";
		cin >> Inventory;
		cout << "\n Enter the Number of book:";
		cin >> Number_book;
		cout << "\n Enter the Category of book:";
		Category = c.WritCategory();
		outBookfile << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory

			<< "\t" << Number_book << "\t" << Category << endl;
	}


	Bookfile.close();
	outBookfile.close();
	remove("Book.txt");
	rename("Bookback.txt", "Book.txt");
}







void Book::Delet(int id) {
	for (int i = 0; i < book.size(); i++) {
		if (book[i].get_ID() == id) {
			book1.push_back(book[i]);
		}
	}
	book = book1;
	vector<Book>().swap(book1);
	ofstream outBookfile("Bookback.txt", ios::trunc);
	if (!outBookfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Bookfile("Book.txt", ios::in);
	if (!Bookfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Bookfile >> ID) {
		Bookfile >> Title;
		Bookfile >> Page_Number;
		Bookfile >> Inventory;
		Bookfile >> Number_book;
		Bookfile >> Category;
		book.push_back(Book(ID, Title, Page_Number, Inventory, Number_book, Category));
		if (book[i].get_ID() == id) {
			;


		}
		else
		{
			outBookfile << book[i].ID << "\t" << book[i].Title << "\t" << book[i].Page_Number << "\t" << book[i].Inventory << "\t"
				<< book[i].Number_book << "\t" << book[i].Category << endl;
		}
		i++;
	}
	Bookfile.close();
	outBookfile.close();
	remove("Book.txt");
	rename("Bookback.txt", "Book.txt");
}
void Book::Edit(int id) {
	ofstream outBookfile("Bookback.txt", ios::out);
	if (!outBookfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Bookfile("Book.txt", ios::in);
	if (!Bookfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Bookfile >> ID) {
		Bookfile >> Title;
		Bookfile >> Page_Number;
		Bookfile >> Inventory;
		Bookfile >> Number_book;
		Bookfile >> Category;
		book.push_back(Book(ID, Title, Page_Number, Inventory, Number_book, Category));
		if (book[i].get_ID() == id) {
			cout << "\n 1.Edit Title of book.";
			cout << "\n 2.Edit Page_Number of book.";
			cout << "\n 3.Edit Inventory of book.";
			cout << "\n 4.Edit Number of book.";
			cout << "\n 5.Edit Category of book.\n";
			int a;
			Book C;
			cout << "\n Which part you want to do?";
			cin >> a;
			system("cls");
			switch (a)
			{
			case 1: cout << "\n Enter the Title of book: "; cin >> Title; system("cls"); break;
			case 2: cout << "\n Enter the Page_Number of book: "; cin >> Page_Number; system("cls"); break;
			case 3: cout << "\n Enter the Inventory of book: "; cin >> Inventory; system("cls"); break;
			case 4: cout << "\n Enter the Number of book:\n"; cin >> Number_book; system("cls"); break;
			case 5: cout << "\n Enter the Category of book:\n"; Category = C.WritCategory(); system("cls"); break;
			default:
				break;
			}
		}
		outBookfile << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory

			<< "\t" << Number_book << "\t" << Category << endl;
		i++;

	}
	Bookfile.close();
	outBookfile.close();
	remove("Book.txt");
	rename("Bookback.txt", "Book.txt");
}
void Book::Search(int id) {

	ifstream Bookfile("Book.txt", ios::in);
	if (!Bookfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Bookfile >> ID) {
		Bookfile >> Title;
		Bookfile >> Page_Number;
		Bookfile >> Inventory;
		Bookfile >> Number_book;
		Bookfile >> Category;
		book.push_back(Book(ID, Title, Page_Number, Inventory, Number_book, Category));
		if (book[i].get_ID() == id) {

			cout << book[i].ID << "\t" << book[i].Title << "\t" << book[i].Page_Number << "\t" << book[i].Inventory

				<< "\t" << book[i].Number_book << "\t" << book[i].Category << endl;

		}
		i++;
	}
	Bookfile.close();
}
void Book::Show() {
	ifstream Bookfile("Book.txt", ios::in);
	if (!Bookfile) {
		cout << " The file could not be opened!";
		return;
	}
	string C;
	Book r;
	C = r.WritCategory();
	int i = 0;
	while (Bookfile >> ID) {
		Bookfile >> Title;
		Bookfile >> Page_Number;
		Bookfile >> Inventory;
		Bookfile >> Number_book;
		Bookfile >> Category;
		book.push_back(Book(ID, Title, Page_Number, Inventory, Number_book, Category));
		if (book[i].get_Category() == C) {

			cout << book[i].ID << "\t" << book[i].Title << "\t" << book[i].Page_Number << "\t" << book[i].Inventory

				<< "\t" << book[i].Number_book << "\t" << book[i].Category << endl;
			i++;
		}
	}
	Bookfile.close();
}






class Magazine :public Library {
public:
	friend class Amanat;
	Magazine() {}
	Magazine(int id, string T, int PNumber, int Inv, int Number_M)
		:Library(id, T, PNumber, Inv), Number_magazine(Number_M) {}
	void set_Number_magazine(int number_magazine);
	int get_Number_magazine()const;
	void Enter(int id);
	void Delet(int id);
	void Edit(int id);
	void Search(int id);
	void Show();
private:
	int Number_magazine;
};
void Magazine::set_Number_magazine(int Number_M) {
	this->Number_magazine = Number_M;
}
int Magazine::get_Number_magazine()const {
	return Number_magazine;
}
vector<Magazine>magazine, magazine1;
void Magazine::Enter(int id) {

	ofstream outBookfile("Magazineback.txt", ios::out);
	if (!outBookfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Bookfile("Magazine.txt", ios::in);
	if (!Bookfile) {
		cout << " The file could not be opened!";
		return;
	}

	int t = 0;
	int i = 0;
	while (Bookfile >> ID) {
		Bookfile >> Title;
		Bookfile >> Page_Number;
		Bookfile >> Inventory;
		Bookfile >> Number_magazine;

		magazine.push_back(Magazine(ID, Title, Page_Number, Inventory, Number_magazine));
		if (magazine[i].get_ID() == id) {
			t = 1;
			cout << " \n This magazine whit  this ID   is available in the library" << endl;

			cout << "\n Enter the desired number of Book: ";
			int N_book;
			cin >> Number_magazine;
			N_book = Number_magazine + magazine[i].Number_magazine;
			magazine[i].Inventory = magazine[i].Inventory + Number_magazine;

			magazine[i].Number_magazine = N_book;


		}
		outBookfile << magazine[i].ID << "\t" << magazine[i].Title << "\t" << magazine[i].Page_Number << "\t" << magazine[i].Inventory

			<< "\t" << magazine[i].Number_magazine << endl;
		i++;
	}
	if (t == 0) {
		ID = id;
		cout << "\n Enter the Title of book: ";
		cin >> Title;
		cout << "\n Enter the Page_Number of book: ";
		cin >> Page_Number;
		cout << "\n Enter the Inventory of book: ";
		cin >> Inventory;
		cout << "\n Enter the Number of book:";
		cin >> Number_magazine;

		outBookfile << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory

			<< "\t" << Number_magazine << endl;
	}


	Bookfile.close();
	outBookfile.close();
	remove("Magazine.txt");
	rename("Magazineback.txt", "Magazine.txt");

}
void Magazine::Delet(int id) {
	for (int i = 0; i < magazine.size(); i++) {
		if (magazine[i].get_ID() == id) {
			magazine1.push_back(magazine[i]);
		}
	}
	magazine = magazine1;
	vector<Magazine>().swap(magazine1);
	ofstream outMagazinefile("Magazineback.txt", ios::out);
	if (!outMagazinefile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Magazinefile("Magazine.txt", ios::in);
	if (!Magazinefile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Magazinefile >> ID) {
		Magazinefile >> Title;
		Magazinefile >> Page_Number;
		Magazinefile >> Inventory;
		Magazinefile >> Number_magazine;
		magazine.push_back(Magazine(ID, Title, Page_Number, Inventory, Number_magazine));
		if (magazine[i].get_ID() == id) {
			;


		}
		else
		{
			outMagazinefile << magazine[i].ID << "\t" << magazine[i].Title << "\t" << magazine[i].Page_Number

				<< "\t" << magazine[i].Inventory << "\t" << magazine[i].Number_magazine << endl;
		}
		i++;
	}
	Magazinefile.close();
	outMagazinefile.close();
	remove("Magazine.txt");
	rename("Magazineback.txt", "Magazine.txt");
}
void Magazine::Edit(int id) {
	ofstream outMagazinefile("Magazineback.txt", ios::out);
	if (!outMagazinefile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Magazinefile("Magazine.txt", ios::in);
	if (!Magazinefile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Magazinefile >> ID) {
		Magazinefile >> Title;
		Magazinefile >> Page_Number;
		Magazinefile >> Inventory;
		Magazinefile >> Number_magazine;
		magazine.push_back(Magazine(ID, Title, Page_Number, Inventory, Number_magazine));
		if (magazine[i].get_ID() == id) {
			cout << "\n 1.Edit Title of magazine.";
			cout << "\n 2.Edit Page_Number of magazine.";
			cout << "\n 3.Edit Inventory of magazine.";
			cout << "\n 4.Edit Number of magazine.\n";
			int a;
			cout << "\n Which part you want to do?";
			cin >> a;
			system("cls");
			switch (a)
			{
			case 1: cout << "\n Enter the Title of magazine: "; cin >> Title; system("cls"); break;
			case 2: cout << "\n Enter the Page_Number of magazine: "; cin >> Page_Number; system("cls"); break;
			case 3: cout << "\n Enter the Inventory of magazine: "; cin >> Inventory; system("cls"); break;
			case 4: cout << "\n Enter the Number of magazine:\n"; cin >> Number_magazine; system("cls"); break;
			default:
				break;
			}
		}
		outMagazinefile << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory << "\t" <<
			Number_magazine << endl;
		i++;
	}
	Magazinefile.close();
	outMagazinefile.close();
	remove("Magazine.txt");
	rename("Magazineback.txt", "Magazine.txt");
}
void Magazine::Search(int id) {
	ifstream Magazinefile("Magazine.txt", ios::in);
	if (!Magazinefile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Magazinefile >> ID) {
		Magazinefile >> Title;
		Magazinefile >> Page_Number;
		Magazinefile >> Inventory;
		Magazinefile >> Number_magazine;
		magazine.push_back(Magazine(ID, Title, Page_Number, Inventory, Number_magazine));
		if (magazine[i].get_ID() == id) {

			cout << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory << "\t" <<
				Number_magazine << endl;

		}
		i++;
	}
	Magazinefile.close();
}
void Magazine::Show() {
	ifstream Magazinefile("Magazine.txt", ios::in);
	if (!Magazinefile) {
		cout << " The file could not be opened!";
		return;
	}

	int i = 0;
	while (Magazinefile >> ID) {
		Magazinefile >> Title;
		Magazinefile >> Page_Number;
		Magazinefile >> Inventory;
		Magazinefile >> Number_magazine;
		magazine.push_back(Magazine(ID, Title, Page_Number, Inventory, Number_magazine));


		cout << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory << "\t" <<
			Number_magazine << endl;
		i++;
	}
	Magazinefile.close();
}



class Thesis :public Library {
public:
	friend class Amanat;

	Thesis(int id = 0, string T = "", int PNumber = 0, int Inv = 1, string G = "", string Collg = "", string Gro = "") :
		Library(id, T, PNumber, Inv), Grade(G), College(Collg), Group(Gro) {}
	void set_Grade(string G);
	void set_College(string Collg);
	void set_Groupe(string Gro);
	string get_Grade()const;
	string get_College()const;
	string get_Groupe()const;
	void Enter(int id);
	void Delet(int id);
	void Edit(int id);
	void Search(int id);
	void Show();
private:
	string Grade;
	string College;
	string Group;

};
void Thesis::set_Grade(string G) {
	Grade = G;
}
void Thesis::set_College(string Collg) {
	College = Collg;
}
void Thesis::set_Groupe(string Gro) {
	Group = Gro;
}
string Thesis::get_Grade()const {
	return Grade;
}
string Thesis::get_College()const {
	return College;
}
string Thesis::get_Groupe()const {
	return Group;
}
vector<Thesis>thesis, thesis1;
void Thesis::Enter(int id) {
	ifstream Thesisfile("Thesis.txt", ios::in);
	if (!Thesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	ofstream inThesisfile("Thesisback.txt", ios::app);
	if (!inThesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	int t = 0;
	int i = 0;
	while (Thesisfile >> ID) {
		Thesisfile >> Title;
		Thesisfile >> Page_Number;
		Thesisfile >> Inventory;
		Thesisfile >> Grade;
		Thesisfile >> College;
		Thesisfile >> Group;
		thesis.push_back(Thesis(ID, Title, Page_Number, Inventory, Grade, College, Group));
		if (thesis[i].get_ID() == id && thesis[i].get_Inventory() == 1) {
			t = 1;
			cout << " \n This Book whit  this ID   is available in the library" << endl;
			_getch();
		}
		else if (thesis[i].get_ID() == id) {
			t = 1;
			thesis[i].Inventory = thesis[i].Inventory + 1;
		}

		inThesisfile << thesis[i].ID << "\t" << thesis[i].Title << "\t" << thesis[i].Page_Number << "\t" << thesis[i].Inventory << "\t" <<
			thesis[i].Grade << "\t" << thesis[i].College << "\t" << thesis[i].Group << endl;

		i++;

	}
	if (t == 0) {
		ID = id;
		cout << "\n   Enter the Title of thesis: ";
		cin >> Title;
		cout << "\n   Enter the Page_Number of thesis: ";
		cin >> Page_Number;
		cout << "\n\n Enter the Inventory of thesis: 1";
		cout << "\n   Enter the Grade of thesis:";
		cin >> Grade;
		cout << "\n   Enter the College of thesis:";
		cin >> College;
		cout << "\n   Enter the Group of thesis:";
		cin >> Group;

		inThesisfile << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory << "\t" <<
			Grade << "\t" << College << "\t" << Group << endl;

	}

	Thesisfile.close();
	inThesisfile.close();
	remove("Thesis.txt");
	rename("Thesisback.txt", "Thesis.txt");
}
void Thesis::Delet(int id) {
	for (int i = 0; i < thesis.size(); i++) {
		if (thesis[i].get_ID() == id) {
			thesis1.push_back(thesis[i]);
		}
	}
	thesis = thesis1;
	vector<Thesis>().swap(thesis1);
	ofstream outThesisfile("Thesisback.txt", ios::out);
	if (!outThesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Thesisfile("Thesis.txt", ios::in);
	if (!Thesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Thesisfile >> ID) {
		Thesisfile >> Title;
		Thesisfile >> Page_Number;
		Thesisfile >> Inventory;
		Thesisfile >> Grade;
		Thesisfile >> College;
		Thesisfile >> Group;
		thesis.push_back(Thesis(ID, Title, Page_Number, Inventory, Grade, College, Group));
		if (thesis[i].get_ID() == id) {
			;


		}
		else
		{
			outThesisfile << thesis[i].ID << "\t" << thesis[i].Title << "\t" << thesis[i].Page_Number << "\t" << thesis[i].Inventory << "\t" <<
				thesis[i].Grade << "\t" << thesis[i].College << "\t" << thesis[i].Group << endl;

		}
		i++;
	}
	Thesisfile.close();
	outThesisfile.close();
	remove("Thesis.txt");
	rename("Thesisback.txt", "Thesis.txt");

}
void Thesis::Edit(int id) {
	ofstream outThesisfile("Thesisback.txt", ios::out);
	if (!outThesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	ifstream Thesisfile("Thesis.txt", ios::in);
	if (!Thesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Thesisfile >> ID) {
		Thesisfile >> Title;
		Thesisfile >> Page_Number;
		Thesisfile >> Inventory;
		Thesisfile >> Grade;
		Thesisfile >> College;
		Thesisfile >> Group;
		thesis.push_back(Thesis(ID, Title, Page_Number, Inventory, Grade, College, Group));
		if (thesis[i].get_ID() == id) {
			cout << "\n 1.Edit Title of thesis.";
			cout << "\n 2.Edit Page_Number of thesis.";
			cout << "\n 3.Edit Inventory of thesis.";
			cout << "\n 4.Edit Grade of thesis.";
			cout << "\n 5.Edit Group of thesis.\n";
			int a;
			cout << "\n Which part you want to do?";
			cin >> a;
			system("cls");
			switch (a)
			{
			case 1: cout << "\n Enter the Title of thesis: "; cin >> Title; system("cls"); break;
			case 2: cout << "\n Enter the Page_Number of thesis: "; cin >> Page_Number; system("cls"); break;
			case 3: cout << "\n Enter the Inventory of thesis between 0 && 1:";
				cin >> Inventory;
				if (Inventory == 0) {
					cout << "\n The dissertation is on loan!!\n";
				}
				else {
					cout << "\n Thesis is available!!";
				} break; system("cls");
			case 4: cout << "\n Enter the Grade of thesis:"; cin >> Grade; system("cls"); break;
			case 5: cout << "\n Enter the Group of thesis:"; cin >> Group; system("cls"); break;
			default:
				break;
			}
		}
		outThesisfile << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory << "\t" <<
			Grade << "\t" << College << "\t" << Group << endl;
		i++;
	}
	Thesisfile.close();
	outThesisfile.close();
	remove("Thesis.txt");
	rename("Thesisback.txt", "Thesis.txt");
}
void Thesis::Search(int id) {
	ifstream Thesisfile("Thesis.txt", ios::in);
	if (!Thesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Thesisfile >> ID) {
		Thesisfile >> Title;
		Thesisfile >> Page_Number;
		Thesisfile >> Inventory;
		Thesisfile >> Grade;
		Thesisfile >> College;
		Thesisfile >> Group;
		thesis.push_back(Thesis(ID, Title, Page_Number, Inventory, Grade, College, Group));
		if (thesis[i].get_ID() == id) {

			cout << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory << "\t" <<
				Grade << "\t" << College << "\t" << Group << endl;

		}
		i++;
	}
	Thesisfile.close();
}
void Thesis::Show() {
	ifstream Thesisfile("Thesis.txt", ios::in);
	if (!Thesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	int i = 0;
	while (Thesisfile >> ID) {
		Thesisfile >> Title;
		Thesisfile >> Page_Number;
		Thesisfile >> Inventory;
		Thesisfile >> Grade;
		Thesisfile >> College;
		Thesisfile >> Group;
		thesis.push_back(Thesis(ID, Title, Page_Number, Inventory, Grade, College, Group));


		cout << ID << "\t" << Title << "\t" << Page_Number << "\t" << Inventory << "\t" <<
			Grade << "\t" << College << "\t" << Group << endl;
		i++;
	}
	Thesisfile.close();
}


class Amanat {

public:
	Amanat() {}
	Amanat(int idm,  int idbmt, int da, int ma, int ya, Date Tahvil) :
		idmember(idm),idBMT(idbmt), amanat(da, ma, ya), delivery(Tahvil) {}
	void set_idmember(int idm);
	void set_idbmt(int idbmt);
	
	int  get_idmember();
	int  get_idbmt();
	
	Date getdelivery()
	{
		return delivery;
	}
	void sabt();
	void searchn();
	void searchm();
	void show();
	void Delet();
	void Edit();
private:
	
	int idmember;
	int idBMT;
	Date amanat;
	Date delivery;
};
void Amanat::set_idmember(int idm) {
	idmember = idm;
}
void Amanat::set_idbmt(int idbmt) {
	idBMT = idbmt;
}

int Amanat::get_idmember() {
	return idmember;
}
int Amanat::get_idbmt() {
	return idBMT;
}



int amanatlibrary = 0;
/*void Amanat::sabt() {


	Member M;
	int a;
	int Idd;
	int Page_Number, ID, Inventory, Number_book, Number_magazine;
	string  Title, Category, Grade, College, Group;
	int Number_Amanat1;
	int Number_Amanat2;
	int Number_Amanat3;
	char choice;


	   cout << "Please Enter member 'ID For Sabt Book:"; cin >> Idd;
	do {

		M.Search(Idd);

		cout << "1. Record amant Book:\n";
		cout << "2. Record amanat Magazine:\n";
		cout << "3. Record amanat Thesis:\n";
		cout << "4. Exit\n\n";
		cout << "\n Which part you want to do?";

		cin >> a;
		if (a == 1) {

			ofstream AmanatBookfile("AmanatBook.txt", ios::app);
			if (!AmanatBookfile) {
				cout << " The file could not be opened!";
				return;
			}
			ofstream inBookfile("book1.txt", ios::out);
			if (!inBookfile) {
				cout << " The file could not be opened!";
				return;
			}

			int idB;
			cout << "Please Enter Book ID:";
			cin >> idB;

			int i = 0;
			ifstream Bookfile("Book.txt", ios::in);
			if (!Bookfile) {
				cout << " The file could not be opened!";
				return;
			}
			while (Bookfile >> ID) {
				Bookfile >> Title;
				Bookfile >> Page_Number;
				Bookfile >> Inventory;
				Bookfile >> Number_book;
				Bookfile >> Category;
				book.push_back(Book(ID, Title, Page_Number, Inventory, Number_book, Category));

				if (book[i].get_ID() == idB) {

					cout << book[i].ID << "\t" << book[i].Title << "\t" << book[i].Page_Number << "\t" << book[i].Inventory

						<< "\t" << book[i].Number_book << "\t" << book[i].Category << endl;


					if (Inventory == 0) {
						cout << "This Book is not Library!!\n";
						break;
					}
					else {
						cout << "amanatlibrary" << amanatlibrary << "\n";
						if (amanatlibrary < 3) {
							cout << "Enter the number of Books you want to borrow?";

							cin >> Number_Amanat1;
							amanatlibrary = amanatlibrary + Number_Amanat1;
						}
						else {
							cout << "you dont borrow\n";
							break;
						}
						book[i].Inventory = book[i].Inventory - Number_Amanat1;
						cout << ID << setw(12) << Title << setw(8) << Page_Number << setw(19)
							<< book[i].Inventory << setw(15) << Number_book << setw(22) << Category << endl;

						int da, ma, ya, Dd, Md, Yd;
						cout << "Enter the amanat data\n";
						try {
							cin >> da >> ma >> ya;
							amanat.setDate(da, ma, ya);

						}

						catch (Bad_Date_Exception ex)
						{
							cout << "The entered data is out of range, Try again\n";
							cin >> da >> ma >> ya;
							amanat.setDate(da, ma, ya);

						}
						Date d(da, ma, ya);
						cout << "delivery data is:";
						Date D = d + 7;
						D.printDate();
						vector<Amanat>amanat1;
						amanat1.push_back(Amanat(Idd,Title ,idB, da, ma, ya, D));

						AmanatBookfile << Idd << "     " << Title << "     " << idB << "      "

							<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

					}

				}
				inBookfile << book[i].ID << "    " << book[i].Title << "    " << book[i].Page_Number << "    "
					<< book[i].Inventory << "    " << book[i].Number_book << "     " << book[i].Category << endl;


				i++;
			}
			Bookfile.close();
			inBookfile.close();
			remove("Book.txt");
			rename("book1.txt", "Book.txt");


		}


		if (a == 2) {
			ofstream AmanatMagazinefile("AmanatMagazine.txt", ios::app);
			if (!AmanatMagazinefile) {
				cout << " The file could not be opened!";
				return;
			}

			ofstream inMagazinefile("magazine1.txt", ios::out);
			if (!inMagazinefile) {
				cout << " The file could not be opened!";
				return;
			}


			int idM;
			cout << "Please Enter Magazine ID:";
			cin >> idM;
			int j = 0;
			ifstream Magazinefile("Magazine.txt", ios::in);
			if (!Magazinefile) {
				cout << " The file could not be opened!";
				return;
			}
			while (Magazinefile >> ID) {
				Magazinefile >> Title;
				Magazinefile >> Page_Number;
				Magazinefile >> Inventory;
				Magazinefile >> Number_magazine;
				magazine.push_back(Magazine(ID, Title, Page_Number, Inventory, Number_magazine));
				if (magazine[j].get_ID() == idM) {

					cout << magazine[j].ID << "\t" << magazine[j].Title << "\t" << magazine[j].Page_Number

						<< "\t" << magazine[j].Inventory << "\t" << magazine[j].Number_magazine << endl;
					if (Inventory == 0) {
						cout << "This Magazine is not Library!!\n";
						break;
					}
					else {

						cout << "amanatlibrary" << amanatlibrary << "\n";
						if (amanatlibrary < 3) {
							cout << "Enter the number of Books you want to borrow?";
							cin >> Number_Amanat2;
							amanatlibrary = amanatlibrary + Number_Amanat2;
						}
						else {
							cout << "you dont borrow\n";
							break;
						}
						magazine[j].Inventory = magazine[j].Inventory - Number_Amanat2;
						cout << magazine[j].ID << setw(12) << magazine[j].Title << setw(8) << magazine[j].Page_Number << setw(19)
							<< magazine[j].Inventory << setw(15) << magazine[j].Number_magazine << endl;

						int da, ma, ya, Dd, Md, Yd;
						cout << "Enter the amanat data\n";
						try {
							cin >> da >> ma >> ya;
							amanat.setDate(da, ma, ya);
						}
						catch (Bad_Date_Exception ex)
						{
							cout << "The entered data is out of range, Try again\n";
							cin >> da >> ma >> ya;
							amanat.setDate(da, ma, ya);
						}
						cout << "delivery data is:";
						Date d(da, ma, ya);
						Date D = d + 7;
						D.printDate();
						vector<Amanat>amanat2;
						amanat2.push_back(Amanat(Idd, Title,idM, da, ma, ya, D));

						AmanatMagazinefile << Idd << "     " << Title << "     " << idM << "      "

							<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

					}

				}
				inMagazinefile << magazine[j].ID << "      " << magazine[j].Title << "     " << Page_Number << "      "
					<< magazine[j].Inventory << "      " << magazine[j].Number_magazine << endl;
				j++;
			}
			Magazinefile.close();
			inMagazinefile.close();
			remove("Magazine.txt");
			rename("magazine1.txt", "Magazine.txt");


		}

		if (a == 3) {

			ofstream AmanatThiesisfile("AmanatThiesis.txt", ios::app);
			if (!AmanatThiesisfile) {
				cout << " The file could not be opened!";
				return;
			}
			ofstream inThesisfile("thesis1.txt", ios::app);
			if (!inThesisfile) {
				cout << " The file could not be opened!";
				return;
			}



			int idT;
			cout << "Please Enter Thesis ID:";
			cin >> idT;
			int j = 0;

			ifstream Thesisfile("Thesis.txt", ios::in);
			if (!Thesisfile) {
				cout << " The file could not be opened!";
				return;
			}

			int k = 0;
			while (Thesisfile >> ID) {
				Thesisfile >> Title;
				Thesisfile >> Page_Number;
				Thesisfile >> Inventory;
				Thesisfile >> Grade;
				Thesisfile >> College;
				Thesisfile >> Group;
				thesis.push_back(Thesis(ID, Title, Page_Number, Inventory, Grade, College, Group));
				if (thesis[k].get_ID() == idT) {

					cout << thesis[k].ID << "\t" << thesis[k].Title << "\t" << thesis[k].Page_Number << "\t" <<

						thesis[k].Inventory << "\t" << thesis[k].Grade << "\t" << thesis[k].College << "\t" << thesis[k].Group << endl;


					if (Inventory == 0) {
						cout << "This Thesis is not Library!!\n";
						break;
					}
					else {

						cout << "amanatlibrary" << amanatlibrary << "\n";
						if (amanatlibrary < 3) {
							cout << "Enter the number of Books you want to borrow?";
							cin >> Number_Amanat3;
							amanatlibrary = amanatlibrary + Number_Amanat3;
						}
						else {
							cout << "you dont borrow\n";
							break;
						}
						thesis[k].Inventory = thesis[k].Inventory - Number_Amanat3;
						cout << thesis[k].ID << "     " << thesis[k].Title << "      " << Page_Number << "      "
							<< thesis[k].Inventory << "      " << thesis[k].Grade << "      " << thesis[k].College << "      " << Group << endl;
						int da, ma, ya, Dd, Md, Yd;
						cout << "Enter the amanat data\n";
						try {
							cin >> da >> ma >> ya;
							amanat.setDate(da, ma, ya);
						}
						catch (Bad_Date_Exception ex)
						{
							cout << "The entered data is out of range, Try again\n";
							cin >> da >> ma >> ya;
							amanat.setDate(da, ma, ya);
						}
						Date d(da, ma, ya);
						Date D = d + 7;
						cout << "delivery data is:";
						D.printDate();
						vector<Amanat>amanat3;
						amanat3.push_back(Amanat(Idd, Title,idT, da, ma, ya, D));

						AmanatThiesisfile << Idd << "     " << Title << "     " << idT << "      "

							<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

					}

				}
				inThesisfile << thesis[k].ID << "     " << thesis[k].Title << "      " << Page_Number << "      " << thesis[k].Inventory

					<< "      " << thesis[k].Grade << "      " << thesis[k].College << "      " << Group << endl;
				k++;
			}
			Thesisfile.close();
			inThesisfile.close();
			remove("Thesis.txt");
			rename("thesis1.txt", "Thesis.txt");


		}

		cout << "Do you want to insert new information  Book? Y|N";
		cin >> choice;
		system("cls");

	} while (choice == 'Y' || choice == 'y');

}*/
void Amanat::sabt() {


	Member M;
	int a;
	int Idd;
	int Page_Number, ID, Inventory, Number_book, Number_magazine;
	string  Title, Category, Grade, College, Group;
	int Number_Amanat1;
	int Number_Amanat2;
	int Number_Amanat3;
	char choice;
	string Type;
	string Idnumber;
	int Penalty;
	string Name;
	string Family;
	string National_code;
	int Id;
	cout << "Please Enter member 'ID For Sabt Book:"; cin >> Idd;
	do {

		int d, m, y;

		ifstream Memberfile("Member.txt", ios::in);
		if (!Memberfile) {
			cout << " The file could not be opened!";
			return;
		}
		int g = 0;
		while (Memberfile >> Name) {
			Memberfile >> Family;
			Memberfile >> National_code;
			Memberfile >> Id;
			Memberfile >> d;
			Memberfile >> m;
			Memberfile >> y;
			Memberfile >> Type;
			Memberfile >> Idnumber;
			Memberfile >> Penalty;
			member.push_back(Member(Name, Family, National_code, Id, d, m, y, Type, Idnumber, Penalty));
			g++;
		}
		for (int i = 0; i < member.size(); i++) {
			if (member[i].Id == Idd) {

				cout << member[i].Name << "     " << member[i].Family << "     " << member[i].National_code << "     " << member[i].Id << "     "

					<< d << "/" << m << "/" << y << "     " << member[i].Type << "     " << member[i].Idnumber << "     " << member[i].Penalty << endl;
				cout << "1. Record amant Book:\n";
				cout << "2. Record amanat Magazine:\n";
				cout << "3. Record amanat Thesis:\n";
				cout << "4. Exit\n\n";
				cout << "\n Which part you want to do?";

				cin >> a;
				if (a == 1) {

					ofstream AmanatBookfile("AmanatBook.txt", ios::app);
					if (!AmanatBookfile) {
						cout << " The file could not be opened!";
						return;
					}
					ofstream inBookfile("book1.txt", ios::out);
					if (!inBookfile) {
						cout << " The file could not be opened!";
						return;
					}

					int idB;
					cout << "Please Enter Book ID:";
					cin >> idB;

					int i = 0;
					ifstream Bookfile("Book.txt", ios::in);
					if (!Bookfile) {
						cout << " The file could not be opened!";
						return;
					}
					while (Bookfile >> ID) {
						Bookfile >> Title;
						Bookfile >> Page_Number;
						Bookfile >> Inventory;
						Bookfile >> Number_book;
						Bookfile >> Category;
						book.push_back(Book(ID, Title, Page_Number, Inventory, Number_book, Category));

						if (book[i].get_ID() == idB) {

							cout << book[i].ID << "\t" << book[i].Title << "\t" << book[i].Page_Number << "\t" << book[i].Inventory

								<< "\t" << book[i].Number_book << "\t" << book[i].Category << endl;


							if (Inventory == 0) {
								cout << "This Book is not Library!!\n";
								break;
							}
							else {
								cout << "amanatlibrary" << amanatlibrary << "\n";
								if (amanatlibrary < 3) {
									cout << "Enter the number of Books you want to borrow?";

									cin >> Number_Amanat1;
									amanatlibrary = amanatlibrary + Number_Amanat1;
								}
								else {
									cout << "you dont borrow\n";
									break;
								}
								book[i].Inventory = book[i].Inventory - Number_Amanat1;
								cout << ID << setw(12) << Title << setw(8) << Page_Number << setw(19)
									<< book[i].Inventory << setw(15) << Number_book << setw(22) << Category << endl;

								int da, ma, ya, Dd, Md, Yd;
								cout << "Enter the amanat data\n";
								try {
									cin >> da >> ma >> ya;
									amanat.setDate(da, ma, ya);

								}

								catch (Bad_Date_Exception ex)
								{
									cout << "The entered data is out of range, Try again\n";
									cin >> da >> ma >> ya;
									amanat.setDate(da, ma, ya);

								}
								Date d(da, ma, ya);
								cout << "delivery data is:";
								Date D = d + 7;
								D.printDate();
								vector<Amanat>amanat1;
								amanat1.push_back(Amanat(Idd, idB, da, ma, ya, D));

								AmanatBookfile << Idd << "     "  << idB << "      "

									<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

							}

						}
						inBookfile << book[i].ID << "    " << book[i].Title << "    " << book[i].Page_Number << "    "
							<< book[i].Inventory << "    " << book[i].Number_book << "     " << book[i].Category << endl;


						i++;
					}
					Bookfile.close();
					inBookfile.close();
					remove("Book.txt");
					rename("book1.txt", "Book.txt");


				}


				if (a == 2) {
					ofstream AmanatMagazinefile("AmanatMagazine.txt", ios::app);
					if (!AmanatMagazinefile) {
						cout << " The file could not be opened!";
						return;
					}

					ofstream inMagazinefile("magazine1.txt", ios::out);
					if (!inMagazinefile) {
						cout << " The file could not be opened!";
						return;
					}


					int idM;
					cout << "Please Enter Magazine ID:";
					cin >> idM;
					int j = 0;
					ifstream Magazinefile("Magazine.txt", ios::in);
					if (!Magazinefile) {
						cout << " The file could not be opened!";
						return;
					}
					while (Magazinefile >> ID) {
						Magazinefile >> Title;
						Magazinefile >> Page_Number;
						Magazinefile >> Inventory;
						Magazinefile >> Number_magazine;
						magazine.push_back(Magazine(ID, Title, Page_Number, Inventory, Number_magazine));
						if (magazine[j].get_ID() == idM) {

							cout << magazine[j].ID << "\t" << magazine[j].Title << "\t" << magazine[j].Page_Number

								<< "\t" << magazine[j].Inventory << "\t" << magazine[j].Number_magazine << endl;
							if (Inventory == 0) {
								cout << "This Magazine is not Library!!\n";
								break;
							}
							else {

								cout << "amanatlibrary" << amanatlibrary << "\n";
								if (amanatlibrary < 3) {
									cout << "Enter the number of Books you want to borrow?";
									cin >> Number_Amanat2;
									amanatlibrary = amanatlibrary + Number_Amanat2;
								}
								else {
									cout << "you dont borrow\n";
									break;
								}
								magazine[j].Inventory = magazine[j].Inventory - Number_Amanat2;
								cout << magazine[j].ID << setw(12) << magazine[j].Title << setw(8) << magazine[j].Page_Number << setw(19)
									<< magazine[j].Inventory << setw(15) << magazine[j].Number_magazine << endl;

								int da, ma, ya, Dd, Md, Yd;
								cout << "Enter the amanat data\n";
								try {
									cin >> da >> ma >> ya;
									amanat.setDate(da, ma, ya);
								}
								catch (Bad_Date_Exception ex)
								{
									cout << "The entered data is out of range, Try again\n";
									cin >> da >> ma >> ya;
									amanat.setDate(da, ma, ya);
								}
								cout << "delivery data is:";
								Date d(da, ma, ya);
								Date D = d + 7;
								D.printDate();

								vector<Amanat>amanat2;
								amanat2.push_back(Amanat(Idd, idM, da, ma, ya, D));

								AmanatMagazinefile << Idd << "     " << idM << "      "

									<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

							}

						}
						inMagazinefile << magazine[j].ID << "      " << magazine[j].Title << "     " << Page_Number << "      "
							<< magazine[j].Inventory << "      " << magazine[j].Number_magazine << endl;
						j++;
					}
					Magazinefile.close();
					inMagazinefile.close();
					remove("Magazine.txt");
					rename("magazine1.txt", "Magazine.txt");


				}

				if (a == 3) {

					ofstream AmanatThiesisfile("AmanatThiesis.txt", ios::app);
					if (!AmanatThiesisfile) {
						cout << " The file could not be opened!";
						return;
					}
					ofstream inThesisfile("thesis1.txt", ios::app);
					if (!inThesisfile) {
						cout << " The file could not be opened!";
						return;
					}



					int idT;
					cout << "Please Enter Thesis ID:";
					cin >> idT;
					int j = 0;

					ifstream Thesisfile("Thesis.txt", ios::in);
					if (!Thesisfile) {
						cout << " The file could not be opened!";
						return;
					}

					int k = 0;
					while (Thesisfile >> ID) {
						Thesisfile >> Title;
						Thesisfile >> Page_Number;
						Thesisfile >> Inventory;
						Thesisfile >> Grade;
						Thesisfile >> College;
						Thesisfile >> Group;
						thesis.push_back(Thesis(ID, Title, Page_Number, Inventory, Grade, College, Group));
						if (thesis[k].get_ID() == idT) {

							cout << thesis[k].ID << "\t" << thesis[k].Title << "\t" << thesis[k].Page_Number << "\t" <<

								thesis[k].Inventory << "\t" << thesis[k].Grade << "\t" << thesis[k].College << "\t" << thesis[k].Group << endl;


							if (Inventory == 0) {
								cout << "This Thesis is not Library!!\n";
								break;
							}
							else {

								cout << "amanatlibrary" << amanatlibrary << "\n";
								if (amanatlibrary < 3) {
									cout << "Enter the number of Books you want to borrow?";
									cin >> Number_Amanat3;
									amanatlibrary = amanatlibrary + Number_Amanat3;
								}
								else {
									cout << "you dont borrow\n";
									break;
								}
								thesis[k].Inventory = thesis[k].Inventory - Number_Amanat3;
								cout << thesis[k].ID << "     " << thesis[k].Title << "      " << Page_Number << "      "
									<< thesis[k].Inventory << "      " << thesis[k].Grade << "      " << thesis[k].College << "      " << Group << endl;
								int da, ma, ya, Dd, Md, Yd;
								cout << "Enter the amanat data\n";
								try {
									cin >> da >> ma >> ya;
									amanat.setDate(da, ma, ya);
								}
								catch (Bad_Date_Exception ex)
								{
									cout << "The entered data is out of range, Try again\n";
									cin >> da >> ma >> ya;
									amanat.setDate(da, ma, ya);
								}
								Date d(da, ma, ya);
								Date D = d + 7;
								cout << "delivery data is:";
								D.printDate();

								vector<Amanat>amanat3;
								amanat3.push_back(Amanat(Idd, idT, da, ma, ya, D));

								AmanatThiesisfile << Idd << "     " << idT << "      "

									<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

							}

						}
						inThesisfile << thesis[k].ID << "     " << thesis[k].Title << "      " << Page_Number << "      " << thesis[k].Inventory

							<< "      " << thesis[k].Grade << "      " << thesis[k].College << "      " << Group << endl;
						k++;
					}
					Thesisfile.close();
					inThesisfile.close();
					remove("Thesis.txt");
					rename("thesis1.txt", "Thesis.txt");


				}




			}



		}
		cout << "Do you want to insert new information  Book? Y|N";
		cin >> choice;
		system("cls");

	} while (choice == 'Y' || choice == 'y');

}
void Amanat::searchn() {
	while (1) {
		cout << "1. Search to view  members who borrow a particular Book:\n";
		cout << "2. Search to view  members who borrow a particular Magazine:\n";
		cout << "3. Search to view  members who borrow a particular Thesis:\n";
		cout << "4. Exit\n\n";
		cout << "\n Which part you want to do?";

		int da, ma, ya, Dd, Md, Yd;
		
		int a;
		cin >> a;
		if (a == 1) {

			ifstream AmanatBookfile("AmanatBook.txt", ios::in);
			if (!AmanatBookfile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanatt1;
			int idB;
			cout << "Please Enter Book ID For Search:";
			cin >> idB;
			int i = 0;
			while (AmanatBookfile >> idmember) {
				AmanatBookfile >> idBMT;
				AmanatBookfile >> da;
				AmanatBookfile >> ma;
				AmanatBookfile >> ya;
				AmanatBookfile >> Dd;
				AmanatBookfile >> Md;
				AmanatBookfile >> Yd;
				Date D(Dd, Md, Yd);
				amanatt1.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
				if (amanatt1[i].get_idbmt() == idB) {
					cout << " ID Member is:" << idmember << endl;

				}
				i++;
			}
			AmanatBookfile.close();

		}
		else if (a == 2) {


			ifstream AmanatMagazinefile("AmanatMagazine.txt", ios::in);
			if (!AmanatMagazinefile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanatt2;
			int idM;
			cout << "Please Enter Magazine ID For Search:";
			cin >> idM;
			int j = 0;
			while (AmanatMagazinefile >> idmember) {
				AmanatMagazinefile >> idBMT;
				AmanatMagazinefile >> da;
				AmanatMagazinefile >> ma;
				AmanatMagazinefile >> ya;
				AmanatMagazinefile >> Dd;
				AmanatMagazinefile >> Md;
				AmanatMagazinefile >> Yd;
				Date D(Dd, Md, Yd);
				amanatt2.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
				if (amanatt2[j].get_idbmt() == idM) {
					cout << " ID Member is:" << idmember << endl;

				}
				j++;
			}
			AmanatMagazinefile.close();
		}
		else if (a == 3) {
			ifstream AmanatThiesisfile("AmanatThiesis.txt", ios::in);
			if (!AmanatThiesisfile) {
				cout << " The file could not be opened!";
				return;
			}


			vector<Amanat>amanatt3;
			int idT;
			cout << "Please Enter Thesis ID For Search:";
			cin >> idT;
			int h = 0;
			while (AmanatThiesisfile >> idmember) {
				AmanatThiesisfile >> idBMT;
				AmanatThiesisfile >> da;
				AmanatThiesisfile >> ma;
				AmanatThiesisfile >> ya;
				AmanatThiesisfile >> Dd;
				AmanatThiesisfile >> Md;
				AmanatThiesisfile >> Yd;
				Date D(Dd, Md, Yd);
				amanatt3.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
				if (amanatt3[h].get_idbmt() == idT) {
					cout << " ID Member is:" << idmember << endl;

				}
				h++;
			}
			AmanatThiesisfile.close();
		}
		else {
			return;
		}

	}
}
void Amanat::searchm() {


	int idmember, da, ma, ya, Dd, Md, Yd;
	string name, family, idnumber;
	int a;


	ifstream AmanatBookfile("AmanatBook.txt", ios::in);
	if (!AmanatBookfile) {
		cout << " The file could not be opened!";
		return;
	}
	vector<Amanat>amanatt1;
	int idM;
	cout << "Please Enter member 'ID";
	cin >> idM;
	int i = 0;
	while (AmanatBookfile >> idmember) {
		AmanatBookfile >> idBMT;
		AmanatBookfile >> da;
		AmanatBookfile >> ma;
		AmanatBookfile >> ya;
		AmanatBookfile >> Dd;
		AmanatBookfile >> Md;
		AmanatBookfile >> Yd;
		Date D(Dd, Md, Yd);
		amanatt1.push_back(Amanat(idmember,idBMT, da, ma, ya, D));
		if (amanatt1[i].get_idmember() == idM) {

			cout << amanatt1[i].idBMT << "       " << "Data Amanat:" << da << "/" << ma << "/" << ya <<

				"     " << "Data Delivery:" << Dd << "/" << Md << "/" << Yd << endl;

		}
		i++;
	}
	AmanatBookfile.close();


	ifstream AmanatThiesisfile("AmanatThiesis.txt", ios::in);
	if (!AmanatThiesisfile) {
		cout << " The file could not be opened!";
		return;
	}
	vector<Amanat>amanatt3;

	int h = 0;
	while (AmanatThiesisfile >> idmember) {
		AmanatThiesisfile >> idBMT;
		AmanatThiesisfile >> da;
		AmanatThiesisfile >> ma;
		AmanatThiesisfile >> ya;
		AmanatThiesisfile >> Dd;
		AmanatThiesisfile >> Md;
		AmanatThiesisfile >> Yd;
		Date D(Dd, Md, Yd);
		amanatt3.push_back(Amanat(idmember,  idBMT, da, ma, ya, D));
		if (amanatt3[h].get_idmember() == idM) {

			cout << amanatt3[h].idBMT << "       " << "Data Amanat:" << da << "/" << ma << "/" << ya <<

				"     " << "Data Delivery:" << Dd << "/" << Md << "/" << Yd << endl;

		}
		i++;
	}
	AmanatThiesisfile.close();

	ifstream AmanatMagazinefile("AmanatMagazine.txt", ios::in);
	if (!AmanatMagazinefile) {
		cout << " The file could not be opened!";
		return;
	}
	vector<Amanat>amanatt2;

	int j = 0;
	while (AmanatMagazinefile >> idmember) {

		AmanatMagazinefile >> idBMT;
		AmanatMagazinefile >> da;
		AmanatMagazinefile >> ma;
		AmanatMagazinefile >> ya;
		AmanatMagazinefile >> Dd;
		AmanatMagazinefile >> Md;
		AmanatMagazinefile >> Yd;
		Date D(Dd, Md, Yd);
		amanatt2.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
		if (amanatt2[j].get_idmember() == idM) {
			cout << amanatt2[j].idBMT << "       " << "Data Amanat:" << da << "/" << ma << "/" << ya <<

				"     " << "Data Delivery:" << Dd << "/" << Md << "/" << Yd << endl;
		}
		j++;
	}
	AmanatMagazinefile.close();




}
void Amanat::show() {
	while (1) {
		cout << "1. report Books:\n";
		cout << "2. report Magazines:\n";
		cout << "3. report Thesises:\n";
		cout << "4. Exit\n\n";
		cout << "\n Which part you want to do?";

		int  da, ma, ya, Dd, Md, Yd;


		ifstream AmanatBookfile("AmanatBook.txt", ios::in);
		if (!AmanatBookfile) {
			cout << " The file could not be opened!";
			return;
		}
		int d, m, y;
		cout << "Please Enter Data Inventory" << endl;
		cin >> d >> m >> y;

		vector<Amanat>amanatt1;
		vector<Date>date1;
		int i = 0;
		while (AmanatBookfile >> idmember) {
			AmanatBookfile >> idBMT;
			AmanatBookfile >> da;
			AmanatBookfile >> ma;
			AmanatBookfile >> ya;
			AmanatBookfile >> Dd;
			AmanatBookfile >> Md;
			AmanatBookfile >> Yd;
			Date D(Dd, Md, Yd);
			amanatt1.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
			date1.push_back(Date(Dd, Md, Yd));
			if (date1[i].getDay() == d &&date1[i].getMonth() == m&& date1[i].getYear() == y) {

				cout << amanatt1[i].idmember << "          " << amanatt1[i].idBMT << "       " << "Data Amanat:" << da << "/" << ma << "/" << ya <<

					"     " << "Data Delivery:" << Dd << "/" << Md << "/" << Yd << endl;

			}
			i++;
		}
		AmanatBookfile.close();




		ifstream AmanatMagazinefile("AmanatMagazine.txt", ios::in);
		if (!AmanatMagazinefile) {
			cout << " The file could not be opened!";
			return;
		}


		vector<Amanat>amanatt2;
		vector<Date>date2;
		int j = 0;
		while (AmanatMagazinefile >> idmember) {
			AmanatMagazinefile >> idBMT;
			AmanatMagazinefile >> da;
			AmanatMagazinefile >> ma;
			AmanatMagazinefile >> ya;
			AmanatMagazinefile >> Dd;
			AmanatMagazinefile >> Md;
			AmanatMagazinefile >> Yd;
			Date D(Dd, Md, Yd);
			amanatt2.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
			date2.push_back(Date(Dd, Md, Yd));
			if (date2[j].getDay() == d &&date2[j].getMonth() == m&& date2[j].getYear() == y) {

				cout << amanatt2[j].idmember << "          " << amanatt2[j].idBMT << "       " << "Data Amanat:" << da << "/" << ma << "/" << ya <<

					"     " << "Data Delivery:" << Dd << "/" << Md << "/" << Yd << endl;

			}
			j++;
		}
		AmanatMagazinefile.close();

		vector<Amanat>amanatt3;
		vector<Date>date3;

		ifstream AmanatThiesisfile("AmanatThiesis.txt", ios::in);
		if (!AmanatThiesisfile) {
			cout << " The file could not be opened!";
			return;
		}


		int h = 0;
		while (AmanatThiesisfile >> idmember) {

			AmanatThiesisfile >> idBMT;
			AmanatThiesisfile >> da;
			AmanatThiesisfile >> ma;
			AmanatThiesisfile >> ya;
			AmanatThiesisfile >> Dd;
			AmanatThiesisfile >> Md;
			AmanatThiesisfile >> Yd;
			Date D(Dd, Md, Yd);
			amanatt3.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
			date3.push_back(Date(Dd, Md, Yd));
			if (date3[h].getDay() == d &&date3[h].getMonth() == m&& date3[h].getYear() == y) {

				cout << amanatt3[h].idmember << "          " << amanatt3[h].idBMT << "       " << "Data Amanat:" << da << "/" << ma << "/" << ya <<

					"     " << "Data Delivery:" << Dd << "/" << Md << "/" << Yd << endl;

			}
			h++;
		}
		AmanatThiesisfile.close();


	}
}
void Amanat::Delet() {
	int d, m, y;
	int da, ma, ya, Dd, Md, Yd, IDmember, IDneveshtar;
	while (1) {

		cout << "1. Delet amant Book:\n";
		cout << "2. Delet amanat Magazine:\n";
		cout << "3. Delet amanat Thesis:\n";
		cout << "4. Exit\n\n";
		cout << "\n Which part you want to do?";
		int a;
		cin >> a;
		if (a == 1) {

			ofstream outAmanatBookfile("Amanatbook1.txt", ios::out);
			if (!outAmanatBookfile) {
				cout << " The file could not be opened!";
				return;
			}
			ifstream AmanatBookfile("AmanatBook.txt", ios::in);
			if (!AmanatBookfile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanat1;
			cout << "Pleasa Enter ID Member";
			cin >> IDmember;
			cout << "\nPlease Enter ID Book";
			cin >> IDneveshtar;
			int i = 0;
			while (AmanatBookfile >> idmember) {
				AmanatBookfile >> idBMT;
				AmanatBookfile >> da;
				AmanatBookfile >> ma;
				AmanatBookfile >> ya;
				AmanatBookfile >> Dd;
				AmanatBookfile >> Md;
				AmanatBookfile >> Yd;
				Date D(Dd, Md, Yd);
				amanat1.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
				if (amanat1[i].get_idmember() == IDmember && amanat1[i].get_idbmt() == IDneveshtar) {
					;
					Book b;
					b.Enter(IDneveshtar);
					try {
						cin >> d >> m >> y;
						delivery.setDate(d, m, y);
					}
					catch (Bad_Date_Exception ex)
					{
						cout << "The entered data is out of range, Try again";
						cin >> d >> m >> y;
						delivery.setDate(d, m, y);
					}
					Date today(d, m, y);
					Date tahvil(Dd, Md, Yd);

					if (daysCompare(today, tahvil) == 1) {
						cout << "you should  be for each day of deale!!";
						int jarime = d - Dd;
						jarime = jarime * 500;
						Member m;
						m.Jarime(IDmember, jarime);

					}
					else {

						Member m1;
						m1.Payment(IDmember);
					}


				}
				else
				{
					outAmanatBookfile << amanat1[i].idmember  << "\t" << amanat1[i].idBMT << "\t"

						<< da << " " << ma << " " << ya << "      " << Dd << " " << Md << " " << Yd << endl;

				}
				i++;
			}
			AmanatBookfile.close();
			outAmanatBookfile.close();
			remove("AmanatBook.txt");
			rename("Amanatbook1.txt", "AmanatBook.txt");

		}

		else if (a == 2) {

			ofstream outAmanatMagazinefile("Amanatmagazine1.txt", ios::out);
			if (!outAmanatMagazinefile) {
				cout << " The file could not be opened!";
				return;
			}
			ifstream AmanatMagazinefile("AmanatMagazine.txt", ios::in);
			if (!AmanatMagazinefile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanat2;
			cout << "Pleasa Enter ID Member";
			cin >> IDmember;
			cout << "\nPlease Enter ID Book";
			cin >> IDneveshtar;
			int j = 0;
			while (AmanatMagazinefile >> idmember) {
				AmanatMagazinefile >> idBMT;
				AmanatMagazinefile >> da;
				AmanatMagazinefile >> ma;
				AmanatMagazinefile >> ya;
				AmanatMagazinefile >> Dd;
				AmanatMagazinefile >> Md;
				AmanatMagazinefile >> Yd;
				Date D(Dd, Md, Yd);
				amanat2.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
				if (amanat2[j].get_idmember() == IDmember && amanat2[j].get_idbmt() == IDneveshtar) {

					;
					Magazine M;
					M.Enter(IDneveshtar);
					try {
						cin >> d >> m >> y;
						delivery.setDate(d, m, y);
					}
					catch (Bad_Date_Exception ex)
					{
						cout << "The entered data is out of range, Try again";
						cin >> d >> m >> y;
						delivery.setDate(d, m, y);
					}
					Date today(d, m, y);
					Date tahvil(Dd, Md, Yd);
					if (daysCompare(today, tahvil) == 1) {
						cout << "you should  be for each day of deale!!";
						int jarime = d - Dd;
						jarime = jarime * 500;
						Member m;
						m.Jarime(IDmember, jarime);

					}
					else {
						Member m2;
						m2.Payment(IDmember);
					}

				}
				else {
					outAmanatMagazinefile << amanat2[j].idmember << "\t" << amanat2[j].idBMT << "\t"

						<< da << " " << ma << " " << ya << "      " << Dd << " " << Md << " " << Yd << endl;
				}
				j++;


			}
			AmanatMagazinefile.close();
			outAmanatMagazinefile.close();
			remove("AmanatMagazine.txt");
			rename("Amanatmagazine1.txt", "AmanatMagazine.txt");

		}

		else if (a == 3) {

			ifstream AmanatThiesisfile("AmanatThiesis.txt", ios::in);
			if (!AmanatThiesisfile) {
				cout << " The file could not be opened!";
				return;
			}



			ofstream outAmanatThiesisfile("Amanatthiesis1.txt", ios::out);
			if (!outAmanatThiesisfile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanat3;
			cout << "Pleasa Enter ID Member";
			cin >> IDmember;
			cout << "\nPlease Enter ID Book";
			cin >> IDneveshtar;
			int h = 0;
			while (AmanatThiesisfile >> idmember) {
				AmanatThiesisfile >> idBMT;
				AmanatThiesisfile >> da;
				AmanatThiesisfile >> ma;
				AmanatThiesisfile >> ya;
				AmanatThiesisfile >> Dd;
				AmanatThiesisfile >> Md;
				AmanatThiesisfile >> Yd;
				Date D(Dd, Md, Yd);
				amanat3.push_back(Amanat(idmember,idBMT, da, ma, ya, D));
				if (amanat3[h].get_idmember() == IDmember && amanat3[h].get_idbmt() == IDneveshtar) {

					;
					Thesis t;
					t.Enter(IDneveshtar);
					try {
						cin >> d >> m >> y;
						delivery.setDate(d, m, y);
					}
					catch (Bad_Date_Exception ex)
					{
						cout << "The entered data is out of range, Try again";
						cin >> d >> m >> y;
						delivery.setDate(d, m, y);
					}
					Date today(d, m, y);
					Date tahvil(Dd, Md, Yd);
					if (daysCompare(today, tahvil) == 1) {
						cout << "you should  be for each day of deale!!";
						int jarime = d - Dd;
						jarime = jarime * 500;
						Member m;
						m.Jarime(IDmember, jarime);

					}
					else {
						Member m2;
						m2.Payment(IDmember);
					}


				}

				else {
					outAmanatThiesisfile << amanat3[h].idmember << "\t" << amanat3[h].idBMT << "\t"

						<< da << " " << ma << " " << ya << "      " << Dd << " " << Md << " " << Yd << endl;
				}
				h++;

			}

			AmanatThiesisfile.close();
			outAmanatThiesisfile.close();
			remove("AmanatThiesis.txt");
			rename("Amanatthiesis1.txt", "AmanatThiesis.txt");
		}
	}
}
void Amanat::Edit() {
	int da, ma, ya, Dd, Md, Yd, IDmember, IDneveshtar;

	while (1) {
		cout << "1. Edit amant Book:\n";
		cout << "2. Edit amanat Magazine:\n";
		cout << "3. Edit amanat Thesis:\n";
		cout << "4. Exit\n\n";
		cout << "\n Which part you want to do?";

		int a;
		cin >> a;
		if (a == 1) {
			ofstream outAmanatBookfile("Amanatbook1.txt", ios::out);
			if (!outAmanatBookfile) {
				cout << " The file could not be opened!";
				return;
			}
			ifstream AmanatBookfile("AmanatBook.txt", ios::in);
			if (!AmanatBookfile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanat1;
			cout << "Pleasa Enter ID Member";
			cin >> IDmember;
			cout << "\nPlease Enter ID Book";
			cin >> IDneveshtar;
			int i = 0;

			while (AmanatBookfile >> idmember) {
				AmanatBookfile >> idBMT;
				AmanatBookfile >> da;
				AmanatBookfile >> ma;
				AmanatBookfile >> ya;
				AmanatBookfile >> Dd;
				AmanatBookfile >> Md;
				AmanatBookfile >> Yd;
				Date D(Dd, Md, Yd);
				amanat1.push_back(Amanat(idmember, idBMT, da, ma, ya, D));
				if (amanat1[i].get_idmember() == IDmember && amanat1[i].get_idbmt() == IDneveshtar) {

					D = D + 7;

				}
				outAmanatBookfile << idmember << "     " << idBMT << "      "

					<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;
				i++;
			}


			AmanatBookfile.close();
			outAmanatBookfile.close();
			remove("AmanatBook.txt");
			rename("Amanatbook1.txt", "AmanatBook.txt");
		}

		else if (a == 2) {
			ofstream outAmanatMagazinefile("Amanatmagazine1.txt", ios::out);
			if (!outAmanatMagazinefile) {
				cout << " The file could not be opened!";
				return;
			}
			ifstream AmanatMagazinefile("AmanatMagazine.txt", ios::in);
			if (!AmanatMagazinefile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanat2;
			cout << "Pleasa Enter ID Member";
			cin >> IDmember;
			cout << "\nPlease Enter ID Book";
			cin >> IDneveshtar;
			int j = 0;
			while (AmanatMagazinefile >> idmember) {
				AmanatMagazinefile >> idBMT;
				AmanatMagazinefile >> da;
				AmanatMagazinefile >> ma;
				AmanatMagazinefile >> ya;
				AmanatMagazinefile >> Dd;
				AmanatMagazinefile >> Md;
				AmanatMagazinefile >> Yd;
				Date D(Dd, Md, Yd);
				amanat2.push_back(Amanat(idmember,  idBMT, da, ma, ya, D));
				if (amanat2[j].get_idmember() == IDmember && amanat2[j].get_idbmt() == IDneveshtar) {

					D = D + 7;

				}
				outAmanatMagazinefile << amanat2[j].idmember << "     " << amanat2[j].idBMT << "      "

					<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;
				j++;
			}
			AmanatMagazinefile.close();
			outAmanatMagazinefile.close();
			remove("AmanatMagazine.txt");
			rename("Amanatmagazine1.txt", "AmanatMagazine.txt");
		}


		else if (a == 3) {
			ifstream AmanatThiesisfile("AmanatThiesis.txt", ios::in);
			if (!AmanatThiesisfile) {
				cout << " The file could not be opened!";
				return;
			}

			ofstream outAmanatThiesisfile("Amanatthiesis1.txt", ios::out);
			if (!outAmanatThiesisfile) {
				cout << " The file could not be opened!";
				return;
			}
			vector<Amanat>amanat3;
			cout << "Pleasa Enter ID Member";
			cin >> IDmember;
			cout << "\nPlease Enter ID Book";
			cin >> IDneveshtar;
			int h = 0;
			while (AmanatThiesisfile >> idmember) {
				AmanatThiesisfile >> idBMT;
				AmanatThiesisfile >> da;
				AmanatThiesisfile >> ma;
				AmanatThiesisfile >> ya;
				AmanatThiesisfile >> Dd;
				AmanatThiesisfile >> Md;
				AmanatThiesisfile >> Yd;
				Date D(Dd, Md, Yd);
				amanat3.push_back(Amanat(idmember,idBMT, da, ma, ya, D));
				if (amanat3[h].get_idmember() == IDmember && amanat3[h].get_idbmt() == IDneveshtar) {

					D = D + 7;

				}

				outAmanatThiesisfile << amanat3[h].idmember  << "     " << amanat3[h].idBMT << "      "

					<< da << " " << ma << " " << ya << "      " << D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;
				h++;
			}

			AmanatThiesisfile.close();
			outAmanatThiesisfile.close();
			remove("AmanatThiesis.txt");
			rename("Amanatthiesis1.txt", "AmanatThiesis.txt");

		}
	}

}












void Bookmenu() {
	Library *L;
	Book b;
	char choice;
	int n;
	while (1) {
		cout << endl;
		cout << "1. Insert New Book\n";
		cout << "2. Remove the Book\n";
		cout << "3. Edit Book information\n";
		cout << "4. Search a Book\n";
		cout << "5. Show List Book\n";
		cout << "6. Exit\n\n";
		cout << "\n Which part you want to do?";
		int a;
		cin >> a;
		cout << endl;
		system("cls");
		switch (a) {
		case 1:

			do {
				cout << "\n Enter the ID  of Book: ";
				cin >> n;
				L = &b;
				L->Enter(n);
				system("cls");
				cout << "Do you want to insert new information  Book? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2: cout << " Please Enter Book 'ID For remove:"; cin >> n; L = &b; L->Delet(n); system("cls"); break;
		case 3: cout << " Please Enter Book 'ID For edit:"; cin >> n; L = &b; system("cls"); L->Edit(n);  break;
		case 4: cout << " Please Enter Book 'ID For search:"; cin >> n; L = &b; L->Search(n); break;
		case 5: cout << " Please Enter Book 'Category For show:";  L = &b; L->Show();  break;
		case 6: return;
		default: cout << "Enter 1<number<6\n";
		};

	}
}
void Magazinemenu() {
	Library *L;
	Magazine m;
	char choice;
	int n;
	while (1) {
		cout << endl;
		cout << "1. Insert New Magazine\n";
		cout << "2. Remove the Magazine\n";
		cout << "3. Edit Magazine information\n";
		cout << "4. Search a Magazine\n";
		cout << "5. Show List Magazine\n";
		cout << "6. Exit\n\n";
		cout << "\n Which part you want to do?";

		int a;
		cin >> a;
		cout << endl;
		system("cls");
		switch (a) {
		case 1:

			do {
				cout << "\n Enter the ID  of magazine : ";
				cin >> n;
				L = &m;
				L->Enter(n);
				system("cls");
				cout << "Do you want to insert new information  Magazine? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2: cout << "Please Enter Magazine 'ID For remove:"; cin >> n; L = &m; L->Delet(n); system("cls"); break;
		case 3: cout << "Please Enter Magazine 'ID For edit:"; cin >> n; L = &m; system("cls"); L->Edit(n);  break;
		case 4: cout << "Please Enter Magazine 'ID For search:"; cin >> n; L = &m; L->Search(n); break;
		case 5:   L = &m; L->Show(); break;
		case 6: return;
		default: cout << "Enter 1<number<6\n";
		};

	}
}
void Thesismenu() {
	Library *L;
	Thesis t;
	char choice;
	int n;
	while (1) {
		cout << endl;
		cout << "1. Insert New Thesis\n";
		cout << "2. Remove the Thesis\n";
		cout << "3. Edit Thesis information\n";
		cout << "4. Search a Thesis\n";
		cout << "5. Show List Thesis\n";
		cout << "6. Exit\n\n";
		cout << "\n Which part you want to do?";

		int a;
		cin >> a;
		cout << endl;
		system("cls");
		switch (a) {
		case 1:

			do {
				cout << "\n Enter the ID of thesis: ";
				cin >> n;
				L = &t;
				L->Enter(n);
				system("cls");
				cout << "Do you want to insert new information  Thesis? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2: cout << "Please Enter Thesis 'ID For remove:"; cin >> n; L = &t; L->Delet(n); system("cls"); break;
		case 3: cout << "Please Enter Thesis 'ID For edit:"; cin >> n; system("cls"); L = &t; L->Edit(n);  break;
		case 4: cout << "Please Enter Thesis 'ID For search:"; cin >> n; L = &t; L->Search(n); break;
		case 5:   L = &t; L->Show(); break;
		case 6: return;
		default: cout << "Enter 1<number<6\n";
		};

	}
}
void Librarianmenu() {
	Person *P;
	Librarian l;
	char choice;
	int n;
	while (1) {
		cout << endl;
		cout << "1. Insert New Librarian\n";
		cout << "2. Remove the Librarian\n";
		cout << "3. Edit Librarian information\n";
		cout << "4. Search a Librarian\n";
		cout << "5. Show List Librarian\n";
		cout << "6. Exit\n\n";
		cout << "\n Which part you want to do?";

		int a;
		cin >> a;
		cout << endl;
		system("cls");
		switch (a) {
		case 1:
			do {

				P = &l;
				P->Enter();
				system("cls");
				cout << "Do you want to insert new information  Book? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2:  cout << "Please Enter librarian 'ID For remove:"; cin >> n; P = &l; P->Delet(n); system("cls"); break;
		case 3:  cout << "Please Enter librarian 'ID For edit:"; cin >> n; system("cls"); P = &l; P->Edit(n);  break;
		case 4:  cout << "Please Enter librarian 'ID For search:"; cin >> n; P = &l; P->Search(n);  break;
		case 5:P = &l; P->Show(); break;
		case 6: return;
		default: cout << "Enter 1<number<6\n";
		};

	}
}
void Membermenu() {
	Person *P;
	Member m;
	char choice;
	int n;
	while (1) {
		cout << endl;
		cout << "1. Insert New Member\n";
		cout << "2. Remove the Member\n";
		cout << "3. Edit Member information\n";
		cout << "4. Search a Member\n";
		cout << "5. Show List Member\n";
		cout << "6. Payment of fines' Member\n";
		cout << "7. Exit\n\n";
		cout << "\n Which part you want to do?";

		int a;
		cin >> a;
		cout << endl;
		system("cls");
		switch (a) {
		case 1:

			do {

				P = &m;
				P->Enter();
				system("cls");
				cout << "Do you want to insert new information  Member? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2:  cout << "Please Enter member 'ID For remove:"; cin >> n; P = &m; P->Delet(n); system("cls"); break;
		case 3:  cout << "Please Enter member 'ID For edit:"; cin >> n; system("cls"); P = &m; P->Edit(n); break;
		case 4:  cout << "Please Enter member 'ID For search:"; cin >> n; P = &m; P->Search(n); break;
		case 5:P = &m; P->Show(); break;
		case 6:  cout << "Please Enter member 'ID For Payment of fines:"; cin >> n; m.Payment(n); break;
		case 7: return;
		default: cout << "Enter 1<number<7\n";
		};

	}
}
void Amantmenu() {
	char choice;
	int n;
	Amanat A;
	while (1) {
		cout << endl;
		cout << "1. Sabt Amanat\n";
		cout << "2. Search for report Members\n";
		cout << "3. Search for report Neveshtar\n";
		cout << "4. Report\n";
		cout << "5.Remove Amanat\n";
		cout << "6.Edite Amant\n;";
		cout << "\n Which part you want to do?";

		int a;
		cin >> a;
		cout << endl;
		system("cls");
		switch (a) {
		case 1:A.sabt(); break;
		case 2:A.searchn(); break;
		case 3:A.searchm(); break;
		case 4:A.show(); break;
		case 5:A.Delet(); break;
		case 6:A.Edit(); break;
		}; break;
	}
}
int main()
{
	while (1) {

		cout << "\n  < Library Menu > \n";
		cout << "1. Book Management;\n";
		cout << "2. Magazine Management;\n";
		cout << "3. Thesis Management;\n";
		cout << "4. Member Management;\n";
		cout << "5. Librarian Management;\n";
		cout << "6. Amanat Management;\n";
		cout << "7. Exit ;\n";

		int number;
		cout << "\n Which part you want to do?";
		cin >> number;
		system("cls");
		switch (number) {
		case 1: Bookmenu(); break;
		case 2: Magazinemenu(); break;
		case 3: Thesismenu(); break;
		case 4:	Membermenu(); break;
		case 5:	Librarianmenu(); break;
		case 6:	Amantmenu(); break;
		case 7:	return 0;
		default: cout << "Enter 1<number<3 \n";
		};

	}


	_getch();
	return 0;
}

