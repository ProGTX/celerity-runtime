#pragma once

enum MPI_Datatype {
	MPI_DATATYPE_NULL,
	MPI_BYTE,
	MPI_INT,
};

enum MPI_Group {};

enum MPI_Comm {
	MPI_COMM_NULL,
	MPI_COMM_WORLD,
	MPI_COMM_TYPE_SHARED,
	MPI_BOTTOM,
};

enum MPI_Thread {
	MPI_THREAD_MULTIPLE,
};

enum MPI_info {
	MPI_INFO_NULL,
};

using MPI_Aint = int*;

enum MPI_Request { MPI_REQUEST_NULL, };

struct MPI_Status {
	size_t MPI_SOURCE;
};

enum MPI_Status_Status {
  MPI_STATUS_IGNORE,
};

enum MPI_Message {};

#define MPI_Comm_dup(...)
#define MPI_Type_free(...)
#define MPI_Comm_split_type(...)
#define MPI_Comm_rank(...)
#define MPI_Comm_size(...)
#define MPI_Comm_free(...)
#define MPI_Type_create_struct(...)
#define MPI_Type_commit(...)
#define MPI_Finalize(...)
#define MPI_Improbe(...)
#define MPI_Get_count(...)
#define MPI_Imrecv(...)
#define MPI_Test(...)
#define MPI_Isend(...)
#define MPI_Barrier(...)
#define MPI_Mrecv(...)
#define MPI_Init_thread(...)
#define MPI_Send(...)
#define MPI_Comm_group(...)
#define MPI_Comm_create(...)
#define MPI_Recv(...)
