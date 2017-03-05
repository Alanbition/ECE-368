#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
void Save_Seq1(char *Filename, int N);
void Save_Seq2(char *Filename, int N);

long* Load_File(char *Filename, int *Size)
{
  FILE *fptr= fopen(Filename, "r");
  int i;
  long* Array = NULL;
  int Sizew = 0;
  if(fptr == NULL)
  {return NULL;}
  fseek(fptr,0, SEEK_SET);
  fscanf(fptr, "%d", &Sizew);
  Array = malloc(sizeof(long)* Sizew);
  for(i=0;i<Sizew;i++)
  {fscanf(fptr, "%ld", &(Array[i])); 
    (*Size)++;}
 fclose(fptr);
 return Array;
}

int Save_File(char *Filename, long *Array, int Size)
{
 FILE *fptr;
 int i;
 fptr = fopen(Filename, "w");
 fprintf(fptr, "%d", Size);
 fputc('\n',fptr);
 for(i=0;i<Size;i++)
 {
  fprintf(fptr, "%ld\n", Array[i]);
 }
 fclose(fptr);
 return i;
}

void Improved_Bubble_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
  int End=Size;
  int ind = 0;
  while(End>1)
  {
    End = End/1.3;
    if(End == 9 || End == 10)
    {End = 11;}
    ind++;
  }
  int SeqArr[ind-1];
  ind = 0;
  End = Size;
  int q;
  int k;
  int temp;
  int i;
  int j;
 while(End>1)
  {
        End = End/1.3;
	if(End == 9 || End == 10)
	{End = 11;}
	SeqArr[ind] = End;
        ind++;
  }
  for(q=0;q<ind;q++)
  {
    k = SeqArr[q];
        for(j = k;j < (Size);j++)
	{
          for(i = j- k; i >=0; i = i - k)
          {
              (*N_Comp)++;
		  if(Array[k+i] >= Array[i])                   
		    break;
		  else
		  {
		   temp = Array[i];
                     (*N_Move)++;
		   Array[i] = Array[i+k];
                     (*N_Move)++;
		   Array[k+i] = temp;
                     (*N_Move)++;
	      }
	   } 
       }
   }
}
void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
  
  int ind = 0;
  int q = 0;
  int k;
  int temp;
  int j = 0;
  int i = 1;
  int resold[Size];
  resold[0] = 1;
  for (i=1;i<Size;i++)
  resold[i]=0;
  i=1;
  int p2 = 0;
  int p3 = 0;
  int u2 = 0;
  int u3 = 0;
     while(resold[i-1] < Size)
     {
       if(resold[p2]*2 == resold[i-1])
	  {p2++;}
	if(resold[p3]*3 == resold[i-1])
	  {p3++;}        
	   u2 = resold[p2] *2;
           u3 = resold[p3] *3;
       if(u2<u3)
	  {p2++;
           resold[i] = u2;}
	else
	  {p3++;
	   resold[i] = u3;}
	  i++;
      }
        ind=i;
 for(q=ind-2;q>=0;q--)
  {
    k = resold[q];
    for(j = k;j < (Size);j++)
	{
	   temp = Array[j];
           (*N_Move)++;
	   i=j;
	   if(i>=k)
	     (*N_Comp)++;
	   while((i>=k)&&(Array[i-k] > temp))
           {Array[i] = Array[i-k];
           (*N_Move)++;
	   i = i-k;}
      Array[i] = temp;
      (*N_Move)++;} 
     }
}

void Save_Seq2(char *Filename, int N)
{
  FILE* fptr;
  fptr = fopen(Filename, "w");
  int End = N;
  int ind = 0;
  fprintf(fptr,"%d\n\n",0);
  while(End>1)
  {
    End = End/1.3;
	if(End == 9 || End == 10)
	{End = 11;}
    fprintf(fptr, "%d\n", End);
    ind++;
  }
  fseek(fptr,0, SEEK_SET);
  fprintf(fptr,"%d\n",ind);
 fclose(fptr);
}

void Save_Seq1(char *Filename, int N)
{
  FILE* fptr;
  fptr = fopen(Filename, "w");
  int i = 1;
  int resold[N];
  resold[0] = 1;
  for (i=1;i<N;i++)
  resold[i]=0;
  i=1;
  int p2 = 0;
  int p3 = 0;
  int u2 = 0;
  int u3 = 0;
  fprintf(fptr, "%d\n\n", 0);
     while(resold[i-1] < N)
     {
       if(resold[p2]*2 == resold[i-1])
	  {p2++;}
	if(resold[p3]*3 == resold[i-1])
	  {p3++;}        
	   u2 = resold[p2] *2;
           u3 = resold[p3] *3;
       if(u2<u3)
	  {p2++;
	    resold[i] = u2;}
	else
	  {p3++;
	   resold[i] = u3;}
         fprintf(fptr, "%d\n", resold[i-1]);
	  i++;
     }
     fseek(fptr,0,SEEK_SET);
     fprintf(fptr, "%d", i-1);
   fclose(fptr);
}

