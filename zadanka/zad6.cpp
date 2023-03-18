#include <iostream>
#include <fstream>
#include <sstream>


int calculate(int tab[200][300]);
int main()
{
	std::ifstream plik;
	plik.open ("z6.txt");

	std::string tabu[300];
	int tab[200][300]; //x,y
	std::string temp;
 	
 	
	int i =0;

 	if (plik.is_open())
 	{
	while(i < 101)
	{
			
		getline(plik,temp);

		tabu[i] = temp;

		i++;

		}

		plik.close();
		
	}

	
	int num;
	for (int i = 0; i < 100; ++i)
	{
		int k=0; 
		std::stringstream ss(tabu[i]);
		while(ss >> num && k<100)
		{
			tab[i][k++] = num;
		}

	}
	

	std::cout << calculate(tab);

return 0;
}


int calculate(int tab[200][300])
{
	int x = 0;
	int y = 0;
	int sum = 0;
	while(tab[y][x] > 0)
	{
		int tab1 = tab[y][x];
		int tab2 = tab[y][x+1];
		if (tab1> tab2)
		{
			sum = sum + tab1;
			++y;
			
			

		}
		
		if(tab1 < tab2)
		{
			
			sum= sum+tab2;
			++y;
			++x;
			
			
		}


	}



return sum;
}