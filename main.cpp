#include "mbed.h"
#include "C12832.h"
#include "Sht31.h"

Sht31 sht31(I2C_SDA, I2C_SCL);
 
DigitalOut white(p7);
PwmOut red(p5);
PwmOut blue(p6);
Ticker tickr_1,tickr_2;


InterruptIn btn(p8);

void temp() {
    printf("temp and humidity\n");
   float t = sht31.readTemperature();
   float h = sht31.readHumidity();
    red=t*0.02;
    blue=h*0.01;
    }
    
void blink() {
    printf("blink white light\n");
       white=1;
       wait_ms(500);
      
       white=0;
    }
    
void button() {
    
    printf("BUTTON1 invoked\n");
   float t = sht31.readTemperature();
   float h = sht31.readHumidity();
    red=t*0.02;
    blue=h*0.01;
}

int main() {
    
   btn.fall(callback(&button));
   
   tickr_1.attach(callback(&blink), 2.5f);
   
   tickr_2.attach(callback(&temp), 10.0f);
   
   
   wait_ms(osWaitForever);
}
