## Question 1:

declare -a itemARRAY

## Question 2:

#!/bin/bash

declare -a dirarr   
mapfile -t dirarr < <(ls -l ~)   
echo "${dirarr[2]}"   
echo "${dirarr[3]}"   

![Q2](images/Q2.PNG)

## Question 3

#!/bin/bash

declare -a dirarr   
mapfile -t dirarr < <(ls -l ~) 


LENGTH=${#dirarr[@]}   

for ((i=0; i<${LENGTH}; i++))   
do  
        echo ${dirarr[$i]}  
done   
![Q3](images/Q3.PNG)

## Question 4

5 * * * * ~/lab8.sh

## Question 5

This must be added to the script : 

if [ -a /datapool1 ]  
then  
        echo ""  
else  
        echo "There is a problem, the folder doesn't exist !"  
fi  

![Q5](images/Q5.PNG)

## Question 6

Same as before, but with "if [ -a $1 ]" instead.
And to test it we do "./install-java-8.sh /datapool1".
(No screenshot done, result is the same as before).

## Question 7

Add this at the beginning:  

if [ "$#" != "1" ]  
then 
        exit 1  
fi  

![Q7](images/Q7.PNG)

## Question 8

if [ -x $1  ]  
then  
        echo "You can execute this file !"  
else  
        echo "ERROR you can't execute this file !!!"  
fi  

![Q8](images/Q8.PNG)

## Question 9

Same as before ! But with this change : 
"if [ -x ~/topsecret/$1  ]"

![Q9](images/Q9.PNG)

## Question 10

if [ -f $1 ] || [ -d $1 ]  
then  
        echo "this is indeed a file or a directory ! :)!"  
else  
        echo "$1 is neither a file nor a directory !!!"  
fi  

![Q10](images/Q10.PNG)


## Question 11 

echo "$0 is the command used"  
echo "$# is the number of parameters"  
echo "$@ are all the parameters"  

![Q11](images/Q11.PNG)

## Question 12

5 * * * * ~/lab8.sh &>~/Documents/my.log
