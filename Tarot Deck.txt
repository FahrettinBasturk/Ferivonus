# Ferivonus

/*
	Name: Fahrettin
	Surname: Baştürk
	last correction: 07.03.2021
	Version 1.2.1
	I wrote this code to astrology interesters. By that, everyone can use my deck. 
 */

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
string Writing_to_Txt(int random_Number[], int size, int writing_turn);


bool Controller(int random_Number[], int length, int turn)
{
	for (int controller = 0; controller < length; controller++) 
	{
		if (turn != controller)
		{
			if (random_Number[turn] == random_Number[controller])
			{
				return true;
			}
		}
		
	}
	return false;
}

bool Controller_for_İmput_on_Black_Screen()
{
	int Controller_for_İmput, counter=0;
	do
	{
		if(counter > 0)
			cout << "You made a mistake. You have to write 1 or 0 "<<endl;
		cout << "would you want to see card numbers?" << endl << "If you want       write 1" << endl << "If you don't want write 0 " << endl;
		cin >> Controller_for_İmput;
		counter++;
	} while (Controller_for_İmput != 1 && Controller_for_İmput != 0);
	if (Controller_for_İmput == 1)
		return true;
	else if (Controller_for_İmput == 0)
		return false;
}
int main()
{   
	int length, Controller_for_İmput;
	int random_Number[150] = { 0 };
	cout << "How numbers cards do we need?"<< endl <<"You Can choose between 0 to 150: ";
	cin >> length;
	srand((unsigned)time(0));
	for (int turn = 0; turn < length; turn++)
	{
		do
		{
			random_Number[turn] = (rand() % 78) + (1000 *(rand() % 2));
		} while (Controller(random_Number, length, turn));
	}
	if (Controller_for_İmput_on_Black_Screen( ) )
	for (int x = 0;	x < length; x++)
	{
		if (random_Number[x] >= 1000) 
		{
			x++; 
			cout << x << ". card is reverse ";
			x--;
			cout << random_Number[x] - 1000 << endl;
		}
			else 
		{
			x++;
			cout << x << ". card is         ";
			x--;
			cout << random_Number[x] << endl;
		}
	}

	//for txt

	string name, surname, full_Name, Full_Name_for_txt, turner, Reverser;
	cout << "For writing txt with cards names by your name "<< endl <<"Enter your name and surname ";
	cin >> name >> surname;
	full_Name = name + " " + surname;
	Full_Name_for_txt = "The Cards Drawn By " + full_Name + ".txt";

	ofstream File_of_Tarot ( Full_Name_for_txt );
	for (int writing_turn = 0; writing_turn < length; writing_turn++)
	{
		Reverser = "        ";
		if (random_Number[writing_turn] >= 1000)
		{
			Reverser = "Reverse ";
			random_Number[writing_turn] = random_Number[writing_turn] - 1000;
		}
		turner = Writing_to_Txt(random_Number, length, writing_turn);
		writing_turn++;
		File_of_Tarot << writing_turn << ". card is "<< Reverser << turner <<endl << endl ;
		writing_turn--;
	}

	File_of_Tarot.close();
	return 0;
}
string Writing_to_Txt(int random_Number[], int size, int writing_turn)
{
	string Turner;
	if (random_Number[writing_turn] == 0)
		 Turner = "Joker, The Fool";
	else if (random_Number[writing_turn] == 1)
		 Turner = "Sihirbaz, The Magican";
	else if (random_Number[writing_turn] == 2)
		 Turner = "Azize, The High Priestess";
	else if (random_Number[writing_turn] == 3)
		 Turner = "İmparatoriçe, The Empress";
	else if (random_Number[writing_turn] == 4)
		 Turner = "İmparator, The Emperor";
	else if (random_Number[writing_turn] == 5)
		 Turner = "Aziz, The Hierophant";
	else if (random_Number[writing_turn] == 6)
		 Turner = "Aşıklar, The Lovers";
	else if (random_Number[writing_turn] == 7)
		 Turner = "Savaş Arabası, The Chariot";
	else if (random_Number[writing_turn] == 8)
		 Turner = "Güç, Strength";
	else if (random_Number[writing_turn] == 9)
		 Turner = "Ermiş, Rhe Hermit";
	else if (random_Number[writing_turn] == 10)
		 Turner = "Kader Çarkı, Wheel of Fortune";
	else if (random_Number[writing_turn] == 11)
		 Turner = "Adalet, Justice";
	else if (random_Number[writing_turn] == 12)
		 Turner = "Asılan Adam, The Hanged Man";
	else if (random_Number[writing_turn] == 13)
		 Turner = "Ölüm, Death";
	else if (random_Number[writing_turn] == 14)
		 Turner = "Denge, Temperance";
	else if (random_Number[writing_turn] == 15)
		 Turner = "Şeytan, The Devil";
	else if (random_Number[writing_turn] == 16)
		 Turner = "Yıkılan Kule, The Tower";
	else if (random_Number[writing_turn] == 17)
		 Turner = "Yıldız, The Star";
	else if (random_Number[writing_turn] == 18)
		 Turner = "Ay, The Moon";
	else if (random_Number[writing_turn] == 19)
		 Turner = "Güneş, The Sun";
	else if (random_Number[writing_turn] == 20)
		 Turner = "Mahkeme, The Last Judgement";
	else if (random_Number[writing_turn] == 21)
		 Turner = "Dünya, The World";
	else if (random_Number[writing_turn] == 22)
		 Turner = "Değnek Ası";
	else if (random_Number[writing_turn] == 23)
		 Turner = "Değnek İkilisi";
	else if (random_Number[writing_turn] == 24)
		 Turner = "Değnek Üçlüsü";
	else if (random_Number[writing_turn] == 25)
		 Turner = "Değnek Dörtlüsü";
	else if (random_Number[writing_turn] == 26)
		 Turner = "Değnek Beşlisi";
	else if (random_Number[writing_turn] == 27)
		 Turner = "Değnek Altılısı";
	else if (random_Number[writing_turn] == 28)
		 Turner = "Değnek Yedilisi";
	else if (random_Number[writing_turn] == 29)
		 Turner = "Değnek Sekizlisi";
	else if (random_Number[writing_turn] == 30)
		 Turner = "Değnek Dokuzlusu ";
	else if (random_Number[writing_turn] == 31)
		 Turner = "Değnek Onlusu ";
	else if (random_Number[writing_turn] == 32)
		 Turner = "Değnek Prensi ";
	else if (random_Number[writing_turn] == 33)
		 Turner = "Değnek Şövalyesi";
	else if (random_Number[writing_turn] == 34)
		 Turner = "Değnek Kraliçesi";
	else if (random_Number[writing_turn] == 35)
		 Turner = "Değnek Kralı";
	else if (random_Number[writing_turn] == 36)
		 Turner = "Kupa Ası";
	else if (random_Number[writing_turn] == 37)
		 Turner = "Kupa İkilisi";
	else if (random_Number[writing_turn] == 38)
		 Turner = "Kupa Üçlüsü";
	else if (random_Number[writing_turn] == 39)
		 Turner = "Kupa Dörtlüsü";
	else if (random_Number[writing_turn] == 40)
		 Turner = "Kupa Beşlisi";
	else if (random_Number[writing_turn] == 41)
		 Turner = "Kupa Altılısı";
	else if (random_Number[writing_turn] == 42)
		 Turner = "Kupa Yedilisi";
	else if (random_Number[writing_turn] == 43)
		 Turner = "Kupa Sekizlisi";
	else if (random_Number[writing_turn] == 44)
		 Turner = "Kupa Dokuzlusu";
	else if (random_Number[writing_turn] == 45)
		 Turner = "Kupa Onlusu";
	else if (random_Number[writing_turn] == 46)
		 Turner = "Kupa Prensi";
	else if (random_Number[writing_turn] == 47)
		 Turner = "Kupa Şövalyesi";
	else if (random_Number[writing_turn] == 48)
		 Turner = "Kupa Kraliçesi";
	else if (random_Number[writing_turn] == 49)
		 Turner = "Kupa Kralı";
	else if (random_Number[writing_turn] == 50)
		 Turner = "Kılıç Ası";
	else if (random_Number[writing_turn] == 51)
		 Turner = "Kılıç İkilisi";
	else if (random_Number[writing_turn] == 52)
		 Turner = "Kılıç Üçlüsü";
	else if (random_Number[writing_turn] == 53)
		 Turner = "Kılıç Dörtlüsü";
	else if (random_Number[writing_turn] == 54)
		 Turner = "Kılıç Beşlisi";
	else if (random_Number[writing_turn] == 55)
		 Turner = "Kılıç Altılısı";
	else if (random_Number[writing_turn] == 56)
		 Turner = "Kılıç Yedilisi";
	else if (random_Number[writing_turn] == 57)
		 Turner = "Kılıç Sekizlisi";
	else if (random_Number[writing_turn] == 58)
		 Turner = "Kılıç Dokuzlusu";
	else if (random_Number[writing_turn] == 59)
		 Turner = "Kılıç Onlusu";
	else if (random_Number[writing_turn] == 60)
		 Turner = "Kılıç Prensi";
	else if (random_Number[writing_turn] == 61)
		 Turner = "Kılıç Şövalyesi";
	else if (random_Number[writing_turn] == 62)
		 Turner = "Kılıç Kraliçesi";
	else if (random_Number[writing_turn] == 63)
		 Turner = "Kılıç Kralı";
	else if (random_Number[writing_turn] == 64)
	  	 Turner = "Tılsım Ası";
	else if (random_Number[writing_turn] == 65)
		 Turner = "Tılsım İkilisi";
	else if (random_Number[writing_turn] == 66)
	 	 Turner = "Tılsım Üçlüsü";
	else if (random_Number[writing_turn] == 67)
	 	 Turner = "Tılsım Dörtlüsü";
	else if (random_Number[writing_turn] == 68)
	 	 Turner = "Tılsım Beşlisi";
	else if (random_Number[writing_turn] == 69)
		 Turner = "Tılsım Altılısı";
	else if (random_Number[writing_turn] == 70)
		 Turner = "Tılsım Yedilisi";
	else if (random_Number[writing_turn] == 71)
		 Turner = "Tılsım Sekizlisi";
	else if (random_Number[writing_turn] == 72)
		 Turner = "Tılsım Dokuzlusu";
	else if (random_Number[writing_turn] == 73)
		 Turner = "Tılsım Onlusu";
	else if (random_Number[writing_turn] == 74)
		 Turner = "Tılsım Prensi";
	else if (random_Number[writing_turn] == 75)
		 Turner = "Tılsım Şövalyesi";
	else if (random_Number[writing_turn] == 76)
		 Turner = "Tılsım Kraliçesi";
	else if (random_Number[writing_turn] == 77)
		 Turner = "Tılsım Kralı";
	else
		 Turner = "Error";
		 return Turner;
}
