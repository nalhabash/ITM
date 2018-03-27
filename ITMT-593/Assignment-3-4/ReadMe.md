# Smart Ionization Probe
In this project I built a Smart Ionization Probe system connected to a web server and to a phone via bluetooth. 
I used an arduino UNO card, an SD card and an Ethernet Shield from Adafruit, as well as well as some wires, aluminum foil and a resistor.
Here are 2 pictures of the final setup and the display on the web server.

![Nour](images/picture1.jpg)
![Nour](images/picture2.jpg)

The goal was to measure the conductivity of water in a certain cup using the 2 ends of the probe. The tension value (between 0 and 5 V) allows us to calculate the conductivity value. Then we had several goals:
+ Store the data in a SD card
+ Make a web server to display the data from a browser
+ Send the data using a bluetooth dongle to display it on a receiver (in this case my android phone).

Here's a fritzing sketch of my project: 

![sketch](images/sketch.PNG)


## How it works

So once the card is powered the probe voltage value is measured and all the other values are computed (like the conductivity). Then, a web server is started with a MAC address I defined and I send all of the data and some strings with HTML tags to the client. This allows the data to display nicely in the browser at the IP address I specified. The browser is also set to refresh avery 5 seconds.

At the same time, the arduino writes the data every 5 seconds in a file stored in the SD card.

However the card I have is more limited in memory than official arduino cards, so there was only a limited amount of things I could display without the web server freezing. Same goes for the shield that I used that came with its great share of problems. It was the adafruit shield that kept me awake for hours trying to make the Ethernet and SD card library work at the same time ! This problem did not happen on my friends' official shields. (I tested their own working code on mine). I would like this handicap to be taken into account in the grading.

Furthermore I did the bluetooth part on another separate script, where the arduino would open and read the values stored in a file and send them via bluetooth to a receiver using the bluetooth dongle. I couldn't do everything on a single script because of the memory issues I mentioned earlier.  
Yet, given the extra time I spent dealing with the problematic Adafruit shield, I could only open the file successfully but still had troubles connecting the dongle to the phone from times to times. I'd like to underline again that the dongle I ended up with was the HC 05, an old model that wasn't even detected by my OnePlus One, but it was on the Nexus 5 (given to me by the AP team).
