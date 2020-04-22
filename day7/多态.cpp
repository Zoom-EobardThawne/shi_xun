//Inheritance and Derivation
#include <iostream>	
#include<string.h>						
using namespace std;						


class Hero{
protected:
// data Number:
	string name ;												
	string sex  ;						
	
public:
// public functions:
	 Hero (string nm, string sx)			
	//construct obj
	{
		name=nm;								
		sex = sx;					
	}	

	void Show() const						  
	{ 
		cout << "name: " << name << endl;		
		cout << "sex: " << sex << endl;			
	}	
    virtual void skill_1(){
        cout << "Hero skill_1" << endl;
    }
    virtual void skill_2(){
        cout << "Hero skill_2" << endl;
    }
    virtual  void skill_3(){
        cout << "Hero skill_3" << endl;
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
	Houyi(string nm, string sx,int sd):  Hero(nm,sx),skin("yellow")	
	{ speed = sd; }						

	void Show() const							
	{ 
		Hero::Show();							
        
		cout << "speed: " << speed << endl;	
        skin.show();	
		cout << endl;							
	}	

    void skill_1(){
        cout << "Houyi skill_1" << endl;
    }
     void skill_2(){
        cout << "Houyi skill_2" << endl;
    }
    void skill_3(){
        cout << "Houyi skill_3" << endl;
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

    void skill_1(){
        cout << "Luban skill_1" << endl;
    }
    void skill_2(){
        cout << "Luban skill_2" << endl;
    }
    void skill_3(){
        cout << "Luban skill_3" << endl;
    }
};

void playgame(Hero & hero){
    hero.skill_1();
    hero.skill_2();
    hero.skill_3();
}


int main(void)							
{
	Houyi obj1("HOUYI","male",66);						
	Luban obj2("luban", "male",55 );	
    cout << "--------------------------------------" <<endl;

	obj1.Show();	
    playgame(obj1);	
    cout << "--------------------------------------" <<endl;

	obj2.Show();
    playgame(obj2);				
    cout << "--------------------------------------" <<endl;
    
    return 0;                    			
}


