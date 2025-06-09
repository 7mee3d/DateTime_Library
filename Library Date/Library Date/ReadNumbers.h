#include <iostream> 

#ifndef READNUMBERS 
#define READNUMBERS


using namespace std;

unsigned short int kZERO{ 0 };




namespace read_Number {

	/**

			 This is function read numbers positive is lnger zero

			message This is parameter to the progrmmer using to enter the message manially

			and this function return value is data type *integer*

	*/

	int readNumberPositiveInteger(const string kMSSAGE) {

		int number{};

		do {

			cout << kMSSAGE;
			cin >> number;

			while (cin.fail()) {

				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Enter the Number Validation , Please : ";
				cin >> number;

			}
		} while (number < ::kZERO);


		return number;
	}

	/**

			 This is function read numbers positive is lnger zero

			message This is parameter to the progrmmer using to enter the message manially

			and this function return value is data type *Double*

	*/

	double readNumberPositiveDouble(const string kMSSAGE) {

		double number{};

		do {

			cout << kMSSAGE;
			cin >> number;

			while (cin.fail()) {

				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Enter the Number Validation , Please : ";
				cin >> number;

			}
		} while (number < ::kZERO);



		return number;
	}


	float  readNumberFloatingPointPositive(const string kMSSAGE) {


		float number{};


		do {

			cout << kMSSAGE;
			cin >> number;


			while (cin.fail()) {

				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Enter the Number Validation , Please : ";
				cin >> number;

			}

		} while (number < ::kZERO);

		return static_cast <float>(number);
	}



	/**

			 This is function read numbers positive is lnger zero

			message This is parameter to the progrmmer using to enter the message manially

			and this function return value is data type *Short int*

	*/


	short int readNumberPositiveShort(const string kMSSAGE) {


		short int number{};

		do {

			cout << kMSSAGE;
			cin >> number;

			while (cin.fail()) {

				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Enter the Number Validation , Please : ";
				cin >> number;

			}
		} while (number < ::kZERO);

		return number;
	}


	unsigned short int readNumberPositiveShortUnsinged (const string kMSSAGE) {


		unsigned short int number{};

			cout << kMSSAGE;
			cin >> number;

			while (cin.fail()) {

				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Enter the Number Validation , Please : ";
				cin >> number;

			}

		return number;
	}

	char readCharacter(const string kMSSAGE) {


		char character{};
		cout << kMSSAGE;
		cin >> character;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Enter the Character is coorect , Please : ";
			cin >> character;
		}

		return character;
	}




	bool readBooleanValue(const string kMSSAGE) {

		bool flagBoolean{};
		string inputBoolean{};

		while (true) {

			cout << kMSSAGE;
			cin >> inputBoolean;

			// Check if the input is a valid boolean value
			if (inputBoolean == "true" || inputBoolean == "1") {
				flagBoolean = true;
				break;
			}
			else if (inputBoolean == "false" || inputBoolean == "0") {
				flagBoolean = false;
				break;
			}
			else {

				cout << "Invalid input. Please enter 'true', 'false', 0, or 1: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		return flagBoolean;
	}

	long long int  readNumberPositiveLongLongInteger(const string kMSSAGE) {


		long long int number{};

		do {

			cout << kMSSAGE;
			cin >> number;

			while (cin.fail()) {

				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Enter the Number Validation , Please : ";
				cin >> number;

			}
		} while (number < ::kZERO);

		return number;
	}




	long long int  readNumberLongLongIntegerSigned(const string kMSSAGE) {


		unsigned long long int number{};

		cout << kMSSAGE;
		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Enter the Number Validation , Please : ";
			cin >> number;

		}


		return number;
	}


	signed int  readNumberIntegerSigned(const string kMSSAGE) {


		signed  int number{};

		cout << kMSSAGE;
		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Enter the Number Validation , Please : ";
			cin >> number;

		}


		return number;
	}

	double  readNumberDoubleSigned(const string kMSSAGE) {


		double number{};

		cout << kMSSAGE;
		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Enter the Number Validation , Please : ";
			cin >> number;

		}


		return number;
	}


	short int   readNumberShortIntegerSigned(const string kMSSAGE) {


		short int  number{};

		cout << kMSSAGE;
		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Enter the Number Validation , Please : ";
			cin >> number;

		}


		return number;
	}


	float  readNumberFloatingPointSigned(const string kMSSAGE) {


		float number{};

		cout << kMSSAGE;
		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Enter the Number Validation , Please : ";
			cin >> number;

		}


		return static_cast <float> (number);
	}
};


#endif 