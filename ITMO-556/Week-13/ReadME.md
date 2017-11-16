# Chapter 09 LAB

## Question 1

sudo useradd controller
![Q1](images/Q1.PNG)

## Question 2 

sudo usermod -aG sudo controller
![Q2](images/Q2.PNG)

## Question 3

sudo useradd nsa-spy  
sudo userdel nsa-spy
![Q3](images/Q3.PNG)

## Question 4

sudo visudo  
then add "mysql-backup ALL=(ALL:ALL) ALL" in the editor
![Q4](images/Q4.PNG)

## Question 5

sudo visudo  
then add "%mysql-admins ALL=(ALL:ALL) ALL" in the editor
![Q5](images/Q5.PNG)

## Question 6

sudo visudo  
then add "mysql-admin ALL=(ALL:/usr/sbin/mysqldump) ALL"
![Q6](images/Q6.PNG)

## Question 7

sudo visudo  
then add "mysql-admin ALL=(ALL) NOPASSWD:/usr/bin/mysql ALL"
![Q7](images/Q7.PNG)


## Question 8

Yes there is an error. Because journalctl isn't a file but a command, and the tail command takes a file as an argument.  
![Q8](images/Q8.PNG)


## Question 9

journalctl \__COMM=sshd
![Q9](images/Q9.PNG)

## Question 10

journalctl --since=yesterday _PID=1
![Q10](images/Q10.PNG)

 ## Question 11
 
journalctl -b
![Q11](images/Q11.PNG)

 ## Question 12
 
This file: /etc/systemd/journald.conf  
There, we need to change the value of Storage to 'volatile'.
![Q12](images/Q12.PNG)


 ## Question 13
 
System disk's size is 17G. Therefore, we must change the values in journald.conf as follows:
SystemMaxUse=3.4G  
RuntimeMaxUse=5.1G
![Q13](images/Q13.PNG)


 ## Question 14
 
0 2 * * 0 mysqldump -xml -u root world City

 ## Question 15
 
\* \* 1 * * mysqldump -xml -u root world City

 ## Question 16
 
/45 * * * * mysqldump -xml -u root world City

 ## Question 17
 
45 * * * 0 mysqldump -xml -u root world City

 ## Question 18
  
45 2 * * 2 mysqldump -xml -u root world City
 
## Question 19

Assuming the accounting group and the txt file are created:  
sudo chgrp accounting todo-list.txt
![Q19](images/Q19.PNG)

## Question 20

sudo chown root:root todo-list.txt
![Q20](images/Q20.PNG)

