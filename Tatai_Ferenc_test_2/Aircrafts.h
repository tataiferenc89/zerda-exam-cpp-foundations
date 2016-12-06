/*
 * Aircrafts.h
 *
 *  Created on: 2016 dec. 6
 *      Author: Feri
 */

#ifndef AIRCRAFTS_H_
#define AIRCRAFTS_H_

#include <iostream>

class Aircrafts {
private:
  int ammo_store;
protected:
  int max_ammo;
  int base_damage;
  std::string aircraft_type;
public:
  Aircrafts();
  int fight();
  int total_damage();
  int required_ammo();
  int refill(int&);
  std::string get_type();
  std:: string get_status();
};

#endif /* AIRCRAFTS_H_ */
