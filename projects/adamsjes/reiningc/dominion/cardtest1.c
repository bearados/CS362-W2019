//author: Jessica Adams
//date:2/8/2019
//cardtest1.c: unit test of adventure_card function 

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);


int main() {
	printf("beginning random test of adventure function...\n");
	int i = 0, j = 0, num = 0, drawnTreasure = 0;
	int temphand[500];
	struct gameState* state = newGame();
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	initializeGame(2, k, 6, state);
	state->handCount[0] = 0;
	state->deckCount[0] = 10;
	for (i = 0; i < 10; i++) {

		if (i < 4) {//if treasure cards are added
			state->deck[0][i] = 4;
		}
		else {
			state->deck[0][i] = 1;
		}
	}

	//call adventurer		
	adventurer_card(temphand, state, 0);
	//test results
	printf("Test results for unit test:\n");
	asserttrue(state->handCount[0] == 2)
	asserttrue(state->discardCount[0] == 6)
	free(state);
	return 0;
}
