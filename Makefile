nccl_wrappers.so: nccl_wrappers.c
	gcc -shared -fPIC -ldl -I/path/to/cuda/include nccl_wrappers.c -o nccl_wrappers.so

program: program.c
	nvcc program.c -o program -lnccl

run: nccl_wrappers.so program
	LD_PRELOAD=./nccl_wrappers.so 
	./program
	unset LD_PRELOAD

clean:
	rm -f nccl_wrapper.so program