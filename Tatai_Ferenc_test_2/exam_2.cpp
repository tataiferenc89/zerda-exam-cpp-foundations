#include <iostream>
using namespace std;
#include "Aircrafts.h"
#include "F16.h"
#include "F35.h"
#include "Carrier.h"

int main() {
  // Create carriers
  Carrier carrier_1(50,5000);
  try {
  carrier_1.add_aircraft("F16");
  carrier_1.add_aircraft("F35");
  carrier_1.add_aircraft("F35");
  carrier_1.add_aircraft("F3");
  }
  catch (int x) {
    cout << "Wrong type of aircraft" << endl;
  }
  Carrier carrier_2(500,700);
  carrier_2.add_aircraft("F16");
  carrier_2.add_aircraft("F16");
  carrier_2.add_aircraft("F35");
  try{
  carrier_1.refill_aircrafts();
  carrier_2.refill_aircrafts();
  }
  catch(int x) {
    cout << "The ammo store is empty" << endl;
  }

  cout << carrier_1.get_carrier_status() << endl;
  cout << carrier_2.get_carrier_status() << endl;

  // Fight
  carrier_2.fight(carrier_1);
  carrier_1.fight(carrier_2);

  try{
  carrier_2.fight(carrier_1);
  }
  catch(int x) {
        cout <<  "Its already under water" << endl;
  }
  carrier_1.refill_aircrafts();
  cout << carrier_1.get_carrier_status() << endl;
  cout << carrier_2.get_carrier_status() << endl;

	return 0;
}
