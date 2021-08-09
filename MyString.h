
#include <sstream>
#include <string>
using namespace std;


/*
The Mystring class extends string and is used to interpret the input
*/
class Mystring :public string {

private:

public:


	Mystring():string() {
		
	}



	//Overloaded operator for converting to unsigned int
	operator unsigned() const {
		unsigned int val = 0;

		for (int i = 0; i < this->size(); i++) {
			val += (*this)[i];
		}
		return val;
	}

	//The toLower method converts all alphabets to lower case
	void tolower() {

		for (int i = 0; i < this->size(); i++) {
			if ((*this)[i] >= 'A' && (*this)[i] <= 'Z') {
				(*this)[i] = (*this)[i] - 'A' + 'a';
			}
		}

	}


	//The removePunctuation method removes any punctuations from the string
	void removePunctuation() {

		stringstream str("");

		if ((*this) == "--") {
			bool comeHere = true;
		}

		bool appostopheInPrev = false;
		for (int i = 0; i < this->size(); i++) {
			if (((*this)[i] >= 'A' && (*this)[i] <= 'Z') 
				|| ((*this)[i] >= 'a' && (*this)[i] <= 'z')){
				
				if (!appostopheInPrev) {
					str << (*this)[i];
				}
			}
			if (appostopheInPrev) {
				appostopheInPrev = false;
			}
			if ((*this)[i] == '\'') {
				appostopheInPrev = true;
			}
			
			
		}

		this->clear();
		str >> (*this);

	}
};





