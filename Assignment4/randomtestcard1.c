#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TEST_BUG 1 // Test for bug
#define TEST_OTHER 0 // Test not for bug

int assert(int flag, int isBUG) {
  if (flag) {
    if (isBUG) {
      printf("Warning: ");
    } else {
      printf("Info: ");
    }
  }
  return flag;
}

int main () {
  // set your card array
  int k[10] = { adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall };
  // declare the game state
  struct gameState G;
  // declare the arrays
  int coppers[MAX_HAND];
  int silvers[MAX_HAND];
  int golds[MAX_HAND];
  printf("Begin Testing actionBaron():\n");
  //
  // The game should over when supplyCount of estate card equals 0.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test bug:Game not over.\n");
  printf("Test start: The game should over when supplyCount of estate card equals 0.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  int r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  int player = 0;
  G.handCount[player] = 1; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 1);
  G.supplyCount[estate] = 1;//Decrement estates
  // call the refactored function: The game should over when supplyCount of estate equals 0.
  int supplyCountBeforeFunction = supplyCount(estate, &G);
  printf("supplyCount of estate before: %d\n", supplyCountBeforeFunction);
  actionBaron(&G, player, 1);
  int supplyCountAfterFunction = supplyCount(estate, &G);
  printf("supplyCount of estate after: %d\n", supplyCountAfterFunction);
  // verify that your asserts pass, for the bugs your asserts may fail
  int res = assert(isGameOver(&G) == 0, TEST_BUG); // check a condition
  if (res) {
    printf("The game does not over when supplyCount of estate equals 0.\n");
  }
  printf("Test end: The game should over when supplyCount of estate card equals 0.\n\n");

  //
  // Player should not gain estate card if player choose to discard an Estate for +4.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test bug:Gain an Estate.\n");
  printf("Test begin: Player should not gain estate card if player choose to discard an Estate for +4.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game
  player = 0;
  G.handCount[player] = 1; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 1);
  // call the refactored function: The game should over when supplyCount of estate equals 0.
   supplyCountBeforeFunction = supplyCount(estate, &G);
  printf("supplyCount of estate before: %d\n", supplyCountBeforeFunction);
  actionBaron(&G, player, 1);
   supplyCountAfterFunction = supplyCount(estate, &G);
  printf("supplyCount of estate after: %d\n", supplyCountAfterFunction);
  // verify that your asserts pass, for the bugs your asserts may fail
  res = assert(supplyCountBeforeFunction - 1 == supplyCountAfterFunction, TEST_BUG); // check a condition
  if (res) {
    printf("Player should not gain estate card if player choose to discard an Estate for +4.\n");
  }
  printf("Test end: Player should not gain estate card if player choose to discard an Estate for +4.\n\n");

  //
  // Player choose to gain an estate card. Supply count should be reduced 2. One for this action, one for the player.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Player choose to gain an estate card. Supply count should be reduced 2. One for this action, one for the player.\n");
  printf("Test begin: Player choose to gain an estate card.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game
  player = 0;
  G.handCount[player] = 1; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 1);
  // call the refactored function: The game should over when supplyCount of estate equals 0.
  supplyCountBeforeFunction = supplyCount(estate, &G);
  printf("supplyCount of estate before: %d\n", supplyCountBeforeFunction);
  actionBaron(&G, player, 0);
  supplyCountAfterFunction = supplyCount(estate, &G);
  printf("supplyCount of estate after: %d\n", supplyCountAfterFunction);
  // Supply count should be reduced 2. One for this action, one for the player.
  res = assert(supplyCountBeforeFunction - 2 == supplyCountAfterFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Player choose to gain an estate card.\n");
  }
  printf("Test end: Player choose to gain an estate card.\n\n");
  
  //
  // SupplyCount of estate card greater then 0.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: SupplyCount of estate card greater then 0.\n");
  printf("Test start: SupplyCount of estate card greater then 0.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  player = 0;
  G.handCount[player] = 5; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 5);
  // G.hand[0] = estate;
  G.hand[player][0] = estate;
  G.hand[player][1] = estate;
  G.hand[player][2] = estate;
  G.supplyCount[estate] = 1;//Decrement estates
  // call the refactored function: The game should over when supplyCount of estate equals 0.
  supplyCountBeforeFunction = supplyCount(estate, &G);
  printf("supplyCount of estate before: %d\n", supplyCountBeforeFunction);
  actionBaron(&G, player, 1);
  supplyCountAfterFunction = supplyCount(estate, &G);
  printf("supplyCount of estate after: %d\n", supplyCountAfterFunction);
  // verify that your asserts pass, for the bugs your asserts may fail
  res = assert(isGameOver(&G) == 0, TEST_OTHER); // check a condition
  if (res) {
    printf("SupplyCount of estate card greater then 0.\n");
  }
  printf("Test end: SupplyCount of estate card greater then 0.\n\n");
  
  //
  // Game over
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Game over.\n");
  printf("Test start: Game over.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  player = 0;
  G.handCount[player] = 5; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 5);
  // G.hand[0] = estate;
  G.hand[player][0] = estate;
  G.hand[player][1] = estate;
  G.hand[player][2] = estate;
  G.supplyCount[estate] = 1;//Decrement estates
  // call the refactored function: The game should over when supplyCount of estate equals 0.
  supplyCountBeforeFunction = supplyCount(estate, &G);
  printf("supplyCount of estate before: %d\n", supplyCountBeforeFunction);
  actionBaron(&G, player, 0);
  supplyCountAfterFunction = supplyCount(estate, &G);
  printf("supplyCount of estate after: %d\n", supplyCountAfterFunction);
  // verify that your asserts pass, for the bugs your asserts may fail
  res = assert(isGameOver(&G), TEST_OTHER); // check a condition
  if (res) {
    printf("Game over.\n");
  }
  printf("Test end: Game over.\n\n");

  printf("Test completed!\n");
  return 0;
}
