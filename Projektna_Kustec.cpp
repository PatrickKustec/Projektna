#include <iostream>
#include <string> //ker smo definirali string oz. spremenljivke
#include <fstream> //filestream, uporabljamo za bratnje datotek
using namespace std;

int main()
{
	string text;
	string imedatoteke;
	int crkaA = 0; 
	int crkaE = 0;
	int crkaI = 0;
	int crkaO = 0;
	int crkaU = 0;

	cout << "Vnesi ime .txt datoteke: ";
	cin >> imedatoteke;
	imedatoteke.append(".txt"); //append doda text zraven
	ifstream inFile(imedatoteke.c_str(), ios::in); //iz datoteke stejemo stringe...in pomeni da jih stejemo in ne zapisujemo

	if (!inFile.is_open()){ //is_open() nam pove ali je odprta pravilna datoteka
		cout << "Napaka pri .txt datoteki: " << imedatoteke << ", ne deluje!" << endl;
		return 0; 
	}

	while (inFile.good()) //zanka se izvaja tako dolgo, dokler ne prebere dokonca datoteke
	{
		getline(inFile, text); //preberemo linijo teksta iz datoteke in shranimo v 'text'

		for (int i = 0; i < text.size(); i++) //velikost text spremenljivke
		{
			if (text[i] == 'A' || text[i] == 'a')
				++crkaA;
			if (text[i] == 'E' || text[i] == 'e')
				++crkaE;
			if (text[i] == 'I' || text[i] == 'i')
				++crkaI;
			if (text[i] == 'O' || text[i] == 'o')
				++crkaO;
			if (text[i] == 'U' || text[i] == 'u')
				++crkaU;
		}
	}
	cout << "V " << imedatoteke << " datoteki je : " << endl;
	cout << crkaA << " crk A" << endl;
	cout << crkaE << " crk E" << endl;
	cout << crkaI << " crk I" << endl;
	cout << crkaO << " crk O" << endl;
	cout << crkaU << " crk U" << endl;

	return 0;
}
