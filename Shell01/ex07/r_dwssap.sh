cat /etc/passwd | sed -e '/^[ ]*#/d' -e 'N;s/.*\n//' | rev | sed 's/.*://' | sort -r | sed -n "`echo $FT_LINE1`, `echo $FT_LINE2`p" |  tr '\n' ' ' | sed -e 's/ /, /g' | sed 's/..$/./' | tr -d '\n'
