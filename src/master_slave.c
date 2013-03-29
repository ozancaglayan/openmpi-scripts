#include <stdio.h>
#include <mpi.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
		int num_procs, rank, namelength;
		char processor_name[MPI_MAX_PROCESSOR_NAME];

		MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Get_processor_name(processor_name, &namelength);

		switch (rank) {
				case 0:
						printf("[%02d/%02d %s]: I am the master\n", rank+1, num_procs, processor_name);
						break;
				default:
						printf("[%02d/%02d %s]: I am a slave\n", rank+1, num_procs, processor_name);
						break;
		}

		MPI_Finalize();
		return 0;
}



