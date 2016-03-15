/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>


struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct elems{
	int date_pos[4];
};


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{


	int len1, len2, inc;
	struct elems *first, *second;
	int i, j, k, len[2];
	int *common;
	struct transaction *common_elems;
	int flag = 0;
	if (A == NULL || B == NULL)
		return NULL;
	else{
		len[0] = ALen;
		len[1] = BLen;
		common_elems = (struct transaction*)malloc(sizeof(struct transaction)*(ALen+BLen));
		
		first = (struct elems*)malloc(sizeof(struct elems)*ALen);
		second = (struct elems*)malloc(sizeof(struct elems)*BLen);
		for (i = 0; i < ALen; i++){
			k = strlen(A[i].date) - 1;
			inc = 1;
			first[i].date_pos[0] = 0;
			for (j = k; j >= k - 3; j--){
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
		int x = 0;
		i = 0;
		j = 0;
		while( i <= ALen - 1){
			while( j <= BLen - 1){
				
				if (first[i].date_pos[0] < second[j].date_pos[0]){
					common_elems[x] = A[i];
					i++;
				}
				else if (first[i].date_pos[0] > second[j].date_pos[0]){
					common_elems[x] = B[j];
					j++;
				}
				else{
					if (first[i].date_pos[1] < second[j].date_pos[1]){
						common_elems[x] = A[i];
						i++;
					}
					else if (first[i].date_pos[1] > second[j].date_pos[1]){
						common_elems[x] = B[j];
						j++;
					}
					else{
						if (first[i].date_pos[0] < second[j].date_pos[0]){
							common_elems[x] = A[i];
							i++;
						}
						else if (first[i].date_pos[0] > second[j].date_pos[0]){
							common_elems[x] = B[j];
							j++;
						}
						else{
							common_elems[x] = B[j];
							x++;
							common_elems[x] = A[i];
							i++;
							j++;
						}
					}
				}
				x++;
				if (i >= ALen || j >= BLen){
					flag = 1;
					break;
				}

			}
			if (flag == 1)
				break;
		}
		if (i < ALen  ){
			for (; i <= ALen - 1; i++){
				common_elems[x] = A[i];
				x++;
			}
		}
		else if (j < BLen ){
			for (; j <= BLen - 1; j++){
				common_elems[x] = B[j];
				x++;
			}
		}
		return common_elems;
	}
}