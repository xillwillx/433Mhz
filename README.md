# 433Mhz
Code to sniff and send 433Mhz RF signals to outlets and bulb sockets. Based off the code from [ninjablocks](https://github.com/ninjablocks/433Utils)

This will be used in cheap home automation using a Raspberry Pi.  You will need to install [Apache, PHP](http://www.raspberrypi.org/documentation/remote-access/web-server/apache.md) & [WiringPi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install) on your Pi first. 
 Consult [Wiring Pi wiring guide](https://projects.drogon.net/raspberry-pi/wiringpi/pins/) and [433mhz  wiring diagram](http://i.imgur.com/0BNjG2Y.png) & [here](http://i.imgur.com/FfZB7Se.jpg) for more info.

###Install Instructions: 
```
sudo apt-get install git
sudo apt-get install git-core
git clone git://git.drogon.net/wiringPi
cd wiringPi
git pull origin
./build

git clone https://github.com/xillwillx/433Mhz.git 
cd 433Mhz
sudo make all
sudo chown root.root codesend RFSniffer
sudo chmod 4755 codesend RFSniffer
sudo mv codesend RFSniffer index.html send.php /var/www/
sudo rm -rf /433Mhz
cd /var/www/
```
RFSniffer to find RF codes for your devices
```
sudo ./RFSniffer
```

Record all 6 digit and pulse codes for on/off for each EtekCity plug outlet, if using the bulb sockets you will only get 1 digit and pulse code for on/off.

Edit the send.php to your on/off codes and save 
```
sudo nano send.php
```

Browse to Raspberry Pi's ip address http://x.x.x.x/

You should be able to turn off the sockets on/off as long as your codes were properly edited

###Stuff to buy:
- [Raspberry Pi 2 Model B - 1GB RAM/900 MHz CPU $44.99](http://amzn.to/1e2pbgO)

- [SMAKN 433Mhz Rf Transmitter and Receiver Link Kit $6.66](http://amzn.to/1E6wtoC)  

- [40P dupont cable 200mm male to female $2.26](http://amzn.to/1E6AOYM)

- [433Mhz Etekcity Plug Outlet 5-Pack $29.99 (sometimes on sale for $22)](http://amzn.to/1ICejS6)

- [433mhz LED Concepts Wireless Light Bulb Socket 3-pack $18.99](http://amzn.to/1IyRBf4)
