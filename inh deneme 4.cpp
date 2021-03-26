/*
    Creator: Fahrettin Baþtürk
    last correction: 26.03.2021
    Version 2.2.1
    I wrote this code to make a world for me and to learn making multiple inheritance by original world
*/

#include <iostream>
using namespace std;
class World {
private:
    string name;
    string surname;
    string Full_Name;
    int age = 0;
public :
    World(string name, string surname, int age)
    {
        this->name = name;
        this->surname = surname;
        this->age = age;
        Full_Name = name + " " + surname;
    }
    World(){}
    void print_FullName() {
        cout << Full_Name << endl;
    }
    string full_name_taker()
    {
        return Full_Name;
    }
    int ageTaker() {
        return age;
    }
    ~World(){}
};

class People: public World {

private:
    string hobby, Legallity;
    int money=0;
public:
    People(string name, string surname, int age, string hobby, int money): World ( name,surname,age), hobby(hobby), money(money){
        this->hobby = hobby;
        this->money = money;
    }
    People() {}
    bool Legality_controller() {
        if (ageTaker() >= 18)
            return true;
        return false;
    }
    int Money_Taker() {
        return money;
    }
    void Legallity_func()
    {
        if (Legality_controller())
            Legallity = " its calculation legal for him ";
        else
            Legallity = " its calculation illegal for him ";
    }
    ~People() {}
};

class Men : public People {
private:
    int size_of_him;
    string Legallity, full_name;
public:
    Men(string name, string surname, int age, string hobby, int money, int size_of_him) : People(name, surname, age, hobby, money), size_of_him(size_of_him) {
        full_name = name + " " + surname;
    }
    Men() : size_of_him(size_of_him = 0) {}

    ~Men() {
        cout << full_name << "'s penis was cuted from " << size_of_him << " to 0" << endl;
    }

};


class Women : public People {
private:
    int size_of_his;
    string Legallity, full_name;

public:
    Women(string name, string surname, int age, string hobby, int money, int size_of_his) : People(name, surname, age, hobby, money), size_of_his(size_of_his) {
        full_name = name + " " + surname;
    }
    Women() :size_of_his(size_of_his = 0) {}


    ~Women() {
        cout << full_name << "'s breast was cuted from " << size_of_his << " to 0" << endl;

    }
};


class BankAccount {
private:
    int money=0;
    string full_name;
public:
    BankAccount(string full_name ,int money)
    {
        this->full_name = full_name;
        this->money = money;
    }

    BankAccount(){}
    ~BankAccount() {
        cout << full_name << "'s bank account closed " << endl;
    }
};


int How_Many_people(string need) {
    int returner = 0, counter = 0;
    do
    {
        if (counter > 0)
            cout << "The program cannot deal with " << returner << " " << need << endl;
        cout << "How many " << need << " do we need (between 0 and 20): ";
        cin >> returner;
        counter++;
    } while (returner > 20 || returner < 0);
    return returner;
}



int main()
{
    Men* Men_Array[20] = { 0 };
    Women* Women_Array[20] = { 0 };
    BankAccount *Men_Bank_Account[20] = { 0 };
    BankAccount *Women_Bank_Account[20] = { 0 };
    int Men_of_number, Women_of_number, age, size, money;
    string Name, Surname, Full_Name, hobby;

    Men_of_number = How_Many_people("Men");
    Women_of_number = How_Many_people("Women");
    if (Men_of_number > 0){
        cout << endl << "For men: " << endl;
        for (int m = 0; m < Men_of_number; m++)
        {
            if (m > 0)
            {
                cout << endl << "For other man," << endl;
            }
            m++;
            cout << "Enter name and surname with age for " << m << ". man: " << endl;
            m--;
            cin >> Name >> Surname >> age;
            Full_Name = Name + " " + Surname;
            cout << "enter " << Full_Name << "'s penis size with hobby: ";
            cin >> size >> hobby;
            cout << "how much money do have " << Full_Name << " : ";
            cin >> money;
            Men_Array[m] = new Men(Name, Surname, age, hobby, money, size);
        }
    }
    else 
        cout << "there is no man" << endl;
    if (Women_of_number > 0) {
        cout << endl << "For women: " << endl;
        for (int w = 0; w < Women_of_number; w++)
        {
            if (w > 0)
            {
                cout << endl << "For other women," << endl;
            }
            w++;
            cout << "Enter name and surname with age for " << w << ". women: " << endl;
            w--;
            cin >> Name >> Surname >> age;
            Full_Name = Name + " " + Surname;
            cout << "enter " << Full_Name << "'s breast size with hobby: ";
            cin >> size >> hobby;
            cout << "how much money do have " << Full_Name << " : ";
            cin >> money;
            Women_Array[w] = new Women(Name, Surname, age, hobby, money, size);
        }
    }
    else
        cout << "there is no woman" << endl;
    if (Men_of_number > 0) {
        cout << endl << "Men are :" << endl;
        for (int man = 0; man < Men_of_number; man++) {
            cout << Men_Array[man]->full_name_taker() << endl;
        }
    }
    if (Women_of_number > 0) {
        cout << endl << "Women are :" << endl;
        for (int woman = 0; woman < Women_of_number; woman++) {
            cout << Women_Array[woman]->full_name_taker() << endl;
        }
    }
    string Bank_Account_wanter;
    int account_counter_men = 0;
    if (Men_of_number > 0) {
        cout << endl << "For Men bank accounts: " << endl;
        for (int x = 0; x < Men_of_number; x++)
        {
            if (Men_Array[x]->Legality_controller()) {
                cout << Men_Array[x]->full_name_taker() << " would want to open an bank account? Please type yes or no: ";
                cin >> Bank_Account_wanter;
                if (Bank_Account_wanter == "yes") {
                    Full_Name = Men_Array[x]->full_name_taker();
                    money = Men_Array[x]->Money_Taker();
                    Men_Bank_Account[account_counter_men] = new BankAccount(Full_Name, money);
                    account_counter_men++;
                    cout << Full_Name << "'s bank account created " << endl;
                }
            }
            else
                cout << Men_Array[x]->full_name_taker() << " cannot open an bank account." << endl;
        }
    }
    
    int account_counter_women = 0;
    if (Women_of_number > 0) {
        cout << endl << "For Women bank accounts: " << endl;
        for (int x = 0; x < Women_of_number; x++)
        {
            if (Women_Array[x]->Legality_controller()) {
                cout << Women_Array[x]->full_name_taker() << " would want to open an bank account? Please type yes or no: ";
                cin >> Bank_Account_wanter;
                if (Bank_Account_wanter == "yes") {
                    Full_Name = Women_Array[x]->full_name_taker();
                    money = Women_Array[x]->Money_Taker();
                    Women_Bank_Account[account_counter_women] = new BankAccount(Full_Name, money);
                    account_counter_women++;
                    cout << Full_Name << "'s bank account created. " << endl;
                }
                else
                    cout << Full_Name << "'s bank account did not created. " << endl;
            }
            else 
                cout << Women_Array[x]->full_name_taker() << " cannot open an bank account." << endl;
        }
     }
    cout << endl;
    for (int delater = 0; delater < Men_of_number; delater++)
    {
        delete Men_Array[delater];

    }
    for (int delater = 0; delater < Women_of_number; delater++)
    {
        delete Women_Array[delater];
    }
    for (int delater = 0; delater < account_counter_men; delater++)
    {
        delete Men_Bank_Account[delater];
    }
    for (int delater = 0; delater < account_counter_women; delater++)
    {
        delete Women_Bank_Account[delater];
    }
    return 0;
}
