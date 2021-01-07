#include <iostream>
#include <vector>

//bool isDiv(std::string nr)
//{
//
//}
int paritate(std::vector<int> aux)
{
	int counter = 0;
	for (int i = 0; i < aux.size(); i++)
	{
		if (aux.at(i) == 1)
		{
			counter++;
		}
	}
	if (counter % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void printMatrix(std::vector<std::vector<int>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat.at(i).size(); j++)
		{
			std::cout << mat.at(i).at(j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::string matToMessage(std::vector<std::vector<int>> mat)
{
	std::string mesaj="";
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat.at(i).size(); j++)
		{
			char c = mat.at(i).at(j)+48;
			mesaj = mesaj + c;
			if (j == 7)
			{
				mesaj = mesaj + " ";
			}
		}
	}
	return mesaj;
}

bool valid(std::string nr)
{
	for (int i = 0; i < nr.size(); i++)
	{
		if (nr.at(i) - 48 != 0 )
		{
			if ( nr.at(i) - 48 != 1)
			{
				return false;
			}
		
		}
	}
	return true;

}


int main()
{
	std::vector<std::string> x;
	std::vector<std::vector<int>> mat;
	
	std::string nr;	
	//std::string nr = "101011010111110101001";

	std::cout << "Citeste M(x): ";
	std::cin >>nr;

	
	if (valid(nr) == true)
	{
		if (nr.size() % 7 == 0)
		{
			std::vector<int> aux;
			for (int i = 0; i < nr.size(); i++)
			{
				if (i != 0)
				{
					if (i % 7 == 0)
					{
						mat.push_back(aux);
						aux.clear();
					}
				}
				aux.push_back(nr.at(i) - 48);
			}
			mat.push_back(aux);


			printMatrix(mat);


			for (int i = 0; i < mat.size(); i++)
			{
				int par = paritate(mat.at(i));
				mat.at(i).push_back(par);
			}


			printMatrix(mat);

			std::cout << std::endl;

			int colsize = mat.at(0).size();
			int matsize = mat.size();

			aux.clear();

			std::vector<int> lastLine;

			for (int i = 0; i < colsize; i++)
			{
				for (int j = 0; j < matsize; j++)
				{
					//	std::cout << mat.at(j).at(i);
					aux.push_back(mat.at(j).at(i));
				}
				lastLine.push_back(paritate(aux));
				aux.clear();
			}
			mat.push_back(lastLine);

			printMatrix(mat);
			std::cout << "T(x)=";
			std::cout << matToMessage(mat);
		}
		else
		{
			std::cout << "M(x) nu este valid, deoarece nu e multiplu de 7!";
			std::cout << std::endl;
		}


	}
	else
	{

		std::cout << "Numarul nu este valid, nu contine doar 0 si 1!";
		std::cout << std::endl;
	}
	
	

	return 0;

 
}