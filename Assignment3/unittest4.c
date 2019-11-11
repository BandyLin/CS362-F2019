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
  printf("Begin Testing actionTribute():\n");
  // //
  // // Other player don't gain card.
  // //
  // printf("---------------------------------------------------------------------------------\n");
  // printf("Test bug: Other player don't gain card.\n");
  // printf("Test start: Other player don't gain card.\n");
  // memset(&G, 0, sizeof(struct gameState)); // set the game state
  // int r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  // int player = 0;
  // int otherPlayer = 1;
  // G.handCount[player] = 3; // set other variables
  // memcpy(G.hand[player], coppers, sizeof(int) * 3);
  // G.hand[player][0] = ambassador;
  // G.hand[player][1] = minion;
  // G.hand[player][2] = minion;
  // G.handCount[otherPlayer] = 2;
  // memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  // // call the refactored function: The game should over when supplyCount of estate equals 0.
  // int otherHandCountBeforeFunction = G.handCount[otherPlayer];
  // printf("Other player hand Count before: %d\n", otherHandCountBeforeFunction);
  // actionAmbassador(&G, player, 1, 1, 0);
  // int otherHandCountAfterFunction = G.handCount[otherPlayer];
  // printf("Other player hand Count after: %d\n", otherHandCountAfterFunction);
  // // verify that your asserts pass, for the bugs your asserts may fail
  // int res = assert(otherHandCountAfterFunction == 4, TEST_BUG); // check a condition
  // if (res) {
  //   printf("Other player don't gain card.\n");
  // }
  // printf("Test end: Other player don't gain card.\n\n");

  //
  // Next player have only Action card, should add action number.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test bug: Next player have only Action card, should add action number.\n");
  printf("Test begin: Next player have only Action card, should add action number.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  int player = 0;
  int otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.hand[player][2] = minion;
  G.handCount[otherPlayer] = 2;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  G.hand[otherPlayer][0] = ambassador;
  G.hand[otherPlayer][1] = ambassador;
  int numActionsBeforeFunction = G.numActions;
  printf("Action Count before: %d\n", numActionsBeforeFunction);
  actionTribute(&G, player, otherPlayer);
  int numActionsAfterFunction = G.numActions;
  printf("Action Count after: %d\n", numActionsAfterFunction);
  int res = assert(numActionsAfterFunction == numActionsBeforeFunction, TEST_BUG); // check a condition
  if (res) {
    printf("Next player have only Action card, should add action number.\n");
  }
  printf("Test end: Next player have only Action card, should add action number.\n\n");
  
  //
  // Next player have only Treasure card, should add $2.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Next player have only Treasure card, should add $2.\n");
  printf("Test begin: Next player have only Treasure card, should add $2.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.hand[player][2] = minion;
  G.handCount[otherPlayer] = 2;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  G.hand[player][0] = copper;
  G.hand[player][1] = copper;
  int coinCountBeforeFunction = G.coins;
  printf("Coin Count before: %d\n", coinCountBeforeFunction);
  actionTribute(&G, player, otherPlayer);
  int coinCountAfterFunction = G.coins;
  printf("Coin Count after: %d\n", coinCountAfterFunction);
  res = assert(coinCountBeforeFunction + 2 == coinCountAfterFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Next player have only Treasure card, should add $2.\n");
  }
  printf("Test end: Next player have only Treasure card, should add $2.\n\n");
  
  //
  // Next player have only Victory card, should add 2 cards.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Next player have only Victory card, should add 2 cards.\n");
  printf("Test begin: Next player have only Victory card, should add 2 cards.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.hand[player][2] = minion;
  G.handCount[otherPlayer] = 2;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  G.hand[player][0] = copper;
  G.hand[player][1] = copper;
  int handCountBeforeFunction = G.handCount[otherPlayer];
  printf("Hand Count before: %d\n", handCountBeforeFunction);
  actionTribute(&G, player, otherPlayer);
  int handCountAfterFunction = G.handCount[otherPlayer];
  printf("Hand Count after: %d\n", handCountAfterFunction);
  res = assert(handCountBeforeFunction + 2 == handCountAfterFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Next player have only Victory card, should add 2 cards.\n");
  }
  printf("Test end: Next player have only Victory card, should add 2 cards.\n");
  
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
