//author: Jessica Adams
//date:2/8/2019
//unittest1: test of getcost function 

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);


int main() {
	printf("testing getcost() function...\n");
	int costArray[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
	int i = 0, cost = 0;
	for(i = 0; i < 27; i++){
		cost = getCost(i);
		asserttrue(cost == costArray[i]);
	}
	return 0;	
}
