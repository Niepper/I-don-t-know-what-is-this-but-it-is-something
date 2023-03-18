#include <iostream>
#include <string>

using namespace std;

string s1, s2, sLCS;

int LCS ( int i, int j )
{
  if( !s1 [ i ] || !s2 [ j ] ) return 0;
  else if( s1 [ i ] == s2 [ j ] ) return 1;
  else return max ( LCS ( i+1, j ), LCS ( i, j+1 ) );
}

int main( )
{
  int i, j;
  s1 = "Litwo, Ojczyzno moja! ty jesteś jak zdrowie";
  s2 = "Szlachetne zdrowie, nikt się nie dowie";

   
  sLCS = ""; i = j = 0;
  while( s1 [ i ] && s2 [ j ] )
    if( s1 [ i ] == s2 [ j ] )
    {
      sLCS += s1 [ i ]; i++; j++;
    }
    else if( LCS ( i+1, j ) <= LCS ( i, j+1 ) ) j++; else i++;
  cout << sLCS << ": " << sLCS.length( ) << endl;
  return 0;
} 