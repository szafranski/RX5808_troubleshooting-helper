// this code makes Arduino built-in led blinking fast when it detects strong vtx signal near the rx5808 receiver

// vtx transmitter should be tuned to 5885MHz (E5 channel) +/- 5Mhz (5880MHz - R7 is also working)

// if you want to use another channel - you can tune the receiver accordingly to this table: 
//  https://oscarliang.com/ctt/uploads/2016/02/vtx-frequency-5-band-40-channel-boscam-fatshark-raceband-abef.png

/*

 
connect the RX5808 to the Arduino:

RX5808   Arduino
  CH1      11
  CH2      10
  CH3      13
  RSSI     A0
  GND      GND
   5V      5V

you can additionally place 10-100kOhm resistor between A0 and ground to prevent false radings. 
if no please keep fingers away from A0 pin during measurements

*/

#define CH1 11
#define CH2 10
#define CH3 13
#define RSSIpin A0
#define ledPin 13

int rssi_readout;

void setup() {
  // put your setup code here, to run once:

pinMode(RSSIpin, INPUT);
pinMode(CH1, OUTPUT);
pinMode(CH2, OUTPUT);
pinMode(CH3, OUTPUT);
pinMode(ledPin, OUTPUT);
}

void loop() {
rssi_readout = analogRead(RSSIpin);

digitalWrite(CH1, LOW); // sets reciver frequency to 5885MHz - can be changed as mentioned in the comment at the top
digitalWrite(CH2, LOW);
digitalWrite(CH3, HIGH);

if (rssi_readout >750)          // makes built-in led blinking when quad is near the receiver 
{ digitalWrite(ledPin, HIGH);
delay(300);
digitalWrite(ledPin, LOW);
delay(300);
}
else digitalWrite(ledPin, LOW);

}
