#include"horse.h"
/********************************************************/
horse :: horse(){
	strong = true;
	size  = 0;
	name = "";
}
/********************************************************/
horse :: horse(const string & aname, const int val) : animal("horse", 30){
	name = aname;
	age = val;
	animal :: type = "horse";
	animal :: max_age = 25;
	size = 0;
	hungry = false;
}
/********************************************************/
bool horse :: setter(const string str, const int ageU){
	name = str;
	age = ageU;
	return true;
}
/********************************************************/
horse :: ~horse(){
	strong = false;
	size = 0;
	name = "";
}
/********************************************************/
void horse :: print(){
	if(name == ""){
		throw " Nothing to print ";
	}
	cout << "\n--HORSE--";
	cout << "\nHorse name: " << name << endl;
	cout << "Horse's age your looking for: " << age << endl;
	cout << "  Hungry: ";
	if(hungry)
		cout << "No";
	else
		 cout << "Yes" << endl;
}
/********************************************************/
bool horse :: checkAge(const int val){
	if(name == ""){
		throw "No cat has been entered";
	}
	age = val;
	bool temp = false;
	if( val < 30){	
		temp = true;
		cout << "\nHorse is a good option NEIGH NEIGH NEIGH (horse sound :)";
	}
	else{
		cout << "\nA horse willl live less. Might not be a good option";
	}
	return temp;
}
/*********************************************************/
string horse :: getType() const{
	return type;
}
/********************************************************/
bool horse :: feedAnimal(){
	if(name == ""){
		throw "No horse to feed";

	}
	if(hungry == false){
		cout << "\n" << name << " is HUNGRY :( : ( : (" << endl;
		cout << "\n" << name << " is eating now. YEEHAW :)" << endl;
		hungry = true;
	}
	else{
		
		cout << "\n" << name << " is Full. YEEHAW" << endl;
	}
	bool temp = hungry;
	return temp;
}
/********************************************************/
bool horse :: getAlong(){
	cout << "\nA horse will always get along with other animal" << endl;
	return true;
}
/********************************************************/
string horse:: getName() const{
	return name;
}
