/*
@class Interface for Currency class
This class is a base class, and contains two protected members representing the whole parts and fractional parts of a generic currency.
*/

#ifndef CURRENCY_H
#define CURRENCY_H

#include <cstdlib>		//required for abs() function
#include <string>

using namespace std;

class Currency
{
protected:
	int iWholeValue, iFractionalValue;
	string sCurrencyName, sFractionalName;

public:
	//Constructors
	Currency();
	Currency(const int&, const int&);

	//Mutators
	void setiWholeValue(const int&);
	void setiFractionalValue(const int&);

	//Accessors
	virtual const int& getiWholeValue();
	virtual const int& getiFractionalValue();
	virtual const string& getsCurrencyName();
	virtual const string& getsFractionalName();

	//Overloaded Operators
	//virtual friend ostream &operator << (ostream&, const Currency&); //not allowed

	//Miscellaneous Functions

	/*
	simplify Function
	- Checks if iFractionalValue is greater than 100 or less than 0
	- If value is found, then iWholeValue and iFractionalValue are adjusted to conform to proper representation of the given currency
	- For example, 2 USD and 110 Cent(s) ($2.110) would be simplified to 3 USD and 10 Cent(s) ($3.10), and 2 USD and -10 Cent(s) ($2.-10) would be simplified to 1 USD and 90 Cent(s) ($2.90).
	@pre	A Currency with iFractionalValue > 100 or iFractionalValue < 0 exists.
	*/
	void simplify();
};

#endif