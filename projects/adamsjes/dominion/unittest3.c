//author: Jessica Adams
//date:2/8/2019
//unittest3.c : tests function updateCoins()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rngs.h"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
	printf("testing updateCoins()...\n");
	struct gameState* state = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	int i = 0;
	initializeGame(2, k, 5, state);
	for (i = 0; i < 5; i++){
		state->hand[0][i] = 4;
	}
	printf("current hand: ");
	for (i = 0; i < state->handCount[0]; i++){
		printf("%d ", state->hand[0][i]);
	}
	printf("\n");
	updateCoins(0, state, 0);
	asserttrue(state->coins == 5);
	
	for (i = 0; i < 5; i++){
                state->hand[0][i] = 1;
        }
	printf("current hand: ");
        for (i = 0; i < state->handCount[0]; i++){
                printf("%d ", state->hand[0][i]);
        }
        printf("\n");
        updateCoins(0, state, 0);
        asserttrue(state->coins == 0);
	
	for (i = 0; i < 5; i++){
                state->hand[0][i] = 5;
        }
        printf("current hand: ");
        for (i = 0; i < state->handCount[0]; i++){
                printf("%d ", state->hand[0][i]);
        }
        printf("\n");
        updateCoins(0, state, 0);
        asserttrue(state->coins == 10);
	for (i = 0; i < 5; i++){
                state->hand[0][i] = 6;
        }
        printf("current hand: ");
        for (i = 0; i < state->handCount[0]; i++){
                printf("%d ", state->hand[0][i]);
        }
        printf("\n");
	printf("bonus = 1\n");
        updateCoins(0, state, 1);
        asserttrue(state->coins == 16);

	return 0;
}
