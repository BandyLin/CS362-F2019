#include "dominion.h"
#include "card_effects.h"
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
  printf("Begin Testing actionMinion():\n");
  //
  // Redraw
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test bug:Redraw\n");
  printf("Test start: When player choose to discard hand, other player with no more then 4 cards in hand should not discards their hand and draws 4 cards.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  int r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  int player = 0;
  int otherPlayer = 1;
  G.handCount[player] = 1; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 1);
  G.hand[player][0] = minion;
  G.handCount[otherPlayer] = 2;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  // call the refactored function: The game should over when supplyCount of estate equals 0.
  int otherHandCountBeforeFunction = G.handCount[otherPlayer];
  printf("Other player hand Count before: %d\n", otherHandCountBeforeFunction);
  // actionMinion(&G, player, 0, 1, 0);
  minionEffect(player, &G, 0, 0, 1);
  int otherHandCountAfterFunction = G.handCount[otherPlayer];
  printf("Other player hand Count after: %d\n", otherHandCountAfterFunction);
  // verify that your asserts pass, for the bugs your asserts may fail
  int res = assert(otherHandCountAfterFunction == 4, TEST_BUG); // check a condition
  if (res) {
    printf("Other player redraw 4 cards.\n");
  }
  printf("Test end: When player choose to discard hand, other player with no more then 4 cards in hand should not discards their hand and draws 4 cards.\n");

  //
  // Player choose to gain $2.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Player choose to gain $2.\n");
  printf("Test begin: Player choose to gain $2.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game
  player = 0;
  G.handCount[player] = 1; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 1);
  // call the refactored function: The game should over when supplyCount of estate equals 0.
  int coinCountBeforeFunction = G.coins;
  printf("Coin count before: %d\n", coinCountBeforeFunction);
  // actionMinion(&G, player, 1, 0, 0);
  minionEffect(player, &G, 0, 1, 0);
  int coinCountAfterFunction = G.coins;
  printf("Coin count after: %d\n", coinCountAfterFunction);
  res = assert(coinCountAfterFunction - 2 == coinCountBeforeFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Player gain $2.\n");
  }
  printf("Test end: Player choose to gain $2.\n\n");
  printf("Test completed!\n");
  return 0;
}
