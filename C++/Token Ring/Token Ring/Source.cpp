#include<iostream>
#include"Jeton.h"
#include"ReteaCalculatoare.h"
int main() {
	//Jeton j =  Jeton("192.168.0.2", "192.168.0.5", "Sall", false, false);
	//ReteaCalculatoare calculator = ReteaCalculatoare("192.168.0.2", "192.168.0.1", "192.168.0.3");
	//std::cout << calculator;
	int dim;
	std::string IpStart;
	std::string IpTarget;
	bool sens;
	std::string mesaj;
	int x = 0;
	std::cout << "Dimensiunea retelei: ";
	std::cin >> dim;
	std::cout << "\n";
	system("CLS");
	ReteaCalculatoare calculator = ReteaCalculatoare(dim);
	while (x == 0)
	{
		std::cout << "Dimensiunea retelei: "<< dim;
		std::cout << "\nSelecteaza din lista calculatoarele dorite.\n";
		std::cout << calculator;
		std::cout << "IpStart: ";
		std::cin >> IpStart;
		std::cout << "\n";
		std::cout << "IpTarget: ";
		std::cin >> IpTarget;
		std::cout << "Mesajul: ";
		std::cin >> mesaj;
		Jeton token = Jeton(IpStart, IpTarget, mesaj, false, false);
		std::cout << "\n";
		std::cout << "Sensul retelei \n";
		std::cout << "0->sensul arcelor de ceasornic \n1-> sensul invers arcelor de ceasornic: ";
		std::cin >> sens;
		std::cout << "\n";
		std::cout << "Token initial: \n" << token;
		calculator.takeToken(token,sens); 
		std::cout << "\n";
		std::cout << "\nToken final: \n" << token;

		std::cout << "Doriti sa transmiteti alt mesaj?\n";
		std::cout << "Scrieti 0-Da\n1-Nu\n";
		std::cin >> x;
		if (x == 0)
		{
			system("CLS");
		}
	}
	

	

	return 0;
}