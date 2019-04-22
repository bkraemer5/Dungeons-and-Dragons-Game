//
//  Dungons+Dragons.cpp
//  CPSC 121 SI Projects
//
//  Created by Brittany Kraemer on 4/17/19.
//  Copyright © 2019 Brittany Kraemer. All rights reserved.
//

#include <iostream>
#include <memory>

using namespace std;

class CommonStats {
protected:
    string name;
    int health;
    int healingDieNum;
    string healingDie;
    int baseAttackDieNum;
    string baseAttackDie;
    int armor;
    int attackModifier;
    int initiativeModifier;
    int rollInitiative() {
        return rand() % 20 + 1;
    }
    int rollDie(int num) {
        return rand() % num + 1;
    }
public:
    CommonStats() {
        name = "";
        health = 0;
        healingDieNum = 0;
        healingDie = "";
        baseAttackDieNum = 0;
        baseAttackDie = "";
        armor = 0;
        attackModifier = 0;
        initiativeModifier = 0;
    }
    virtual void printStats() {
        cout << "Health: " << health << endl;
        cout << "Healing Die: " << healingDie << endl;
        cout << "Base Attack Die: " << baseAttackDie << endl;
        cout << "Armor: " << armor << endl;
        cout << "Attack Modifier (Strength): " << attackModifier << endl;
        cout << "Initiative Modifier (Speed): " << initiativeModifier << endl;
    }
    int getHP() {
        return health;
    }
    void takeDamage(int d) {
        health -= d;
        cout << name << " has taken " << d << " damage and is now at " << health << " HP" << endl << endl;
    }
};

class Warrior : public CommonStats {
public:
    Warrior() {
        name = "Knight Timmy";
        health = 20;
        healingDieNum = 10;
        healingDie = "2 D5";
        baseAttackDieNum = 6;
        baseAttackDie = "1 D6";
        armor = 5;
        attackModifier = 3;
        initiativeModifier = 4;
        cout << "You are now " << name << ", a ferocious Warrior." << endl;
    }
    virtual void printStats() {
        cout << "Warrior " << name << "'s current stats:" << endl;
        cout << "Health: " << health << endl;
        cout << "Healing Die: " << healingDie << endl;
        cout << "Base Attack Die: " << baseAttackDie << endl;
        cout << "Armor: " << armor << endl;
        cout << "Attack Modifier (Strength): " << attackModifier << endl;
        cout << "Initiative Modifier (Speed): " << initiativeModifier << endl << endl;
    }
    int initiative() {
        int roll = rollInitiative();
        int total = roll + initiativeModifier;
        cout << "You rolled one dice(1-20): Initiative score of " << roll << " + a speed modifier of " << initiativeModifier << " for a total of " << total << endl;
        return total;
    }
    void move(CommonStats &p) {
        int choice;
        cout << "Your move:" << endl;
        cout << "What will you do?" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Heal" << endl;
        cin >> choice;
        if (choice == 1) {
            int roll = rollDie(baseAttackDieNum);
            int total = roll + attackModifier;
            cout << "You rolled one dice(1-6): Damage score of " << roll << " + a strength modifier of " << attackModifier << " for a total of " << total << endl;
            total = rand() % total + 1;
            p.takeDamage(total);
        }
        else if (choice == 2) {
            int roll = rollDie(healingDieNum);
            health += roll;
            cout << "You heal yourself for " << roll << " hit points!" << endl;
            if (health >= 20) {
                health = 20;
                cout << "Total HP capped at: " << health << endl;
            }
            else {
                cout << "Total HP now at: " << health << endl;
            }
        }
    }
    void restore() {
        health = 20;
        cout << "A magical fairy visits you, health has been reset to 20!" << endl;
    }
};

class Mage : public CommonStats {
public:
    Mage() {
        name = "Wizard Gandolfo";
        health = 15;
        baseAttackDieNum = 4;
        baseAttackDie = "1 D4";
        armor = 2;
        attackModifier = 7;
        cout << "A Mage named " + name + " appears and is ready for battle!" << endl << endl;
    }
    virtual void printStats() {
        cout << "Mage " << name << "'s current stats:" << endl;
        cout << "Health: " << health << endl;
        cout << "Base Attack Die: " << baseAttackDie << endl;
        cout << "Armor: " << armor << endl;
        cout << "Attack Modifier (Intellect): " << attackModifier << endl << endl;
    }
    int initiative() {
        int roll = rollInitiative();
        cout << "The Mage rolled one dice(1-20): Initiative score of " << roll << " and has no bonus modifier" << endl;
        return roll;
    }
    void move(CommonStats &p) {
        cout << name << "'s move:" << endl;
        int roll = rollDie(baseAttackDieNum);
        int total = roll + attackModifier;
        cout << name << " rolled one dice(1-4): Damage score of " << roll << " + an intellect modifier of " << attackModifier << " for a total of " << total << endl;
        total = rand() % total + 1;
        p.takeDamage(total);
    }
};

class Rogue : public CommonStats {
public:
    Rogue() {
        name = "Assassin Jim";
        health = 10;
        baseAttackDieNum = 8;
        baseAttackDie = "2 D4";
        armor = 3;
        attackModifier = 4;
        initiativeModifier = 5;
        cout << "A Rogue named " + name + " appears and is ready for battle!" << endl << endl;
    }
    virtual void printStats() {
        cout << "Rogue " << name << "'s current stats:" << endl;
        cout << "Health: " << health << endl;
        cout << "Base Attack Die: " << baseAttackDie << endl;
        cout << "Armor: " << armor << endl;
        cout << "Attack Modifier (Agility): " << attackModifier << endl;
        cout << "Initiative Modifier (Speed): " << initiativeModifier << endl;
        cout << "Dodge: 50% chance to dodge an incoming attack" << endl << endl;
    }
    int initiative() {
        int roll = rollInitiative();
        int total = roll + initiativeModifier;
        cout << "The rogue rolled one dice(1-20): Initiative score of " << roll << " + a speed modifier of " << initiativeModifier << " for a total of " << total << endl;
        return total;
    }
    void move(CommonStats &p) {
        cout << "Rogue " << name << "'s move:" << endl;
        int roll = rollDie(baseAttackDieNum);
        int total = roll + attackModifier;
        cout << "Wizard " << name << " rolled one dice(1-4): Damage score of " << roll << " + an agility modifier of " << attackModifier << " for a total of " << total << endl;
        total = rand() % total + 1;
        p.takeDamage(total);
    }
    void takeDamage(int d) {
        int dodge = rand() % 2 + 1;
        if (dodge == 1) {
            health -= d;
            cout << name << " has taken " << d << " damage and is now at " << health << " HP" << endl << endl;
        }
        else {
            cout << name << " dodged the attack!" << endl << endl;
        }
    }
};

int main() {
    
    shared_ptr<Warrior> player = make_shared<Warrior>();
    shared_ptr<Mage> mage = make_shared<Mage>();
    
    player->printStats();
    mage->printStats();
    
    int playerStart, mageStart, rogueStart;
    
    while (player->getHP() > 0 && mage->getHP() > 0) {
        cout << endl;
        playerStart = player->initiative();
        mageStart = mage->initiative();
        cout << endl;
        if (playerStart > mageStart) {
            player->move(*mage);
            if (mage->getHP() > 0) {
                mage->move(*player);
            }
        }
        else {
            mage->move(*player);
            if (player->getHP() > 0) {
                player->move(*mage);
            }
        }
    }
    
    if (player->getHP() <= 0) {
        cout << "You have lost the game." << endl;
        exit(0);
    }
    else {
        cout << "The Mage has been slain!" << endl << endl;
    }
    
    player->restore();
    shared_ptr<Rogue> rogue = make_shared<Rogue>();
    
    player->printStats();
    rogue->printStats();
    
    while (player->getHP() > 0 && rogue->getHP() > 0) {
        playerStart = player->initiative();
        rogueStart = rogue->initiative();
        cout << endl;
        if (playerStart > rogueStart) {
            player->move(*rogue);
            if (rogue->getHP() > 0) {
                rogue->move(*player);
            }
        }
        else {
            rogue->move(*player);
            if (player->getHP() > 0) {
                player->move(*rogue);
            }
        }
    }
    
    if (player->getHP() <= 0) {
        cout << "You have lost the game." << endl;
        exit(1);
    }
    else {
        cout << "The Rogue has been slain!" << endl << endl;
    }
    
    cout << "\nYou won the video game!" << endl;
    return 0;
}
