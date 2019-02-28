//author: Jessica Adams
//date:2/27/2019
//randomtestcard2.c: random test of smithy card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rngs.h"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
	srand((unsigned)time(0));
	printf("Beginning random testing of council room card...\n");
	struct gameState* state = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	int i = 0, j = 0, numCards;
	//test gernerator
	for(j = 0; j < 30; j++){
		//create new game
		struct gameState* state = newGame();
		int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	                sea_hag, tribute, smithy};
		
		numCards = 10 + (rand() % 21); //number of cards in deck, at least 10 less than 30
		initializeGame(2, k, 6, state);
		state->deckCount[0] = numCards;
		state->handCount[0] = 1;
		state->discardCount[0] = 0;
		
		for(i = 0; i < numCards; i++){
			state->deck[0][i] = 1 + (rand() % 27);
		}
		
		//initialize hand for player holding smithy card (player 13)
		state->hand[0][0] = 13;
		//call smithy
		smithyF(0, state, 0); //player #, state, handpos
		//assert statements
		printf("Results of test %d:\n", j+1);
		asserttrue(state->handCount[0] == 3);
		free(state);
	}
	return 0;
	
}


