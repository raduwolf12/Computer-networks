#pragma once
#include <string>
#include<list>
#include <iostream>
#include <vector>
class ReteaCalculatoare
{
public:
	std::string	IP;
	bool sens;
	std::vector<std::string> reteaCalculatoare;
	ReteaCalculatoare()
	{

	}
	ReteaCalculatoare(int n)
	{
		for (int i = 0; i < n; i++)
		{
			this->reteaCalculatoare.push_back("192.168.0."+std::to_string(i+1));
		}
	}
	void takeToken(Jeton &j)
	{
		int size = reteaCalculatoare.size();
		int start = j.IPSursa.at((j.IPSursa.size() - 1)) - 48;
		for (int i = start; i < size; i++)
		{
			j.Istoric.push_back(reteaCalculatoare.at(i));
			if (j.IPDestinatie == reteaCalculatoare.at(i))
			{
				j.AjunsLaDestinatie = true;
				std::cout << j.MesajTransmis;
			}
			
		}
		for (int i = 0 ; i < start; i++)
		{
			j.Istoric.push_back(reteaCalculatoare.at(i));
			if (j.IPDestinatie == reteaCalculatoare.at(i))
			{
				j.AjunsLaDestinatie = true;
				std::cout << j.MesajTransmis;
			}
			if (j.IPSursa == reteaCalculatoare.at(i))
			{
				std::cout << "\nTokenul a ajuns inapoi la sura!";
				if (j.AjunsLaDestinatie == true)
				{
					j.Liber = true;
					j.IPSursa.clear();
					j.IPDestinatie.clear();
					j.Istoric.clear();
					j.MesajTransmis.clear();
					j.AjunsLaDestinatie = false;
				}
				else
				{
					std::cout << "Erroare mesajul nu a ajuns la destinatie!";
				}
				
			}

		}
	}
	
	void takeToken(Jeton& j,bool sens)
	{
		
		int size = reteaCalculatoare.size();
		int start = j.IPSursa.at((j.IPSursa.size() - 1)) - 48;
		if (sens == 1)
		{
			for (int i = start-1; i >= 0; i--)
			{
				j.Istoric.push_back(reteaCalculatoare.at(i));
				if (j.IPDestinatie == reteaCalculatoare.at(i))
				{
					j.AjunsLaDestinatie = true;
					std::cout << j.MesajTransmis;
				}
			}
			for (int i = size - 1; i >= start-1; i--)
			{
				j.Istoric.push_back(reteaCalculatoare.at(i));
				if (j.IPDestinatie == reteaCalculatoare.at(i))
				{
					j.AjunsLaDestinatie = true;
					std::cout << j.MesajTransmis;
				}
				if (j.IPSursa == reteaCalculatoare.at(i))
				{
					std::cout << "\nTokenul a ajuns inapoi la sura!";
					std::cout << "\n###Istoric###\n";
					for (auto index : j.Istoric)
						std::cout << index << " ";
					if (j.AjunsLaDestinatie == true)
					{
						j.Liber = true;
						j.IPSursa.clear();
						j.IPDestinatie.clear();
						j.Istoric.clear();
						j.MesajTransmis.clear();
						j.AjunsLaDestinatie = false;
					}
					else
					{
						std::cout << "Erroare mesajul nu a ajuns la destinatie!";
					}

				}
			}
		}
		
		if (sens == 0)
		{
			for (int i = start; i < size; i++)
			{
				j.Istoric.push_back(reteaCalculatoare.at(i));
				if (j.IPDestinatie == reteaCalculatoare.at(i))
				{
					j.AjunsLaDestinatie = true;
					std::cout << j.MesajTransmis;
				}

			}
			for (int i = 0; i < start; i++)
			{
				j.Istoric.push_back(reteaCalculatoare.at(i));
				if (j.IPDestinatie == reteaCalculatoare.at(i))
				{
					j.AjunsLaDestinatie = true;
					std::cout << j.MesajTransmis;
				}
				if (j.IPSursa == reteaCalculatoare.at(i))
				{
					std::cout << "\nTokenul a ajuns inapoi la sura!";
					std::cout << "\n###Istoric###\n";
					for (auto index : j.Istoric)
						std::cout << index << " ";
					if (j.AjunsLaDestinatie == true)
					{
						j.Liber = true;
						j.IPSursa.clear();
						j.IPDestinatie.clear();
						j.Istoric.clear();
						j.MesajTransmis.clear();
						j.AjunsLaDestinatie = false;
					}
					else
					{
						std::cout << "Erroare mesajul nu a ajuns la destinatie!";
					}

				}

			}
		}
		
		
	}
	/*ReteaCalculatoare(std::string	IP, std::string successor, std::string predecesor)
	{
		this->IP = IP;
		this->successor = successor;
		this->predecesor = predecesor;
	}*/
	friend std::ostream& operator<<(std::ostream& os, ReteaCalculatoare& c)
	{

		int x = 1;
		for (const auto& i : c.reteaCalculatoare)
		{
			os<<"Calculatorul "<<x<<": " << i << "\n ";
			x++;
		}
		return os;
	}
};

