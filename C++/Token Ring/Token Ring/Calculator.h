#pragma once
#include <string>
#include<list>
#include <iostream>
class Calculator
{
public:
	int numar;
	std::string	IP;
	std::string successor;
	std::string predecesor;
	Calculator()
	{

	}
	Calculator(std::string	IP, std::string successor, std::string predecesor)
	{
		this->IP = IP;
		this->successor = successor;
		this->predecesor = predecesor;
	}
	friend std::ostream& operator<<(std::ostream& os, Calculator& c)
	{
		os << "Numar: " << c.numar << "\n";
		os << "IP: " << c.IP << "\n";
		os << "Successor: " << c.successor << "\n";
		os << "Predecesor: " << c.predecesor << "\n";
		
		return os;
	}


};

