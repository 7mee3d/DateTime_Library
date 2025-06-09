#pragma once
#pragma warning ( disable : 4996 ) 

#include <iostream> 
#include <ctime> 
#include <string> 
#include<vector> 
#include<iomanip> 


using namespace  std; 

#define _Integer  int

namespace myDate {

	//Enumrations 
	

	enum enDayOfWeek {

		kSUNDAY = 0,
		kMONDAY = 1,
		kTUESDAY = 2,
		kWEDNESDAY = 3,
		kTHURSDAY = 4,
		kFRIDAY = 5,
		kSATURDAY = 6
	};

	enum enMounth {

		kJANUARY = 0,
		kFEBRUARY = 1,
		kMARCH = 2,
		kAPRIL = 3,
		kMAY = 4,
		kJUNE = 5,
		kJULY = 6,
		kAUGUST = 7,
		kSEPTEMBER = 8,
		kOCTOBER = 9,
		kNOVEMBER = 10,
		kDECEMBER = 11,
	};

	enum enCompareTwoDate {

		kBEFORE = -1 ,
		kEQUAL = 0 , 
		kAFTER = 1 
	};


	//Structures 
	
	struct stDateInformation {

		unsigned short _Integer kYEAR{};
		unsigned short _Integer kMONTH{};
		unsigned short _Integer kDAY {};

	};


	struct stPeriodOfDate {

		stDateInformation startDate{};
		stDateInformation endDate{};

	}; 

	//stDateInformation increasingDayByX(stDateInformation date, unsigned short int const kNUMBER_ADDING_DAY_NEW);

	//Constants 

	unsigned short _Integer const kZERO{ 0 };
	unsigned short _Integer const kONE_HUNDRED{ 100 };
	unsigned short _Integer const kFOUR_HUNDRED{ 400 };
	unsigned short _Integer const kNUMBER_FOUR{ 4 };
	unsigned short _Integer       kNUMBER_DAY_IN_YEAR_ORGINAL { 365 };
	unsigned short _Integer const kNUMBER_HOUR_IN_DAY {24 };
	unsigned short _Integer const kNUMBER_MINTUES_IN_DAY { 60 };
	unsigned short _Integer const kNUMBER_SECOUNDS_IN_DAY { 60 };
	unsigned short _Integer const kNUMBER_OF_WEEK { 7 };
	unsigned short _Integer const kNUMBER_MONTH  { 12 };
	unsigned short _Integer const kNUMBER_FIRST_MONTH { 1 };
	unsigned short _Integer const kONE  { 1 };
	unsigned short _Integer const kNUMBER_ONE_DECADE   { 10 };
	unsigned short _Integer const kNUMBER_ONE_CENTURY  { 100 };
	unsigned short _Integer const kNUMBER_ONE_MILLENNIUM  { 1000 };


	/*
			A function that checks whether a year is a leap year or not

			leap year--> 466 Day 
			Not Leap ( Orginal Year ) --> 465 Day
	*/

	bool isLeapYear(unsigned short _Integer const kYEAR) {

		if (kYEAR % kFOUR_HUNDRED == kZERO) //kFOUR_HUNDRED --> 400 
			return true; 
		else if (kYEAR % kONE_HUNDRED == kZERO) //kONE_HUNDRED --> 100 
			return false; 
		else if (kYEAR % kNUMBER_FOUR == kZERO) //kNUMBER_FOUR --> 4 
			return true; 

		else
		return false; 

		//return (kYEAR % 4 == ::kZERO && kYEAR % 100 != ::kZERO) || (kYEAR % 400 == ::kZERO);
		//return kYEAR % 100 == kZERO ? kYEAR % 400 == kZERO : kYEAR % 4 == kZERO; 
	}


	/*
			Return the number of days if leap 366 and non-leap 365
	*/
	unsigned short _Integer numberOfDayInYear(unsigned short _Integer const kYEAR) {

		return isLeapYear(kYEAR) ? ++kNUMBER_DAY_IN_YEAR_ORGINAL : kNUMBER_DAY_IN_YEAR_ORGINAL  ;
	}

	unsigned short _Integer numberOfDayInMonth(unsigned short _Integer const kYEAR, unsigned short _Integer const kMONTH) {

		if (kMONTH < kONE || kMONTH >  kNUMBER_MONTH ) return kZERO;

		//unsigned short int const kDAY_OF_MONTH[13]{ kZERO , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }; 
		unsigned short int const kDAY_OF_MONTH[13]{ kZERO , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1 , 0 , 1 }; 
		return (kMONTH == 2) ? isLeapYear(kYEAR) ? 29 : 28 : kDAY_OF_MONTH[kMONTH] + 30;

		//return (kMONTH == 2)? isLeapYear(kYEAR) ? 29 : 28  : kDAY_OF_MONTH[kMONTH]  ;
	}


	// --------------------------------- Calc year ----------------------------------


	//Calculating the number of hours in a day 
	_Integer calcNumberOfHourInYear( _Integer const kYEAR) {

		return (numberOfDayInYear (kYEAR ) * kNUMBER_HOUR_IN_DAY);

	}

	//Calculating the number of minutes in a day
	_Integer calcNumberOfMinutsInYear(_Integer const kYEAR) {
		return (kNUMBER_MINTUES_IN_DAY * calcNumberOfHourInYear (kYEAR));
	}

	//Calculating the number of Secoounds in a day
	_Integer calcNumberOfSecoundsInYear(_Integer const kYEAR) {
		return (kNUMBER_SECOUNDS_IN_DAY * calcNumberOfMinutsInYear (kYEAR));
	}


	// --------------------------------- Calc month ----------------------------------

	//Calculating the number of hours in a month 
	_Integer calcNumberOfHourInMonth(_Integer const kYEAR , _Integer const kMONTH) {

		return (numberOfDayInMonth(kYEAR , kMONTH) * kNUMBER_HOUR_IN_DAY);

	}

	//Calculating the number of minutes in a month
	_Integer calcNumberOfMinutsInMonth(_Integer const kYEAR,  _Integer const kMONTH) {
		return (kNUMBER_MINTUES_IN_DAY * calcNumberOfHourInMonth(kYEAR , kMONTH));
	}

	//Calculating the number of Secoounds in a month
	_Integer calcNumberOfSecoundsInMonth(_Integer const kYEAR,  _Integer const kMONTH) {
		return (kNUMBER_SECOUNDS_IN_DAY * calcNumberOfMinutsInMonth(kYEAR , kMONTH));
	}
	// ----------------------------------- Date Formating -------------------------------------


	void printDateFormat(stDateInformation date, string const kSEPARATOR = "/") {


		cout << date.kDAY << kSEPARATOR << date.kMONTH << kSEPARATOR << date.kYEAR <<'\n';

	}

	//------------------------ Find Order Day and Name of Week -----------------------------------------

	unsigned short _Integer findTheOrderOfDayInWeek(unsigned short _Integer const kYEAR, unsigned short _Integer const kMOUNTH, unsigned short _Integer const kDAY = {1}) {
	
		unsigned short _Integer const kNUMBER_FOUTEEN{ 14 };
		unsigned short _Integer const kNUMBER_MOUNTH_OF_YEAR{ kNUMBER_MONTH };
		unsigned short _Integer const kNUMBER_DAY_OF_WEEK{ 7 };

		unsigned short _Integer const a = ((kNUMBER_FOUTEEN - kMOUNTH) / kNUMBER_MOUNTH_OF_YEAR);
		unsigned short _Integer const year = kYEAR - a;

		unsigned short _Integer const mounth = kMOUNTH + (a * kNUMBER_MOUNTH_OF_YEAR) - 2;

		unsigned short _Integer const dayBornOrder = (kDAY + year + (year / 4) - (year / 100) + (year / 400) + ((31 * mounth) / kNUMBER_MOUNTH_OF_YEAR)) % kNUMBER_DAY_OF_WEEK;


		return dayBornOrder;
	}

	unsigned short _Integer findTheOrderOfDayInWeek(stDateInformation &date) {
/*
		unsigned short _Integer const kNUMBER_FOUTEEN{ 14 };
		unsigned short _Integer const kNUMBER_MOUNTH_OF_YEAR{ kNUMBER_MONTH };
		unsigned short _Integer const kNUMBER_DAY_OF_WEEK{ 7 };

		unsigned short _Integer const a = ((kNUMBER_FOUTEEN - date.kMONTH) / kNUMBER_MOUNTH_OF_YEAR);
		unsigned short _Integer const year = date.kYEAR - a;

		unsigned short _Integer const mounth = date.kMONTH + (a * kNUMBER_MOUNTH_OF_YEAR) - 2;

		unsigned short _Integer const dayBornOrder = (date.kDAY + year + (year / 4) - (year / 100) + (year / 400) + ((31 * mounth) / kNUMBER_MOUNTH_OF_YEAR)) % kNUMBER_DAY_OF_WEEK;
	
		return dayBornOrder;

	*/

		return findTheOrderOfDayInWeek(date.kYEAR, date.kMONTH, date.kDAY); 
	}
	
	string findDayOfWeekString(const enDayOfWeek kDAY_INDEX_ORDER , bool IS_FULL_NAME_DAY = false ) {

		string dayOfWeek[kNUMBER_OF_WEEK]{ "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , " Fri " , " Sat" };
	
		string dayOfWeekFull[kNUMBER_OF_WEEK]{ "Sunday" , "Monday" , "Tuesday" , "Wedneday" , "Thursday" , " Friday " , " Saturday" };

		return IS_FULL_NAME_DAY ? dayOfWeekFull[kDAY_INDEX_ORDER] : dayOfWeek[kDAY_INDEX_ORDER];
	}

	
	
	string findNameMounthString(const enMounth kMUNTH_INDEX_ORDER, bool IS_FULL_NAME_DAY = false ) {

		string Mounth[kNUMBER_MONTH]{ "Jan" , "Feb" , "Mar" , "Apr" , "May" , " Jun " , " Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
	
		string Mounth_FullName [kNUMBER_MONTH]{ "January" , "February" , "March" , "April" , "May" , " June" , "July" , "August" , "Septemper" , "Octobar" , "November" , "December" };

		return IS_FULL_NAME_DAY ? Mounth_FullName[kMUNTH_INDEX_ORDER - kONE] :   Mounth[kMUNTH_INDEX_ORDER - kONE ];
	}



	void printCalenderOfMonth(unsigned short _Integer const kYEAR, unsigned short _Integer const kMOUNTH) {
	
	
		printf("\n\n----------------- %s -----------------\n\n",
			findNameMounthString(static_cast <enMounth> (kMOUNTH )).c_str()
		);

		printf(" Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");

		unsigned short _Integer const currentOrderDay{ findTheOrderOfDayInWeek(kYEAR, kMOUNTH) };
		unsigned short _Integer const numberOfDayMonth{ numberOfDayInMonth(kYEAR, kMOUNTH) };

		_Integer counter{ kZERO };
		for (; counter < currentOrderDay; counter++)
			printf("     "); 

		for (_Integer counterJ{ kONE }; counterJ <= numberOfDayMonth; counterJ++) {

			printf("%5d", counterJ);

			if (++counter == kNUMBER_OF_WEEK ) {
				counter = { kZERO }; 
				printf("\n"); 
			}

		}

		printf("\n\n---------------------------------------");
	}

	void printAllMonthCalenderAccordingYear(unsigned short _Integer const kYEAR) {
		

			printf("\n\n---------------------------------------");
			printf("\n          Calender = %d                  ", kYEAR);
			printf("\n\n---------------------------------------");

			for (_Integer counter{ kONE }; counter <= kNUMBER_MONTH ; counter++)
				printCalenderOfMonth(kYEAR, counter);

		}

	unsigned short int numberOfBeforeBeginingYear(unsigned short _Integer const kYEAR, unsigned short _Integer const kMOUNTH, unsigned short _Integer const kDAY = { 1 }) {
	
		unsigned short int totalDay{ kZERO };
		
		for (_Integer counter{ kONE }; counter <= kMOUNTH - kONE; counter++) {
			totalDay += numberOfDayInMonth(kYEAR, counter);

		}

		totalDay += kDAY;

	
		return totalDay; 
	}

	stDateInformation  convertNumberBeginingYearToDate (unsigned short _Integer const kYEAR , unsigned short _Integer const kBEGINING_YEAR )
		{
			stDateInformation date{ };

			unsigned short _Integer numberBeginingTotal{ kBEGINING_YEAR };

			date.kYEAR = kYEAR; 
			date.kMONTH = { kONE };

	/*		for (int counter{kONE}; counter <= kNUMBER_MONTH; counter++) {

				unsigned short _Integer numbersDayInMonth{ numberOfDayInMonth(kYEAR , counter) };


				if (numberBeginingTotal > numbersDayInMonth) {

					numberBeginingTotal -= numbersDayInMonth;
					date.kMONTH++; 
				}
				else
					break;
			}

			date.kDAY = numberBeginingTotal;*/


			while (true) {

				unsigned short _Integer numbersDayInMonth{ numberOfDayInMonth(kYEAR ,date.kMONTH ) };
					
				if (numberBeginingTotal > numbersDayInMonth) {

					numberBeginingTotal -= numbersDayInMonth;
					date.kMONTH++;

				}
				else {
					date.kDAY = numberBeginingTotal;
					break;
				}
			}

			return date; 
		}


	stDateInformation  convertNumberBeginingYearToDateAfterAddingDays (unsigned short _Integer const kYEAR, unsigned short _Integer const kBEGINING_YEAR , unsigned short _Integer const kADDING_DAYS  )
	{
		stDateInformation date{ };

		unsigned short _Integer numberBeginingTotal = kBEGINING_YEAR + kADDING_DAYS ;

		date.kYEAR = kYEAR;
		date.kMONTH = { kONE };
		date.kDAY = { kZERO };


	/*	while (true) {

			unsigned short _Integer numbersDayInMonth{ numberOfDayInMonth(date.kYEAR , date.kMONTH) };

			if (numberBeginingTotal >= numbersDayInMonth) {

				numberBeginingTotal -= numbersDayInMonth;
				date.kMONTH++;

				if (date.kMONTH > 12) {
					date.kMONTH = 1; 
					date.kYEAR++;
				}

			}
			else {

				date.kDAY = numberBeginingTotal;
				break;
			}
		}
		*/


		while (numberBeginingTotal > (isLeapYear(date.kYEAR) ? 366 : 365))
		{
			numberBeginingTotal -= (isLeapYear(date.kYEAR) ? 366 : 365);
			date.kYEAR++;

		}

		date = convertNumberBeginingYearToDate(date.kYEAR , numberBeginingTotal);

		return date;
	}

	bool cheakDateOneLessThanDateTwo(stDateInformation date1, stDateInformation date2) {

	/*	if (date1.kYEAR < date2.kYEAR) {
			return true;
		}
		else if (date1.kYEAR == date2.kYEAR) {
			if (date1.kMONTH < date2.kMONTH) {
				return true;
			}
			else if (date1.kMONTH == date2.kMONTH) {
				if (date1.kDAY < date2.kDAY) {
					return true;
				}
			}
		}
		return false;*/

		return (date1.kYEAR < date2.kYEAR) ? true : ((date1.kYEAR ==date2.kYEAR) ? (date1.kMONTH < date2.kMONTH ? true : (date1.kMONTH ==date2.kMONTH ? date1.kDAY < date2.kDAY : false)) : false);		
		
		
		
	}

	bool IsDate1EqualDate2(stDateInformation date1, stDateInformation date2 ) 
	{

		return (date1.kYEAR == date2.kYEAR) ? ((date1.kMONTH ==date2.kMONTH) ? ((date1.kDAY == date2.kDAY) ? true : false): false) : false;
		//return  date1.kYEAR == date2.kYEAR && date1.kMONTH == date2.kMONTH && date1.kDAY == date2.kDAY; 
	
	}

	bool cheakIsLastDay(stDateInformation date) {

		unsigned short _Integer const  numberDayInMonthToFindLastDay{ numberOfDayInMonth(date.kYEAR ,date.kMONTH) };

		return (numberDayInMonthToFindLastDay == date.kDAY); 
	
	}
	
	bool cheakIsFirstDay(stDateInformation date) {

		unsigned short _Integer const  numberDayInMonthToFindFirstDay{ kONE };

		return (numberDayInMonthToFindFirstDay == date.kDAY);

	}

	bool cheakIsLastMonth(stDateInformation date) {

		return (date.kMONTH  == kNUMBER_MONTH ) ; 
	}

	bool cheakIsFirstMonth(stDateInformation date) {

		return (date.kMONTH == kNUMBER_FIRST_MONTH ) ; 
	}

	stDateInformation increasingDayByOne(stDateInformation date) {

		if (cheakIsLastDay(date)) {
			date.kDAY = { kONE }; 

			if (cheakIsLastMonth(date)) {
				date.kYEAR++;
				date.kMONTH = { kONE }; 
			}
			else 
				date.kMONTH++; 
			
		}
		else
			date.kDAY++;

		return date;

	}

	
	void SwapDates(stDateInformation& Date1, stDateInformation& Date2)
	{
		stDateInformation TempDate;

		TempDate.kYEAR = Date1.kYEAR;
		TempDate.kMONTH = Date1.kMONTH;
		TempDate.kDAY = Date1.kDAY;

		Date1.kYEAR = Date2.kYEAR;
		Date1.kMONTH = Date2.kMONTH;
		Date1.kDAY = Date2.kDAY;

		Date2.kYEAR = TempDate.kYEAR;
		Date2.kMONTH = TempDate.kMONTH;
		Date2.kDAY = TempDate.kDAY;
	}

	stDateInformation ReadInformationDateInSystem() {

		stDateInformation date;

		time_t  timee = time(NULL);
		tm* timeUTC = localtime(&timee);

		date.kDAY = timeUTC->tm_mday;
		date.kYEAR = timeUTC->tm_year + 1900;
		date.kDAY = timeUTC->tm_mon + 1;

		return date;

	}

	int  calcDifferanceBetweenTwoDate(stDateInformation date1, stDateInformation date2 , bool flagIncludeEndDay = false ) {

		int day{}; 
		short flagSwapValue{ kONE }; 

		if (!cheakDateOneLessThanDateTwo(date1, date2)) {
			SwapDates(date1, date2); 
			flagSwapValue = { -1 };
		}
		while (cheakDateOneLessThanDateTwo(date1, date2)) {
			day++; 
			date1 = increasingDayByOne(date1);
		}
	
		return flagIncludeEndDay ? ++day * flagSwapValue  : day * flagSwapValue ;
	}


	///------------------------------- Date Function Incresing ------------------------------------------------ 


	stDateInformation increasingDayByX(stDateInformation date, unsigned short _Integer const kNUMBER_ADDING_DAY_NEW) {

		/*
		unsigned short int totalDayAfterCalc = kNUMBER_ADDING_DAY_NEW + date.kDAY;
		bool flagInisde{ true };

		while (totalDayAfterCalc >= numberOfDayInMonth(date.kYEAR, date.kMONTH)) {

			totalDayAfterCalc = totalDayAfterCalc - numberOfDayInMonth(date.kYEAR, date.kMONTH);

			if (date.kMONTH ==  kNUMBER_MONTH ) {
				date.kMONTH = { kONE };
				date.kYEAR++;

			}
			else {

				if (totalDayAfterCalc == kZERO ) {
					date.kDAY = kNUMBER_ADDING_DAY_NEW + kONE ;
					flagInisde = { false };
					break;
				}

				else {
					date.kDAY = totalDayAfterCalc;
					date.kMONTH++;
					flagInisde = { false };
				}
			}

		}
		if (flagInisde)
			date.kDAY = totalDayAfterCalc;
			*/
		
		for (_Integer counter{ kONE }; counter <= kNUMBER_ADDING_DAY_NEW; counter++)
			date = increasingDayByOne(date);
		
		return date;

	}


	stDateInformation increasingOneWeek(stDateInformation& date) {

		unsigned short _Integer totalDayAfterCalc = kNUMBER_OF_WEEK ;
		return increasingDayByX(date, totalDayAfterCalc);

	}

	stDateInformation increasingXWeek(stDateInformation& date, unsigned short _Integer const kNUMBER_WEEK) {

		for (_Integer counter{ kONE }; counter <= kNUMBER_WEEK; counter++)
			date = increasingOneWeek(date);
		

			return date; 
	} 

	stDateInformation increasingXWeekFast(stDateInformation& date, unsigned short _Integer const kNUMBER_WEEK) {

		unsigned short _Integer numberWeek = kNUMBER_OF_WEEK * kNUMBER_WEEK;
		return increasingDayByX(date, numberWeek);

	}
	stDateInformation increasingOneMonth(stDateInformation& date) {


		if (date.kMONTH == kNUMBER_MONTH ) {
			date.kMONTH = kONE; 
			date.kYEAR++; 
		}
		else
			date.kMONTH++; 

		//last check day in date should not exceed max days in the current month
			// example if date is 31/1/2022 increasing one month shouldnot be 31 / 2 / 2022, it should // be 28/2/2022

		unsigned short _Integer const NumberOfDayOfMonth = numberOfDayInMonth(date.kYEAR, date.kMONTH);

		if (date.kDAY > NumberOfDayOfMonth)
			date.kDAY = NumberOfDayOfMonth; 


		return date; 

	}
	stDateInformation increasingXMonth(stDateInformation& date, unsigned short _Integer const kNUMBER_MONTH_IN_USER) {


		/*	for (_Integer counter{kONE}; counter <= kNUMBER_MONTH; counter++) {

				if ((numberOfDayInMonth(date.kYEAR, date.kMONTH) % 30 == 0) && ( date.kMONTH <= date.kMONTH + kNUMBER_MONTH))
					++counter2;
			}
			//unsigned short int numberMonth = numberOfDayInMonth(date.kYEAR, date.kMONTH) * kNUMBER_MONTH ;
			return increasingDayByX(date, kNUMBER_MONTH* 30  + counter2 );
			*/

		/*for (int counter = kONE; counter <= kNUMBER_MONTH_IN_USER; counter++) {

			if (date.kMONTH == kNUMBER_MONTH) {
				date.kMONTH = kONE ;
				date.kYEAR++;
			}
			else
				date.kMONTH++;
		}*/

		for (_Integer counter{ kONE }; counter <= kNUMBER_MONTH_IN_USER; counter++)
			date = increasingOneMonth(date); 
	
		return date;
	}

	stDateInformation increasingOneYear(stDateInformation& date) {

		date.kYEAR++;

		// لو التاريخ 29/2 والسنة الجديدة مش كبيسة، خليه 28
		if (date.kMONTH == 2 && date.kDAY == 29 && !isLeapYear(date.kYEAR)) {
			date.kDAY = 28;
		}

		return date;
	}
	stDateInformation increasingXYear(stDateInformation& date, unsigned short  _Integer const   kNUMBER_YEAR_INPUT_USER) {

		for (_Integer counter{ kONE }; counter <= kNUMBER_YEAR_INPUT_USER; counter++)
			date = increasingOneYear(date);

		return date;
	}

	stDateInformation increasingOneDecade(stDateInformation& date) {

		date.kYEAR += kNUMBER_ONE_DECADE ;

		if (date.kMONTH == 2 && date.kDAY == 29 && !isLeapYear(date.kYEAR)) {
			date.kDAY = 28;
		} 
		return date;
	}

	stDateInformation increasingXDecade(stDateInformation& date, unsigned short _Integer const kNUMBER_DECADE) {

		date.kYEAR += kNUMBER_ONE_DECADE * kNUMBER_DECADE;

		if (date.kMONTH == 2 && date.kDAY == 29 && !isLeapYear(date.kYEAR)) {
			date.kDAY = 28;
		}
		return date;
	}

	stDateInformation increasingOneCentury(stDateInformation& date) {

		date.kYEAR += kNUMBER_ONE_CENTURY ;

		if (date.kMONTH == 2 && date.kDAY == 29 && !isLeapYear(date.kYEAR)) {
			date.kDAY = 28;
		}
		return date; 
	}

	stDateInformation increasingOneMillennium(stDateInformation& date) {

		// millennium سنة ريفية 1000 عام 
		date.kYEAR += kNUMBER_ONE_MILLENNIUM ;

		if (date.kMONTH == 2 && date.kDAY == 29 && !isLeapYear(date.kYEAR)) {
			date.kDAY = 28;
		} 
		return date;
	}

	// ------------------------------------- Substracting Date ---------------------------------------

	stDateInformation decreasingDayByOne(stDateInformation& date) {

		unsigned short _Integer const numberLastMonth = date.kMONTH;
		unsigned short _Integer const numberLastYear = date.kYEAR;

		if (cheakIsFirstDay(date)) {


			if (cheakIsFirstMonth(date)) {
				date.kYEAR--;
				date.kMONTH = { kNUMBER_MONTH };
			}
			else
				date.kMONTH--;


			date.kDAY = { numberOfDayInMonth(date.kYEAR  ,	date.kMONTH) };

		}
		else
			date.kDAY--;

		return date;

	}


	stDateInformation decreasingDayByX(stDateInformation& date , unsigned short _Integer const kNUMBER_DAY_SUBSTRACTING ) {

		for (_Integer counter{ kONE }; counter <= kNUMBER_DAY_SUBSTRACTING; counter++)
			date = decreasingDayByOne(date); 

		return date; 


	}



	stDateInformation decreasingOneWeek(stDateInformation& date) {

		for (_Integer counter{ kONE }; counter <= kNUMBER_OF_WEEK; counter++)
			date = decreasingDayByOne(date); 

		return date; 
	}

	stDateInformation decreasingWeekX(stDateInformation& date, unsigned short _Integer const kNUMBER_WEEK_SUBSTRACTING ) {

		for (_Integer counter{ kONE }; counter <= kNUMBER_WEEK_SUBSTRACTING; counter++)
			date = decreasingOneWeek(date);

		return date;
	}

	stDateInformation decreasingOneMonth(stDateInformation& date) {

		if(cheakIsFirstMonth(date)) {
			date.kMONTH = { kNUMBER_MONTH }; 
			date.kYEAR--; 

		}
		else 
			date.kMONTH--; 
		

		unsigned short _Integer const numberDay{ numberOfDayInMonth(date.kYEAR , date.kMONTH) };
		if (date.kDAY > numberDay)
			date.kDAY = numberDay; 

			return date;
	}

	stDateInformation decreasingMonthX(stDateInformation& date , unsigned short _Integer const kNUMBER_SUBSTRACTING_MONTH ) {
	
		for (_Integer counter{ kONE }; counter <= kNUMBER_SUBSTRACTING_MONTH; counter++)
			date = decreasingOneMonth(date); 

		return date; 
	}

	stDateInformation decreasingOneYear(stDateInformation& date) {

		date.kYEAR--; 

		if (date.kDAY == 29 && date.kMONTH == 2 && !isLeapYear(date.kYEAR))
			date.kDAY = 28; 

		return date;
	}

	stDateInformation decreasingYearX(stDateInformation& date, unsigned short _Integer const kNUMBER_SUBSTRACTING_YEAR) {

		for (_Integer counter{ kONE }; counter <= kNUMBER_SUBSTRACTING_YEAR; counter++)
			date = decreasingOneYear(date);

		return date;
	}
	stDateInformation decreasingOneDecade(stDateInformation& date) {
	
		date.kYEAR -= kNUMBER_ONE_DECADE; 

		if (date.kDAY == 29 && date.kMONTH == 2 && !isLeapYear(date.kYEAR))
			date.kDAY = 28;
		return date; 
	
	}

	stDateInformation decreasingDecadeX(stDateInformation& date, unsigned short _Integer const kNUMBER_SUBSTRACTING_DECADE) {

		for (_Integer counter{ kONE }; counter <= kNUMBER_SUBSTRACTING_DECADE; counter++)
			date = decreasingOneDecade(date); 

		return date;

	}
	stDateInformation decreasingOneCentury(stDateInformation& date) {

		date.kYEAR -= kNUMBER_ONE_CENTURY;

		if (date.kDAY == 29 && date.kMONTH == 2 && !isLeapYear(date.kYEAR))
			date.kDAY = 28;

		return date;

	} 

	stDateInformation decreasingOneMilleninum(stDateInformation& date) {

		date.kYEAR -= kNUMBER_ONE_MILLENNIUM;

		if (date.kDAY == 29 && date.kMONTH == 2 && !isLeapYear(date.kYEAR))
			date.kDAY = 28;

		return date;

	}


	// -----------------------------------------------------------------------------------------


	bool isEndOfWeek(stDateInformation date) {

		return (findDayOfWeekString(static_cast<enDayOfWeek> (findTheOrderOfDayInWeek(date))) == findDayOfWeekString(static_cast<enDayOfWeek> (6)));
		//return (findTheOrderOfDayInWeek(date) == 6); 

	}


	bool isWeekendDay(stDateInformation date) {

		return (findDayOfWeekString(static_cast<enDayOfWeek> (findTheOrderOfDayInWeek(date))) == findDayOfWeekString(static_cast<enDayOfWeek> (5))
			|| findDayOfWeekString(static_cast<enDayOfWeek> (findTheOrderOfDayInWeek(date))) == findDayOfWeekString(static_cast<enDayOfWeek> (6)));

		//(findTheOrderOfDayInWeek(date) == 5 || findTheOrderOfDayInWeek(date) == 6 )

	}

	bool isBusinessDay(stDateInformation date) {

		return !isWeekendDay(date);

	}


	unsigned short _Integer dayUntilEndOfWeek(stDateInformation date) {

		unsigned short _Integer counter{ kZERO };
		unsigned short _Integer  orderDayWeek = findTheOrderOfDayInWeek(date);

		/*for (int i{orderDayWeek}; i < 6; i++)
				++counter;*/

		while (orderDayWeek++ != 6)
			++counter;

		return counter;

		//return 6 - findTheOrderOfDayInWeek(date.kYEAR , date.kMONTH , date.kDAY );
	}

	unsigned short _Integer dayUntilEndOfMonth(stDateInformation date) {

		unsigned short _Integer counter{ kZERO };
		unsigned short _Integer  numberDayMonth = numberOfDayInMonth(date.kYEAR, date.kMONTH);
		unsigned short _Integer  Day = date.kDAY;

		stDateInformation date2;
		date2.kDAY = numberOfDayInMonth(date.kYEAR, date.kMONTH);
		date2.kMONTH = date.kMONTH;
		date2.kYEAR = date.kYEAR;

		return calcDifferanceBetweenTwoDate(date, date2, true);

		/*for (int i{orderDayWeek}; i < 6; i++)
				++counter;*/

				/*	while (Day++ <= numberDayMonth)
					++counter;*/


					/*	counter = numberDayMonth - Day + 1;
						return counter;*/
	}


	unsigned short _Integer dayUntilEndOfYear(stDateInformation date) {


	/*	unsigned short _Integer  numberdayUntilEndOfYear{dayUntilEndOfMonth(date)};

		for (int counter = { date.kMONTH + 1 }; counter <= 12; counter++)
			numberdayUntilEndOfYear += numberOfDayInMonth(date.kYEAR, counter);

		return numberdayUntilEndOfYear;

		*/

		stDateInformation date2;
		date2.kDAY = 31;
		date2.kMONTH = kNUMBER_MONTH ;
		date2.kYEAR = date.kYEAR; 

		return calcDifferanceBetweenTwoDate(date, date2, true);
	}
 

	unsigned short _Integer vacationDays(stDateInformation date1, stDateInformation date2) {

		if (!cheakDateOneLessThanDateTwo(date1, date2)) {
			SwapDates(date1, date2); 
		}

		unsigned short _Integer counterVacationDays{ kZERO };

	/*	1-
	
		unsigned short _Integer begingingDate1 = { numberOfBeginingYear(date1.kYEAR , date1.kMONTH , date1.kDAY) };
		unsigned short _Integer begingingDate2 = { numberOfBeginingYear(date2.kYEAR , date2.kMONTH , date2.kDAY) };

			while (begingingDate1 <= begingingDate2) {

			unsigned short _Integer orderDay{ findTheOrderOfDayInWeek(date1.kYEAR , date1.kMONTH , date1.kDAY) };

			if( (orderDay != 5) && ( orderDay != 6) )
			counterVacationDays++;

			date1 = increasingDayByOne(date1); 
			orderDay = { findTheOrderOfDayInWeek(date1.kYEAR , date1.kMONTH , date1.kDAY) };

			begingingDate1 = { numberOfBeginingYear(date1.kYEAR , date1.kMONTH , date1.kDAY) };
			begingingDate2 = { numberOfBeginingYear(date2.kYEAR , date2.kMONTH , date2.kDAY) };

		}
			return counterVacationDays -1   ;
		*/

		while (cheakDateOneLessThanDateTwo(date1, date2)) {

			unsigned short _Integer orderDay{ findTheOrderOfDayInWeek(date1.kYEAR , date1.kMONTH , date1.kDAY) };

			if (isBusinessDay(date1))
				counterVacationDays++;

			date1 = increasingDayByOne(date1);
			orderDay = { findTheOrderOfDayInWeek(date1.kYEAR , date1.kMONTH , date1.kDAY) };

		}

		return counterVacationDays  ;
	}

	stDateInformation returnDateAccordingVacationDays(stDateInformation date, unsigned short _Integer const  kVACATION_DAY ) {

		_Integer counter{ kZERO };


		while (counter < kVACATION_DAY) {

			if (isBusinessDay(date)) {
				++counter;
			}
			if (counter < kVACATION_DAY) date = increasingDayByOne(date);
		}

		//Day of return day in the work 
		date = increasingDayByOne(date);
	
	
		return date; 

 	}

	bool Date1AfterDate2(stDateInformation date1, stDateInformation date2) {

		//return (cheakDateOneLessThanDateTwo(date1, date2) == false);
		return (cheakDateOneLessThanDateTwo(date2, date1) && !IsDate1EqualDate2(date1 , date2 ));

	}

	 short _Integer compareTwoDates(stDateInformation date1, stDateInformation date2) {

	
		if (IsDate1EqualDate2(date1, date2))
			return enCompareTwoDate::kEQUAL  ;
		else if (cheakDateOneLessThanDateTwo(date1, date2))
			return enCompareTwoDate::kBEFORE ;
		
		/*else if (Date1AfterDate2(date1, date2))
			return enCompareTwoDate::kAFTER ;

		else kZERO; */
		return enCompareTwoDate::kAFTER;

		//return (IsDate1EqualDate2(date1, date2) ? kZERO : (cheakDateOneLessThanDateTwo(date1, date2) ? -1 : (Date1AfterDate2(date1, date2) ? 1 : 0)));
	}



	 bool isOverLapTwoDate(stPeriodOfDate periodOne, stPeriodOfDate periodTwo) {
	 
		 //return !(cheakDateOneLessThanDateTwo(periodTwo.endDate, periodOne.startDate) || cheakDateOneLessThanDateTwo(periodOne.endDate, periodTwo.startDate));

		 if (compareTwoDates(periodTwo.endDate, periodOne.startDate) == enCompareTwoDate::kBEFORE || compareTwoDates(periodTwo.startDate, periodOne.endDate) == enCompareTwoDate::kAFTER)
			 return false;
		 else
			 return true; 
	 }

	 unsigned short _Integer calcDifferantaceBetweenTwoDateInPeriod(stPeriodOfDate periodOne , bool isIncludeEndDay = false )  {
		 return calcDifferanceBetweenTwoDate(periodOne.startDate, periodOne.endDate , isIncludeEndDay );
	 }

	 bool isDateWithinPeriod(stPeriodOfDate period, stDateInformation date) {

		return (compareTwoDates(date, period.endDate) == enCompareTwoDate::kBEFORE && compareTwoDates(date, period.startDate) == enCompareTwoDate::kAFTER);
			 
	 }

	  short _Integer countOverlapDayBetweenTwoDate(stPeriodOfDate periodOne, stPeriodOfDate periodTwo) {

		 unsigned short _Integer countOverlapDay{ kZERO };

		 if (!isOverLapTwoDate(periodOne, periodTwo))
			 return kZERO;

		 if (isOverLapTwoDate(periodOne, periodTwo)) {

			 if (compareTwoDates(periodTwo.startDate, periodOne.startDate) == enCompareTwoDate::kAFTER && compareTwoDates(periodOne.endDate , periodTwo.endDate) == enCompareTwoDate::kBEFORE) 
				 countOverlapDay = calcDifferanceBetweenTwoDate(periodTwo.startDate , periodOne.endDate, true) ;
			 
			 else if (compareTwoDates(periodOne.endDate, periodTwo.endDate) == enCompareTwoDate::kAFTER && compareTwoDates(periodOne.startDate, periodTwo.endDate) == enCompareTwoDate::kBEFORE) 
				 countOverlapDay = calcDifferanceBetweenTwoDate(periodOne.startDate, periodTwo.endDate , true );
			 

		 }

		 return countOverlapDay;

	 }

	  bool validationDate(stDateInformation date) {

		  if (date.kMONTH < kONE || date.kMONTH > kNUMBER_MONTH )return false; 

		  unsigned short _Integer numberDayMonth = numberOfDayInMonth(date.kYEAR, date.kMONTH);
		  if (numberDayMonth < date.kDAY) return false; 

		  // is case not entered in the before two if statment 
		  return true;
	  }

	  string readDate(const string kMESSAGE) {

		  string dateInfo{ "" }; 

		  cout << kMESSAGE; 
		  getline(cin, dateInfo);

		  return dateInfo; 

	  }

	  vector<string> splitDateInformation(string  &dateInformation , string const kSEPARATOR = "/") {

		  vector<string> splitD{}; 

		  string text{ "" }; 
		  _Integer positionText{ kZERO };

		  while ((positionText = dateInformation.find(kSEPARATOR)) != string::npos) {
			  text = dateInformation.substr(kZERO, positionText);

			  if (text != "")
				  splitD.emplace_back(text); 

			  dateInformation.erase(kZERO, positionText + kSEPARATOR.length());
		  }

		  if(!dateInformation.empty())
			  splitD.emplace_back(dateInformation);

		  return splitD;

	  }
	  
	  stDateInformation fillDateInformation(vector<string> const kINFORMATION_DATE, string const kSEPARATOR = "/") {

		  stDateInformation dateInfo; 

		  if (kINFORMATION_DATE.size() > 2) {
			  dateInfo.kDAY = stoi(kINFORMATION_DATE[0]);
			  dateInfo.kMONTH = stoi(kINFORMATION_DATE[1]);
			  dateInfo.kYEAR = stoi(kINFORMATION_DATE[2]);
		  } 
		  return dateInfo;

	  }

	  string convertRecordToLine(stDateInformation &dateInformation, string const kSEPARATOR = "/") {

		  string lineDate; 

		  lineDate += to_string ( dateInformation.kDAY) + kSEPARATOR; 
		  lineDate += to_string( dateInformation.kMONTH  ) + kSEPARATOR;
		  lineDate += to_string( dateInformation.kYEAR );

		  return lineDate; 
	  }

	  string replaceStringToString(string textString, string textReplace, string  kTEXT_TO_REPLACE) {

		  short  positionText = textString.find(textReplace);

		  while (positionText != string::npos) {

			  textString = textString.replace(positionText , textReplace.length() , kTEXT_TO_REPLACE);
			   positionText = textString.find(textReplace);

		  }
		  return textString;

	  }

	  string replaseDatekDAY_kMONTH_kYEAR(vector<string> dateInformations, unsigned short _Integer  indexInformationDate, unsigned short _Integer  indexInformationDateToReplase , string const & kSEPARATOR = "/") {

		  if (indexInformationDate - kONE  < 3 && indexInformationDateToReplase - kONE < 3) {

			  string temp = dateInformations[indexInformationDate - kONE];
			  dateInformations[indexInformationDate - kONE] = dateInformations[indexInformationDateToReplase - kONE];
			  dateInformations[indexInformationDateToReplase - kONE] = temp;
		  }
		  else 
			  indexInformationDate = kZERO, indexInformationDateToReplase = kZERO;


		  stDateInformation dateInformationAfterRepleace = fillDateInformation(dateInformations, kSEPARATOR);

		  return convertRecordToLine(dateInformationAfterRepleace, kSEPARATOR);

	  }

	  string replaseDatekDAY_kMONTH_kYEAR_FormatDate (stDateInformation date , string replace = "dd/mm/yyyy") {

		  string dateFormat = ""; 

		  dateFormat = replaceStringToString(replace, "dd", to_string ( date.kDAY ) );
		  dateFormat = replaceStringToString(dateFormat, "mm", to_string ( date.kMONTH ) );
		  dateFormat = replaceStringToString(dateFormat, "yyyy", to_string ( date.kYEAR ) );
		  dateFormat = replaceStringToString(dateFormat, "yy", to_string ( date.kYEAR % 100  ) );	
		  dateFormat = replaceStringToString(dateFormat, "DDDD", findDayOfWeekString(static_cast <enDayOfWeek> (findTheOrderOfDayInWeek(date.kYEAR, date.kMONTH, date.kDAY)), true));
		  dateFormat = replaceStringToString(dateFormat, "MMM", findNameMounthString(static_cast <enMounth> (date.kMONTH)));
		  dateFormat = replaceStringToString(dateFormat, "Month", findNameMounthString(static_cast <enMounth> (date.kMONTH), true));

		  return dateFormat; 
	  } 
}; 