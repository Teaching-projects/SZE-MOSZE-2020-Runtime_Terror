/**
 * \class Monster
 * 
 * \brief Monster class
 * A Monster can attack, suffer damage and we can also get its values and wether it is alive or not
 * 
 * \author Jaksics Benedek & Tömördi Tamás
 * 
 * Created on: 2020/10/12 12:04
*/

#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Monster
{

public:
    Monster(const std::string, const int, const int, const int, const double, const int, const std::string); ///< Constructor of Monster class

    /**
     * \brief Checks if the Monster's health value is greater than zero
     * \return True, if the health value is greater than zero, False, if it is not
    */
    bool isAlive() const;

     /**
     * \brief Two monsters fight until one's death
    */
    void fightTilDeath(Monster & /** [in] The Monster the attack is targeting*/); 

    /**
     * \brief Damages target Monster using SufferDamage()
    */
    virtual void Attack(Monster & /** [in] The Monster the attack is targeting*/); 

    /**
     * \brief Fills Monster data from JSON file
     * \return Monster with values from the specified JSON file
    */
    static Monster parse(const std::string& /** [in] The name of the file to be parsed*/);

    /// This is a simple getter function for name
    std::string getName() const;
    /// This is a simple getter function for health value
    int getHealthPoints() const;
    /// This is a simple getter function for physical damage value
    int getPhysicalDamage() const;
     /// This is a simple getter function for magical damage value
    int getMagicalDamage() const;
    /// This is a simple getter function for current time until next attack
    double getAttackCoolDown() const;
    /// This is a simple getter function for current defense value
    int getDefense() const;

    std::string getTexture() const;

    protected:

    struct Damage 
    {
        int physical;
        int magical;

        Damage() : physical(0), magical(0) {}
        Damage(int physical, int magical) : physical(physical), magical(magical) {}

        Damage operator+(const Damage& d) 
        {
            Damage damage;
            damage.physical = this->physical + d.physical;
            damage.magical = this->magical + d.magical;
            return damage;
        }

        Damage& operator+=(const Damage& d)
        {
            this->physical += d.physical;
            this->magical += d.magical;
            return *this;
        }

        Damage& operator*=(const Damage& d)
        {
            this->physical *= d.physical;
            this->magical *= d.magical;
            return *this;
        }
    };

    const std::string name; ///< The name of a unit
    int health; ///< The health value of a unit
    Monster::Damage damage; ///< The damage values of a unit
    double atkcooldown; ///< The time between the unit's attacks
    int defense; ///< The defense value of a unit
    std::string texture;

    private:
    static void RemoveChar(std::string & /** [in] The target string the charater(s) need to be removed from */, const char /** [in] The charater to be removed*/); ///< Removes specified characters from a given string. Used by the parseMonster function
    void SufferDamage(Damage); ///< Lowers a unit's health value by the specified amount

};

#endif