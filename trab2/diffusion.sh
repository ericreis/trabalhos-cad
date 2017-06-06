[ -e diffusion-execution_time.txt ] && rm diffusion-execution_time.txt

num_threads=(1 2 4 8 16 32 64 128 256 512 1024 2048)
for num_thread in ${num_threads[*]}
do
    echo 'OMP_NUM_THREADS = '$num_thread >> diffusion-execution_time.txt
    export OMP_NUM_THREADS=$num_thread
    ./diffusion >> diffusion-execution_time.txt
done