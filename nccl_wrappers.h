#ifndef NCCL_WRAPPERS_H
#define NCCL_WRAPPERS_H

#include <nccl.h>
#include <cuda_runtime.h>

// Function pointer type definitions
typedef ncclResult_t (*ncclSend_t)(const void*, size_t, ncclDataType_t, int, ncclComm_t, cudaStream_t);
typedef ncclResult_t (*ncclRecv_t)(void*, size_t, ncclDataType_t, int, ncclComm_t, cudaStream_t);

// Global function pointers (extern means defined elsewhere)
extern ncclSend_t real_ncclSend;
extern ncclRecv_t real_ncclRecv;

// Initialization functions
void init_real_ncclSend();
void init_real_ncclRecv();

#endif // NCCL_WRAPPERS_H