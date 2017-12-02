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












