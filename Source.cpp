#include "Igra3.h"

int main()
{
	Igra3 userNumbers, computerNumbers(20);
	int points;

	userNumbers.addNumbers();
	cout << endl << "Izabrali ste sljedece brojeve: ";
	userNumbers.print();

	cout << "Izvlacenje lota je zavrsilo! Izvuceni su sljedeci brojevi: ";
	computerNumbers.drawnNumbers();
	computerNumbers.print();

	points = userNumbers.compare(computerNumbers);
	cout << "Broj bodova koji ste osvojili je: " << points; 

	getchar();
	getchar();
}