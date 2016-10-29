/*
@class Implementation for Currency class
*/

#include "Currency.h"
using namespace std;

//Constructors
Currency::Currency()
{
	iWholeValue = 0;
	iFractionalValue = 0;
}

Currency::Currency(const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

//Mutators
void Currency::setiWholeValue(const int& iLocalWholeValue)
{
	iWholeValue = iLocalWholeValue;
}

void Currency::setiFractionalValue(const int& iLocalFractionalValue)
{
	iFractionalValue = iLocalFractionalValue;
}

//Accessors
const int& Currency::getiWholeValue()
{
	return iWholeValue;
}

const int& Currency::getiFractionalValue()
{
	return iFractionalValue;
}

const string& Currency::getsCurrencyName()
{
	return sCurrencyName;
}
const string& Currency::getsFractionalName()
{
	return sFractionalName;
}


//Miscellanous Functions
void Currency::simplify()
{
	if (iFractionalValue < 0)	//check for underflow of iFractionalValue to i_WholeParts
	{
		iWholeValue -= ((abs(iFractionalValue) / 100) + 1);
		iFractionalValue = 100 - (abs(iFractionalValue) % 100);
	}

	if (iFractionalValue >= 100) //check for overflow of iFractionalValue to i_WholeParts
	{
		iWholeValue += (iFractionalValue / 100);
		iFractionalValue = iFractionalValue % 100;
	}
}