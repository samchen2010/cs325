/*
 * sorted-list.c
 */
// change 3

change 4

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "sorted-list.h"
 #include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>

//may change TKGetNextToken(filename);

			            		//read very token, insert in sorted-list,
			            	   //if token already in list, the file of the count +1.
			            		//use two/three file as test case.
			            		// then insert after node . so should be a node structiure.
			            	// and resious. the can if (the file != name) insert the name
			            		// the.

			            	//	SLInsert( list, token);
			            		//change the insert function, if already have. return 1;
			            		// insert the node of file under the token. if fund return the point node.

			         // at the end  to recoard the imformation. two loop end until null
int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}
int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	return i1 - i2;
}
int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}

/*char *fgets(char *s, int n, FILE *iop)
  {
      register int c;
      register char *cs;

      cs = s;
      while (--n > 0 && (c = getc(iop)) != EOF)
          if ((*cs++ = c) == '\n')
              break;
      *cs = '\0';
      return (c == EOF && cs == s) ? NULL : s;
  }

int getline(char *line, int max)
   {
       if (fgets(line, max, stdin) == NULL)
           return 0;
       else
           return strlen(line);
   }*/

	int read (char *filen,SortedListPtr slp){
		char *my_string;
			int nbytes = 3;
			 int bytes_read;
char *sep=" ";
			 char * token;
			 char *filecontent=malloc(1000);
			my_string = (char *) malloc (nbytes + 1);
			 FILE *fp;
		 if ((fp = fopen(filen, "r")) == NULL) {
			                  printf(" can't open:%s.\n", filen);
			                  return 1;
			              }
		 else {

			            	  fgets(filecontent, 1000, fp);
			            	  TokenizerT *tk;
			            	  tk= TKCreate(sep, filecontent);
			            //	  printf("inner file  content is:%s\n", filecontent);
			            	  int loop=0;
			            	  while( tk->ts[0]!='\0'){
			            		  //get all content of file.
loop++;
			            		token=  TKGetNextToken(tk);



			            		SLInsert(slp, token,filen);//if


			            //		  printf("inner file  token is  %s\n", token);

			            		  	// printf("file is  %d\n",bytes_read);
			            	  }

			                 fclose(fp);





			      }


	}

	static void
	list_dir (const char * dir_name,SortedListPtr slp)
	{
	    DIR * d;
	    int nu;
	    /* Open the directory specified by "dir_name". */

	    d = opendir (dir_name);

	//    SortedListIteratorPtr SLIP=SLCreateIterator(slp);

	    /* Check it was opened. */
	    if (! d) {
	        fprintf (stderr, "Cannot open directory '%s': %s\n",
	                 dir_name, strerror (nu));
	        exit (EXIT_FAILURE);
	    }
	    while (1) {
	        struct dirent * entry;
	        const char * d_name;

	        /* "Readdir" gets subsequent entries from "d". */
	        entry = readdir (d);
	        if (! entry) {
	            /* There are no more entries in this directory, so break
	               out of the while loop. */
	            break;
	        }
	        d_name = entry->d_name;
	        /* Print the name of the file and directory. */
	        //printf ("%s\n",  d_name);

	        /* See if "entry" is a subdirectory of "d". */

	        if (entry->d_type & DT_DIR) {

	            /* Check that the directory is not "d" or d's parent. */

	            if (strcmp (d_name, "..") != 0 &&
	                strcmp (d_name, ".") != 0) {
	                int path_length;
	                char path[PATH_MAX];

	                path_length = snprintf (path, PATH_MAX,
	                                        "%s/%s", dir_name, d_name);
	              //  printf ("%s\n", path);
	                if (path_length >= PATH_MAX) {
	                    fprintf (stderr, "Path length has got too long.\n");
	                    exit (EXIT_FAILURE);
	                }
	                /* Recursively call "list_dir" with the new path. */
	                list_dir (path,slp);



	            }
	        }


	        else{// begain file
	        	 int path_length;
	        		                char path[PATH_MAX];
	        		                path_length = snprintf (path, PATH_MAX,
	        		              	                                        "%s/%s", dir_name, d_name);
	        	//printf ("%s\n", path);
	        	// printf ("the file is  %s.\n",  d_name);
	        	 read(path,slp);

	        	 //  here to insert the count.
	        	 SortedListIteratorPtr SLIP=SLCreateIterator(slp);
	        	 while(1){


	        		            		  NODE *p	=malloc(sizeof(NODE*));
	        		            		  p=SLNextItem(SLIP);
	        		            		//  printf("  NODE *p	=SLNextItem(SLIP),,, %s\n",p->data);

	        		            		  if(p==NULL){break;}
	        		            		//  printf("  NODE *p	=SLNextItem(SLIP),,, %s\n",p->data);
	        		            		  NODE* first;

	        		            		  if(p->head==NULL){
	        		            			  if(p->head==NULL){
	        		            				 //printf(" p->head==NULL\n");
	        		            			 }

	        		            			 p->head= malloc(sizeof(NODE*));
	        		            					p->head= countCreate(compareInts);

	        		            			 SLInsertCount(p->head, p->temp->count,p->temp->fn);

	        		            			 if(p->head==NULL){
	        		            		//		 printf(" p->head==NULL\n");
	        		            			 }

	        		            		  }

	        		            		  else{
	        		            		//	  printf("p->head->node->fn %s\n",p->head->node->fn);
	        		            			//  printf("p->head->node->fn %s\n",p->temp->fn);
	        		            			  //printf("p->head->node->fn %d\n",p->temp->count);
	        		            			  if(strcmp(p->temp->fn,path)==0){

	        		            			  SLInsertCount(p->head, p->temp->count,p->temp->fn);}

	        		            		  }

	        		            		  p->temp->count=0;  p->temp->fn="";
	        		            		 //maybe store in structure.think about when 3th file comming.


	        		            		  //printf("p->temp->count  %d\n",p->temp->count);
	        		            		  //printf("p->temp->fn  %s\n",p->temp->fn);
	        		            		  }
	        }
	    }
	    /* After going through all the entries, close the directory. */
	    if (closedir (d)) {
	        fprintf (stderr, "Could not close '%s': %s\n",
	                 dir_name, strerror (errno));
	        exit (EXIT_FAILURE);
	    }
	}
int main(int argc, char **argv)
{
	char *filename;
	int nbytes = 10;
	 int bytes_read;
	filename = (char *) malloc (nbytes + 1);
	 FILE *fp;

	 SortedListPtr slp=SLCreate(compareStrings);


	   // list_dir ("/Users/chensiyuan2010/Documents/workspace-c/214 assign3/direct",slp);
	    list_dir (argv[1],slp);


	            		 // read(filename,slp);

	            		  /*while(1){
	            		  SortedListIteratorPtr SLIP=SLCreateIterator(slp);


	            		  NODE *p	=SLNextItem(SLIP);
	            		  if(p==NULL){break;}

	            		  NODE* first;
	            		 first= countCreate(compareInts);//maybe store in structure.think about when 3th file comming.

	            		  SLInsertCount(first, p->temp->count,p->temp->fn);

	            		  printf("p->temp->count  %d\n",p->temp->count);
	            		  printf("p->temp->fn  %s\n",p->temp->fn);
	            		  }*/
	            		  	// printf("file is  %d\n",);


	 SortedListIteratorPtr SLIP=SLCreateIterator(slp);
	 void * next; char *f; int cc; char * tok1;





							while (1) {
								//next=SLNextItem(SLIP);
						NODE *p	=SLNextItem(SLIP);
						// printf("the filename is %d\n",p->temp->count);
						//  printf("p->head %s\n",p->head->node->fn);

					if(p==NULL)
						{ break;}
						tok1=p->data;
						 printf("<list> %s\n</list>\n",tok1);

						// Index *n =malloc(sizeof(Index));

						while(1){
							//if(p->head==NULL)
							//{ printf("end????? %s\n");}

							Index *n =malloc(sizeof(Index));

							//p->head=malloc(sizeof(NODE*));//make mistake.
							// printf("p->head->node->fn %s\n",p->head->node->fn);
							if(p->head->node==NULL)
														{ break;}

							n=p->head->node;
								//	t=CountNextItem(n);


							//printf("the filename is %d\n",n->count);
							if(n==NULL)
							{ break;}
							//if(n->fn==NULL)
							//							{ printf("n is null end %s\n");break;}
						//	  printf("the filename is %s\n",n->fn);
							//  printf("the count is %d\n",n->count);
							  p->head->node=p->head->node->next;

						}


												}




}
