//---------------------------------------------------
// Purpose:     Header file for the Room class
// Author:      Andrew Murphy
//---------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

const int CANDY_RESTORE = 10;
const int STEAK_RESTORE = 20;
const int BUNNY_DAMAGE = 25;
const int DWARF_DAMAGE = 40;

class Room
{
private:
  string room_name;
  string room_description;
  int max_gold;
  string food_name;
  string creature_name;
  string item_name;

public:
    Room ();
   ~Room ();

  void setRoomName (const string Room_Name);
  void setDescription (const string Room_Description);
  void setMaxGold (const int Max_Gold);
  void setFoodName (const string Food_Name);
  void setCreatureName (const string Creature_Name);
  void setItemName (const string Item_Name);
  void EatFood (const int food);
  int FindTreasure (const int max_gold);
  int FightBattle (const int creature);
  string PickupItem (const int thing);
  string getRoomName () const;
  string getDescription () const;
  int getMaxGold () const;
  string getFoodName () const;
  string getCreatureName () const;
  string getItemName () const;

  void Print ();

};
