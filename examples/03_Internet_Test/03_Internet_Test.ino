#include <ETH.h>
#include <WiFi.h>
#include <HTTPClient.h>

void setup()
{
  Serial.begin(115200);
  delay(2000);

  Serial.println();
  Serial.println("WT32-ETH01-EVO");
  Serial.println("Starting Ethernet...");

  bool ok = ETH.begin(
      ETH_PHY_DM9051,
      1,          // PHY Address
      9,          // CS
      8,          // INT
      6,          // RESET
      SPI2_HOST,  // SPI Host
      7,          // SCK
      3,          // MISO
      10,         // MOSI
      8           // SPI Clock MHz
  );

  if (!ok)
  {
    Serial.println("ETH.begin() FAILED");
    while (1)
      delay(1000);
  }

  Serial.println("ETH.begin() OK");

  Serial.println("Waiting for Link...");

  unsigned long start = millis();

  while (!ETH.linkUp())
  {
    if (millis() - start > 15000)
    {
      Serial.println("Ethernet Link Timeout");
      break;
    }

    Serial.print(".");
    delay(500);
  }

  if (ETH.linkUp())
  {
    Serial.println();
    Serial.println("Ethernet Link UP");

    Serial.println("Waiting for DHCP...");

unsigned long t = millis();

while (ETH.localIP() == IPAddress(0,0,0,0))
{
    if (millis() - t > 15000)
    {
        Serial.println("DHCP Timeout");
        break;
    }

    Serial.print(".");
    delay(500);
}

Serial.println();

Serial.print("MAC Address : ");
Serial.println(ETH.macAddress());

Serial.print("IP Address  : ");
Serial.println(ETH.localIP());

Serial.print("Gateway     : ");
Serial.println(ETH.gatewayIP());

Serial.print("Subnet Mask : ");
Serial.println(ETH.subnetMask());

Serial.print("DNS         : ");
Serial.println(ETH.dnsIP());

Serial.println();
Serial.println("Ethernet Ready");
  }
  

HTTPClient http;

http.begin("http://clients3.google.com/generate_204");

int code = http.GET();

Serial.print("HTTP Response = ");
Serial.println(code);

http.end();

}

void loop()
{
}