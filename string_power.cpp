
/**
 * Catherine Rodriquez 
 * CSC 3380 Coding Exercise
 * 
 * The power algorithm is typically used for raising a number to a certain power efficiently. 
 * In this case, I'm using a character (which can be interpreted as an ASCII value) as the base, 
 * and I'm raising it to the user selected power (N). This operation effectively repeats the character
 * N times, creating a string of N equal characters.
 * 
 * By utilizing this property, I can efficiently generate a string consisting of N equal characters
 * without the need for explicit loops or repeated concatenation operations, making it a simple and 
 * efficient approach.
*/


#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

const int BLUE = 1, WHITE = 15; //variables for the text colors

//changes the color of the text
void changeColor(int color) {
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

//clears the screen
void clearScreen(int characterLength) {
	for (int i = 0; i < characterLength; i++) {
		std::cout << "\b";
	}
}

//initial exercise for the activity
std::string equalChar(char character, int power){
    if (power == 0){
        return "";
    }

    std::string powerChar(power, character); //creates a string with N characters

    return powerChar;
}

std::string patternChar(char character, int power, char character2, int power2){
    if (power == 0 || power2 == 0){
        return "";
    }

    std::cout << "Time to choose your pattern! \nUse arrow keys to go through options and ENTER to select\n";
    int setColor[] = {7, 7, 7};
    int counter = 1;
	char key;
	bool selectPattern = false;
    bool patternType = false;
    std::string result = "";

    //loop used for pattern options
    while(!selectPattern){
		changeColor(setColor[0]);
		std::cout << "[1]\t";
		changeColor(setColor[1]);
		std::cout << "[2]\t";
		changeColor(setColor[2]);
		std::cout << "[3]";

        key = getch();

        if(key == 75 && (counter >= 2 && counter <= 3)){ //75 is left arrow
			counter--;
		}
		if(key == 77 && (counter >= 1 && counter <= 2)){ //77 is right arrow 
			counter++;
		}

        if(key == '\r'){ //enter key
            changeColor(WHITE);
            if(counter == 1){
                while(!patternType){
                    std::string powerChar(power, character);
                    std::string powerChar2(power2, character2);
                    result = result + powerChar + powerChar2;
                    //checks to make sure power will not be a negative option
                    if(power - 1 <= 0 || power2 - 1 <= 0){
                        patternType = true;
                    }
                    power--;
                    power2--;
                }
                return result;
                //selectPattern = true;
            }
            if(counter == 2){
                while(!patternType){
                    std::string powerChar(power, character);
                    std::string powerChar2(power2, character2);
                    result = result + powerChar + powerChar2;
                    //checks to make sure power will not be a negative option
                    if(power - 2 <= 0 || power2 - 2 <= 0){ 
                        patternType = true;
                    }
                    power = power - 2;
                    power2 = power2 - 2;
                }
                return result;
                //selectPattern = true;
            }
            if(counter == 3){
                while(!patternType){
                    std::string powerChar(power, character);
                    std::string powerChar2(power2, character2);
                    result = result + powerChar + powerChar2;
                    //checks to make sure power will not be a negative option
                    if(power - 3 <= 0 || power2 - 3 <= 0){ 
                        patternType = true;
                    }
                    power = power - 3;
                    power2 = power2 - 3;
                }
                return result;
                //selectPattern = true;
            }
        }

        setColor[0] = 7, setColor[1] = 7, setColor[2] = 7;

        //changes the color for the paterrn ption the user is choosing
		for(int i = 1; i < 4; i++){
			if(counter == i){
				setColor[i-1] = BLUE;
			}
		}
		clearScreen(30); //clears screen help demonstrate pattern selection

    }

    return result;
}

//creating a string od O(logN complexity)
std::string create_string_using_power(int count, char fill = ' ') {
    if (count <= 0)
        return ""; // Return an empty string if count is non-positive

    // Base case: If count is 1, return a string with a single character
    if (count == 1)
        return std::string(1, fill);

    // Recursive case: Divide and conquer using exponentiation by squaring
    if (count % 2 == 0) {
        // If count is even, recursively call with half of count and square the string
        std::string half_string = create_string_using_power(count / 2, fill);
        return half_string + half_string; // Concatenate the half string with itself
    } else {
        // If count is odd, recursively call with (count - 1) and append one more character
        std::string half_string = create_string_using_power((count - 1) / 2, fill);
        return half_string + half_string + fill; // Concatenate the half string with itself and append one more character
    }
}

int main(){
    int P; //variable used to store power number
    char character; //variable used to store letter
    std::cout << "Enter the number of characters you would like to generate: ";
    std::cin >> P;
    std::cout << "Enter the letter would like to generate: ";
    std::cin >> character;

    std::string equalCharString = equalChar(character, P); //calls function

    std::cout << "Generated String: " << equalCharString << std::endl;

    //fun practice
    std::cout << "Now let's create a pattern! \nEnter a different character: ";
    char character2;
    std::cin >> character2;
    std::cout << "Enter the number of characters you would like to generate: ";
    int P2;
    std::cin >> P2;

    std::string stringPattern = patternChar(character, P, character2, P2); //calls function

    std::cout << "\nString Pattern: " << stringPattern << std::endl;

    //creating a string of O(logN) complexity
    int count = 10;
    char fill_character = '*';
    std::string result = create_string_using_power(count, fill_character);
    std::cout << "String with " << count << " equal characters: " << result << std::endl;


    return 0;
}