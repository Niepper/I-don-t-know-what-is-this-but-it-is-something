#include <iostream>
#include <cstring>
using namespace std;

string changeStyle(string name);

int main()
{

	string ogStyle;

	cin >>ogStyle;

	string newStyle = changeStyle(ogStyle);
	cout << newStyle << endl;
	return 0;

	
}

string changeStyle(string name)
{
	bool isCamel= 0;

	if(name.find("_") == -1)
	{
		
		isCamel=1;
		
	}

	if(isCamel)
	{
		for (int i = 0; i < name.length(); ++i)
		{
			if(name[i]<='Z')
			{ 
				name[i] +=32;
				name.insert(i,"_");

			}
		}


	}
	if(!isCamel)
	{
		for (int i = 0; i < name.length(); ++i)
		{
			if (name[i] == '_')
			{
				name.erase(i,1);
				name[i] -=32;
			}
		}



	}


return name;

}