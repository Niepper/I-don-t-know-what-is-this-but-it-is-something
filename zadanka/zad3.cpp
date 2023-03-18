#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string mostPopular(string[]);
string TLDS(string link);

int main()
{
    std::ifstream plik; 
    plik.open("z3.txt");
    std::string temp;
    string linki[66];
    string tld; 

    for (int i = 0; i < 66; ++i)
    {
      getline(plik,temp);
      linki[i] = TLDS(temp);

    }



      cin >> temp;

      tld = TLDS(temp);

      string typ= tld.size() > 2 ? "gTLD" : "ccTLD";
      cout << "url " << temp << " ma domenę \"" << tld << "\" i typ " << typ <<endl;
      cout << mostPopular(linki);
    


    plik.close();
    return 0;
}

string TLDS(string link)
{
  string FDomain;
  int protocol= link.find("://");
  if(protocol>0)
   link.erase(0,protocol+3);
  int fSlash =link.find_first_of("/");
  if(fSlash>0)
   link.erase(fSlash,link.size());
  FDomain = link;
  int domain = link.find_last_of(".");
  link.erase(0,domain+1);
   return(link);


}

string mostPopular(string domain[])
{
  int ammount[66];
  for (int i = 0; i < 66 ; ++i)
  {
    for (int k = 0; k < 66; ++k)
    {
      
      if (domain[i] == domain[k])
      {
        ammount[i]++;
        domain[k] += " ";

      }

    }
  }
 int biggest = 0;
 int biggest_id = 0;
  for (int i = 0; i < 66; ++i)
  {
    if (biggest < ammount[i])
    {
      biggest = ammount[i];
      biggest_id = i;
    }
    

  }

  return "najwięcej jest " + domain[biggest_id];
}