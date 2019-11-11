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
  printf("Begin Testing actionMine():\n");
  //
  // bug: No cost check
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test bug: No cost check\n");
  printf("Test start: No cost check\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  int r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  int player = 0;
  int otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = mine;
  G.hand[player][1] = copper;
  G.hand[player][2] = copper;
  int goldSupplyBeforeFunction = supplyCount(gold, &G);
  printf("Gold supply count before: %d\n", goldSupplyBeforeFunction);
  actionMine(&G, player, 1, gold, 0);
  int goldSupplyAfterFunction = supplyCount(gold, &G);
  printf("Gold supply count after: %d\n", goldSupplyAfterFunction);
  int res = assert(goldSupplyBeforeFunction - 1 == goldSupplyAfterFunction, TEST_BUG); // check a condition
  if (res) {
    printf("No cost check. Gain a card gold, which cost 6.\n");
  }
  printf("Test end: No cost check.\n\n");
  
  //
  // bug: range check for choice2 error
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test bug: No cost check\n");
  printf("Test start: No cost check\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = mine;
  G.hand[player][1] = copper;
  G.hand[player][2] = copper;
  int great_hallSupplyBeforeFunction = supplyCount(great_hall, &G);
  printf("Great_hall supply count before: %d\n", great_hallSupplyBeforeFunction);
  actionMine(&G, player, 1, great_hall, 0);
  int great_hallSupplyAfterFunction = supplyCount(great_hall, &G);
  printf("Great_hall supply count after: %d\n", great_hallSupplyBeforeFunction);
  res = assert(great_hallSupplyBeforeFunction - 1 == great_hallSupplyBeforeFunction, TEST_BUG); // check a condition
  if (res) {
    printf("Range check for choice2 error. Gain a card great_hall.\n");
  }
  printf("Test end: Range check for choice2 error.\n\n");

  //
  // Choice1 out of range.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Choice1 out of range.\n");
  printf("Test begin: Choice1 out of range.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = mine;
  G.hand[player][1] = gardens;
  G.hand[player][2] = copper;
  int res_val = actionMine(&G, player, 1, gold, 0);
  res = assert(res_val == -1, TEST_OTHER); // check a condition
  if (res) {
    printf("Choice1 out of range.\n");
  }
  printf("Test end: Choice1 out of range.\n\n");
  
  // //
  // // choice1 == handPos
  // //
  // printf("---------------------------------------------------------------------------------\n");
  // printf("Test for coverage: choice1 == handPos\n");
  // printf("Test begin: choice1 == handPos\n");
  // memset(&G, 0, sizeof(struct gameState)); // set the game state
  // player = 0;
  // otherPlayer = 1;
  // G.handCount[player] = 3; // set other variables
  // memcpy(G.hand[player], coppers, sizeof(int) * 3);
  // G.hand[player][0] = ambassador;
  // G.hand[player][1] = minion;
  // G.hand[player][2] = minion;
  // G.handCount[otherPlayer] = 2;
  // memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  // res_val = actionAmbassador(&G, player, 0, 5, 0);
  // res = assert(res_val == -1, TEST_OTHER); // check a condition
  // if (res) {
  //   printf("choice1 == handPos\n");
  // }
  // printf("Test end: choice1 == handPos\n\n");
  
  // //
  // // Hand count of chosen cards is less then number to discard.
  // //
  // printf("---------------------------------------------------------------------------------\n");
  // printf("Test for coverage: Hand count of chosen cards is less then number to discard.\n");
  // printf("Test begin: Hand count of chosen cards is less then number to discard.\n");
  // memset(&G, 0, sizeof(struct gameState)); // set the game state
  // player = 0;
  // otherPlayer = 1;
  // G.handCount[player] = 3; // set other variables
  // memcpy(G.hand[player], coppers, sizeof(int) * 3);
  // G.hand[player][0] = ambassador;
  // G.hand[player][1] = minion;
  // G.handCount[otherPlayer] = 2;
  // memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  // res_val = actionAmbassador(&G, player, 1, 2, 0);
  // res = assert(res_val == -1, TEST_OTHER); // check a condition
  // if (res) {
  //   printf("Hand count of chosen cards is less then number to discard.\n");
  // }
  // printf("Test end: Hand count of chosen cards is less then number to discard.\n\n");
  printf("Test completed!\n");
  return 0;
}
