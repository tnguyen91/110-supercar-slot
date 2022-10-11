// who: Tu Nguyen, mnguyen207@student.mtsac.edu
// what: Supercar Slots
// why: Lab Exam 1
// when: Oct 4, 2021

#include <iostream>
#include <cstdlib>
#include <ctime>

void start(float&, bool&);
void end(float, bool&);
void checkCredit(float);
int input();
int spinWheel(int);
int random(int, int);
std::string carName(int);
float calcPrize(float, std::string, std::string, std::string, std::string);
bool twoMatch(std::string, std::string, std::string, std::string);
bool threeMatch(std::string, std::string, std::string, std::string);
bool fourMatch(std::string, std::string, std::string, std::string);

int main(int argc, char const *argv[]){
    std::cout << "Welcome to Supercar Slots" << std::endl;

    std::cout << "Enter your initial deposit: $";
    float credit = input();

	bool toContinue = true;

    if (credit > 0){
		do{
			start(credit, toContinue);
		} while (credit > 0 && toContinue == true);

		if (credit == 0){
			end(credit, toContinue);
		}
    }
    else{
        end(credit, toContinue);
    }
    
    return 0;
}

void start(float& credit, bool& toContinue){
	checkCredit(credit);

	std::cout << "Place your bet: $";
	float bet = input();

	if (bet > 0 && bet <= credit){
		credit -= bet;
		checkCredit(credit);

		std::cout << "The machine rolled:" << std::endl;

		int wheel1 = spinWheel(random(10, 1001));
		std::string car1 = carName(wheel1);

		int wheel2 = spinWheel(random(10, 1001));
		std::string car2 = carName(wheel2);

		int wheel3 = spinWheel(random(10, 1001));
		std::string car3 = carName(wheel3);

		int wheel4 = spinWheel(random(10, 1001));
		std::string car4 = carName(wheel4);

		std::cout << "    " << car1 << " - " << car2 << " - " << car3 << " - " << car4 << std::endl;

		float prize = calcPrize(bet, car1, car2, car3, car4);
		std::cout << "You won $" << prize << std::endl;
		credit += prize;
	}
	else if (bet > credit){
		std::cout << "You don't have enough credit. Bet a smaller amount." << std::endl;
	}
	else{
		end(credit, toContinue);
	}
}

void end(float credit, bool& toContinue){
	if (credit > 0){
		std::cout << "Returning $" << credit << std::endl;
    	std::cout << "Thanks for playing Supercar Slots" << std::endl;

		toContinue = false;
	}
	else{
		std::cout << "You don't have enough credit to bet." << std::endl;
    	std::cout << "Thanks for playing Supercar Slots" << std::endl;
	}
}

void checkCredit(float credit){
    std::cout << "Your credit is $" << credit << std::endl;
}

int input(){
    int amount;
    std::cin >> amount;

    return amount;
}

int spinWheel(int spinCount){
    srand(time(NULL));

    int randValue;

    for (int i = 0; i < spinCount; i++){
        randValue = random(1, 7);
    }

    return randValue;
}

int random(int start, int end){
    return rand() % (end - start) + start;
}

std::string carName(int carNumber){
    std::string car;

    switch (carNumber){
        case 1:
            car = "Ferrari";
            break;

        case 2:
            car = "Lamborghini";
            break;

        case 3:
            car = "Bugatti";
            break;

        case 4:
            car = " McLaren";
            break;

        case 5:
            car = "Koenigsegg";
            break;

        case 6:
            car = "Maserati";
            break;
    }
	
    return car;
}

float calcPrize(float betAmount, std::string car1, std::string car2, std::string car3, std::string car4){
    float moneyWin;
    
    if (threeMatch(car1, car2, car3, car4) == false && twoMatch(car1, car2, car3, car4)){
        moneyWin = betAmount;
    }
    else if (fourMatch(car1, car2, car3, car4) == false && threeMatch(car1, car2, car3, car4)){
        moneyWin = betAmount * 1.5;
    }
    else if (fourMatch(car1, car2, car3, car4)){
        moneyWin = betAmount * 10;
    }
    else{
        moneyWin = 0;
    }

    return moneyWin;
}

bool twoMatch(std::string car1, std::string car2, std::string car3, std::string car4){
	if (car1 == car2){
		return true;
	}
	else if (car1 == car4){
		return true;
	}
	else if (car2 == car3){
		return true;
	}
	else if (car2 == car4){
		return true;
	}
	else if (car3 == car1){
		return true;
	}
	else if (car3 == car4){
		return true;
	}
	else{
		return false;
	}
}

bool threeMatch(std::string car1, std::string car2, std::string car3, std::string car4){
	if (car1 == car2 && car2 == car3){
		return true;
	}
	else if (car1 == car3 && car3 == car4){
		return true;
	}
	else if (car1 == car2 && car2 == car4){
		return true;
	}
	else if (car2 == car3 && car3 == car4){
		return true;
	}
	else{
		return false;
	}
}

bool fourMatch(std::string car1, std::string car2, std::string car3, std::string car4){
	if (car1 == car2 && car2 == car3 && car3 == car4){
		return true;
	}
	else{
		return false;
	}
}