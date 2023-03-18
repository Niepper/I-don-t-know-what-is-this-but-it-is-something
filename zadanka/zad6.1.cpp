#include <iostream>
#include <fstream>
#include <sstream>


int calculate(int tab[200][300]);
int main()
{
	

	
	int tab[200][300]={
		{75},
		{95,64},
		{17,47,82},
		{18,35,87,10},
		{20,04,82,47,65},
		{19,01,23,75,03,34},
		{88,02,77,73,07,63,67},
		{99,65,04,28,06,16,70,92},
		{41,41,26,56,83,40,80,70,33},
		{41,48,72,33,47,32,37,16,94,29},
		{53,71,44,65,25,43,91,52,97,51,14},
		{70,11,33,28,77,73,17,78,39,68,17,57},
		{91,71,52,38,17,14,91,43,58,50,27,29,48},
		{63,66,04,68,89,53,67,30,73,16,69,87,40,31},
		{04,62,98,27,23,9,70,98,73,93,38,53,60,04,23}






	}; //y,x
	std::string temp;
 		

	std::cout << "Maksymalna suma dla od góry do dołu wynosi " << calculate(tab);

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
		int tab3 = tab[y][x-1];
		if (tab1> tab2 || tab1>tab3)
		{
			sum = sum + tab1;
			++y;	

		}
		
		if(tab1 < tab3 || tab3 > tab2)
		{
			sum = sum+tab3;
			++y;
			x--;
		}

		if(tab1 < tab2 || tab2> tab3)
		{
			
			sum= sum+tab2;
			++y;
			++x;
			
			
		}


	}



return sum;
}