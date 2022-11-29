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
else 
    path=meta4
fi

make # for making sure that the compiler is updated
echo "Testcases"
echo "---------------------------------------------"

for input in $path/*.java; do
    filename=`echo $input | cut -d "." -f1`
    if [ "$1" = "-s" ]; then 
        if [ "$filename" != "meta3/valid_program" ] && [ "$filename" != "meta3/factorial" ] && [ "$filename" != "meta3/logical_operators" ] && [ "$filename" != "meta3/variable_func_symtab_aast" ]; then
            out=$(./run < $filename.java | sort | diff $filename.out -)
        else
            out=$(./run $flag < $filename.java | diff $filename.out -)
        fi
    elif [ "$1" = "" ]; then
        compile=$(./run < $filename.java > $filename.ll)
        if [ "$filename" = "meta4/parse_args" ]; then
            out=$(lli $filename.ll 0 1 2 3 | diff $filename.out - ) 
        elif [ "$filename" = "meta4/recursive_factorial" ]; then
            out=$(lli $filename.ll 10 | diff $filename.out - ) 
        else
            out=$(lli $filename.ll | diff $filename.out - ) 
        fi
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