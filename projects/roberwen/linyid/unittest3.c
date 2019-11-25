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
  printf("Begin Testing actionAmbassador():\n");
  //
  // Other player don't gain card.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test bug: Other player don't gain card.\n");
  printf("Test start: Other player don't gain card.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  int r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  int player = 0;
  int otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.hand[player][2] = minion;
  G.handCount[otherPlayer] = 2;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  // call the refactored function: The game should over when supplyCount of estate equals 0.
  int otherHandCountBeforeFunction = G.handCount[otherPlayer];
  printf("Other player hand Count before: %d\n", otherHandCountBeforeFunction);
  // actionAmbassador(&G, player, 1, 1, 0);
  ambassadorEffect(player, &G, 0, 1, 1);
  int otherHandCountAfterFunction = G.handCount[otherPlayer];
  printf("Other player hand Count after: %d\n", otherHandCountAfterFunction);
  // verify that your asserts pass, for the bugs your asserts may fail
  int res = assert(otherHandCountAfterFunction == 4, TEST_BUG); // check a condition
  if (res) {
    printf("Other player don't gain card.\n");
  }
  printf("Test end: Other player don't gain card.\n\n");
  
  // //
  // // should consider the condition when the choice2 equals to 0
  // //
  // printf("---------------------------------------------------------------------------------\n");
  // printf("Test bug: Should consider the condition when the choice2 equals to 0.\n");
  // printf("Test start: Should consider the condition when the choice2 equals to 0.\n");
  // memset(&G, 0, sizeof(struct gameState)); // set the game state
  // r = initializeGame(2, k, (unsigned)time(NULL), &G); // initialize a new game

  // player = 0;
  // otherPlayer = 1;
  // G.handCount[player] = 3; // set other variables
  // memcpy(G.hand[player], coppers, sizeof(int) * 3);
  // G.hand[player][0] = ambassador;
  // G.hand[player][1] = minion;
  // G.hand[player][2] = minion;
  // G.handCount[otherPlayer] = 2;
  // memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  // int res_val = actionAmbassador(&G, player, 1, 0, 0);
  // res = assert(res_val == -1, TEST_BUG); // check a condition
  // if (res) {
  //   printf("Should consider the condition when the choice2 equals to 0.\n");
  // }
  // printf("Test end: Should consider the condition when the choice2 equals to 0.\n\n");

  //
  // Choice2 out of range.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Choice2 out of range.\n");
  printf("Test begin: Choice2 out of range.\n");
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
  // int res_val = actionAmbassador(&G, player, 1, 5, 0);
  int res_val = ambassadorEffect(player, &G, 0, 1, 5);
  res = assert(res_val == -1, TEST_OTHER); // check a condition
  if (res) {
    printf("Choice2 out of range.\n");
  }
  printf("Test end: Choice2 out of range.\n\n");
  
  //
  // choice1 == handPos
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: choice1 == handPos\n");
  printf("Test begin: choice1 == handPos\n");
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
  // res_val = actionAmbassador(&G, player, 0, 5, 0);
  res_val = ambassadorEffect(player, &G, 0, 0, 5);
  res = assert(res_val == -1, TEST_OTHER); // check a condition
  if (res) {
    printf("choice1 == handPos\n");
  }
  printf("Test end: choice1 == handPos\n\n");
  
  //
  // Hand count of chosen cards is less then number to discard.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Hand count of chosen cards is less then number to discard.\n");
  printf("Test begin: Hand count of chosen cards is less then number to discard.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.handCount[otherPlayer] = 2;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 2);
  // res_val = actionAmbassador(&G, player, 1, 2, 0);
  res_val = ambassadorEffect(player, &G, 0, 1, 2);
  res = assert(res_val == -1, TEST_OTHER); // check a condition
  if (res) {
    printf("Hand count of chosen cards is less then number to discard.\n");
  }
  printf("Test end: Hand count of chosen cards is less then number to discard.\n\n");
  printf("Test completed!\n");
  return 0;
}
