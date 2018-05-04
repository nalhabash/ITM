# Final Project - Arduino Game Controller for Unity

I chose to design and build a motion sensor game controller for Unity, using Arduino. This is the final project I chose to work in the Embedded Systems class.

Before starting, you may look at this video that demonstrates the whole working project:
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/SUkSW-QTOq8/0.jpg)](http://www.youtube.com/watch?v=SUkSW-QTOq8)


I wanted to do that because I have played a lot of videogames on various platforms in my life, and I was always fascinated by the many innovative controllers that developers often came up with (Duck Hunt Pistol on NES, Wii Remote and Wii Fit, VR controllers,...).

So I chose to make my own controller to play on my own game I also built myself.
I would actually say that this is more than a normal arduino project, since it combines skills and programming knowledge in Unity (using C#).

I first made my own game in Unity, a "Roll a Ball" game that you can learn to make with an interactive tutorial in the Unity documentation. The original finished game uses the arrows on the keyboard to move the ball and gather the collectibles. 

### Project Description

The goal is to control the ball using an accelerometer sensor plugged to an Arduino, that sends the geometrical data to Unity on my laptop. Here's a picture of the final setup:

![](images/setup.jpg)

The controller is wired to the laptop (USB). At first I wanted to go for a wireless controller (Bluetooth connection) but I didn't have the time to solve the latency issues that ensued. 
The controller being wired, it is powered via USB. But I had prepared a solution in case I went with the wireless option, and was ready to use a 9V battery with an adapter as shown in the sketch.

Here's the sketch I am talking about, it shows all the hardware I used.

![](images/sketch.PNG)

There is a passive buzzer I use to make a small jingle when the game starts, and when the player wins !
As you can see there is also a bluetooth module, despite me having focused on a USB connection through SerialPort to connect to the PC. It sends a "victory" message (with the score) to an Android Phone. The phone first needs to be connected to the arduino first. Here is a screenshot of the phone connected to the controller, at the end of a game !

![](images/phonescreen.png)

The score is the time in seconds it takes the player to collect all yellow orbs. The game is quite simple, as you can see.
Here's a picture of the game UI:

![](images/unity1.PNG)

And now a picture of the game once all orbs are collected ! (with the score displayed in the upper right corner, and a Victory message that displays).

![](images/unity2.PNG)

Now I also wanted to save the score and the player name (yes, the player can input his/her name in the script attributes). At first, I wanted to save them in an SD card, like old gaming consoles used to do with memory cards. But instead, I save them in a stuff.txt file on the hard drive (like newer consoles who save data in a hard drive).
Here's how it looks like:

![](images/unity3.PNG)

### Project Cost

The prototype I built costs between 30 and 40 dollars, according to where you purchase the components. But it is unnecessarily overpriced, I could drop the cost if I used a smaller Arduino for example (I don't need all the pins or the entire memory on the Arduino UNO) or if I bought components in bulk for production.

### What I could improve

This project taught me much, and especially gave me experience in using new technologies I am not used to (Unity).
There are several ways to pimp this project and make it bigger, shinier, and cooler, our imagination is the only limit. I was thinking of making the winning event more meaningful, by adding blinking LEDs or a more exciting winning animation.
I could also implement a fully functionnal wireless communication between the controller and Unity. I could improve the game, make it more complicated, add modes (countdown mode, try to actually avoid moving orbs for a certain time, etc...).
I could use two accelerometer and implement a 2 player mode,... As I said, so many options !!
