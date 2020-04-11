#include<iostream>
#include<string.h>

using namespace std;


int main(){
	
	char *q;
	q  = new char[15];
	strcpy (q,"hello world");
	cout << q << endl;
	int a,i;
	a= strlen(q);
	
	for(i=0;i<=a;i++){
		if (q[i]>='a'&&q[i]<='z')
			q[i] = q[i]-32;
		else continue;
	}
	
	cout << q << endl;
	
	delete []q;
	return 0;
}