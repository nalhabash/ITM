# Chapter 11 - Lab 2

## Question 1:

First, "sudo vi /etc/default/grub" to edit the file in root mode (then :wq! to save and quit instead of :wq).
![Q](images/1.PNG)

Then sudo update-grub to save the modifications.

Here's GRUB with a new background :
![](images/1-3.PNG)

And the start-up with details:
![](images/1-2.PNG)

## Question 2:

![](images/2.PNG)

## Question 3:

sudo dnf install mariadb  
systemctl -a (to display the services), but I can't find mariadb.service. Tried installing mariadb-server too, as stated here (https://fedoraproject.org/wiki/MariaDB).  
Then :
systemctl enable mariadb  
systemctl start mariadb

You can see it is activated and running: 

![](images/3.PNG)

## Question 4

As you can see the boot time takes much more time, but it's probably mainly due to me using Fedora this time ! I started this lab on ubuntu..
![](images/4.PNG)

## Question 5

It seems mariadb increased the boot time by almost 15 seconds.
![](images/5.PNG)

## Question 6

![](images/6.PNG)

## Question 7

sudo systemctl kill -s SIGHUP httpd
As you can see the service isn't running anymore:
![](images/7.PNG)

## Question 8

I thought at first I need to do systemctl isolate graphical.target. But that displayed a black screen and nothing happens. The black screen stays even after a reboot so I don't know who to solve it.
So I changed to ubuntu and did this:
![](images/8.PNG)

## Question 9

The fact that the values are blank might be due to me changing to a vey recently newly installed ubuntu, with a lot of packages not installed..
![](images/9.PNG)

## Question 10

Here's the short C code I did, compiled and executed:
![](images/10-1.PNG)

The low priority test of the code:
![](images/10-2.PNG)

The high priority test of the code:
![](images/10-3.PNG)

## Question 11

ps -ef to display the list. (Yes, killing the processes did close the browser, I took the screenshot afterwards)
![](images/11.PNG)

## Question 12

Here's the result displayed (it's actually better to search for vb.* instead of vb*)

![](images/12.PNG)

## Question 13

![](images/13.PNG)

## Question 14

cat /proc/cpuinfo | grep flags
![](images/14.PNG)

## Question 15

![](images/15.PNG)

## Question 16

![](images/16.PNG)

## Question 17

![](images/17.PNG)

## Question 18

![](images/18.PNG)

## Question 19

![](images/19.PNG)




