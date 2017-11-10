# Question 1:

declare -a itemARRAY

# Question 2:

#!/bin/bash

declare -a dirarr
mapfile -t dirarr < <(ls -l ~)
echo "${dirarr[2]}"
echo "${dirarr[3]}"

# Question 3

#!/bin/bash

declare -a dirarr
mapfile -t dirarr < <(ls -l ~)

LENGTH=${#dirarr[@]}

for ((i=0; i<${LENGTH}; i++))
do
        echo ${dirarr[$i]}
done

# Question 4

5 * * * * ~/lab8.sh

# Question 5



# Question 6
