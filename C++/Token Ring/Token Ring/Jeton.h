#pragma once
#include <string>
#include<vector>
#include <iostream>
class Jeton
{
public:
	std::string	IPSursa;
	std::string	IPDestinatie;
	std::string	MesajTransmis;
	bool AjunsLaDestinatie;
	bool Liber;
	std::vector<std::string>Istoric;
	Jeton()
	{
	}
	Jeton(std::string	IPSursa,std::string	IPDestinatie,std::string	MesajTransmis,
		bool AjunsLaDestinatie,bool Liber )
	{
		this->IPSursa = IPSursa;
		this->IPDestinatie=IPDestinatie;
		this->MesajTransmis= MesajTransmis;
		this->AjunsLaDestinatie= AjunsLaDestinatie;
		this->Liber= Liber;
		this->Istoric.push_back(IPSursa);
	}

	friend std::ostream& operator<<(std::ostream& os, Jeton& j)
	{
		os <<"IPSursa: "<< j.IPSursa << "\n";
		os<<"IPDestinatie: "<< j.IPDestinatie << "\n";
		os <<"AjunsLaDestinatie: "<< j.AjunsLaDestinatie << "\n";
		os <<"Liber: "<< j.Liber << "\n";
		os <<"MesajTransmis: "<< j.MesajTransmis << "\n";
		os << "Istoric: " << "\n";

		for (const auto& i : j.Istoric)
		{
			os << i << " \n ";
		}
		return os;
	}
};

