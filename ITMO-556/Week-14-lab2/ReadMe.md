# Chapter 11 - Lab 2

## Question 1:

First, "sudo vi /etc/default/grub" to edit the file in root mode (then :wq! to save and quit instead of :wq).
![Q](images/1.png)

Then sudo update-grub to save the modifications.

Here's GRUB with a new background :
![](images/1-3.png)

And the start-up with details:
![](images/1-2.png)

## Question 2:

![](images/2.png)

## Question 3:

sudo dnf install mariadb  
systemctl -a (to display the services), but I can't find mariadb.service. Tried installing mariadb-server too, as stated here (https://fedoraproject.org/wiki/MariaDB).  
Then :
systemctl enable mariadb  
systemctl start mariadb

You can see it is activated and running: 

![](images/3.png)

## Question 4

As you can see the boot time takes much more time, but it's probably mainly due to me using Fedora this time ! I started this lab on ubuntu..
![](images/4.png)

## Question 5

It seems mariadb increased the boot time by almost 15 seconds.
![](images/5.png)

## Question 6

![](images/6.png)

## Question 7

sudo systemctl kill -s SIGHUP httpd
As you can see the service isn't running anymore:
![](images/7.png)

## Question 8

I thought at first I need to do systemctl isolate graphical.target. But that displayed a black screen and nothing happens. The black screen stays even after a reboot so I don't know who to solve it.
So I changed to ubuntu and did this:
![](images/8.png)

## Question 9

The fact that the values are blank might be due to me changing to a vey recently newly installed ubuntu, with a lot of packages not installed..
![](images/9.png)

## Question 10

Here's the short C code I did, compiled and executed:
![](images/10-1.png)

The low priority test of the code:
![](images/10-2.png)

The high priority test of the code:
![](images/10-3.png)

## Question 11

![](images/11.png)

## Question 12

Here's the result displayed (it's actually better to search for vb.* instead of vb*)

![](images/12.png)

## Question 13

![](images/13.png)

## Question 14

cat /proc/cpuinfo | grep flags
![](images/14.png)

## Question 15

![](images/15.png)

## Question 16

![](images/16.png)

## Question 17

![](images/17.png)

## Question 18

![](images/18.png)

## Question 19

![](images/19.png)




