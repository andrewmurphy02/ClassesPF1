//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Author: Andrew Murphy & John Gauch
//------------------------------------------------------------

#include "player.h"
#include "room.h"
int
main ()
{
  // Initialize game
  srandom (time (NULL));

  // Create room1
  Room room1;
  room1.setRoomName ("entrance");
  room1.setDescription
    ("\nYou just stumbled into a hole in the ground. When you \nshake off the dirt and leaves you realize you are in the \nentrance to a cave that looks man made. As you take a \nlook around, you decide it might be fun to explore.\n");
  room1.setMaxGold (10);
  room1.setFoodName ("STEAK");
  room1.setCreatureName ("BUNNY");
  room1.setItemName ("compass");

  // Create room2
  Room room2;
  room2.setRoomName ("throne room");
  room2.setDescription
    ("\nYou have entered the throne room. In the middle\nof the room there is a giant wooden throne with\nintricate carvings. As you take a closer look at the\ncarvings, you see that they show trolls chasing humans.\nHmmm, maybe this is not a great place to stop for a rest.\n");
  room2.setMaxGold (20);
  room2.setFoodName ("CANDY");
  room2.setCreatureName ("TROLL");
  room2.setItemName ("crown");
  // Create player
  Player player;
  player.setName ("Andrew");
  player.setGold (0);
  player.setHealth (MAX_HEALTH);
  player.setItems ("");

  // Call Player methods
  player.addItem ("flashlight");
  player.addItem ("shovel");

  // Call Room methods
  room1.Print ();
  int treasure = room1.FindTreasure (10);
  int battle_health;
  battle_health = room1.FightBattle (1);
  room1.EatFood (2);
  string newItem = room1.PickupItem (1);
  player.addItem(newItem);
  player.setHealth (MAX_HEALTH - battle_health + STEAK_RESTORE);
  player.setGold (treasure);

  // Call Player methods

  player.Print ();
  // Call Room methods
  room2.Print ();
  treasure = treasure + room2.FindTreasure (20);
  battle_health = battle_health + room2.FightBattle (2);
  room2.EatFood (1);
  newItem = room2.PickupItem (2);
  player.addItem(newItem);
  player.setHealth (MAX_HEALTH - battle_health + CANDY_RESTORE);
  player.setGold (treasure);

  // Call Player methods
  player.Print ();
  return 0;
}
