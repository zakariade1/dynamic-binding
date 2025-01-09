#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
using namespace std;

class animal{
	public:
		animal();
		virtual string getType() const;
		virtual ~animal();
		virtual string getName() const = 0;
		bool isFull();// unique only in animal to check if parent is full or not. 
		animal(const string & str, const int age);
		virtual bool setter(const string str, const int ageU);
		virtual bool checkAge(const int val);//checks the life span and if it meets it returns true.
		virtual void print();// will print the data for a specific animal.  
		virtual bool feedAnimal();// will tell you how much you need to spend on the food. 
		virtual bool getAlong() = 0;// will tell you if the animal gets along with other animals or not. true or false
	protected:
		string type; // name of the animal
		int max_age; // maximum life span in human years
};
#endif
