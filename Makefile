TEST_FILE = test_file.c

nccl_wrappers.so: nccl_wrappers.c
	gcc -shared -fPIC -ldl -I/shared/EL9/explorer/nvidia-hpc-sdk/24.7/Linux_x86_64/24.7/cuda/include nccl_wrappers.c -o nccl_wrappers.so

test_file: ${TEST_FILE}
	nvcc ${TEST_FILE} -o test_file -lnccl

run: nccl_wrappers.so test_file
	LD_PRELOAD=./nccl_wrappers.so ./test_file

clean:
	rm -f nccl_wrappers.so test_file