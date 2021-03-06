[ -e execution_time.txt ] && rm execution_time.txt

compilers=('g++' 'icc')
for compiler in "${compilers}"
do
    echo $compiler >> execution_time.txt
    otm_lvls=('-O0' '-O1' '-O3')
    for i in "${otm_lvls[@]}"
    do
        otm=$i
        if [ $compiler == 'g++' ] 
        then
            $compiler main.cpp -o main.out $otm
        else
            $compiler main.cpp -o main$otm.out -qopt-report $otm
        fi
        echo $otm >> execution_time.txt
        matrix_size=1024
        mult_types=(1 2 3 4)
        for j in "${mult_types[@]}"
        do
            type=$j
            nbs=(2 4 8 16)
            for k in "${nbs[@]}"
            do
                nb=$k
                result=$(./main.out $matrix_size $type $nb)
                echo $nb': '$result' secs' >> execution_time.txt
            done
        done
        echo '' >> execution_time.txt
    done
    echo '' >> execution_time.txt
    echo '' >> execution_time.txt
done