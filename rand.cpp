#include <iostream>
#include <random>
#include <string>

using namespace std;

void nop(int nou[])
{
	nou[0] = 1;
	nou[1] = 100;
}

int main(int argc, char **argv)
{
	
	srand(time(NULL));

	int nou[2];
	
	if (argc > 0)
		nop(nou);
	

	
	if (argc > 2)
	{
		nou[0] = stoi(argv[1]);
		nou[1] = stoi(argv[2]);
	}

	 if (argc ==2)
	{
		nou[1] = stoi(argv[1]);
	}
	


		cout << rand() % nou[1] + nou[0] << endl; 
		

	return 0;

}

