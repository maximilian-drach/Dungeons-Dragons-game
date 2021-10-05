#include "utils.hpp"


// Convert string to enum
Job stringToJob(int n){
  return static_cast<Job>(n);
}

DamageType stringToDamage(std::string s){
  static std::map<std::string, DamageType> types;
  if(types.empty()){
    types.insert(std::pair<std::string, DamageType>("physical", DamageType::physical));
    types.insert(std::pair<std::string, DamageType>("magical", DamageType::magical));
    types.insert(std::pair<std::string, DamageType>("healing", DamageType::healing));   
  }
  if(types.count(s)) return types[s];
  return DamageType::healing;
}

