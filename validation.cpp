/*******************************
/Author: Joshua Barton
/Date: 5/31/15
/Description: Two functions that check a string's 
/contents to see whether it is a valid integer
/and/or a valid floating point number. The 
/functions will return true if valid,
/and false if invalid. Disqualifying factors
/include empty strings, spaces in between digits,
/decimal places in ints, alphas, and recursion of
/polarity signs. 
/*********************************/


//libraries used
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <locale>
//using standard namespace
using namespace std;

	//function prototypes
	bool stringIsInt(std::string myString);
bool stringIsFloat(std::string myString);

//checks to see if the string is an integer 
bool stringIsInt(std::string myString){
	//converts string to charCheck to perform testing
	std::string charCheck = myString;

	//will return false if entered string is empty
	if(charCheck.empty()){
		return false;
	}
	//checks through the string for valid inputs
	for(int i = 0; i < charCheck.length(); i++){
		//will return false if there is a sign after a digit
		if ((charCheck.at(i) == '-' && charCheck.at(i-1) != ' ' )){
			return false;
		}
		if ((charCheck.at(i) == '+' && charCheck.at(i-1) != ' ')){
			return false;
		}
		//checks whether only signs or digits have been entered
		if ((!isdigit(charCheck.at(i)) && charCheck.at(i)!= '-'
			&& charCheck.at(i)!= '+' && charCheck.at(i)!= ' ')){

				return false;
		}
		//uses nested loops to see if a space has been found
		if (i<charCheck.length() && i >0){

			if (isspace(charCheck.at(i))){
				//checks to see if the location contains a space
				for (int j =0; j <i; j++){
					//checks to see if any previous numbers are a digit 
					if (isdigit(charCheck.at(j))){
						//checks to see if any following numbers are digit so
						//trailing spaces do not flag as false.
						for (int k =i; k <charCheck.length(); k++){
							if (isdigit(charCheck.at(k))){

								return false;
							}

						}
					}
				}
			}
		}
		//checks to see if any signs are found in the string after one has already been declared
		for (int j = 0; j < i; j++) {
			if (charCheck.at(i) == charCheck.at(j) && charCheck.at(j) == '-'){
				return false;
			}
			if (charCheck.at(i) == charCheck.at(j) && charCheck.at(j) == '+'){
				return false;
			}
		}
	}

	//returns true if all the disqualifying factors are not present.
	return true;

}


//checks to see if string is a valid float. Returns true if so.
bool stringIsFloat(std::string myString){
	//string used to check 
	string charCheck = myString;
	//if string is empty returns false
	if(charCheck.empty()){
		return false;
	}


	//checks through each set
	for(int i = 0; i < charCheck.length(); i++){
		//checks to see if a sign comes after a digit
		if ((charCheck.at(i) == '-' && charCheck.at(i-1) != ' ' )){
			return false;
		}
		if ((charCheck.at(i) == '+' && charCheck.at(i-1) != ' ')){
			return false;
		}
		//checks for invalid inputs
		if ((!isdigit(charCheck.at(i))  && charCheck.at(i)!= '.'&& 
			charCheck.at(i)!= '-'
			&& charCheck.at(i)!= '+'&& charCheck.at(i)!= ' ')){

				return false;
		}
		//uses nested loops to see if a space has been found
		if (i<charCheck.length() && i >0){

			//in the case of a float, checks to see if the subsequent space
			//is empty and returns false;
			if (charCheck.at(i) == '.' && isspace(charCheck.at(i+1))){
				return false;
			}
			if (isspace(charCheck.at(i))){
				//checks to see if the location contains a space
				for (int j =0; j <i; j++){
					//checks to see if any previous numbers are a digit 
					if (isdigit(charCheck.at(j))){
						//checks to see if any following numbers are digit so
						//trailing spaces do not flag as false.
						for (int k =i; k <charCheck.length(); k++){
							if (isdigit(charCheck.at(k))){

								return false;
							}

						}
					}
				}
			}
		}
		//checks to see if the number ends in a decimal 
		if ((charCheck.at(charCheck.length()-1)=='.')){
			return false;
		}
		//checks for recursion of decimals and signs
		for (int j = 0; j < i; j++) {
			if (charCheck.at(i) == charCheck.at(j) && charCheck.at(j) == '.'){
				return false;
			}
			if (charCheck.at(i) == charCheck.at(j) && charCheck.at(j) == '-'){
				return false;
			}
			if (charCheck.at(i) == charCheck.at(j) && charCheck.at(j) == '+'){
				return false;
			}

		}


	}



	//returns true if all the disqualifying factors are not present.
	return true;


}