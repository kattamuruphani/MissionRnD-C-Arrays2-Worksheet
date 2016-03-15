/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<string.h>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct elems{
	int date_pos[4];
};


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int len1, len2,inc;
	struct elems *first, *second;
	int i, j, k,len[2];
	int *common;
	struct transaction *common_elems;

	if (A==NULL || B==NULL)
		return NULL;
	else{
		len[0] = ALen;
		len[1] = BLen;
		if (ALen < BLen){
			common = (int*)malloc(sizeof(int)*ALen);
		}
		else{
			common = (int*)malloc(sizeof(int)*BLen);
		}
		common[0] = -1;
		first = (struct elems*)malloc(sizeof(struct elems)*ALen);
		second = (struct elems*)malloc(sizeof(struct elems)*BLen);
		for (i = 0; i < ALen; i++){
			k = strlen(A[i].date)-1;
			inc = 1;
			first[i].date_pos[0] = 0;
			for (j = k ; j >= k-3; j--){
				first[i].date_pos[0] += (A[i].date[j] - 48)* inc;
				inc *= 10;
			}
			k -= 4;
			first[i].date_pos[1] = 0;
			inc = 1;
			for (j -= 1; j >= k - 2; j--){
				first[i].date_pos[1] += (A[i].date[j] - 48)*inc;
				inc *= 10;
			}
			k -= 3;
			first[i].date_pos[2] = 0;
			inc = 1;
			for (j = j - 1; j >= k - 2; j--){
				first[i].date_pos[2] += (A[i].date[j] - 48)*inc;
			}
			first[i].date_pos[3] = i;
		}
		
		
		
		for (i = 0; i < BLen; i++){
			k = strlen(B[i].date) - 1;
			inc = 1;
			second[i].date_pos[0] = 0;
			for (j = k; j >= k - 3; j--){
				second[i].date_pos[0] += (B[i].date[j] - 48)* inc;
				inc *= 10;
			}
			k -= 4;
			second[i].date_pos[1] = 0;
			inc = 1;
			for (j -= 1; j >= k - 2; j--){
				second[i].date_pos[1] += (B[i].date[j] - 48)*inc;
				inc *= 10;
			}
			k -= 3;
			second[i].date_pos[2] = 0;
			inc = 1;
			for (j = j - 1; j >= k - 2; j--){
				second[i].date_pos[2] += (B[i].date[j] - 48)*inc;
			}
			second[i].date_pos[3] = i;
		}
		int x=0;
		for (i = 0; i <= ALen - 1; i++){

			for (j = 0; j <= BLen - 1; j++){
			
				if (first[i].date_pos[0] == second[j].date_pos[0]){
					
					if (first[i].date_pos[1] == second[j].date_pos[1]){
					
						if (first[i].date_pos[2] == second[j].date_pos[2]){
							common[x] = first[i].date_pos[3];
							x++;
							i++;
						}
				
					}
				
				}
			
			}
		}
		if (common[0] == -1){
			return NULL;
		}
		else{
			common_elems = (struct transaction*)malloc(sizeof(struct transaction)*x);
			for (i = 0; i <= x - 1; i++){
				common_elems[i] = A[common[i]];
			}
			return common_elems;
		}

	}
}


int length(struct transaction *temp){
	return sizeof(temp) / sizeof(struct transaction);
}