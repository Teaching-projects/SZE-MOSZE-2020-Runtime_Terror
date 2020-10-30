/**
 * \class Monster
 * 
 * \brief Monster class
 * 
 * \author Jaksics Benedek
 * 
 * Created on: 2020/10/12 12:04
*/

#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Monster
{

public:
    Monster(const std::string, const int, const int, const float); ///< Constructor of Monster class

    /**
     * \brief Checks if the Monster's health value is zero
     * \return True, if the health value is zero, False, if it is not
    */

    bool isAlive() const;

    /**
     * \brief Damages target Monster using SufferDamage(), then lowers target's attack cooldown and resets the attacker's cooldown. (LowerCooldown() and ResetCooldown() respectively)
    */
    void fightTilDeath(Monster & /** [in] The Monster the attack is targeting*/); 

    /**
     * \brief Fills Monster data from JSON file
     * \return Monster with values from the specified JSON file
    */
    static Monster parse(const std::string& /** [in] The name of the file to be parsed*/);

    /// This is a simple getter function for name
    std::string getName() const;
    /// This is a simple getter function for health value
    int getHealthPoints() const;
    /// This is a simple getter function for damage value
    int getDamage() const;
    /// This is a simple getter function for current time until next attack
    float getAttackCoolDown() const;

    protected:
    const std::string name; ///< The name of a unit
    int health; ///< The health value of a unit
    int damage; ///< The damage value of a unit
    const float atkcooldown; ///< The default time between the unit's attacks
    float currentcooldown; ///< The current time until the unit's next attack

    private:
    static void RemoveChar(std::string & /** [in] The target string the charater(s) need to be removed from */, const char /** [in] The charater to be removed*/); ///< Removes specified characters from a given string. Used by the parseMonster function
    void SufferDamage(int); ///< Lowers a unit's health value by the specified amount
    void LowerCooldown(float); ///< Lowers a unit's cooldown until its next attack by the specified amount
    void ResetCooldown(); ///< Resets a unit's attack cooldown to it's base value

};

#endif