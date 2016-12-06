/*
 * Carrier.cpp
 *
 *  Created on: 2016 dec. 6
 *      Author: Feri
 */
#include "util.h"
#include "Carrier.h"

static int id = 1;

Carrier::Carrier(int ammo, int health) {
  carrier_store_of_ammo = ammo;
  health_point = health;
  carrier_id = id;
  id++;
}

void Carrier::add_aircraft(std::string aircraft_type) {
  if (aircraft_type == "F16") {
    aircraft_store.push_back(new F16);
  }
  else if(aircraft_type == "F35") {
    aircraft_store.push_back(new F35);
  }
  else {
    throw 1;
  }
}

int Carrier::carrier_total_damage() {
  int sum_of_aircraft_damage;
  for(unsigned int i = 0; i < aircraft_store.size(); i++) {
    sum_of_aircraft_damage += aircraft_store[i]->total_damage();
  }
  return sum_of_aircraft_damage;
}

int Carrier::amount_of_required_ammo() {
  int amount_of_required_ammo;
  for(unsigned int i = 0; i < aircraft_store.size(); i++) {
    amount_of_required_ammo += aircraft_store[i]->required_ammo();
  }
  return amount_of_required_ammo;
}

void Carrier::fight(Carrier& enemy) {
  if (health_point <= 0 || enemy.health_point <= 0){
    throw 2;
  }
  else {
    for(unsigned int i = 0; i < aircraft_store.size(); i++){
      enemy.health_point -= aircraft_store[i]->fight();
    }
  }
}

void Carrier::refill_aircrafts() {
  if (carrier_store_of_ammo <= 0) {
    throw 3;
  }
  else {
    for(unsigned int i = 0; i < aircraft_store.size(); i++) {
        if (aircraft_store[i]->get_type() == "F35") {
          aircraft_store[i]->refill(carrier_store_of_ammo);
        }
      }
    if (carrier_store_of_ammo > 0) {
      for(unsigned int i = 0; i < aircraft_store.size(); i++) {
        aircraft_store[i]->refill(carrier_store_of_ammo);
      }
    }
  }
}

std::string Carrier::get_carrier_status() {
  std::string output_aircrafts;
  for(unsigned int i = 0; i < aircraft_store.size(); i ++){
    output_aircrafts += aircraft_store[i]->get_status();
  }
  if(health_point > 0) {
    return "Carrier "+to_string(carrier_id) + "\nAircraft count: " + to_string(aircraft_store.size()) +
      ", aircraft ammo storage: " + to_string(carrier_store_of_ammo) +
      ", total damage: " + to_string(carrier_total_damage()) +
      ", health: " + to_string(health_point) + "\n" +
      "Aircrafts: \n" + output_aircrafts;
  }
  else {
    return "It's dead Jim :(";
  }
}
Carrier::~Carrier(){

}
