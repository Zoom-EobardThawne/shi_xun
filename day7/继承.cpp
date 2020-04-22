//Inheritance and Derivation
#include <iostream>	
#include<string.h>							// pre-treatment
using namespace std;						// namespace


class Hero{
protected:
// data Number:
	string name ;												
	string sex  ;						
	
public:
// public functions:
	 Hero (string nm, string sx)			// construction function
	//construct obj
	{
		name=nm;								
		sex = sx;					
	}	

		void Show() const						  
	{ 
		cout << "name: " << name << endl;		// display nanme
		cout << "sex: " << sex << endl;			// display sex
	}	
};

class Skin{
public:
    Skin(const string &cl){
        color =cl;
    }
    ~Skin(){
        cout <<"~Skin()"<<endl;
    }
    void show (void) const{
        cout <<"Skin color: "<<color<<endl;
    }
private:
    string color;
};

class Houyi: virtual public  Hero 
{
protected:
// data Number:
	int speed ;	
    Skin skin;							
public:
// public function:
	Houyi(string nm, string sx,int sd):  Hero(nm,sx),skin("yellow")	// construction function
	{ speed = sd; }						// copy title

	void Show() const							// display related information
	{ 
		Hero::Show();							
        
		cout << "speed: " << speed << endl;	
        skin.show();	
		cout << endl;							// line feed
	}	
};



class Luban: public Hero
{
protected:
// data Number:
	int speed;
    Skin skin;						
public:
// public function:
	Luban(string nm, string sx, int sd)	
		: Hero(nm, sx),skin("red")
	{ speed = sd; }									
	void Show() const								
	{ 
		Hero::Show();												
		cout << "speed " << speed << endl; 	
        skin.show();	
		cout << endl;								
	}	
};




int main(void)							
{
	Houyi obj1("HOUYI","male",66);						
	Luban obj2("luban", "male",55 );	

	obj1.Show();									
	obj2.Show();				

	return 0;                    			
}


