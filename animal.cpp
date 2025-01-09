#include"animal.h"

/*********************************************************/
animal :: animal(){
	type = "";
	max_age = 0;
}

/*********************************************************/
animal :: ~animal(){
	type = "";
	max_age = 0;
}

/*********************************************************/
bool animal :: checkAge(const int val){
	return false;
}
/*********************************************************/
void animal :: print(){
	std :: cout << "\nAnimal Type: " << type << " Max age: " << max_age << endl;
}
/*********************************************************/
bool animal :: feedAnimal(){
	return false;
}
/*********************************************************/
bool animal :: getAlong(){
	return true;
}

/*********************************************************/
animal :: animal(const string & str, const int age){
	type = str;
	max_age = age;
}
/*********************************************************/
string animal :: getType() const{
	return type;
}
/*********************************************************/
bool animal :: setter(const string str, const int ageU){
	type = str;
	max_age = ageU;
	return true;
}
/*********************************************************/
bool animal :: isFull(){
	bool val = false;
	if( max_age != 0){
		cout << "\nThe parent has infos." << endl;
		val = true;
	}
	else{
		cout << "\nparents is empty" << endl;
	}
	return val;
}
