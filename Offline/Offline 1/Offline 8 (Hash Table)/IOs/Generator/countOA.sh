for((i = 1; i<=5; ++i)); do
    echo Test Case $i
    ./gen $i > in$i.txt
    ./ReportOA < in$i.txt >> outOA.txt
done