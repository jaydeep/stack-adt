/*
@class Interface for CurrencyTypes class
This interface contains 5 classes derived from the Currency class, adding two protected members representing the whole parts name and fractional parts name of a specific currency.
*/

#ifndef CURRENCY_TYPES_H
#define CURRENCY_TYPES_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

//United States dollar
class USD : public Currency
{
protected:
	string sCurrencyName, sFractionalName;

public:
	//Constructors
	USD();
	USD(const string&, const string&);
	USD(const int&, const int&);
	USD(const string&, const string&, const int&, const int&);

	//Mutators
	void setiWholeValue(const int&);
	void setiFractionalValue(const int&);

	//Accessors
	const string& getsCurrencyName();
	const string& getsFractionalName();

	//Overloaded Operators		
	/*
	Overloaded Input >>
	- Inputs relevant currency data.
	- Could not implement in CurrencyTypes.cpp (inaccesible members)
	@pre	An instance of a USD object exists.
	@post	The user is prompted to enter values for iWholeValue, then iFractionalValue. These values are then used to alter the member variables of a given instance of a USD object.
	*/
	friend istream &operator >> (istream& strm, USD& obj)
	{
		cout << obj.sCurrencyName << ": ";
		strm >> obj.iWholeValue;
		cout << obj.sFractionalName << ": ";
		strm >> obj.iFractionalValue;
		obj.simplify();
		return strm;
	}

	/*
	Overloaded Output <<
	- Outputs relevant currency data.
	@pre	An instance of a USD object exists.
	@post	Outputs name of currency, value for whole parts, name of fractional, and value for fractional parts to the stream.
	*/
	friend ostream &operator << (ostream&, const USD&);

	/*Overloaded Addition +
	- Allows the user to add one Currency object to another.
	@param	right	Object on the right side of the + sign
	@pre	Two instances of USD objects exist.
	@post	Returns a USD object with the values of the two original USD objects added together.
	*/
	USD USD::operator + (const USD& right);

	/*Overloaded Subtraction -
	- Allows user to subtract one USD object from another.
	@param	right	Object on the right side of the - sign
	@pre	Two instances of USD objects exist.
	@post	Returns a USD object with the whole and fractional values of the second USD object subtracted from the first. If whole value becomes negative, operation is not carried out.*/
	USD USD::operator - (const USD&);
};

/********************************************************************************/
//Euro
class EUR : public Currency
{
protected:
	string sCurrencyName, sFractionalName;

public:
	//Constructors
	EUR();
	EUR(const string&, const string&);
	EUR(const int&, const int&);
	EUR(const string&, const string&, const int&, const int&);

	//Mutators
	void setsCurrencyName(const string&);
	void setsFractionalName(const string&);

	//Accessors
	const string& getsCurrencyName();
	const string& getsFractionalName();

	//Overloaded Operators
	friend istream &operator >> (istream& strm, EUR& obj)
	{
		cout << obj.sCurrencyName << ": ";
		strm >> obj.iWholeValue;
		cout << obj.sFractionalName << ": ";
		strm >> obj.iFractionalValue;
		obj.simplify();
		return strm;
	}
	friend ostream &operator << (ostream&, const EUR&);
	EUR EUR::operator + (const EUR& right);
	EUR EUR::operator - (const EUR&);

};

/********************************************************************************/
//Pound sterling
class GBP : public Currency
{
protected:
	string sCurrencyName, sFractionalName;

public:
	//Constructors
	GBP();
	GBP(const string&, const string&);
	GBP(const int&, const int&);
	GBP(const string&, const string&, const int&, const int&);

	//Mutators
	void setsCurrencyName(const string&);
	void setsFractionalName(const string&);

	//Accessors
	const string& getsCurrencyName();
	const string& getsFractionalName();

	//Overloaded Operators
	friend istream &operator >> (istream& strm, GBP& obj)
	{
		cout << obj.sCurrencyName << ": ";
		strm >> obj.iWholeValue;
		cout << obj.sFractionalName << ": ";
		strm >> obj.iFractionalValue;
		obj.simplify();
		return strm;
	}
	friend ostream &operator << (ostream&, const GBP&);
	GBP GBP::operator + (const GBP& right);
	GBP GBP::operator - (const GBP&);

};

/********************************************************************************/
//Australian dollar
class AUD : public Currency
{
protected:
	string sCurrencyName, sFractionalName;

public:
	//Constructors
	AUD();
	AUD(const string&, const string&);
	AUD(const int&, const int&);
	AUD(const string&, const string&, const int&, const int&);

	//Mutators
	void setsCurrencyName(const string&);
	void setsFractionalName(const string&);

	//Accessors
	const string& getsCurrencyName();
	const string& getsFractionalName();

	//Overloaded Operators
	friend istream &operator >> (istream& strm, AUD& obj)
	{
		cout << obj.sCurrencyName << ": ";
		strm >> obj.iWholeValue;
		cout << obj.sFractionalName << ": ";
		strm >> obj.iFractionalValue;
		obj.simplify();
		return strm;
	}
	friend ostream &operator << (ostream&, const AUD&);
	AUD AUD::operator + (const AUD& right);
	AUD AUD::operator - (const AUD&);
};

/********************************************************************************/
//Canadian dollar
class CAD : public Currency
{
protected:
	string sCurrencyName, sFractionalName;

public:
	//Constructors
	CAD();
	CAD(const string&, const string&);
	CAD(const int&, const int&);
	CAD(const string&, const string&, const int&, const int&);

	//Mutators
	void setsCurrencyName(const string&);
	void setsFractionalName(const string&);

	//Accessors
	const string& getsCurrencyName();
	const string& getsFractionalName();

	//Overloaded Operators
	friend istream &operator >> (istream& strm, CAD& obj)
	{
		cout << obj.sCurrencyName << ": ";
		strm >> obj.iWholeValue;
		cout << obj.sFractionalName << ": ";
		strm >> obj.iFractionalValue;
		obj.simplify();
		return strm;
	}
	friend ostream &operator << (ostream&, const CAD&);
	CAD CAD::operator + (const CAD& right);
	CAD CAD::operator - (const CAD&);
};

#endif