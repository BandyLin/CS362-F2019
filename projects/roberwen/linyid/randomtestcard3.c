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
  printf("Begin Testing actionTribute():\n");
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
  // actionTribute(&G, player, otherPlayer);
  tributeEffect(player, otherPlayer, &G);
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
  // actionTribute(&G, player, otherPlayer);
  tributeEffect(player, otherPlayer, &G);
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
  // actionTribute(&G, player, otherPlayer);
  tributeEffect(player, otherPlayer, &G);
  int handCountAfterFunction = G.handCount[otherPlayer];
  printf("Hand Count after: %d\n", handCountAfterFunction);
  res = assert(handCountBeforeFunction + 2 == handCountAfterFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Next player have only Victory card, should add 2 cards.\n");
  }
  printf("Test end: Next player have only Victory card, should add 2 cards.\n");

  //
  // Discard count == 0, deck count == 1.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Discard count == 0, deck count == 1.\n");
  printf("Test begin: Discard count == 0, deck count == 1.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.hand[player][2] = minion;
  G.handCount[otherPlayer] = 1;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 1);
  G.hand[player][0] = copper;
  
  G.discardCount[otherPlayer] = 0;
  G.deckCount[otherPlayer] = 1;

  handCountBeforeFunction = G.handCount[otherPlayer];
  printf("Hand Count before: %d\n", handCountBeforeFunction);
  // actionTribute(&G, player, otherPlayer);
  tributeEffect(player, otherPlayer, &G);
  handCountAfterFunction = G.handCount[otherPlayer];
  printf("Hand Count after: %d\n", handCountAfterFunction);
  res = assert(handCountBeforeFunction + 2 == handCountAfterFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Discard count == 0, deck count == 1.\n");
  }
  printf("Discard count == 0, deck count == 1.\n");

  //
  // Discard count == 1, deck count == 0.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Discard count == 1, deck count == 0.\n");
  printf("Test begin: Discard count == 1, deck count == 0.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.hand[player][2] = minion;
  G.handCount[otherPlayer] = 1;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 1);
  G.hand[player][0] = copper;
  
  G.discardCount[otherPlayer] = 1;
  G.deckCount[otherPlayer] = 0;

  handCountBeforeFunction = G.handCount[otherPlayer];
  printf("Hand Count before: %d\n", handCountBeforeFunction);
  // actionTribute(&G, player, otherPlayer);
  tributeEffect(player, otherPlayer, &G);
  handCountAfterFunction = G.handCount[otherPlayer];
  printf("Hand Count after: %d\n", handCountAfterFunction);
  res = assert(handCountBeforeFunction + 2 == handCountAfterFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Discard count == 1, deck count == 0.\n");
  }
  printf("Discard count == 1, deck count == 0.\n");
  
  //
  // Discard count > 1, deck count == 0.
  //
  printf("---------------------------------------------------------------------------------\n");
  printf("Test for coverage: Discard count > 1, deck count == 0.\n");
  printf("Test begin: Discard count > 1, deck count == 0.\n");
  memset(&G, 0, sizeof(struct gameState)); // set the game state
  player = 0;
  otherPlayer = 1;
  G.handCount[player] = 3; // set other variables
  memcpy(G.hand[player], coppers, sizeof(int) * 3);
  G.hand[player][0] = ambassador;
  G.hand[player][1] = minion;
  G.hand[player][2] = minion;
  G.handCount[otherPlayer] = 1;
  memcpy(G.hand[otherPlayer], coppers, sizeof(int) * 1);
  G.hand[player][0] = copper;
  
  G.discardCount[otherPlayer] = 2;
  G.deckCount[otherPlayer] = 0;

  handCountBeforeFunction = G.handCount[otherPlayer];
  printf("Hand Count before: %d\n", handCountBeforeFunction);
  // actionTribute(&G, player, otherPlayer);
  tributeEffect(player, otherPlayer, &G);
  handCountAfterFunction = G.handCount[otherPlayer];
  printf("Hand Count after: %d\n", handCountAfterFunction);
  res = assert(handCountBeforeFunction + 2 == handCountAfterFunction, TEST_OTHER); // check a condition
  if (res) {
    printf("Discard count > 1, deck count == 0.\n");
  }
  printf("Discard count > 1, deck count == 0.\n");
  printf("Test completed!\n");
  return 0;
}
