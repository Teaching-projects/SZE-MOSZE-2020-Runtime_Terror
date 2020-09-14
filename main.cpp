#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class Unit {

public:
    string name;
    int health{};
    int damage{};

    bool IsDead() {
        return (health <= 0) ? true : false;
    }

    Unit() {

    }

    Unit(string name, int health, int damage) {
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void Attack(Unit &target) {
        target.health -= this->damage;
        if (target.health < 0) target.health = 0;
    }
};

class Game {

public:
    Unit player;
    Unit enemy;

    Game(vector<string> data) {
        this->player = Unit(data[1], stoi(data[2]), stoi(data[3]));
        this->enemy = Unit(data[4], stoi(data[5]), stoi(data[6]));
    }

    void SimulateTurn(Unit &attacker, Unit &target) {          
        cout << attacker.name << " -> " << target.name << endl;
        attacker.Attack(target);
        PrintCurrentState();             
    }

    void Combat() {
        PrintCurrentState();
        bool endCombat = false;
        while (!endCombat) {
            SimulateTurn(player, enemy);
            if (enemy.IsDead()) {
                endCombat = true;
                cout << enemy.name << " died. " << player.name << " wins." << endl;
                break;
            }  
            SimulateTurn(enemy, player);    
            if (player.IsDead()) {
                endCombat = true;
                cout << player.name << "died. " << enemy.name << " wins." << endl;
                break;
            }
        }
    }

    void PrintCurrentState() {
        cout << player.name << ": " << "HP: " << player.health << ", DMG: " << player.damage << endl;
        cout << enemy.name << ": " << "HP: " << enemy.health << ", DMG: " << enemy.damage << endl;
    }

};

int main(int argc, char* argv[])
{
    vector<string> data;
    for (int i = 0; i < argc; ++i) {
        data.push_back(argv[i]);
    }        

    Game game = Game(data);
    game.Combat();
}