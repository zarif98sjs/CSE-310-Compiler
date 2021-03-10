for((i = 1; i<=5; ++i)); do
    echo Test Case $i
    ./gen $i > in$i.txt
    ./ReportSC < in$i.txt >> outSC.txt
done