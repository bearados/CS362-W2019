//author: Jessica Adams
//date:2/8/2019
//randomtestadventure.c: test of adventuref function 

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
	int i = 0, j = 0, num = 0, drawnTreasure = 0, numCards = 30, numTCards = 0, Discard = 1;
	int temphand[500];
	srand((unsigned)time(0));
	for(j = 0; j < 10; j++){
		//start new game
		struct gameState* state = newGame();
        	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};
        	initializeGame(2, k, 6, state);
		numTCards = 0;
		state->handCount[0] = 0;
		//create a full deck with 30 random cards
		state->deckCount[0] = 30;
		for(i = 0; i < 30; i++){
			num = 1 + (rand() % 26);
			state->deck[0][i] = num;
			if(num > 3 && num < 7){//if treasure cards are added
				numTCards++;
				if(numTCards == 2 && i == 1){
					Discard = 0;
				}
			}
		}
		
	//call adventurer		
		adventurer_card(temphand, state, 0);	
	//test results
		printf("Test results for random test %d:\n", j+1);
		if(numTCards == 0){
			 asserttrue(state->handCount[0] == 0);
		}
		else{
			asserttrue(state->handCount[0] < 3);
		}
		if(Discard == 1){
			asserttrue(state->discardCount[0] > 0);
		}
		else if(Discard == 0){
			asserttrue(state->discardCount[0] == 0);
		}
		free(state);
	}
	return 0;	
}
