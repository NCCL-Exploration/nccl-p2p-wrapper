TEST_FILE = test_file.c

nccl_wrappers.so: nccl_wrappers.c
	gcc -shared -fPIC -ldl -I/path/to/cuda/include nccl_wrappers.c -o nccl_wrappers.so

test_file: ${TEST_FILE}
	nvcc ${TEST_FILE} -o test_file -lnccl

run: nccl_wrappers.so test_file
	LD_PRELOAD=./nccl_wrappers.so 
	./test_file
	unset LD_PRELOAD

clean:
	rm -f nccl_wrapper.so test_file