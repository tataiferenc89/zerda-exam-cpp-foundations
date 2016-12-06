/*
 * Carrier.h
 *
 *  Created on: 2016 dec. 6
 *      Author: Feri
 */

#ifndef CARRIER_H_
#define CARRIER_H_

#include <iostream>
#include <vector>
#include "Aircrafts.h"
#include "F16.h"
#include "F35.h"

class Carrier {
private:
  std::vector<Aircrafts*> aircraft_store;
  int carrier_store_of_ammo;
  int health_point;
  int carrier_id;
public:
  Carrier(int,int);
  void add_aircraft(std::string);
  int carrier_total_damage();
  int amount_of_required_ammo();
  void refill_aircrafts();
  void fight(Carrier&);
  std::string get_carrier_status();
  ~Carrier();
};

#endif /* CARRIER_H_ */
