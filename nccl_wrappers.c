#define _GNU_SOURCE
#include "nccl_wrappers.h"
#include <stdio.h>
#include <dlfcn.h>

// Global function pointers (actual definitions)
ncclSend_t real_ncclSend = NULL;
ncclRecv_t real_ncclRecv = NULL;

void init_real_ncclSend() {
    if (real_ncclSend == NULL) {
        real_ncclSend = (ncclSend_t)dlsym(RTLD_NEXT, "ncclSend");
    }
}

void init_real_ncclRecv() {
    if (real_ncclRecv == NULL) {
        real_ncclRecv = (ncclRecv_t)dlsym(RTLD_NEXT, "ncclRecv");
    }
}

// Wrapper functions
ncclResult_t ncclSend(
    const void* sendbuff,
    size_t count,
    ncclDataType_t datatype,
    int peer,
    ncclComm_t comm,
    cudaStream_t stream
) {
    // Logic here to determine checkpointing or not
    printf("I AM WORKING!!!\n");
    init_real_ncclSend();
    return real_ncclSend(sendbuff, count, datatype, peer, comm, stream);
}

ncclResult_t ncclRecv(
    void* recvbuff,
    size_t count,
    ncclDataType_t datatype,
    int peer,
    ncclComm_t comm,
    cudaStream_t stream
) {
    // Logic here to determine checkpointing or not
    printf("I AM WORKING!!!\n");
    init_real_ncclRecv();
    return real_ncclRecv(recvbuff, count, datatype, peer, comm, stream);
}