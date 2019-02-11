//author: Jessica Adams
//date:2/8/2019
//unittest4.c : test function scorefor()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rngs.h"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
	printf("testing scoreFor() function...\n");
	struct gameState* state = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	int i = 0;
	initializeGame(2, k, 6, state);
	int cardArray[6] = {0, 10, 2, 3, 16, 1};
	state->deckCount[0] = 6;
	state->handCount[0] = 6;
	state->discardCount[0] = 6;
	for(i = 0; i < 6; i++){
		state->deck[0][i] = cardArray[i];
		state->hand[0][i] = cardArray[i];
		state->discard[0][i] = cardArray[i];
	}
	printf("score = %d\n", scoreFor(0, state));
	asserttrue(scoreFor(0, state) == 33);
	return 0;
	
}
