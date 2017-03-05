#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "sorting.h"
#include<time.h>


int main(int argc, char ** argv)
{

  // clock_t IOstart,IOend,Sortstart,Sortend;
    long* Array;
    //  double IO_t, Sort_t;
    //double NC = 0;
    //double *N_Comp = &NC;
    //double NM = 0;
    //double *N_Move = &NM;
    int a = 0; 
    int *Size = &a;
    char* Filename = argv[1];
    
    //IOstart = clock();

    Array = Load_File(Filename, Size);
    Save_Seq1(argv[2],*Size);
    Save_Seq2(argv[3],*Size);







    /*
     if(Array == NULL)
     {
       return EXIT_FAILURE;
     }
     Sortstart = clock();
   if(argv[1][0] == '1')
   {
     if(argv[2][0] == 'i')
	 {
        Shell_Insertion_Sort_Seq1(Array,*Size, N_Comp, N_Move);
	 }
   	 else if(argv[2][0] == 'b')
	 {
        Shell_Bubble_Sort_Seq1(Array, *Size,N_Comp, N_Move);
	 }
     else{return EXIT_FAILURE;}
     Print_Seq_1(argv[4], *Size);
   }
   else if(argv[1][0] == '2')
   {
     if(argv[2][0] == 'i')
	 {
        Shell_Insertion_Sort_Seq2(Array, *Size, N_Comp, N_Move);
	 }
	 else if(argv[2][0] == 'b')
	 {
        Shell_Bubble_Sort_Seq2(Array, *Size, N_Comp, N_Move);
	 }
	 else{return EXIT_FAILURE;}
     Print_Seq_2(argv[4], *Size);
   }

   Sortend = clock();   

   Save_File(argv[5], Array, *Size);


   IOend = clock();

   IO_t = (double)(IOend - IOstart)/ CLOCKS_PER_SEC;
   Sort_t = (double)(Sortend - Sortstart)/ CLOCKS_PER_SEC;
    */
   //printf("Number of comparisons: %le\nNumber of moves: %le\nI/O time [sec]: %le\nSorting time [sec]:%le",*N_Comp,*N_Move,IO_t,Sort_t);
     free(Array);
   return EXIT_SUCCESS;
}






