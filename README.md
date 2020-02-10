# RX5808_troubleshooting-helper
simple arduino code for troubleshooting the RX5808 

// this code makes Arduino built-in led blinking fast when it detects strong vtx signal near the rx5808 receiver

// vtx transmitter should be tune to 5885MHz (E5 channel) +/- 5Mhz (5880MHz - R7 is also working)

// if you want to use another channel - you can tune the receiver accordingly to this table: 
//  https://oscarliang.com/ctt/uploads/2016/02/vtx-frequency-5-band-40-channel-boscam-fatshark-raceband-abef.png

/*

 
connect the RX5808 to the Arduino:
<br>
RX5808   Arduino<br>
  CH1  --    11<br>
  CH2  --    10<br>
  CH3  --    13<br>
  RSSI --   A0<br>
  GND  --    GND<br>
   5V  --    5V<br>

you can additionally place 10-100Ohm resistor between A0 and ground to prevent false radings. if no please keep fingers away from A0 pin during measurements

*/
