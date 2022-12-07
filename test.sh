if [ "$1" = "-l" ]; then
    path=meta1
    flag="$1"
elif [ "$1" = "-t" ]; then
    path=meta2
    flag="$1"
elif [ "$1" = "-e2" ]; then
    path=meta2_errors
    flag="$1"
elif [ "$1" = "-s" ]; then
    path=meta3
    flag="-s"
elif [ "$1" = "-se" ]; then
    path=meta3_semErros
    flag="-s"
else 
    path=meta4
fi

make # for making sure that the compiler is updated
echo "Testcases"
echo "---------------------------------------------"

for input in $path/*.java; do
    filename=`echo $input | cut -d "." -f1`
    if [ "$1" = "-s" ]; then 
            out=$(./run $flag < $filename.java | diff $filename.out -)
    else
        out=$(./run $flag < $filename.java | diff $filename.out -)
    fi
    if [ $? -eq 0 ]; then
        echo "✅ PASSED $filename.java"
    else
        echo "❌ FAILED $filename.java "
        echo "./run $flag < $filename.java | diff $filename.out - -y -t"
    fi
done