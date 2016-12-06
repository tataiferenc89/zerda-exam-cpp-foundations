/*
 * Aircrafts.cpp
 *
 *  Created on: 2016 dec. 6
 *      Author: Feri
 */
#include "util.h"
#include "Aircrafts.h"


Aircrafts::Aircrafts() {
  ammo_store = 0;
}

int Aircrafts::total_damage() {
  return base_damage * ammo_store;
}

int Aircrafts::fight() {
  int damage_done = ammo_store * base_damage;
  ammo_store = 0;
  return damage_done;
}

int Aircrafts::refill(int& ammo) {
  int ammo_needed = max_ammo-ammo_store;
  if (ammo_needed < ammo) {
    ammo_store = max_ammo;
    ammo -= ammo_needed;
  }
  else {
    ammo_store += ammo;
    ammo = 0;
  }
  return ammo;
}

int Aircrafts::required_ammo() {
  return max_ammo - ammo_store;
}

std::string Aircrafts::get_type() {
  return aircraft_type;
}

std:: string Aircrafts::get_status() {
  return "Type: " + aircraft_type +
      ", ammo: " + to_string(ammo_store) +
      ", base damage: " + to_string(base_damage) +
      ", total damage: " + to_string(base_damage*ammo_store) +
      "\n";
}
