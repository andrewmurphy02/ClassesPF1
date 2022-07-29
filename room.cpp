//---------------------------------------------------
// Purpose:     Implementationfile for the Room class
// Author:      Andrew Murphy
//---------------------------------------------------
#include "room.h"

//------------------------------------------------------------
// Purpose: Constructor function
//------------------------------------------------------------
Room::Room ()
{
  room_name = "none";
  room_description = "none";
  max_gold = 0;
  food_name = "none";
  creature_name = "none";
  item_name = "none";

}

//------------------------------------------------------------
// Purpose: Destructor function
//------------------------------------------------------------
Room::~Room ()
{
}

//------------------------------------------------------------
// Purpose: Set Name value
//------------------------------------------------------------
void
Room::setRoomName (const string Room_Name)
{
  room_name = Room_Name;
}

//------------------------------------------------------------
// Purpose: Set Room Description value
//------------------------------------------------------------
void
Room::setDescription (const string Room_Description)
{
  room_description = Room_Description;
}

//------------------------------------------------------------
// Purpose: Set Gold value
//------------------------------------------------------------
void
Room::setMaxGold (const int Max_Gold)
{
  max_gold = Max_Gold;

}

//------------------------------------------------------------
// Purpose: Set Food Name
//------------------------------------------------------------
void
Room::setFoodName (const string Food_Name)
{
  food_name = Food_Name;
}

//------------------------------------------------------------
// Purpose: Set Creature Name
//------------------------------------------------------------
void
Room::setCreatureName (const string Creature_Name)
{
  creature_name = Creature_Name;
}

//------------------------------------------------------------
// Purpose: Set Item Name
//------------------------------------------------------------
void
Room::setItemName (const string Item_Name)
{
  item_name = Item_Name;
}

//------------------------------------------------------------
// Purpose: Get The Room Name
//------------------------------------------------------------
string Room::getRoomName () const
{
  return room_name;
}

//------------------------------------------------------------
// Purpose: Get The Room Description
//------------------------------------------------------------
string Room::getDescription () const
{
  return room_description;
}

//------------------------------------------------------------
// Purpose: Get The Room Name
//------------------------------------------------------------
int
Room::getMaxGold () const 
{
  return max_gold;
}

//------------------------------------------------------------
// Purpose: Get The Food Name
//------------------------------------------------------------
string Room::getFoodName () const
{
  return food_name;
}

//------------------------------------------------------------
// Purpose: Get The Creature Name
//------------------------------------------------------------
string Room::getCreatureName () const
{
  return creature_name;
}

//------------------------------------------------------------
// Purpose: Get The Item Name
//------------------------------------------------------------
string Room::getItemName () const
{
  return item_name;
}

//------------------------------------------------------------
// Purpose: Eat Food Code
//------------------------------------------------------------
void
Room::EatFood (const int food)
{
  switch (food)
    {
    case 1:
      //health = health + CANDY_RESTORE;
      cout << "\nYou find a half eaten energy bar on the floor "
	<< "which restores your health by " << CANDY_RESTORE << endl;
      break;
    case 2:
      //health = health + STEAK_RESTORE;
      cout << "\nYou find a warm and jucy steak on the table "
	<< "which restores your health by " << STEAK_RESTORE << endl;
      break;
    }
}

//------------------------------------------------------------
// Purpose: Find Treasure Code
//------------------------------------------------------------
int
Room::FindTreasure (const int max_gold)
{
  int gold = 1 + random () % max_gold;
  if (gold < max_gold / 2)
    cout << "\nYou find " << gold << " gold pieces on the floor.\n";
  else
    cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";
  return gold;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int
Room::FightBattle (const int creature)
{
  int damage;
  switch (creature)
    {
    case 1:
      damage = 1 + random () % BUNNY_DAMAGE;
      cout << "\nYou trip over a cute bunny and do "
	<< damage << " damage to your health.\n";
      break;
    case 2:
      damage = 1 + random () % DWARF_DAMAGE;
      cout << "\nA drunken dwarf hits you with a beer mug and does "
	<< damage << " damage to your health.\n";
      break;
    }
  return damage;
}

string
Room::PickupItem (const int thing)
{
  string input;
  switch (thing)
    {
    case 1:
      cout << "\nThere is a compass covered in cobwebs in the corner\n"
	"of the room.\n";
      cout << "\nWould you like to pick it up? (yes/no)\n";
      cin >> input;
      while ((input != "yes") && (input != "no"))
	{
	  cout << "\nPlease select yes or no.\n";
	  cin >> input;
	}
      if (input == "yes")
	{
	  cout << "\nYou picked up the compass!\n";
	  return "compass";
	}
      else if (input == "no")
	{
	  cout << "\nWhat a shame you could've used that.\n";
	  return "";
	}
      break;
    case 2:
      cout << "\nThere is a crown that looks like it can be useful\n"
	"on a chair in the middle of the room.\n";
      cout << "\nWould you like to pick it up? (yes/no)\n";
      cin >> input;
      while ((input != "yes") && (input != "no"))
	{
	  cout << "\nPlease select yes or no.\n";
	  cin >> input;
	}
      if (input == "yes")
	{
	  cout << "\nYou picked up the crown!\n";
	  return "crown";
	}
      else if (input == "no")
	{
	  cout << "\nWhat a shame you could've used that.\n";
	  return "";
	}
      break;
    }
return 0;
}

//------------------------------------------------------------
// Purpose: Print all Room data
//------------------------------------------------------------
void
Room::Print ()
{
  cout << "\nRoom Information" << endl;
  cout << "Name:   " << room_name << endl;
  cout << "Description:   " << room_description << endl;
  cout << "Treasure:  " << max_gold << endl;
  cout << "Creature:  " << creature_name << endl;
  cout << "Food:      " << food_name << endl;
  cout << "Item:      " << item_name << endl;
}
