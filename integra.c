
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
  int n, /* number of intervals */
    rank, /* rank of the MPI process */
    size, /* number of processes */
    i, /* variable for the loop */
    len; /* name of the process */

  myfile.open ("sample.dat");
  
 


  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  int N=10;
  double x[N];
  x[0] = 0;
  int s;
  for (s=1; s<N; s++)
    {
      x[s]= x[s-1] + 1/N;

    }

  int xmax = 1;
  int xmin = 0;

  int j;
  double suma = 0;
  for(j=0; j<N; j++)
    {
      suma = suma + exp(x[j]); 
    }
  suma = ((xmax-xmin)/N)*suma;

  myfile << suma;
 


  MPI_Finalize();
   myfile.close();
}
