#include"dog.h"

/*********************************************************/
dog :: dog(){
	comments = "Gets along with other animal";
	hunger = false;
	care = 7;
	lifespan = 0;
	animal :: max_age  = 13; //max;
	animal :: type = "Dog";
}
/*********************************************************/
dog :: dog(const string & aname, const int dogAge){
	comments = "Gets along with other animal";
	hunger = false;
	care = 7;
	name  = aname;
	lifespan = dogAge;
	animal :: max_age = 13;
	animal :: type = "Dog";
}
/*********************************************************/

dog :: ~dog(){
	comments = "";
	hunger = false;
	care = 0;
	lifespan = 0;
}
/*********************************************************/

bool dog :: setter(const string str, const int ageU){
	name = str;
	lifespan = ageU;
	return true;
}

/*********************************************************/
string dog :: getType() const{
	return type;
}
/*********************************************************/
bool dog :: checkAge(const int val){
	if( lifespan != 0){
	bool temp = false;
	int check = animal :: max_age;
	if(val<= check ){
		cout << "\nSeems like a dog has a life span that meets your needs" << endl;
		temp = true;
	}
	else{
		cout << "\nA dog will live less time than you want unfornutnately" << endl;
		temp = false;
	}
	lifespan = val;
	return temp;
	}
	else{
		throw "No age to compare";
	}
}
/*********************************************************/
void dog :: print(){
	if( lifespan != 0){
	cout << "\n--DOG SECTION--" << endl;
	cout << "\nName of dog: " << name;
	if(hunger){
		cout << "\nDog is full " << endl;

	}
	else{
		cout << "\nDog is still hungry" << endl;
	}
	cout << "\nLife span of an animal: " << lifespan;
	cout << " User wanted a lifetime of: " << animal :: max_age;
	cout << "\nLevel of care from 1-10: " << care;
	cout << "\nGeneral comment: " << comments << endl;
	}
	else{
		throw "You Entered a dog with 0 age lifespan, and no name";
	}
}
/*********************************************************/

bool dog :: getAlong(){
	cout << "\n" << comments << " \n";
	return true;
}
/*********************************************************/

bool dog :: feedAnimal(){
	if( hunger == false){
	cout << "\n\nThe dog is happily munching on its food,"
	     << "\n creating a delightful symphony of crunching and lip-smacking sounds!" << endl;
	hunger = true;// the animal ate;
	}
	else{
		throw "Dogis already fed. The dog is FULL";
	}
	return true;
}
/*********************************************************/
string dog :: getName() const{
	return name;
}
