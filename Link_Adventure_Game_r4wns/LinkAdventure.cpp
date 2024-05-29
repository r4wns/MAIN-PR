#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Item
{
public:
    string name;
    int price;
    float weight;
    int damage;
    int heal;

    Item(string n, int p, float w, int d, int h)
    {
        name = n;
        price = p;
        weight = w;
        damage = d;
        heal = h;
    }

    Item()
    {
        name = "";
        weight = 0;
        damage = 0;
        heal = 0;
        price = 0;
    }

    void showInfo()
    {
        cout << "=======================" << endl;
        cout << name << endl;
        cout << "  Weight:" << weight << endl;
        cout << "  HealthPt:" << heal << endl;
        cout << "  DamagePt:" << damage << endl;
        cout << "  Price:" << price << endl;
        cout << "=======================" << endl;
    }
};

class Player
{
public:
    string name;
    vector<Item> backpack;
    vector<Item> weapons;
    vector<Item> healingItems;
    int age;
    int hp;
    int lvl;
    int coins;

    Player(string n, int a, int h, int l, int c)
    {
        name = n;
        age = a;
        hp = h;
        lvl = l;
        coins = c;
    }

    void showInfo()
    {
        cout << "=======================" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "HP: " << hp << endl;
        cout << "Level: " << lvl << endl;
        cout << "Coins: " << coins << endl;
        cout << "=======================" << endl;

        for (int i = 0; i < backpack.size(); i++)
        {
            backpack[i].showInfo();
        }
    }

    void addToBackpack(Item newItem)
    {
        backpack.push_back(newItem);
        if (newItem.damage > 0)
        {
            weapons.push_back(newItem);
        }
        else if (newItem.heal > 0)
        {
            healingItems.push_back(newItem);
        }
    }

    bool hasItem(string itemName)
    {
        for (const auto &item : backpack)
        {
            if (item.name == itemName)
            {
                return true;
            }
        }
        return false;
    }
};

class Playground
{
public:
    int place1(Player &p)
    {
        cout << "This is the first place of the playground, do you wish to explore further? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y')
        {
            cout << endl;
            cout << "Sweet...let's begin..." << endl;
            cout << endl;
            system("pause");
            system("cls");
            cout << "You explore the place and find...A HEALING FLASK!!??" << endl;
            cout << "Do you wish to take it? (y/n): ";
            char takeFlask;
            cin >> takeFlask;
            system("cls");
            if (takeFlask == 'y')
            {
                Item o1("Healing Flask", 10, 0.7, 0, 50);
                p.addToBackpack(o1);
                cout << "Healing Flask added to your backpack!" << endl;
            }
            else
            {
                cout << "You proceed your journey...that flask could've been helpful...ugh..." << endl;
                cout << endl;
                system("pause");
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "There is a forest in front of you..." << endl;
        }
        else
        {
            return 9;
        }
        return 2;
    }
    int place2(Player &p)
    {
        system("cls");
        cout << "Oh? What is that sound?" << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "You encounter a wild MUTATED SQUIRREL!" << endl;
        cout << "He seems ready to fight!" << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "Choose what to do (1/2):" << endl;
        cout << "1. Accept the fight (bonus reward)" << endl;
        cout << "2. Run (No reward)" << endl;
        cout << endl;
        int choice;
        cin >> choice;

        //FIGHT AGAINST SQUIRREL
        if (choice == 1)
        {
            system("pause");
            cout << endl;
            cout << "PREPARE TO FIGHT!!" << endl;
            cout << endl;
            system("pause");
            system("cls");
            int squirrelLife = 20;
            srand(time(0));
            while (squirrelLife > 0 && p.hp > 0)
            {
                cout << "--------------------" << endl;
                cout << "Choose action: " << endl;
                cout << "1. Attack" << endl;
                cout << "2. Heal" << endl;
                cout << "Your choice: ";
                int action;
                cin >> action;
                int probability;
                cout << "--------------------" << endl;
                if (action == 1)
                {
                    // player turn
                    probability = rand() % 100;
                    if (probability < 90)
                    {
                        squirrelLife = squirrelLife - 5;
                        cout << "You have attacked the squirrel." << endl;
                        cout << "Your opponent has " << squirrelLife << " HP remaining." << endl;
                    }
                    else
                    {
                        cout << "You have missed;" << endl;
                    }
                }
                else if (action == 2) // Heal
                {
                    if (p.hasItem("Healing Flask"))
                    {
                        if (p.hp < 100)
                        {
                            p.hp += 50; // Heal the player
                            cout << "You have used a healing flask!" << endl;
                            cout << "HP remaining: " << p.hp << endl;
                        }
                        else
                        {
                            cout << "Your health is already full." << endl;
                        }
                    }
                    else
                    {
                        cout << "You don't have a Healing Flask in your backpack." << endl;
                    }

                    system("pause");
                    system("cls");
                }
                // opponent's turn
                cout << "Your opponent's turn..." << endl;
                cout << "--------------------" << endl;
                system("pause");
                system("cls");
                probability = rand() % 100;
                if (probability > 50)
                {
                    cout << "Your opponent has attacked you!!" << endl;
                    p.hp = p.hp - 10;
                    cout << "You have " << p.hp << " HP left..." << endl;
                }
                else
                {
                    cout << "Your opponent has missed." << endl;
                }
            }

            // when squirrel is defeated
            cout << "YOU HAVE DEFEATED THE MUTATED SQUIRREL!!" << endl;
            cout << "========================================" << endl;
            cout << "Here are your bonus rewards..." << endl;
            cout << endl;
            system("pause");
            Item o2("MedKit", 35, 1, 0, 100); // bonus rewards
            p.coins += 25;
            p.addToBackpack(o2);
            cout << endl;
            cout << "A medkit has been added to your backpack (a medkit restores full player's health)" << endl;
            cout << "You have received 25 COINS!!" << endl;
            cout << endl;
        }
        else // RUN AWAY
        {
            cout << "You ran away...ahhh those rewards could've been nice... :(( " << endl;
        }
        system("pause");
        system("cls");

        return 3;
    }
    int place3(Player &p)
    {
        system("cls");
        cout << "You make a swift turn to your right and see a beatiful fairy village..." << endl;
        cout << endl;
        cout << "You have never been there before..." << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "You make your way to the village and spot a local shop." << endl;
        cout << "Do you wish to get inside? (y/n): ";
        char choice;
        cin >> choice;
        system("pause");
        system("cls");
        if (choice == 'y')
        {
            cout << "*********************" << endl;
            cout << "WELCOME TO OUR SHOP!" << endl;
            cout << "*********************" << endl;
            cout << "You have " << p.coins << " COINS" << endl;
            cout << "-------------------------" << endl;
            cout << "HERE ARE OUR PRODUCTS: " << endl;
            cout << "1. Healing flask, restores 50 HP (10 coins)" << endl;
            cout << "2. Dagger, deals 30 Damage (25 coins)" << endl;
            cout << "3. Healing potion, restores 10 HP (5 coins)" << endl;
            cout << "4. Claymore, deals 50 damage (35 coins)" << endl;
            cout << "..." << endl;
            cout << "Select: " << endl;
            cout << "1. Buy something" << endl;
            cout << "2. Exit" << endl;
            cout << "Choose: ";
            int choice;
            cin >> choice;

            while (choice == 1)
            {
                if (p.coins > 0)
                {
                    cout << "Select an item (type the number of the item or '777' to exit) " << endl;
                    cout << "(if the items are not adding to your backpack type '777' to exit the shop): ";
                    int selection;
                    cin >> selection;
                    if (selection == 1 && p.coins >= 10)
                    {
                        Item o1("Healing Flask", 10, 0.7, 0, 50);
                        p.addToBackpack(o1);
                        p.coins = p.coins - 10;
                        cout << "Healing Flask added to backpack." << endl;
                    }
                    else if (selection == 2 && p.coins >= 25)
                    {
                        Item q1("Dagger", 25, 15, 30, 0);
                        p.addToBackpack(q1);
                        p.coins = p.coins - 25;
                        cout << "Dagger added to backpack." << endl;
                    }
                    else if (selection == 3 && p.coins >= 5)
                    {
                        Item q2("Healing Potion", 5, 0.8, 0, 10);
                        p.addToBackpack(q2);
                        p.coins = p.coins - 5;
                        cout << "Healing Potion added to backpack." << endl;
                    }
                    else if (selection == 4 && p.coins >= 35)
                    {
                        Item q3("Claymore", 35, 20, 50, 0);
                        p.addToBackpack(q3);
                        p.coins = p.coins - 35;
                        cout << "Claymore added to backpack." << endl;
                    }
                    else if (selection == 777)
                    {
                        cout << "Exiting..." << endl;
                        break;
                    }
                }
                else
                {
                    cout << "You don't have enough coins." << endl;
                    break;
                }
            }
            cout << "Exiting the shop." << endl;
            system("pause");
            system("cls");
        }
        return 4;
    }
    int place4(Player &p)
    {
        system("cls");
        cout << "You walk through the woods and suddenly hear a noise behind you..." << endl;
        system("pause");
        system("cls");
        cout << "You fall inside a trap that was setup by a giant rat...he approaches you: " << endl;
        cout << "If you want to get out of this trap you have to pay me 5 coins..." << endl;
        cout << "Otherwise we will have to fight for our lives." << endl;
        system("pause");
        cout << "Accept the offer and hand the mouse 5 coins? (y/n): ";
        char accept;
        cin >> accept;
        if (accept == 'y')
        {
            if (p.coins >= 5)
            {
                cout << "You hand 5 coins to the giant rat and proceed to the next location" << endl;
                p.coins = p.coins - 5;
                return 6;
            }
            else
            {
                cout << "You don't have enough coins...you are forced to fight the rat..." << endl;
                return 5;
            }
        }
        else
        {
            cout << "You have chosen to fight the rat, PREPARE FOR THE BATTLE!!" << endl;
            return 5;
        }
        system("pause");
        system("cls");
    }
    int place5(Player &p)
    {
        cout << "Choose your weapon (type number): " << endl;
        cout << "1. Default Weapon" << endl;

        if(p.hasItem("Dagger"))
        {
            cout << "2. Dagger (30 dmg)" << endl;
        }
        if(p.hasItem("Claymore"))
        {
            cout << "3. Claymore (50 dmg)" << endl;
        }

        Item q1("Dagger", 25, 15, 30, 0);
        Item q3("Claymore", 35, 20, 50, 0);

        int weapon;
        cin >> weapon;

        system("pause");
        system("cls");

        cout << "Choose your healing item (type number):" << endl;
        if(p.hasItem("Healing Flask"))
        {
            cout << "1. Healing Flask (restores 50 HP)" << endl;
        }
        if (p.hasItem("Healing Potion"))
        {
            cout << "2. Healing potion (restores 10 HP)" << endl;
        }

        cout << "Choice: ";

        int healing;
        cin >> healing;

        int ratLife = 70;
        int probability;
        while (ratLife > 0 && p.hp > 0)
        {
            cout << "++++++++++++++++++++" << endl;
            cout << "Choose action: " << endl;
            cout << "1. Attack" << endl;
            cout << "2. Heal" << endl;
            cout << "Your choice: ";
            int action;
            cin >> action;
            int probability;
            cout << "++++++++++++++++++++" << endl;
            if (action == 1 && weapon == 1)
            {
                // player turn
                probability = rand() % 100;
                if (probability < 90)
                {
                    ratLife = ratLife - 5;
                    cout << "You have attacked the rat." << endl;
                    cout << "Your opponent has " <<ratLife << " HP remaining." << endl;
                }
                else
                {
                    cout << "You have missed;" << endl;
                }
            }
            else if (action == 2 && healing == 1) // Heal
            {
                if (p.hasItem("Healing Flask"))
                {
                    if (p.hp < 100)
                    {
                        p.hp += 50; // Heal the player
                        cout << "You have used a healing flask!" << endl;
                        cout << "HP remaining: " << p.hp << endl;
                    }
                    else
                    {
                        cout << "Your health is already full." << endl;
                    }
                }
                else
                {
                    cout << "You don't have a Healing Flask in your backpack." << endl;
                }

                system("pause");
                system("cls");
            }
            if (action == 1 && weapon == 2)
            {
                // player turn
                probability = rand() % 100;
                if (probability < 90)
                {
                    ratLife = ratLife - 30;
                    cout << "You have attacked the rat." << endl;
                    cout << "Your opponent has " << ratLife << " HP remaining." << endl;
                }
                else
                {
                    cout << "You have missed;" << endl;
                }
            }
            else if (action == 2 && healing == 2) // Heal
            {
                if (p.hasItem("Healing Potion"))
                {
                    if (p.hp < 100)
                    {
                        p.hp += 10; // Heal the player
                        cout << "You have used a healing flask!" << endl;
                        cout << "HP remaining: " << p.hp << endl;
                    }
                    else
                    {
                        cout << "Your health is already full." << endl;
                    }
                }
                else
                {
                    cout << "You don't have a Healing Flask in your backpack." << endl;
                }

                system("pause");
                system("cls");
            }
            if (action == 1 && weapon == 3)
            {
                // player turn
                probability = rand() % 100;
                if (probability < 90)
                {
                    ratLife = ratLife - 50;
                    cout << "You have attacked the rat." << endl;
                    cout << "Your opponent has " << ratLife << " HP remaining." << endl;
                }
                else
                {
                    cout << "You have missed;" << endl;
                }
            }
            // opponent's turn
            cout << "Your opponent's turn..." << endl;
            cout << "--------------------" << endl;
            system("pause");
            system("cls");
            probability = rand() % 100;
            if (probability > 40)
            {
                cout << "Your opponent has attacked you!!" << endl;
                p.hp = p.hp - 15;
                cout << "You have " << p.hp << " HP left..." << endl;
            }
            else
            {
                cout << "Your opponent has missed." << endl;
            }
        }
        if(p.hp <= 0)
        {
            cout << "You have lost, maybe next time you will complete the adventure..." << endl;
            system("pause");
            return 9;
        }

        cout << "You have succesfully defeated the Giant Rat!!" << endl;
        system("pause");
        system("cls");
        cout << "Oh...? You found some loot to collect!" << endl;
        cout << "..." << endl;;
        cout << "You have received 50 coins and a Rat's Tooth." << endl;
        Item r1("Rat's Tooth", 100, 0.7, 0, 0);
        p.addToBackpack(r1);
        p.coins += 50;
        system("pause");
        cout << "Items added to your backpack." << endl;
        return 6;
    }
    int place6(Player &p)
    {
        cout << "You feel dizzy and fall asleep..." << endl;
        system("pause");
        system("cls");
        cout << "But a white rabbit wakes you up..." << endl;
        cout << endl;
        cout << "Rabbit: Hey you? What are you doing here?" << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "Link: I got lost in a playground... Can you help me find a way out of here?" << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "Rabbit: Sure! But be aware that at the end of your adventure you will have to face a Gorlock!" << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "Link: A GORLOCK???!!" << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "Rabbit: Yes, I suggest you to use your Items in your backpack wisely!" << endl;
        cout << "Rabbit: And yes, you have to go straight and right to go to the next location." << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "Thank you..." << endl;
        cout << endl;
        system("pause");
        system("cls");
        cout << "You go straight and right as the rabbit told you..." << endl;
        cout << endl;
        return 7;
    }
    int place7(Player &p)
    {
        system("pause");
        system("cls");
        cout << "You find yourself in a dark cave and find a Healing flask...Take it? (y/n): ";
        char choice;
        cin >> choice;
        if(choice == 'y')
        {
            Item o1("Healing Flask", 10, 0.7, 0, 50);
            p.addToBackpack(o1);
            system("pause");
            system("cls");
            cout << "Healing Flask added to backpack." << endl;
        }
        else 
        {
            system("pause");
            system("cls");
            cout << "You leave the Flask on the ground..." << endl;
        }

        system("pause");
        system("cls");
        cout << "You explore the cave and encounter something very strange..." << endl;
        return 8;
    }
    int place8(Player &p)
    {
        system("pause");
        system("cls");
        cout << "In the end of the cave there is a big Gorlock..." << endl;
        cout << "You approach him..." << endl;
        system("pause");
        system("cls");
        cout << "Gorlock: URGHHH WHO IS HERE??" << endl;
        cout << "The Gorlock jumped in front of you and started the fight!" << endl;

        int gorlockLife = 100;
        cout << "-----------------------------------" << endl;
        cout << "Choose your weapon (type number): " << endl;
        cout << "1. Default Weapon" << endl;

        if(p.hasItem("Dagger"))
        {
            cout << "2. Dagger (30 dmg)" << endl;
        }
        if(p.hasItem("Claymore"))
        {
            cout << "3. Claymore (50 dmg)" << endl;
        }
        cout << "-----------------------------------" << endl;

        Item q1("Dagger", 25, 15, 30, 0);
        Item q3("Claymore", 35, 20, 50, 0);

        int weapon;
        cin >> weapon;

        system("pause");
        system("cls");
        cout << "-----------------------------------" << endl;
        cout << "Choose your healing item (type number):" << endl;
        if(p.hasItem("Healing Flask"))
        {
            cout << "1. Healing Flask (restores 50 HP)" << endl;
        }
        if (p.hasItem("Healing Potion"))
        {
            cout << "2. Healing potion (restores 10 HP)" << endl;
        }
        cout << "-----------------------------------" << endl;

        int healing;
        cin >> healing;
        int probability;
        while (gorlockLife > 0 && p.hp > 0)
        {
            cout << "++++++++++++++++++++" << endl;
            cout << "--------------------" << endl;
            cout << "Choose action: " << endl;
            cout << "1. Attack" << endl;
            cout << "2. Heal" << endl;
            cout << "Your choice: ";
            int action;
            cin >> action;
            int probability;
            cout << "--------------------" << endl;
            cout << "++++++++++++++++++++" << endl;
            if (action == 1 && weapon == 1)
            {
                // player turn
                probability = rand() % 100;
                if (probability < 90)
                {
                    gorlockLife = gorlockLife - 5;
                    cout << "You have attacked the Gorlock." << endl;
                    cout << "Your opponent has " <<gorlockLife << " HP remaining." << endl;
                }
                else
                {
                    cout << "You have missed;" << endl;
                }
            }
            else if (action == 2 && healing == 1) // Heal
            {
                if (p.hasItem("Healing Flask"))
                {
                    if (p.hp < 100)
                    {
                        p.hp += 50; // Heal the player
                        cout << "You have used a healing flask!" << endl;
                        cout << "HP remaining: " << p.hp << endl;
                    }
                    else
                    {
                        cout << "Your health is already full." << endl;
                    }
                }
                else
                {
                    cout << "You don't have a Healing Flask in your backpack." << endl;
                }

                system("pause");
                system("cls");
            }
            if (action == 1 && weapon == 2)
            {
                // player turn
                probability = rand() % 100;
                if (probability < 90)
                {
                    gorlockLife = gorlockLife - 30;
                    cout << "You have attacked the Gorlock." << endl;
                    cout << "Your opponent has " << gorlockLife << " HP remaining." << endl;
                }
                else
                {
                    cout << "You have missed;" << endl;
                }
            }
            else if (action == 2 && healing == 2) // Heal
            {
                if (p.hasItem("Healing Potion"))
                {
                    if (p.hp < 100)
                    {
                        p.hp += 10; // Heal the player
                        cout << "You have used a healing flask!" << endl;
                        cout << "HP remaining: " << p.hp << endl;
                    }
                    else
                    {
                        cout << "Your health is already full." << endl;
                    }
                }
                else
                {
                    cout << "You don't have a Healing Flask in your backpack." << endl;
                }

                system("pause");
                system("cls");
            }
            if (action == 1 && weapon == 3)
            {
                // player turn
                probability = rand() % 100;
                if (probability < 90)
                {
                    gorlockLife = gorlockLife - 50;
                    cout << "You have attacked the Gorlock." << endl;
                    cout << "Your opponent has " << gorlockLife << " HP remaining." << endl;
                }
                else
                {
                    cout << "You have missed;" << endl;
                }
            }
            // opponent's turn
            cout << "Your opponent's turn..." << endl;
            cout << "--------------------" << endl;
            system("pause");
            system("cls");
            probability = rand() % 100;
            if (probability > 40)
            {
                cout << "Your opponent has attacked you!!" << endl;
                p.hp = p.hp - 15;
                cout << "You have " << p.hp << " HP left..." << endl;
            }
            else
            {
                cout << "Your opponent has missed." << endl;
            }
        }
        if(p.hp <= 0)
        {
            cout << "You have lost, maybe next time you will complete the adventure..." << endl;
            system("pause");
            return 9;
        }

        cout << "CONGRATULATIONS, YOU HAVE DEFEATED THE FINAL BOSS!!" << endl;
        system("pause");
        system("cls");
        if(p.hasItem("Rat's Tooth"))
        {
            cout << "Do you wish to use the Rat's Tooth and unlock the full story achievement? (y/n): ";
            char option;
            cin >> option;
            if(option == 'y')
            {
                cout << "   O   " << endl;
                cout << "  /|\\  " << endl;
                cout << "  / \\  " << endl;
                cout << "       " << endl;
                cout << "Congratulations!" << endl;
                cout << "You have completed Link's Adventure!!!" << endl;
            }
            else 
            {
                cout << "No problem. Have a great day, see you next time!" << endl;
                return 9;
            }
        }
        else 
        {
            cout << "You haven't defeated the rat and can't unlock the Full Story Achievement." << endl;
            cout << "See you next time!!" << endl;
            return 9;
        }
    }
};

int main()
{
    Player p("Link", 17, 100, 0, 50);
    p.showInfo();

    Playground x;
    int actualPlace = x.place1(p);

    while (actualPlace != 9)
    {
        cout << endl;
        system("pause");
        system("cls");
        p.showInfo();
        cout << endl;
        cout << "*************************" << endl;
        cout << "| THIS IS PLACE NUMBER " << actualPlace << "|" << endl;
        cout << "*************************" << endl;

        cout << endl;
        system("pause");
        switch (actualPlace)
        {
        case 2:
        {
            actualPlace = x.place2(p);
            break;
        }
        case 3:
        {
            actualPlace = x.place3(p);
            break;
        }
        case 4:
        {
            actualPlace = x.place4(p);
            break;
        }
        case 5:
        {
            actualPlace = x.place5(p);
            break;
        }
        case 6:
        {
            actualPlace = x.place6(p);
            break;
        }
        case 7:
        {
            actualPlace = x.place7(p);
            break;
        }
        case 8:
        {
            actualPlace = x.place8(p);
            break;
        }
        }
    }

    return 0;
}
