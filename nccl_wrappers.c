#include <nccl.h>
#include <stdio.h>

#pragma weak ncclRecv = PncclRecv
ncclResult_t PncclRecv(void *recvbuff, size_t count, ncclDataType_t datatype, int peer, ncclComm_t comm, cudaStream_t stream) {
        printf("Intercept--------------------------\n");
        //call real func
}


#pragma weak ncclAllReduce = PncclAllReduce
ncclResult_t PncclAllReduce(const void *sendbuff, void *recvbuff, size_t count, ncclDataType_t datatype, ncclRedOp_t op, ncclComm_t comm, cudaStream_t stream) {
        printf("Intercept--------------------------\n");
        //call real func
}
