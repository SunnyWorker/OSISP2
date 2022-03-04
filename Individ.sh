A=0
for file in `find $1 -type f -name "$2"`
do
	A=$(($A+1))
	echo `realpath $file`
	echo `stat --printf "%s\n%w\n%A\n%i\n" $file`

done
echo "Количество просмотренных файлов - $A"
