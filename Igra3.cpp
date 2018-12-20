#include "Igra3.h"


//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY
//STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY; STEFO GAY


Igra3::Igra3()
{
	numbers = new int[n = 7];
}

Igra3::Igra3(int i)
{
	numbers = new int[i];
	n = i;
}

void Igra3::addNumbers()
{
	cout << endl << "Unesite 7 brojeva koji se nalaze u opsegu izmedju 1 i 45:" << endl;
	int temp;
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			cin >> temp;
			if (exists(temp))
			{
				cout << endl << "Taj broj ste vec uzeli, molimo vas da izaberete neki drugi" << endl;
				continue;
			}
			if (temp < 1 || temp > 45)
			{
				cout << "Uneseni broj se ne nalazi trazenom opsegu! Molimo vas da pokusate ponovo." << endl;
				continue;
			}
			else
				break;
		}
		numbers[i] = temp;
	}
}

Igra3::Igra3(const Igra3 &other)
{
	copy(other);
}

Igra3::Igra3(Igra3 &&other)
{
	move(std::move(other));
}

void Igra3::print()
{
	for (int i = 0; i < n; i++)
		cout << numbers[i] << ", ";
	cout << endl;
}

int & Igra3::operator[](int i)
{
	return numbers[i];
}

const int & Igra3::operator[](int i) const
{
	return numbers[i];
}

void Igra3::drawnNumbers()
{
	const int AMOUNT = 20; //amount of random numbers that need to be generated
	const int MAX = 45; //maximum value (of course, this must be at least the same as AMOUNT;
	 //array to store the random numbers in

	srand(time(NULL)); //always seed your RNG before using it

	//generate random numbers:
	for (int i = 0; i < AMOUNT; i++)
	{
		bool check; //variable to check or number is already used
		int n; //variable to store the number in
		do
		{
			n = rand() % MAX + 1;
			//check or number is already used:
			check = true;
			for (int j = 0; j < i; j++)
				if (n == numbers[j]) //if number is already used
				{
					check = false; //set check to false
					break; //no need to check the other elements of value[]
				}
		} while (!check); //loop until new, unique number is found
		numbers[i] = n; //store the generated number in the array
	}
}

bool Igra3::exists(int n)
{
	for (int i = 0; i < 7; i++)
	{
		if (numbers[i] == n)
			return true;
	}
	return false;
}

void Igra3::copy(const Igra3 &other)
{
	std::copy(other.numbers, other.n + other.numbers, numbers = new int[n + other.n]);
}

void Igra3::move(Igra3 &&other)
{
	n = std::move(other.n);
	numbers = std::move(other.numbers);
	other.numbers = nullptr;
}


int Igra3::compare(const Igra3 &other) const
{
	if (n > other.n)
		return 0;
	int counter = 1;
	int pointsTemp = 0;
	cout << "Brojevi koje ste pogodili na izvlacenju su: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < other.n; j++)
		{
			if (numbers[i] == other.numbers[j])
			{
				cout << numbers[i] << ", ";
				pointsTemp += counter * 10;
				counter++;
			}
		}
	}
	cout << endl;
	return pointsTemp;
}


Igra3::~Igra3()
{
	//delete[] numbers; ------ iz nekog razloga puca kad ovo ima?
	numbers = nullptr;
}
