#include<iostream>
#include<string.h>

using namespace  std;

class Ex_{

public:

	string 	name;
	string  hooby;
	
	int getAge(void);
	string getAdds(void);
	
	void setAge(int _age);
	string setAdds(string _adds);
	
private:

	int 	age;
	string  adds;
};

void Ex_::setAge(int _age){
	if(_age <0 || _age > 1000){
		cout << "Invalid Age" << endl;
	}
	
	age = _age;
}



string Ex_::setAdds(string _adds){
	
	adds = _adds;
}



int Ex_::getAge(void){
	
	return age;
}


string Ex_::getAdds(void){
	
	return adds;
}


int main(){
	
	cout << "-----------------" << endl ;
	cout << "personal information" << endl ;
	Ex_*ex;
	ex = new Ex_;
		
	ex->name = "wxx";
	ex->hooby = "paly computer games";
	ex->setAge(21);
	ex->setAdds("Brooklyn");
	
	cout << "nanme:" << ex->name << endl;
	cout << "age:" 	 << ex->getAge()  << endl;
	cout << "hooby:" << ex->hooby << endl;
	cout << "adds:" 	 << ex->getAdds()  << endl;
	
	
	delete ex;
	
	cout << "-----------------" << endl ;
	
	
	
	
	
	return 0;
}