#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Unit
{
public:
    Unit(const std::string, const int, const int, const float);
    bool IsDead() const;
    void Attack(Unit &);

    static Unit parseUnit(const std::string);

    std::string GetName() const;
    int GetHealth() const;
    int GetDamage() const;
    float GetCurrentCooldown() const;

private:
    const std::string name;
    int health;
    const int damage;
    const float atkcooldown;
    float currentcooldown;

    static void RemoveChar(std::string &, const char);
    void SufferDamage(int);
    void LowerCooldown(float);
    void ResetCooldown();
};

#endif