#pragma once
#include <iostream>
#include <random>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;



//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY




class Igra3
{
	int *numbers;
	int n;
public:
	Igra3();
	Igra3(int);
	void addNumbers();
	Igra3(const Igra3&);
	Igra3(Igra3&&);
	void print();
	int& operator[](int);
	const int& operator[](int) const;
	void drawnNumbers();
	~Igra3();
	int compare(const Igra3&) const; // TODO: Napraviti negativne brojeve
private:
	bool exists(int);
	void copy(const Igra3&);
	void move(Igra3&&);
};

