#include <iostream>
using namespace std;

int tura=1;
char plansza[3][3];
int x,y;
int GX,GY; //pierwszy ruch
string tryb;
bool bezmózg=false;

void print_board();
void konkuter(int,int,int);
char win();

int main() {
  for(int I=0; I<3; I++){
    for(int i=0; i<3; i++){
      plansza[I][i]='-';
    } 
  }
  cout<<"WIELKI MĄDRY WYZYWA CIĘ NA POJEDYNEK!\n\n";
  print_board();
  while(win()=='-'){
    cout<< "tura "<<tura << endl;
    while(true){
       cout<< "podaj pole x (1-3):"; cin >> x;
       cout<< "podaj pole y (1-3):"; cin >> y;
       x--;y--;
       if(plansza[y][x] == '-') break;
       else cout<<"NIE PRÓBUJ WIĘCEJ OSZUKIWAĆ !\n";
    }
    if(tura==1){
      GX=x;
      GY=y;
    }
    plansza[y][x]='O';
    if(win()=='-') konkuter(tura, x, y);
    tura++;
    print_board();
  }
  cout<<endl;
  if(win()=='O') cout<<"NIE ! NIEMOŻLIWE ! WIELKI MĄDRY NIGDY NIE PRZEGRYWA !";
  if(win()=='X') cout<<"NIE MASZ SZANS Z WIELKIM MĄDRYM ! KOLEJNE ZWYCIĘSTWO ALGORYTMICZNEGO DEMONA !!!";
  if(win()=='r') cout<<"REMIS?! CZYLI JEDNAK NIE WYGRAŁEŚ Z WIELKIM MĄDRYM !!!";
}

void print_board(){
  for(int I=0; I<3; I++){
    for(int i=0; i<3; i++){
      cout<<plansza[I][i]<<'|';
    } cout<<"y"<< I+1 <<endl;
  }
  for(int i=0; i<3; i++){
    cout<<"x"<<i+1;
  }cout<<endl;
}

void konkuter(int tura,int x,int y){
  bezmózg=true;
  if (tura==1){
    if(plansza[0][0]=='O' || plansza[2][2]=='O' || plansza[0][2]=='O' || plansza[2][0]=='O'){
      plansza[1][1]='X';
      cout<<"\nWIELKI MĄDRY WYKONAŁ RUCH NA X2Y2 !\n\n";
      tryb = "rożny";
    }else
    if(plansza[1][0]=='O' || plansza[2][1]=='O' || plansza[0][1]=='O' || plansza[1][2]=='O'){
      plansza[1][1]='X';
      cout<<"\nWIELKI MĄDRY WYKONAŁ RUCH NA X2Y2 !\n\n";
      tryb = "edgy";
    }else
    if(plansza[1][1]=='O'){
      plansza[0][0]='X';
      cout<<"\nWIELKI MĄDRY WYKONAŁ RUCH NA X1Y1 !\n\n";
    }
    bezmózg = false;
  }else //PIERWSZY RUCH ZAWSZE JEST OPTYMALNY
  
  if(bezmózg==true) for(int I=0; I<3; I++){ //CZY SI MOŻE WYGRAĆ?
   for(int i=0; i<3; i++){
    if (plansza[I][i]=='-' && bezmózg==true){
     plansza[I][i]='X'; bezmózg=false;  // czy wykonać następny ruch?
     if(win()!='X') {plansza[I][i]='-'; bezmózg=true;}
    }
   }
  } //DEMON ! WIELKI MĄDRY WIDZI WSZYSTKO!!! WYGRANA MU NIE UMKNIE !
  
  if(bezmózg==true) for(int I=0; I<3; I++){ //CZY GRACZ MOŻE WYGRAĆ?
   for(int i=0; i<3; i++){
    if (plansza[I][i]=='-' && bezmózg==true){
     plansza[I][i]='O'; bezmózg=false;  // czy wykonać następny ruch?
     if(win()!='O') {plansza[I][i]='-'; bezmózg=true;}
     else {plansza[I][i]='X'; bezmózg=false;}
    }
   }
  } //DEMON ! WIELKI MĄDRY WIDZI WSZYSTKO!!! NIE POZWOLI CI ZWYCIĘŻYĆ !
  
  if (bezmózg==true){
   for(int I=0; I<3; I++){
    for(int i=0; i<3; i++){
     if (plansza[I][i]=='-' && bezmózg==true){
      cout<<"\nWIELKI MĄDRY NIE MUSIAŁ NAWET MYŚLEĆ !!!\n";
        plansza[I][i]='X';
        bezmózg=false;
      }
    }
   }
  } //GDY NIE WIADOMO CO ROBIĆ, TRZEBA ROBIĆ COKOLWIEK
}

char win(){
  if(plansza[0][0]=='X' && plansza[1][1]=='X' && plansza[2][2]=='X') {return 'X';} else//skos
  if(plansza[2][0]=='X' && plansza[1][1]=='X' && plansza[0][2]=='X') {return 'X';} else//skos
  for(int i=0; i<3; i++) {if(plansza[i][0]=='X' && plansza[i][1]=='X' && plansza[i][2]=='X') return 'X';} //poziomy
  for(int i=0; i<3; i++) {if(plansza[0][i]=='X' && plansza[1][i]=='X' && plansza[2][i]=='X') return 'X';} //piony

  if(plansza[0][0]=='O' && plansza[1][1]=='O' && plansza[2][2]=='O') {return 'O';} else//skos
  if(plansza[2][0]=='O' && plansza[1][1]=='O' && plansza[0][2]=='O') {return 'O';} else//skos
  for(int i=0; i<3; i++) {if(plansza[i][0]=='O' && plansza[i][1]=='O' && plansza[i][2]=='O') return 'O';} //poziomy
  for(int i=0; i<3; i++) {if(plansza[0][i]=='O' && plansza[1][i]=='O' && plansza[2][i]=='O') return 'O';} //piony

  for (int I = 0; I < 3; I++) {
    for (int i = 0; i < 3; i++) {
        if(plansza[I][i]=='-') return '-'; //'-' oznacza gra w trakcie
    }
  }

  return 'r'; //'r' jak przykry 'r'emis
}