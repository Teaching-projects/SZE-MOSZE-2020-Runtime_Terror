/**
 * \class Unit
 * 
 * \brief Unit class
 * 
 * \author Jaksics Benedek
 * 
 * Created on: 2020/10/12 12:04
*/

#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Unit
{
public:
    Unit(const std::string, const int, const int, const float); ///< Constructor of Unit class

    /**
     * \brief Checks if the Unit's health value is zero
     * \return True, if the health value is zero, False, if it is not
    */
    bool IsDead() const;

    /**
     * \brief Damages target Unit using SufferDamage(), then lowers target's attack cooldown and resets the attacker's cooldown. (LowerCooldown() and ResetCooldown() respectively)
    */
    void Attack(Unit & /** [in] The Unit the attack is targeting*/); 

    /**
     * \brief Fills Unit data from JSON file
     * \return Unit with values from the specified JSON file
    */
    static Unit parseUnit(const std::string /** [in] The name of the file to be parsed*/);

    /// This is a simple getter function for name
    std::string GetName() const;
    /// This is a simple getter function for health value
    int GetHealth() const;
    /// This is a simple getter function for damage value
    int GetDamage() const;
    /// This is a simple getter function for current time until next attack
    float GetCurrentCooldown() const;

private:
    const std::string name; ///< The name of a unit
    int health; ///< The health value of a unit
    const int damage; ///< The damage value of a unit
    const float atkcooldown; ///< The default time between the unit's attacks
    float currentcooldown; ///< The current time until the unit's next attack

    static void RemoveChar(std::string & /** [in] The target string the charater(s) need to be removed from */, const char /** [in] The charater to be removed*/); ///< Removes specified characters from a given string. Used by the parseUnit function
    void SufferDamage(int); ///< Lowers a unit's health value by the specified amount
    void LowerCooldown(float); ///< Lowers a unit's cooldown until its next attack by the specified amount
    void ResetCooldown(); ///< Resets a unit's attack cooldown to it's base value
};

#endif