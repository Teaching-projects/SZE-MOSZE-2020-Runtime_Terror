#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Unit
{
    public:
    Unit(const std::string, const int, const int);
    bool IsDead() const;
    void Attack(Unit &) const;
    void SufferDamage(int);

    static Unit parseUnit(const std::string);

    std::string GetName() const;
    int GetHealth() const;
    int GetDamage() const;

    protected:
    const std::string name;
    int health;
    int damage;

    private:
    static void RemoveChar(std::string &, const char);
};

#endif