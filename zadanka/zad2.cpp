#include <iostream>
using namespace std;

string max(float, float, float);

int main()
{
	//id 0 Ania, 1 Patrycja, 2 Magda
	//zarobki będą zrównane do stanu euro z 9.03.2023 z godziny 8:49 ze strony xe.com
	//zarobki będą podawane rocznie jako 52x zarobki tygodniowe lub 12x miesięczne

	float ZarobkiNetto[3] = {78456, 8596128, 53976};
	float ZarobkiBrutto[3];
	float zEuroN[3];
	float zEuroB[3];

  //konwersja walutowa. dalej podawane po zamianie na euro
	zEuroN[0] = ZarobkiNetto[0] * 1.0087661;
	zEuroN[1] = ZarobkiNetto[1] * 0.0069288544;
	zEuroN[2] = ZarobkiNetto[2] * 0.94740421;

  cout << "Największa roczna pensja bez podatku: " << max(zEuroN[0], zEuroN[1], zEuroN[2]) << endl;

  for(int i = 0; i<3; i++){
    cout << zEuroN[i] << endl;
  }
  
  //podatki
  zEuroN[0] *= (0.754 * 1.02 * 1.02); //ULGA 2% ZA DZIECKO, NIE 2p.%
	zEuroN[1] *= 0.95;
	zEuroN[2] *= 0.9;

  cout << "Największa roczna pensja po podatku: " << max(zEuroN[0], zEuroN[1], zEuroN[2]) << endl;

  for(int i = 0; i<3; i++){
    cout << zEuroN[i] << endl;
  }

//ilość godzin pracy w roku to 52x tego co w tygodniu
//Ania 1822, Patrycja 2080, Magda 1560
zEuroN[0] /= 1822;
zEuroN[1] /= 2080;
zEuroN[2] /= 1560;
  
cout<<"Największa pensja na godzinę: "<< max(zEuroN[0], zEuroN[1], zEuroN[2]) << endl;

for(int i = 0; i<3; i++){
  cout << zEuroN[i] << endl;
}
  
	return 0;
}

////////////////////////////////////

string max(float A, float B, float C) {
  float maks = A;
  if(B>maks) maks=B;
  if(C>maks) maks=C;
  if(maks == A) return "Ania";
	if(maks == B) return "Patrycja";
	if(maks == C) return "Magda";
}