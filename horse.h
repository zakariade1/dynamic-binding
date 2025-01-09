#ifndef HORSE_H
#define HORSE_H
#include"animal.h"

class horse: public animal{
	public:
		horse();
		~horse();
		string getName() const;
		horse(const string & aname, const int val);
		string getType() const override;
		bool setter(const string str, const int ageU);
		bool checkSize();
		void print();
		bool checkAge(const int val);// checks if lifespan meets
		bool feedAnimal();// will set hunger to true;
		bool getAlong();// will tell us if we can have other animals with this one. 
	private:
		bool strong;
		int size;
		string name; 
		bool hungry;
		int age;
};
#endif
