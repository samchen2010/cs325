/*
 * tokenizer.c
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */

struct TokenizerT_ {
	char* separate;
	char* ts;

};

typedef struct TokenizerT_ TokenizerT;


/*
 * TKCreate creates a new TokenizerT object for a given set of separator
 * characters (given as a string) and a token stream (given as a string).
 * 
 * TKCreate should copy the two arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate(char *separators, char *ts) {

	TokenizerT * TK;
	int length_ts = strlen(ts)+1;
	int length_separator = strlen(separators)+1;
	TK=(TokenizerT*)malloc(sizeof(TokenizerT));
	TK->separate =(char*) malloc(length_separator*sizeof(char));
	TK->ts = (char*)malloc(length_ts*sizeof(char));
	ts[length_ts-1]='\0';//after if len-1;
	TK->separate = separators;
	TK->ts = ts;

	//printf("the separator:%s \n",TK->separate);
	//printf("the tokens:%s \n",TK->ts);

  return TK;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy(TokenizerT *tk) {

	free(tk);

}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */



char *TKGetNextToken(TokenizerT *tk) {
	char* token=malloc(10);
	//char *sep=malloc(1*sizeof(char));
	//char * tschar=malloc(1*sizeof(char));
	char sep[1];
	char tschar[1];
	int i,j;
	i=0;
	while(i<9){  //i<strlen(tk->ts)+1
		tschar[0]=tk->ts[i];

		 if(isalnum(tschar[0])){
			 i++;
		 }
		 if(tschar[0]=='\0'){
			 strncpy(token, tk->ts, i);
				   strcpy(tk->ts, &tk->ts[i]);
				   //printf("zero??\n");
				   		goto out;

				//return "end";
				//break;

		 }
		 else if(!isalnum(tschar[0])){
			 if(i!=0){
			 token=malloc((i+1)*sizeof(char));
		strncpy(token, tk->ts, i);
		strcpy(tk->ts, &tk->ts[i+1]);
		goto out;
			 }
		strcpy(tk->ts, &tk->ts[i+1]);


		//printf("token:%s?\n",tk->ts);

		//goto out;
						}


	}
  out:
  return token;

}

/*
 * main will have two string arguments (in argv[1] and argv[2]).
 * The first string contains the separator characters.
 * The second string contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

/*
int main(int argc, char **argv) {


	//if(argc!=3){
		//return -1;}
	TokenizerT *newTK=TKCreate(argv[1],argv[2]);

	//TKDestroy(newTK);
int c=0;
char*out;
while( newTK->ts[0]!='\0'){
		out =TKGetNextToken(newTK);

		if(out =="end"){
			break;
		}
			printf("final is:%s?\n", out);

c++;
		}

	return 1;

}
*/
