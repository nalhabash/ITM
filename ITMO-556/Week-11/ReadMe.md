# Question 1:

declare -a itemARRAY

# Question 2:

declare -a dirarr
mapfile -t dirarr < <(ls -l ~)
echo "${dirarr[2]}"
echo "${dirarr[3]}"

# Question 3


# Question 4
