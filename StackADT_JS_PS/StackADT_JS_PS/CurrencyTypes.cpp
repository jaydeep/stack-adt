/*
@class Implementation for CurrencyTypes class
*/

#include "CurrencyTypes.h"

//United States dollar
//Constructors
USD::USD()
{
	sCurrencyName = "USD";
	sFractionalName = "Cent(s)";
}

USD::USD(const string& sLocalCurrencyName, const string& sLocalFractionalName)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
}

USD::USD(const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = "USD";
	sFractionalName = "Cent(s)";
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

USD::USD(const string& sLocalCurrencyName, const string& sLocalFractionalName, const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

//Mutators
void USD::setiWholeValue(const int& iLocalWholeValue)
{
	iWholeValue = iLocalWholeValue;
}

void USD::setiFractionalValue(const int& iLocalFractionalValue)
{
	iFractionalValue = iLocalFractionalValue;
}

//Accessors
const string& USD::getsCurrencyName()
{
	return sCurrencyName;
}
const string& USD::getsFractionalName()
{
	return sFractionalName;
}

//Overloaded Operators
ostream &operator << (ostream& strm, const USD &obj)
{
	if (obj.iFractionalValue < 10)
	{
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << "0" << obj.iFractionalValue << " " << obj.sFractionalName;
	}
	else
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << obj.iFractionalValue << " " << obj.sFractionalName;

	return strm;
}

USD USD::operator + (const USD& right)
{
	USD temp = right;
	temp.iWholeValue = iWholeValue + right.iWholeValue;
	temp.iFractionalValue = iFractionalValue + right.iFractionalValue;
	temp.simplify();
	return temp;
}

USD USD::operator - (const USD &right)
{
	USD temp = right;
	temp.iWholeValue = iWholeValue - right.iWholeValue;
	temp.iFractionalValue = iFractionalValue - right.iFractionalValue;
	temp.simplify();

	if (temp.iWholeValue < 0)
	{
		temp.setiWholeValue(0);
		temp.setiFractionalValue(0);
		string s_SubtractionError = "\nError: Subtraction results in negative value. Operation cancelled.\n";
		throw  (s_SubtractionError);
		return temp;
	}
	else
		return temp;
}


/********************************************************************************/
//Euro
//Constructors
EUR::EUR()
{
	sCurrencyName = "EUR";
	sFractionalName = "Cent";
}

EUR::EUR(const string& sLocalCurrencyName, const string& sLocalFractionalName)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
}

EUR::EUR(const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = "EUR";
	sFractionalName = "Cent";
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

EUR::EUR(const string& sLocalCurrencyName, const string& sLocalFractionalName, const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

//Mutators
void EUR::setsCurrencyName(const string& sLocalCurrencyName)
{
	sCurrencyName = sLocalCurrencyName;
}

void EUR::setsFractionalName(const string& sLocalFractionalName)
{
	sFractionalName = sLocalFractionalName;
}

//Accessors
const string& EUR::getsCurrencyName()
{
	return sCurrencyName;
}
const string& EUR::getsFractionalName()
{
	return sFractionalName;
}

//Overloaded Operators
ostream &operator << (ostream& strm, const EUR &obj)
{
	if (obj.iFractionalValue < 10)
	{
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << "0" << obj.iFractionalValue << " " << obj.sFractionalName;
	}
	else
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << obj.iFractionalValue << " " << obj.sFractionalName;

	return strm;
}

EUR EUR::operator + (const EUR& right)
{
	EUR temp = right;
	temp.iWholeValue = iWholeValue + right.iWholeValue;
	temp.iFractionalValue = iFractionalValue + right.iFractionalValue;
	temp.simplify();
	return temp;
}

EUR EUR::operator - (const EUR &right)
{
	EUR temp = right;
	temp.iWholeValue = iWholeValue - right.iWholeValue;
	temp.iFractionalValue = iFractionalValue - right.iFractionalValue;
	temp.simplify();

	if (temp.iWholeValue < 0)
	{
		temp.setiWholeValue(0);
		temp.setiFractionalValue(0);
		string s_SubtractionError = "\nError: Subtraction results in negative value. Operation cancelled.\n";
		throw  (s_SubtractionError);
		return temp;
	}
	else
		return temp;
}

/********************************************************************************/
//Pound sterling
//Constructors
GBP::GBP()
{
	sCurrencyName = "GBP";
	sFractionalName = "Penny / Pence";
}

GBP::GBP(const string& sLocalCurrencyName, const string& sLocalFractionalName)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
}

GBP::GBP(const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = "GBP";
	sFractionalName = "Penny / Pence";
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

GBP::GBP(const string& sLocalCurrencyName, const string& sLocalFractionalName, const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

//Mutators
void GBP::setsCurrencyName(const string& sLocalCurrencyName)
{
	sCurrencyName = sLocalCurrencyName;
}

void GBP::setsFractionalName(const string& sLocalFractionalName)
{
	sFractionalName = sLocalFractionalName;
}

//Accessors
const string& GBP::getsCurrencyName()
{
	return sCurrencyName;
}
const string& GBP::getsFractionalName()
{
	return sFractionalName;
}

//Overloaded Operators
ostream &operator << (ostream& strm, const GBP &obj)
{
	if (obj.iFractionalValue < 10)
	{
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << "0" << obj.iFractionalValue << " " << obj.sFractionalName;
	}
	else
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << obj.iFractionalValue << " " << obj.sFractionalName;

	return strm;
}

GBP GBP::operator + (const GBP& right)
{
	GBP temp = right;
	temp.iWholeValue = iWholeValue + right.iWholeValue;
	temp.iFractionalValue = iFractionalValue + right.iFractionalValue;
	temp.simplify();
	return temp;
}

GBP GBP::operator - (const GBP &right)
{
	GBP temp = right;
	temp.iWholeValue = iWholeValue - right.iWholeValue;
	temp.iFractionalValue = iFractionalValue - right.iFractionalValue;
	temp.simplify();

	if (temp.iWholeValue < 0)
	{
		temp.setiWholeValue(0);
		temp.setiFractionalValue(0);
		string s_SubtractionError = "\nError: Subtraction results in negative value. Operation cancelled.\n";
		throw  (s_SubtractionError);
		return temp;
	}
	else
		return temp;
}

/********************************************************************************/
//Australian dollar
//Constructors
AUD::AUD()
{
	sCurrencyName = "AUD";
	sFractionalName = "Cent(s)";
}

AUD::AUD(const string& sLocalCurrencyName, const string& sLocalFractionalName)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
}

AUD::AUD(const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = "AUD";
	sFractionalName = "Cent(s)";
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

AUD::AUD(const string& sLocalCurrencyName, const string& sLocalFractionalName, const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

//Mutators
void AUD::setsCurrencyName(const string& sLocalCurrencyName)
{
	sCurrencyName = sLocalCurrencyName;
}

void AUD::setsFractionalName(const string& sLocalFractionalName)
{
	sFractionalName = sLocalFractionalName;
}

//Accessors
const string& AUD::getsCurrencyName()
{
	return sCurrencyName;
}
const string& AUD::getsFractionalName()
{
	return sFractionalName;
}

//Overloaded Operators
ostream &operator << (ostream& strm, const AUD &obj)
{
	if (obj.iFractionalValue < 10)
	{
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << "0" << obj.iFractionalValue << " " << obj.sFractionalName;
	}
	else
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << obj.iFractionalValue << " " << obj.sFractionalName;

	return strm;
}

AUD AUD::operator + (const AUD& right)
{
	AUD temp = right;
	temp.iWholeValue = iWholeValue + right.iWholeValue;
	temp.iFractionalValue = iFractionalValue + right.iFractionalValue;
	temp.simplify();
	return temp;
}

AUD AUD::operator - (const AUD &right)
{
	AUD temp = right;
	temp.iWholeValue = iWholeValue - right.iWholeValue;
	temp.iFractionalValue = iFractionalValue - right.iFractionalValue;
	temp.simplify();

	if (temp.iWholeValue < 0)
	{
		temp.setiWholeValue(0);
		temp.setiFractionalValue(0);
		string s_SubtractionError = "\nError: Subtraction results in negative value. Operation cancelled.\n";
		throw  (s_SubtractionError);
		return temp;
	}
	else
		return temp;
}

/********************************************************************************/
//Canadian dollar
//Constructors
CAD::CAD()
{
	sCurrencyName = "CAD";
	sFractionalName = "Cent(s)";
}

CAD::CAD(const string& sLocalCurrencyName, const string& sLocalFractionalName)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
}

CAD::CAD(const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = "CAD";
	sFractionalName = "Cent(s)";
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

CAD::CAD(const string& sLocalCurrencyName, const string& sLocalFractionalName, const int& iLocalWholeValue, const int& iLocalFractionalValue)
{
	sCurrencyName = sLocalCurrencyName;
	sFractionalName = sLocalFractionalName;
	iWholeValue = iLocalWholeValue;
	iFractionalValue = iLocalFractionalValue;
}

//Mutators
void CAD::setsCurrencyName(const string& sLocalCurrencyName)
{
	sCurrencyName = sLocalCurrencyName;
}

void CAD::setsFractionalName(const string& sLocalFractionalName)
{
	sFractionalName = sLocalFractionalName;
}

//Accessors
const string& CAD::getsCurrencyName()
{
	return sCurrencyName;
}
const string& CAD::getsFractionalName()
{
	return sFractionalName;
}

//Overloaded Operators
ostream &operator << (ostream& strm, const CAD &obj)
{
	if (obj.iFractionalValue < 10)
	{
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << "0" << obj.iFractionalValue << " " << obj.sFractionalName;
	}
	else
		strm << obj.iWholeValue << " " << obj.sCurrencyName << " " << obj.iFractionalValue << " " << obj.sFractionalName;

	return strm;
}

CAD CAD::operator + (const CAD& right)
{
	CAD temp = right;
	temp.iWholeValue = iWholeValue + right.iWholeValue;
	temp.iFractionalValue = iFractionalValue + right.iFractionalValue;
	temp.simplify();
	return temp;
}

CAD CAD::operator - (const CAD &right)
{
	CAD temp = right;
	temp.iWholeValue = iWholeValue - right.iWholeValue;
	temp.iFractionalValue = iFractionalValue - right.iFractionalValue;
	temp.simplify();

	if (temp.iWholeValue < 0)
	{
		temp.setiWholeValue(0);
		temp.setiFractionalValue(0);
		string s_SubtractionError = "\nError: Subtraction results in negative value. Operation cancelled.\n";
		throw  (s_SubtractionError);
		return temp;
	}
	else
		return temp;
}