#include <stdio.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char *argv[]) {
		int rank, size;
		MPI_Init(NULL, NULL);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		printf("Hello world from process %d of %d\n", rank, size);
		sleep(2);
		MPI_Finalize();
		return 0;
}
