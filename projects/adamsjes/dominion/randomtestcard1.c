//author: Jessica Adams
//date:2/27/2019
//randomtestcard1.c: random test of council room card

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
	int i = 0, j = 0, numPlayers = 0, err = 0, r = 0, numCards;
	//test gernerator
	for(j = 0; j < 5; j++){
		//create new game
		struct gameState* state = newGame();
		int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	                sea_hag, tribute, smithy};
		
		numPlayers = 2 + (rand() % 3); //2-4 players
		numCards = 10 + (rand() % 21); //number of cards in deck, at least 10 less than 30
		initializeGame(numPlayers, k, 6, state);
		for(i = 0; i < numPlayers; i++){
			state->deckCount[i] = numCards;
			state->handCount[i] = 0;
			state->discardCount[i] = 0;
		}
		for(r = 0; r < numPlayers; r++){
			for(i = 0; i < 15; i++){
				state->deck[r][i] = 1 + (rand() % 27);
			}
		}
		//initialize hand for player holding council room card (player 0)
		state->deckCount[0]--;
		state->hand[0][0] = 8;
		state->handCount[0]++;
		//call council room in card effect funtion
		err = cardEffect(8, 0, 0, 0, state, 0, 0);
		//assert statements
		printf("Results of test %d:\n", j+1);
		for (i = 1; i < numPlayers; i++){
			asserttrue(state->handCount[i] == 1)
		}
		asserttrue(state->discardCount[0] == 1);
		asserttrue(state->handCount[0] == 4);
		asserttrue(state->numBuys == 2);
		free(state);
	}
	return 0;
	
}

