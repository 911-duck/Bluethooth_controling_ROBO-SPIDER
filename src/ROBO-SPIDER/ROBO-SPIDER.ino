#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

LiquidCrystal_I2C LCD(0x27, 16, 2);

/////////norm emo

byte gpnu1[8]{
  0b00111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};

byte gpnu2[8]{
  0b11100,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};

byte gpnd[8]{
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000,
};

/////////blinck emo

byte gpb[8]{
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
};

/////////sad emo

byte gpsu[8]{
  0b00000,
  0b00001,
  0b00111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};

/////////angry emo

byte gpau[8]{
  0b00000,
  0b10000,
  0b11100,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};

/////////happy emo

byte gphu1[8]{
  0b00000,
  0b00000,
  0b00011,
  0b01111,
  0b11100,
  0b11000,
  0b10000,
  0b00000,
};

byte gphu2[8]{
  0b00000,
  0b00000,
  0b11000,
  0b11110,
  0b00111,
  0b00011,
  0b00001,
  0b00000,
};

Servo FL1;
Servo FR1;
Servo BL1;
Servo BR1;

Servo FL2;
Servo FR2;
Servo BL2;
Servo BR2;

byte SW200 = 7;

byte i = 0;

int nsSW;
bool flagSW;
int ob = 6;

int give_paw_deg = 155;
int HI_TIME_LINE = 5;
int F_TIME_LINE = 3;
int jump_time_line = 7;
int state = 0;
int jumps = 5;
int jumps_state = 0;

int nach1[] = { 180, 180, 180, 180 };

int cal1[] = { 45, 45, 45, 45 };
int cal2[] = { 45, 140, 45, 130 };

int shagforw1_v1[] = { 45, 140 };
int shagforw1_v2[] = { 45, 160 };
int shagforw2_v1[] = { 140, 90 };
int shagforw2_v2[] = { 45, 0 };
int shagforw2_v3[] = { 45, 90 };
int shagforw2_v4[] = { 45, 90 };

int shagbott1_v1[] = { 45, 140 };
int shagbott1_v2[] = { 45, 160 };
int shagbott2_v1[] = { 140, 180 };
int shagbott2_v2[] = { 45, 90 };
int shagbott2_v3[] = { 45, 0 };
int shagbott2_v4[] = { 45, 0 };

int sit_down_v1[] = { 45, 110 };

int jump_v1[] = { 45, 90 };

bool flagNACH = 0;
bool flagT = 0;
bool stateA = 0;

unsigned long interval_30s = 30000;
unsigned long interval_1s = 1000;
unsigned long interval_3s = 3000;

unsigned long millis_save_read;
unsigned long millis_save;
unsigned long millis_save_nm;

void lcdbegin() {
  LCD.init();
  LCD.backlight();
  LCD.createChar(0, gpnu1);
  LCD.createChar(1, gpnd);
  LCD.createChar(7, gpnu2);
  LCD.createChar(2, gpb);
  LCD.createChar(3, gpsu);
  LCD.createChar(4, gpau);
  LCD.createChar(5, gphu1);
  LCD.createChar(6, gphu2);
  LCD.clear();
}

void setup() {
  lcdbegin();

  FL1.attach(2);
  FR1.attach(5);
  BL1.attach(3);
  BR1.attach(4);

  FL2.attach(8);
  BL2.attach(9);
  BR2.attach(10);
  FR2.attach(11);

  pinMode(SW200, INPUT);

  Serial.flush();
  Serial.begin(9600);
  Serial.println("~ROBO-SPIDER Welcome press '0' to start operation~");
}

//emothions
void normal_wait_emo() {
  LCD.setCursor(3, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(3, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  LCD.setCursor(11, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(11, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  delay(1000);
  LCD.clear();
  morganie_emo();
  delay(400);
  LCD.clear();
  LCD.setCursor(2, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(2, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  LCD.setCursor(10, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(10, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  delay(1000);
  LCD.clear();
  morganie_emo();
  delay(400);
  LCD.clear();
  LCD.setCursor(4, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(4, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  LCD.setCursor(12, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(12, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  delay(1000);
  LCD.clear();
  morganie_emo();
  delay(400);
  LCD.clear();
}

void normal_def_emo() {
  LCD.setCursor(3, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(3, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  LCD.setCursor(11, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(11, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  delay(1000);
  LCD.clear();
  morganie_emo();
  delay(300);
  LCD.clear();
}

void normal_emo() {
  LCD.setCursor(3, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(3, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  LCD.setCursor(11, 0);
  LCD.print(char(0));
  LCD.print(char(7));
  LCD.setCursor(11, 1);
  LCD.print(char(1));
  LCD.print(char(1));
}

void morganie_emo() {
  LCD.setCursor(3, 0);
  LCD.print(char(2));
  LCD.print(char(2));
  LCD.setCursor(11, 0);
  LCD.print(char(2));
  LCD.print(char(2));
}

void sad_emo() {
  LCD.setCursor(3, 0);
  LCD.print(char(3));
  LCD.print(char(0));
  LCD.setCursor(11, 0);
  LCD.print(char(0));
  LCD.print(char(4));
}

void angry_emo() {
  LCD.setCursor(3, 0);
  LCD.print(char(0));
  LCD.print(char(4));
  LCD.setCursor(3, 1);
  LCD.print(char(1));
  LCD.print(char(1));
  LCD.setCursor(11, 0);
  LCD.print(char(3));
  LCD.print(char(0));
  LCD.setCursor(11, 1);
  LCD.print(char(1));
  LCD.print(char(1));
}

void happy_emo() {
  LCD.setCursor(3, 0);
  LCD.print(char(5));
  LCD.print(char(6));
  LCD.setCursor(11, 0);
  LCD.print(char(5));
  LCD.print(char(6));
}

void function_give_paw() {
  while (true) {
    if (flagT == 0) {

      for (int j = cal1[2]; j < 125; j++) {
        BR1.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 45; j > 20; j--) {
        FL2.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = cal1[0]; j < nach1[0]; j++) {
        FR1.write(j);
        delay(HI_TIME_LINE);
      }

      flagT = 1;
    }
    if (Serial.available()) {
      LCD.clear();
      normal_emo();
      int read = Serial.parseInt();
      if (read == 10)
        for (int j = nach1[0]; j > cal1[0]; j--) {
          FR1.write(j);
          delay(HI_TIME_LINE);
        }

      for (int j = 125; j > cal1[2]; j--) {
        BR1.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 20; j < 45; j++) {
        FL2.write(j);
        delay(HI_TIME_LINE);
      }

      flagT = 0;
      return;
    }
  }
}


void function_HI() {
  while (true) {
    if (flagT == 0) {
      for (int j = cal1[2]; j < 125; j++) {
        BR1.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 45; j > 20; j--) {
        FL2.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = cal1[0]; j < nach1[0]; j++) {
        FR1.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 45; j < 90; j++) {
        FR2.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 90; j > 0; j--) {
        FR2.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 0; j < 90; j++) {
        FR2.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 90; j > 45; j--) {
        FR2.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = nach1[0]; j > cal1[0]; j--) {
        FR1.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 20; j < 45; j++) {
        FL2.write(j);
        delay(HI_TIME_LINE);
      }

      for (int j = 125; j > cal1[2]; j--) {
        BR1.write(j);
        delay(HI_TIME_LINE);
      }

      flagT = 1;
    } else {
      flagT = 0;
      return;
    }
  }
}

bool STATE(bool flag) {
  //Serial.println("~state - OK press '9' to continui ~");
  while (true) {
    delay(500);
    FL2.write(45);
    delay(500);
    BL2.write(45);
    delay(500);
    BR2.write(140);
    delay(500);
    FR2.write(45);
    delay(500);

    FL1.write(45);
    delay(500);
    BL1.write(45);
    delay(500);
    BR1.write(45);
    delay(500);
    FR1.write(45);
    delay(500);

    return flag = 1;
  }
}

void function_Forward() {
  while (true) {
    if (flagT == 0) {
      //1
      for (int j = shagforw1_v1[0]; j < shagforw1_v1[1]; j++) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v1[0]; j > shagforw2_v1[1]; j--) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v1[1]; j > shagforw1_v1[0]; j--) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }



      for (int j = shagforw1_v2[0]; j < shagforw1_v2[1]; j++) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v2[0]; j > shagforw2_v2[1]; j--) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v2[1]; j > shagforw1_v2[0]; j--) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }



      for (int j = shagforw2_v1[1]; j < shagforw2_v1[0]; j++) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v2[1]; j < shagforw2_v2[0]; j++) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }
      delay(F_TIME_LINE);


      //2

      for (int j = shagforw1_v2[0]; j < shagforw1_v2[1]; j++) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v3[0]; j < shagforw2_v3[1]; j++) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v2[1]; j > shagforw1_v2[0]; j--) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }



      for (int j = shagforw1_v2[0]; j < shagforw1_v2[1]; j++) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v4[0]; j < shagforw2_v4[1]; j++) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v2[1]; j > shagforw1_v2[0]; j--) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v3[1]; j > shagforw2_v3[0]; j--) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v4[1]; j > shagforw2_v4[0]; j--) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }
      delay(F_TIME_LINE);


      LCD.clear();
      morganie_emo();
      delay(200);
      LCD.clear();
      normal_emo();
      flagT = 1;
    } else {
      flagT = 0;
      return;
    }
  }
}

void function_Bottom() {
  while (true) {
    if (flagT == 0) {
      //1
      for (int j = shagbott1_v1[0]; j < shagbott1_v1[1]; j++) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v1[0]; j < shagbott2_v1[1]; j++) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v1[1]; j > shagbott1_v1[0]; j--) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }



      for (int j = shagbott1_v2[0]; j < shagbott1_v2[1]; j++) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v2[0]; j < shagbott2_v2[1]; j++) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v2[1]; j > shagbott1_v2[0]; j--) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }




      for (int j = shagbott2_v1[1]; j > shagbott2_v1[0]; j--) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v2[1]; j > shagbott2_v2[0]; j--) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }
      delay(F_TIME_LINE);
      //2

      for (int j = shagbott1_v2[0]; j < shagbott1_v2[1]; j++) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v3[0]; j > shagbott2_v3[1]; j--) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v2[1]; j > shagbott1_v2[0]; j--) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }



      for (int j = shagbott1_v2[0]; j < shagbott1_v2[1]; j++) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v4[0]; j > shagbott2_v4[1]; j--) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v2[1]; j > shagbott1_v2[0]; j--) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }


      for (int j = shagbott2_v3[1]; j < shagbott2_v3[0]; j++) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v4[1]; j < shagbott2_v4[0]; j++) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }
      delay(F_TIME_LINE);
      LCD.clear();
      morganie_emo();
      delay(200);
      LCD.clear();
      normal_emo();
      flagT = 1;
    } else {
      flagT = 0;
      return;
    }
  }
}

void function_Right() {
  while (true) {
    if (flagT == 0) {
      //1
      for (int j = shagforw1_v1[0]; j < shagforw1_v1[1]; j++) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v1[0]; j > shagforw2_v1[1]; j--) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v1[1]; j > shagforw1_v1[0]; j--) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }



      for (int j = shagforw1_v2[0]; j < shagforw1_v2[1]; j++) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v2[0]; j > shagforw2_v2[1]; j--) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v2[1]; j > shagforw1_v2[0]; j--) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }

      //2


      for (int j = shagbott1_v2[0]; j < shagbott1_v2[1]; j++) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v4[0]; j > shagbott2_v4[1]; j--) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v2[1]; j > shagbott1_v2[0]; j--) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }


      for (int j = shagbott1_v2[0]; j < shagbott1_v2[1]; j++) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v3[0]; j > shagbott2_v3[1]; j--) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v2[1]; j > shagbott1_v2[0]; j--) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }


      //finish

      for (int j = shagforw2_v1[1]; j < shagforw2_v1[0]; j++) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v2[1]; j < shagforw2_v2[0]; j++) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v3[1]; j < shagbott2_v3[0]; j++) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v4[1]; j < shagbott2_v4[0]; j++) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }

      delay(F_TIME_LINE);
      LCD.clear();
      morganie_emo();
      delay(200);
      LCD.clear();
      normal_emo();
      flagT = 1;
    } else {
      flagT = 0;
      return;
    }
  }
}

void function_Left() {
  while (true) {
    if (flagT == 0) {
      //1
      for (int j = shagforw1_v2[0]; j < shagforw1_v2[1]; j++) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v3[0]; j < shagforw2_v3[1]; j++) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v2[1]; j > shagforw1_v2[0]; j--) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }




      for (int j = shagforw1_v2[0]; j < shagforw1_v2[1]; j++) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v4[0]; j < shagforw2_v4[1]; j++) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw1_v2[1]; j > shagforw1_v2[0]; j--) {
        FR1.write(j);
        delay(F_TIME_LINE);
      }

      //2


      for (int j = shagbott1_v2[0]; j < shagbott1_v2[1]; j++) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v2[0]; j < shagbott2_v2[1]; j++) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v2[1]; j > shagbott1_v2[0]; j--) {
        FL1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v1[0]; j < shagbott1_v1[1]; j++) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v1[0]; j < shagbott2_v1[1]; j++) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott1_v1[1]; j > shagbott1_v1[0]; j--) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }

      //finish

      for (int j = shagforw2_v3[1]; j > shagforw2_v3[0]; j--) {
        BL2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagforw2_v4[1]; j > shagforw2_v4[0]; j--) {
        FR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v1[1]; j > shagbott2_v1[0]; j--) {
        BR2.write(j);
        delay(F_TIME_LINE);
      }

      for (int j = shagbott2_v2[1]; j > shagbott2_v2[0]; j--) {
        FL2.write(j);
        delay(F_TIME_LINE);
      }
      LCD.clear();
      morganie_emo();
      delay(200);
      LCD.clear();
      normal_emo();
      delay(F_TIME_LINE);
      flagT = 1;
    } else {
      flagT = 0;
      return;
    }
  }
}

void function_Sit_down() {
  while (true) {
    if (flagT == 0) {
      stateA = 1;
      LCD.clear();
      morganie_emo();

      for (int j = sit_down_v1[0]; j < sit_down_v1[1]; j++) {
        BR1.write(j);
        delay(F_TIME_LINE);
      }
      for (int j = sit_down_v1[0]; j < sit_down_v1[1]; j++) {
        BL1.write(j);
        delay(F_TIME_LINE);
      }
      happy_emo();

      jumps_state = 1;
      flagT = 1;
    }

    def_emoj_fun();

    if (Serial.available()) {
      LCD.clear();
      normal_emo();
      int read = Serial.parseInt();
      switch (read) {
        case 10:
          {
            stateA = 0;
            millis_save = millis();
            for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
              BR1.write(j);
              delay(F_TIME_LINE);
            }
            for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
              BL1.write(j);
              delay(F_TIME_LINE);
            }



            for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
              FR1.write(j);
              delay(F_TIME_LINE);
            }
            for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
              FL1.write(j);
              delay(F_TIME_LINE);
            }
            flagT = 0;
            jumps_state = 0;
            Serial.println("~stand up~");
            return;
            break;
          }
        case 12:
          {
            stateA = 0;
            millis_save = millis();
            Serial.println("~lie~");
            for (int j = sit_down_v1[0]; j < sit_down_v1[1]; j++) {
              FR1.write(j);
              delay(F_TIME_LINE);
            }
            for (int j = sit_down_v1[0]; j < sit_down_v1[1]; j++) {
              FL1.write(j);
              delay(F_TIME_LINE);
            }
            jumps_state = 0;
            break;
          }
        case 8:
          {
            millis_save = millis();
            LCD.clear();
            morganie_emo();
            delay(200);
            LCD.clear();
            happy_emo();
            if (jumps_state == 1) {
              stateA = 1;
              Serial.println("~jump~");
              for (int i = 0; i < jumps; i++) {
                for (int j = jump_v1[0]; j < jump_v1[1]; j++) {
                  FR1.write(j);

                  FL1.write(j);

                  FR1.write(j);

                  FL1.write(j);
                  delay(jump_time_line);
                }
              }
            } else {
              stateA = 0;
              for (int i = 0; i < jumps; i++) {

                for (int j = jump_v1[0]; j < jump_v1[1]; j++) {
                  FR1.write(j);

                  FL1.write(j);

                  FR1.write(j);

                  FL1.write(j);

                  BR1.write(j);

                  BL1.write(j);

                  BR1.write(j);

                  BL1.write(j);
                  delay(jump_time_line);
                }
              }
            }


            break;
          }
        case 6:
          {
            stateA = 1;
            millis_save = millis();
            Serial.println("~sit down~");
            for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
              FR1.write(j);
              delay(F_TIME_LINE);
            }
            for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
              FL1.write(j);
              delay(F_TIME_LINE);
            }
            jumps_state = 1;
            break;
          }
        case 1:
          {
            millis_save = millis();
            LCD.clear();
            morganie_emo();
            delay(200);
            LCD.clear();
            happy_emo();
            Serial.println("~HI~");
            flagT = 0;
            function_HI();
            break;
          }
        case 7:
          {
            millis_save = millis();
            LCD.clear();
            morganie_emo();
            delay(200);
            LCD.clear();
            happy_emo();
            Serial.println("~give paw~");
            flagT = 0;
            function_give_paw();
            break;
          }
        case 13:
          {
            Serial.println("~gaf~");
            golos();
            millis_save = millis();
            break;
          }
      }
    }
  }
}

void function_Jump() {

  while (true) {

    for (int j = jump_v1[0]; j < jump_v1[1]; j++) {
      FR1.write(j);

      FL1.write(j);

      BR1.write(j);

      BL1.write(j);

      delay(jump_time_line);

      if (Serial.available()) {
        int read = Serial.parseInt();
        if (read == 10) {
          LCD.clear();
          morganie_emo();
          for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
            BR1.write(j);
            delay(F_TIME_LINE);
          }
          for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
            BL1.write(j);
            delay(F_TIME_LINE);
          }

          for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
            FR1.write(j);
            delay(F_TIME_LINE);
          }
          for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
            FL1.write(j);
            delay(F_TIME_LINE);
          }

          Serial.println("~stand up~");
          return;
        }
      }
    }
  }
}

void golos() {
  LCD.clear();
  angry_emo();
  delay(500);
  if (stateA == 0) {
    for (int e = 0; e < 6; e++) {
      for (int j = jump_v1[0]; j < jump_v1[1]; j++) {
        FR1.write(j);

        FL1.write(j);

        BR1.write(j);

        BL1.write(j);

        delay(jump_time_line);
      }
    }
    delay(1500);
    for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
      BR1.write(j);
      delay(F_TIME_LINE);
    }
    for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
      BL1.write(j);
      delay(F_TIME_LINE);
    }

    for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
      FR1.write(j);
      delay(F_TIME_LINE);
    }
    for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
      FL1.write(j);
      delay(F_TIME_LINE);
    }
  } else {
    for (int e = 0; e < 6; e++) {
      for (int j = jump_v1[0]; j < jump_v1[1]; j++) {
        FR1.write(j);

        FL1.write(j);

        delay(jump_time_line);
      }
    }
    delay(1500);
    for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
      FR1.write(j);
      delay(F_TIME_LINE);
    }
    for (int j = sit_down_v1[1]; j > sit_down_v1[0]; j--) {
      FL1.write(j);
      delay(F_TIME_LINE);
    }
  }
  LCD.clear();
}

void def_emoj_fun() {
  bool stateSW = digitalRead(SW200);
  Serial.println(stateSW);

  if (millis() - millis_save >= interval_30s && flagNACH == 1) {
    if (millis() - millis_save_nm >= interval_3s) {
      normal_wait_emo();
      millis_save_nm = millis();
    }
  } else {
    if (millis() - millis_save_nm >= interval_3s) {
      normal_def_emo();
      millis_save_nm = millis();
    }
  }

  if (stateSW == true && flagNACH == 1) {
    golos();
  }

  normal_emo();
}

void loop() {
  def_emoj_fun();

  stateA = 0;

  if (Serial.available()) {
    int read = Serial.parseInt();
    if (flagNACH == 0) {
      if (read == 0) {
        Serial.println("~start~");
        flagNACH = STATE(0);
        normal_emo();
        millis_save = millis();
      }
    } else {
      normal_emo();
      switch (read) {
        case 1:
          {
            Serial.println("~HI I'm ROBO-SPIDER 1.0~");
            millis_save = millis();
            LCD.clear();
            morganie_emo();
            delay(200);
            LCD.clear();
            happy_emo();

            function_HI();

            LCD.clear();
            normal_emo();

            break;
          }
        case 2:
          {
            Serial.println("~Forward~");
            function_Forward();
            millis_save = millis();
            break;
          }
        case 3:
          {
            Serial.println("~Bottom~");
            function_Bottom();
            millis_save = millis();
            break;
          }
        case 4:
          {
            Serial.println("~Right~");
            function_Right();
            millis_save = millis();
            break;
          }
        case 5:
          {
            Serial.println("~Left~");
            function_Left();
            millis_save = millis();
            break;
          }
        case 6:
          {
            Serial.println("~Sit down~");
            millis_save = millis();
            function_Sit_down();
            break;
          }
        case 8:
          {
            LCD.clear();
            morganie_emo();
            delay(200);
            LCD.clear();
            happy_emo();
            Serial.println("~jumping~");
            function_Jump();
            LCD.clear();
            normal_emo();
            millis_save = millis();
            break;
          }
        case 7:
          {
            Serial.println("~paw~");
            flagT = 0;
            LCD.clear();
            morganie_emo();
            delay(200);
            LCD.clear();
            happy_emo();
            function_give_paw();

            millis_save = millis();
            break;
          }
        case 13:
          {
            Serial.println("~gaf~");
            golos();
            millis_save = millis();
            break;
          }
      }
    }
  }
}
