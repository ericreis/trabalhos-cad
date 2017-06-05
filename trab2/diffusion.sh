[ -e diffusion-execution_time.txt ] && rm diffusion-execution_time.txt

num_threads=(16)
for num_thread in ${num_threads[*]}
do
    echo 'OMP_NUM_THREADS = '$num_thread >> diffusion-execution_time.txt
    export OMP_NUM_THREADS=$num_thread
    ./diffusion >> diffusion-execution_time.txt
done