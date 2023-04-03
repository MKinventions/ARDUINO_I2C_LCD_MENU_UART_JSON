#include<EEPROM.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display


const int pagesButton = 2;//PB15;
const int MainMenuButton = 5;//PB13;
const int SubMenuButton = 8;//PB12;

int pagesCount = 0;
int MainMenuSelect = 0;
int SubMenuSelect = 0;

int totalPages = 10;
int totalMenus = 10;
int totalSubMenus = 2;

int pot1_address = 1;
int pot2_address = 2;
int pot3_address = 3;
int pot4_address = 4;
int joy1_address = 5;
int joy2_address = 6;
int joy3_address = 7;
int joy4_address = 8;

int pot1Dir_address = 9;
int pot2Dir_address = 10;
int pot3Dir_address = 11;
int pot4Dir_address = 12;
int joy1Dir_address = 13;
int joy2Dir_address = 14;
int joy3Dir_address = 15;
int joy4Dir_address = 16;

int pageCount_address = 17;

int sw1Dir_address = 18;
int sw2Dir_address = 19;
int sw3Dir_address = 20;
int sw4Dir_address = 21; 


byte pot1_value, pot2_value, pot3_value, pot4_value, joy1_value, joy2_value, joy3_value, joy4_value;
byte pot1Dir_value, pot2Dir_value, pot3Dir_value, pot4Dir_value, joy1Dir_value, joy2Dir_value, joy3Dir_value, joy4Dir_value;
byte sw1Dir_value,sw2Dir_value,sw3Dir_value,sw4Dir_value;

String pot1Dir_Type, pot2Dir_Type, pot3Dir_Type, pot4Dir_Type;
String joy1Dir_Type, joy2Dir_Type, joy3Dir_Type, joy4Dir_Type;
String sw1Dir_Type, sw2Dir_Type, sw3Dir_Type, sw4Dir_Type;



void setup() {
  lcd.begin();
  lcd.clear();         
  lcd.backlight();   
  
  Serial.begin(115200);
  pinMode(MainMenuButton, INPUT_PULLUP);
  pinMode(SubMenuButton, INPUT_PULLUP);
  pinMode(pagesButton, INPUT_PULLUP);

  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Device Restarted");
  lcd.setCursor(0,1);   //Set cursor to character 2 on line 0
  lcd.print("Reading Memory");
  delay(2000);
  lcd.clear();


  pot1_value = EEPROM.read(pot1_address);//EEPROM.read(ADDRESS 0-255);
  pot2_value = EEPROM.read(pot2_address);//EEPROM.read(ADDRESS 0-255);
  pot3_value = EEPROM.read(pot3_address);//EEPROM.read(ADDRESS 0-255);
  pot4_value = EEPROM.read(pot4_address);//EEPROM.read(ADDRESS 0-255);
  joy1_value = EEPROM.read(joy1_address);//EEPROM.read(ADDRESS 0-255);
  joy2_value = EEPROM.read(joy2_address);//EEPROM.read(ADDRESS 0-255);
  joy3_value = EEPROM.read(joy3_address);//EEPROM.read(ADDRESS 0-255);
  joy4_value = EEPROM.read(joy4_address);//EEPROM.read(ADDRESS 0-255);

  pot1Dir_value = EEPROM.read(pot1Dir_address);//EEPROM.read(ADDRESS 0-255);
  pot2Dir_value = EEPROM.read(pot2Dir_address);//EEPROM.read(ADDRESS 0-255);
  pot3Dir_value = EEPROM.read(pot3Dir_address);//EEPROM.read(ADDRESS 0-255);
  pot4Dir_value = EEPROM.read(pot4Dir_address);//EEPROM.read(ADDRESS 0-255);
  joy1Dir_value = EEPROM.read(joy1Dir_address);//EEPROM.read(ADDRESS 0-255);
  joy2Dir_value = EEPROM.read(joy2Dir_address);//EEPROM.read(ADDRESS 0-255);
  joy3Dir_value = EEPROM.read(joy3Dir_address);//EEPROM.read(ADDRESS 0-255);
  joy4Dir_value = EEPROM.read(joy4Dir_address);//EEPROM.read(ADDRESS 0-255); 

  pagesCount = EEPROM.read(pageCount_address);//EEPROM.read(ADDRESS 0-255); 

  sw1Dir_value = EEPROM.read(sw1Dir_address);//EEPROM.read(ADDRESS 0-255);
  sw2Dir_value = EEPROM.read(sw2Dir_address);//EEPROM.read(ADDRESS 0-255);
  sw3Dir_value = EEPROM.read(sw3Dir_address);//EEPROM.read(ADDRESS 0-255);
  sw4Dir_value = EEPROM.read(sw4Dir_address);//EEPROM.read(ADDRESS 0-255);
}

void loop() {

  pot1Dir_Type = (pot1Dir_value == 0)?"LFT":"RHT";
  pot2Dir_Type = (pot2Dir_value == 0)?"LFT":"RHT";
  pot3Dir_Type = (pot3Dir_value == 0)?"LFT":"RHT";
  pot4Dir_Type = (pot4Dir_value == 0)?"LFT":"RHT";
  String pot1Dir_Type1 = (pot1Dir_value == 0)?"L":"R";
  String pot2Dir_Type1 = (pot2Dir_value == 0)?"L":"R";
  String pot3Dir_Type1 = (pot3Dir_value == 0)?"L":"R";
  String pot4Dir_Type1 = (pot4Dir_value == 0)?"L":"R";
  
  joy1Dir_Type = (joy1Dir_value == 0)?"LFT":"RHT";
  joy2Dir_Type = (joy2Dir_value == 0)?"LFT":"RHT";
  joy3Dir_Type = (joy3Dir_value == 0)?"LFT":"RHT";
  joy4Dir_Type = (joy4Dir_value == 0)?"LFT":"RHT";
  String joy1Dir_Type1 = (joy1Dir_value == 0)?"L":"R";
  String joy2Dir_Type1 = (joy2Dir_value == 0)?"L":"R";
  String joy3Dir_Type1 = (joy3Dir_value == 0)?"L":"R";
  String joy4Dir_Type1 = (joy4Dir_value == 0)?"L":"R";  
  
  sw1Dir_Type = (sw1Dir_value == 0)?"PSH":"TGL";
  sw2Dir_Type = (sw2Dir_value == 0)?"PSH":"TGL";
  sw3Dir_Type = (sw3Dir_value == 0)?"PSH":"TGL";
  sw4Dir_Type = (sw4Dir_value == 0)?"PSH":"TGL";
  
 if (digitalRead(MainMenuButton) == LOW) {
      MainMenuSelect++;
      if (MainMenuSelect == totalMenus+1) {
        MainMenuSelect = 0;
      }
          Serial.println(MainMenuSelect);
  //    displayMainMenu();
   }
    
    if (digitalRead(SubMenuButton) == LOW) {
      SubMenuSelect++;
      if (SubMenuSelect == totalSubMenus+1) {
        SubMenuSelect = 0;
      }
    }
  
 
    if (digitalRead(pagesButton) == LOW) {
      pagesCount++;
  //    Serial.println(SelectSubMenuValue);
      if (pagesCount == totalPages+1) {
        pagesCount = 0;
      }
    }

 
    
  delay(100);




switch(pagesCount){
  
        
    case 0:EEPROM.write(pageCount_address, 0);
       lcd.setCursor(0,0);lcd.print("Dashboard          ");
      lcd.setCursor(0,1);lcd.print("                    ");
      break;

    case 1:EEPROM.write(pageCount_address, 1);
      lcd.setCursor(0,0); lcd.print("P1:" + String(pot1_value)+ String(pot1Dir_Type1));lcd.setCursor(7,0);lcd.print(",P2:" + String(pot2_value)+ String(pot2Dir_Type1));
      lcd.setCursor(0,1); lcd.print("P3:" + String(pot3_value)+ String(pot3Dir_Type1));lcd.setCursor(7,1);lcd.print(",P4:" + String(pot4_value)+ String(pot4Dir_Type1));
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      break;
    case 2:EEPROM.write(pageCount_address, 2);
      lcd.setCursor(0,0); lcd.print("J1:" + String(joy1_value)+ String(joy1Dir_Type1));lcd.setCursor(7,0);lcd.print(",J2:" + String(joy2_value)+ String(joy2Dir_Type1));
      lcd.setCursor(0,1); lcd.print("J3:" + String(joy3_value)+ String(joy3Dir_Type1));lcd.setCursor(7,1);lcd.print(",J4:" + String(joy4_value)+ String(joy4Dir_Type1));
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      break;
    case 3:EEPROM.write(pageCount_address, 3);
      lcd.setCursor(0,0); lcd.print("S1:" + String(sw1Dir_Type));lcd.setCursor(7,0);lcd.print(",S2:" + String(sw2Dir_Type));
      lcd.setCursor(0,1); lcd.print("S3:" + String(sw3Dir_Type));lcd.setCursor(7,1);lcd.print(",S4:" + String(sw4Dir_Type));
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      break;
    case 4:EEPROM.write(pageCount_address, 4);
      lcd.setCursor(0,0); lcd.print(" P1  P2  P3  P4");
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      potentiometer();
      break;
  
    case 5:EEPROM.write(pageCount_address, 5);
      lcd.setCursor(0,0); lcd.print(" P1  P2  P3  P4");
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      potentiometer_settings();
      break;
          
    case 6:EEPROM.write(pageCount_address, 6);
      lcd.setCursor(0,0); lcd.print(" J1  J2  J3  J4");
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      joystick();
      break;
    
    case 7:EEPROM.write(pageCount_address, 7);
      lcd.setCursor(0,0); lcd.print(" J1  J2  J3  J4");
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      joystick_settings();
      break;      
    
    case 8:EEPROM.write(pageCount_address, 8);
      lcd.setCursor(0,0); lcd.print(" S1  S2  S3  S4");
      lcd.setCursor(15,1);lcd.print(String(pagesCount));
      switch_settings();
      break;
    
    case 9:

          break;
                     
  }
  
}



void potentiometer(){


  switch(MainMenuSelect){
         case 0:
                lcd.setCursor(0,0);lcd.print(" P1  P2  P3  P4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("    ");
                break;

         case 1:
                lcd.setCursor(0,0);lcd.print(">P1  P2  P3  P4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(pot1_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(pot1_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(pot1_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;
        
         case 2:
                lcd.setCursor(0,0);lcd.print(" P1 >P2  P3  P4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(pot2_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(pot2_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(pot2_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;

          case 3:
                lcd.setCursor(0,0);lcd.print(" P1  P2 >P3  P4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(pot3_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(pot3_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(pot3_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;
          case 4:
                lcd.setCursor(0,0);lcd.print(" P1  P2  P3 >P4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(pot4_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(pot4_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(pot4_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;
                
          case 5:
                MainMenuSelect = 0;
                break;
                }
}
  
void potentiometer_settings(){


  switch(MainMenuSelect){
         case 0:
                lcd.setCursor(0,0);lcd.print(" P1  P2  P3  P4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("    ");
                break;

         case 1:
                lcd.setCursor(0,0);lcd.print(">P1  P2  P3  P4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(pot1Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(pot1Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(pot1Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;
        
         case 2:
                lcd.setCursor(0,0);lcd.print(" P1 >P2  P3  P4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(pot2Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(pot2Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(pot2Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;

          case 3:
                lcd.setCursor(0,0);lcd.print(" P1  P2 >P3  P4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(pot3Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(pot3Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(pot3Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;
          case 4:
                lcd.setCursor(0,0);lcd.print(" P1  P2  P3 >P4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(pot4Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(pot4Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(pot4Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;
                
          case 5:
                MainMenuSelect = 0;
                break;
                }
}


void joystick(){


  switch(MainMenuSelect){
         case 0:
                lcd.setCursor(0,0);lcd.print(" J1  J2  J3  J4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("    ");
                break;

         case 1:
                lcd.setCursor(0,0);lcd.print(">J1  J2  J3  J4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(joy1_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(joy1_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(joy1_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;
        
         case 2:
                lcd.setCursor(0,0);lcd.print(" J1 >J2  J3  J4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(joy2_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(joy2_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(joy2_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;

          case 3:
                lcd.setCursor(0,0);lcd.print(" J1  J2 >J3  J4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(joy3_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(joy3_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(joy3_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;
          case 4:
                lcd.setCursor(0,0);lcd.print(" J1  J2  J3 >J4");
                lcd.setCursor(0,1);lcd.print(" 180  255");lcd.setCursor(9,1);lcd.print("|" + String(joy4_value));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" 180  255");
                       break;
                       case 1:
                            EEPROM.write(joy4_address, 180);
                            lcd.setCursor(0,1);lcd.print(">180  255");
                       break;
                       case 2:
                            EEPROM.write(joy4_address, 255);
                            lcd.setCursor(0,1);lcd.print(" 180 >255");
                       break;                       
                }
                break;
                
          case 5:
                MainMenuSelect = 0;
                break;
                }
}
  
void joystick_settings(){


  switch(MainMenuSelect){
         case 0:
                lcd.setCursor(0,0);lcd.print(" J1  J2  J3  J4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("    ");
                break;

         case 1:
                lcd.setCursor(0,0);lcd.print(">J1  J2  J3  J4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(joy1Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(joy1Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(joy1Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;
        
         case 2:
                lcd.setCursor(0,0);lcd.print(" J1 >J2  J3  J4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(joy2Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(joy2Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(joy2Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;

          case 3:
                lcd.setCursor(0,0);lcd.print(" J1  J2 >J3  J4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(joy3Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(joy3Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(joy3Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;
          case 4:
                lcd.setCursor(0,0);lcd.print(" J1  J2  J3 >J4");
                lcd.setCursor(0,1);lcd.print(" LFT  RHT");lcd.setCursor(9,1);lcd.print("|" + String(joy4Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" LFT  RHT");
                       break;
                       case 1:
                            EEPROM.write(joy4Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">LFT  RHT");
                       break;
                       case 2:
                            EEPROM.write(joy4Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" LFT >RHT");
                       break;                       
                }
                break;
                
          case 5:
                MainMenuSelect = 0;
                break;
                }
}



void switch_settings(){


  switch(MainMenuSelect){
         case 0:
                lcd.setCursor(0,0);lcd.print(" S1  S2  S3  S4");
                lcd.setCursor(0,1);lcd.print(" PSH  TGL");lcd.setCursor(9,1);lcd.print("    ");
                break;

         case 1:
                lcd.setCursor(0,0);lcd.print(">S1  S2  S3  S4");
                lcd.setCursor(0,1);lcd.print(" PSH  TGL");lcd.setCursor(9,1);lcd.print("|" + String(sw1Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" PSH  TGL");
                       break;
                       case 1:
                            EEPROM.write(sw1Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">PSH  TGL");
                       break;
                       case 2:
                            EEPROM.write(sw1Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" PSH >TGL");
                       break;                       
                }
                break;
        
         case 2:
                lcd.setCursor(0,0);lcd.print(" S1 >S2  S3  S4");
                lcd.setCursor(0,1);lcd.print(" PSH  TGL");lcd.setCursor(9,1);lcd.print("|" + String(sw2Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" PSH  TGL");
                       break;
                       case 1:
                            EEPROM.write(sw2Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">PSH  TGL");
                       break;
                       case 2:
                            EEPROM.write(sw2Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" PSH >TGL");
                       break;                       
                }
                break;

          case 3:
                lcd.setCursor(0,0);lcd.print(" S1  S2 >S3  S4");
                lcd.setCursor(0,1);lcd.print(" PSH  TGL");lcd.setCursor(9,1);lcd.print("|" + String(sw3Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" PSH  TGL");
                       break;
                       case 1:
                            EEPROM.write(sw3Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">PSH  TGL");
                       break;
                       case 2:
                            EEPROM.write(sw3Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" PSH >TGL");
                       break;                       
                }
                break;
          case 4:
                lcd.setCursor(0,0);lcd.print(" S1  S2  S3 >S4");
                lcd.setCursor(0,1);lcd.print(" PSH  TGL");lcd.setCursor(9,1);lcd.print("|" + String(sw4Dir_Type));
                switch(SubMenuSelect){
                       case 0:
                            lcd.setCursor(0,1);lcd.print(" PSH  TGL");
                       break;
                       case 1:
                            EEPROM.write(sw4Dir_address, 0);
                            lcd.setCursor(0,1);lcd.print(">PSH  TGL");
                       break;
                       case 2:
                            EEPROM.write(sw4Dir_address, 1);
                            lcd.setCursor(0,1);lcd.print(" PSH>TGL");
                       break;                       
                }
                break;
                
          case 5:
                MainMenuSelect = 0;
                break;
                }
}
