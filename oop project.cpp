#include <iostream>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;
class bank {
private:
	string name;
	string address;

};
class user {
private:
	string firstname;
	string lastname;
	string phonenumber;
	string email;
	string id;
	string nicno;
	int accountnumber;
	int pin;
public:
	user(string f, string l, string n, string e, string id, string ni,int p) {
		firstname = f;
		lastname = l;
		phonenumber = n;
		email = e;
		this->id = id;
		nicno = ni;
		pin = p;
	}
	void setfirstname(string n) {
		firstname = n;
	}
	void setlastname(string l) {
		lastname = l;
	}
	void setphonenumber(string nu) {
		phonenumber = nu;
	}
	void setemail(string e) {
		email = e;
	}
	void setid(string g) {
		id = g;
	}
	void setnic(string ni) {
		nicno = ni;
}
	void setpin(int x) {
		pin = x;
	}
	void setaccountnumber(){
		accountnumber = 1000000000000000 + rand() % 100000000;
	}
	string idout() {
		return id;
	}
	int pinout(){
		return pin;
	}
};
class account;
class transation{
	private:
      account from;
      account to;
      double amount;
      bool status;
      public:
      	transation(account &t,account &f,double b,bool s){
      		from=t;
      		to=f;
      		amount=b;
      		status=s;
		  }
		  void excute(){  
	         
		  }
};
class account{
private:
	string id;
	int balance=1299;
	user *owner;

public:
	account(string i, int p, user *t) {
		id = i;
		balance = p;
		this->owner = t;
}
	void withdraw(int amount,int p) {
		if(id==owner->idout()){
		    	if(p==owner->pinout()){
			balance -= amount;
			fstream trans("transation.dat", ios::out);
			trans << amount << "has been withdraw from your account";
			 trans<<"your new balance is"<<balance;
			trans.close();
		}
		else
		  cout<<"sorry you have enter the wrong pin";
	}
		else 
		cout<<"your id is not correct\n";
	}
		void deposit(int money,int p) 
		{
			if (id == owner->idout()){
				if(p==owner->pinout()){
				balance += money;
				fstream trans("transation.dat", ios::out);
				trans << money << "has been added to your account";
				trans<<"your new balance is"<<balance;
				trans.close();
			}
			}
			else 
			cout<<"sorry your id is not correct\n";
		}
};

int main() {
	user t("akshay","kumar","ggdfgdfg00","rrertreterter","22k-4559","4550143248501", 2222);
	ofstream file("person.dat", ios::in);
	file.write((char*)&t,sizeof(user));
	account p("22k-4559",12999,&t);
	p.withdraw(3000,2222);
	p.	deposit(200,2222);
	file.close();
	
}