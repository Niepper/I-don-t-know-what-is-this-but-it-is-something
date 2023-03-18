#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string Podciag(string tekst1, string tekst2); 

int main() {
    
    string tekst1 = "Litwo, Ojczyzno moja! ty jesteś jak zdrowie";
    string tekst2 = "Szlachetne zdrowie, nikt się nie dowie";
    string piosenka1 = "To nie karnawał, Ale tańczyć chcę I będę tańczył z nią po dzień. To nie zabawa, Ale bawię się Bezsenne noce senne dnie. To nie kochanka, Ale sypiam z nią Choć śmieją ze mnie się i drwią. Taka zmęczona I pijana wciąż Dlatego nie Nie pytaj więcej mnie. Nie pytaj mnie, dlaczego jestem z nią, Nie pytaj mnie, dlaczego z inną nie, Nie pytaj mnie, dlaczego myślę że, Że nie ma dla mnie innych miejsc. Nie pytaj mnie, co ciągle widzę w niej, Nie pytaj mnie, dlaczego w innej nie, Nie pytaj mnie, dlaczego ciągle chcę, Zasypiać w niej i budzić się. Te brudne dworce Gdzie spotykam ją, Te tłumy które cicho klną, Ten pijak który mruczy coś przez sen Że PÓKI MY ŻYJEMY ona żyje też. Nie pytaj mnie, Nie pytaj mnie, Co widzę w niej. Nie pytaj mnie, co ciągle widzę w niej, Nie pytaj mnie, dlaczego w innej nie, Nie pytaj mnie, dlaczego ciągle chcę, Zasypiać w niej i budzić się. Nie pytaj mnie dlaczego jestem z nią Nie pytaj mnie dlaczego z inną nie Nie pytaj mnie dlaczego myślę że Że nie ma dla mnie innych miejsc Nie pytaj mnie, dlaczego jestem z nią, Nie pytaj mnie, dlaczego z inną nie, Nie pytaj mnie, dlaczego myślę że, Że nie ma dla mnie innych miejsc. Nie pytaj mnie, co ciągle widzę w niej, Nie pytaj mnie, dlaczego w innej nie, Nie pytaj mnie, dlaczego ciągle chcę, Zasypiać w niej i budzić się. Nie pytaj, Nie pytaj, Nie pytaj, Nie pytaj, Nie pytaj, dlaczego jestem z nią, Nie pytaj, dlaczego z inną nie. Nie pytaj, co ciągle widzę w niej, Nie pytaj, dlaczego w innej nie. Nie pytaj, co ciągle widzę w niej, Nie pytaj, dlaczego w innej nie. ";
    string piosenka2 = "To nie karnawał, ale tańczyć z nią chcę Znam ją 30 lat, ale wciąż niewiele wiem Wiele serc bije dla niej, wiele w niej Do szal eństwa zakochane wszystko zrobić są w stanie Dzień wstaje, nową nadzieją nad jej brzegiem Za rękę przed siebie choć czasem jej nie poznaję To nie matka ale wzięła mnie w opiekę Pokazała mi emocje, nauczyła być człowiekiem I może kiedyś będę musiał wszystko oddać Los zada pytanie: „Staniesz przy niej czy ją poddasz?” Jedna z jej lekcji była o wierności Tej ostatecznej do ostatniej krwi kropli Bywam okropny dla niej, często się wściekam Bywam obojętny, chciałbym tylko ją odwiedzać Tak od święta, wyjechać jak inni to robią Nie umiałbym jej zostawić, proszę nie pytaj mnie o nią  I nie pytaj mnie o nią, znasz ją doskonale Nie pytaj co Tobie da, lecz co Ty możesz zrobić dla niej Codziennie w innym stanie ją spotykasz Lecz czujesz tylko dumę, gdy ktoś o nią Cię zapyta.  To nie kochanka, ale co noc sypiam z nią Nawet jeśli wokół drwią i się śmieją wciąż i wciąż Nawet jeśli będę sam z nią jedynie Bo cała reszta postanowi kochać inne Zły sen, bo to ideał dla milionów Często pierwsza miłość od kołyski do grobu Wielu tęskni za nią, wielu nie może wrócić Więc w sercach ją mają czekając, aż los się odwróci To nie muza, ale daje mi natchnienie By obserwować wszystkie jej blaski i cienie I widzieć ją jaka jest, starać się rozumieć W głosów tłumie czego naprawdę chce i co czuje Nasz wspólny obowiązek i troska Jej dzieci to ja i Ty ale i ćpuny na dworcach Mówią o niej bzdury, nas nic nie przekona A póki my żyjemy, żyje ona!  I nie pytaj mnie o nią, znasz ją doskonale Nie pytaj co Tobie da, lecz co Ty możesz zrobić dla niej Codziennie w innym stanie ją spotykasz Lecz czujesz tylko dumę, gdy ktoś o nią Cię zapyta.  Ona nie urodziła mnie, lecz kocham ją jak matkę nieraz mnie odrzuciła, ale będę z nią na zawsze to miłość przed którą wielu ostrzegało jeśli stracisz dla niej głowę, to położysz ją za nią Niektórzy myślą, że jest ich własnością, chcą jej zmienić imię myślą że mogą bo nią rządzą chcą dać jej numer i mieć ją na wyłączność a to solidarność ludzi przecież zwróciła jej wolność brudne ulice gdzie codziennie ją spotykasz tak pijaną i niechlujną która ciągle się potyka ciągle z niej dumny nie raz się zastanawiam, jak bywam durny bo przecież ciągle mnie zostawia Idealiści mają dziwne motywy by kochać ją choć z nią czasem los parszywy i nie ma dla mnie innych miejsc i innej po za nią nie pytaj znasz ją, budzisz się z nią co rano. ";
    
    string wynik1 = Podciag(piosenka1, piosenka2);
    string wynik2 = Podciag(tekst1,tekst2);

    cout << "Najdłuższy wspólny podciąg dla fragmentów to:" << wynik2 << endl << "A dla tekstów piosenek to:" <<wynik1;

    return 0;
}

string Podciag(string tekst1, string tekst2) {
    int len1 = tekst1.length();
    int len2 = tekst2.length();

    vector<vector<int>> arr(len1+1, vector<int>(len2+1, 0));
    int maxDl= 0, maxEnd = 0;

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0 || j == 0) {
                
                arr[i][j] = 0;
            }
            else if(tekst1[i-1] == tekst2[j-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
                
                if(arr[i][j] > maxDl) {
                    maxDl= arr[i][j];
                 
                    maxEnd = i;
                }
            }
            else {
                arr[i][j] = 0;
            }
        }
    }

    if(maxDl== 0) {
        return "";
    }

    return tekst1.substr(maxEnd-maxDl, maxDl);
}
