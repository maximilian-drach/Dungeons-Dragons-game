#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <string>
#include <map>

// Job Enumeration
enum Job {
  warrior = 0,
  cleric = 1,
  bard = 2, 
  wizard = 3,
  monster = 4
};


// DamageType enumeration
enum DamageType {
  physical = 0,
  magical = 1,
  healing = 2
};

Job stringToJob(int n);
DamageType stringToDamage(std::string s);
#endif