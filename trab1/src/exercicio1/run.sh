[ -e execution_time.txt ] && rm execution_time.txt

compilers=('g++' 'icc')
for compiler in "${compilers}"
do
    echo $compiler >> execution_time.txt
    otm_lvls=('-O0' '-O1' '-O2' '-O3')
    for i in "${otm_lvls[@]}"
    do
        otm=$i
        $compiler main.cpp -o main.out $otm
        echo $otm >> execution_time.txt
        matrix_sizes=(10)
        for j in "${matrix_sizes[@]}"
        do
            n=$j
            mult_types=(1 2 3 4)
            for k in "${mult_types[@]}"
            do
                type=$k
                result=$(./main.out $n $type)
                echo $n': '$result' secs' >> execution_time.txt
            done
        done
        echo '' >> execution_time.txt
    done
    echo '' >> execution_time.txt
    echo '' >> execution_time.txt
done