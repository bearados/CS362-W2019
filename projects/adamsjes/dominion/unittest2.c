//author: Jessica Adams
//date:2/8/2019
//unittest2.c: tests function numHandCards()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "rngs.h"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
	printf("testing numHandCards() function...\n");
	struct gameState* state;
	state = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	int err;
	err = initializeGame(2, k, 5, state);
	
	state-> handCount[0] = 5;
	state-> whoseTurn = 0;
	asserttrue(numHandCards(state) == 5);

	return 0;
}
