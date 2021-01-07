#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iterator>

void ToUpper(std::string & txt)
{
	std::string txt2;
	for (int i = 0; i < txt.size(); i++)
	{
		txt2.push_back(std::toupper(txt.at(i)));
	}
	txt = txt2;
}

void cheieToNr(std::string cheie)
{
	int nr = 1;
	std::string keySorted = cheie;
	std::sort(keySorted.begin(), keySorted.end());
	std::vector<int> aux(cheie.size(), 0);

	for (auto i : keySorted)
	{
		int index = cheie.find(i);
		
		aux.at(index) = nr;
		nr++;
	}
	for (int i = 0; i < aux.size(); i++)
	{
		std::cout << aux.at(i)<<" ";
	}
	std::cout << std::endl;

}

void textToMatrix(std::string text, std::string cheie)
{
	
	std::vector<std::string> matrix;
	std::vector<int> ordine;
	std::string text2;
	text2 = text;
	std::string::iterator end_pos = std::remove(text2.begin(), text2.end(), ' ');
	text2.erase(end_pos, text2.end());
	
	//std::cout << text2<<"\n";
	int rest = cheie.size()-text2.size() % cheie.size();
	if (rest != 0)
	{
		for (int i = 0; i < rest; i++)
		{
			text2.push_back('A' + i);
		}
	}
	//std::cout << text2 << "\n";

	std::string aux="";
	for (int i = 0; i < text2.size(); i++)
	{
		
		if (i % cheie.size()  == 0)
		{
			if (i != 1)
			{
				matrix.push_back(aux);
				aux = "";
			}
		}
		aux.push_back(text2.at(i));
		if (i == text2.size() - 1)
		{
			matrix.push_back(aux);
		}
	}
	for (int i = 0; i < text2.size()/cheie.size()+1; i++)
	{
		std::cout << matrix.at(i)<<"\n";
	}


	std::string keySorted = cheie;
	std::sort(keySorted.begin(), keySorted.end());

	for (auto i : keySorted)
	{
		int index = cheie.find(i);
		ordine.push_back(index);

	}

	
	std::string final="";
	for (int i = 0; i < ordine.size();  i++)
	{
		for (int j = 1; j < text2.size() / cheie.size() + 1; j++)
		{
			final.push_back(matrix.at(j).at(ordine.at(i)));
		}
	}
	std::cout << "\n";
	std::cout << "TEXT CRIPTAT: ";
	std::cout << final;


}

int main()
{
	
	std::string cheie;

	std::cout << "Introduceti cheia de encriptat: ";
	std::cin>>cheie;
	ToUpper(cheie);
	cheieToNr(cheie);

	std::string text;
	std::cout << "Introduceti textul de encriptat: ";
	std::getline(std::cin, text);
	std::getline(std::cin, text);
	////std::cout << text;
	ToUpper(text);
	std::cout << cheie<<"\n";
	cheieToNr(cheie);
	textToMatrix(text,cheie);


	//std::cout << "Hello, " << name << "!\n";



	return 0;

}