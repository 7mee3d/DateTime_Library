
// Library Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LibDate.h" 
#include "ReadNumbers.h"

using namespace myDate;
using namespace std; 
using namespace read_Number; 

int main()
{

	unsigned short int const kYEAR{ readNumberPositiveShortUnsinged("Enter the year : ") }; 
	unsigned short int const kMONTH{ readNumberPositiveShortUnsinged("Enter the month : ") }; 
	unsigned short int const kDAY{ readNumberPositiveShortUnsinged("Enter the day : ") }; 


	stDateInformation date1 = { kYEAR  , kMONTH  , kDAY };


	cout << myDate::replaseDatekDAY_kMONTH_kYEAR_FormatDate(date1, "dd/mm/yyyy  yy  DDDD  MMM  Month") << endl; 
}

