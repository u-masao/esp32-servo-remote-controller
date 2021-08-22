/*
   reffer: https://www.e-tecinc.co.jp/blog/2021/04/23/esp32_buzzerpwm/
*/

#include <ESP32Servo.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#define BUZZER_PIN 23
#define BUZZER_CHANEL 2
#define PERIOD 100

#define SERVO_PIN 13
#define SERVO_PULSE_WIDTH_MIN 700
#define SERVO_PULSE_WIDTH_MAX 2400

Servo myservo;

void setup() {
  Serial.begin(115200);
  setup_buzzer();
  zingle();
  setup_dabble();
  setup_servo();
}

void setup_buzzer() {
  ledcSetup(BUZZER_CHANEL, 12000, 8);
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANEL);
}
void setup_dabble() {
  Dabble.begin("ServoContoller1");
}
void setup_servo() {
  myservo.setPeriodHertz(50);
  myservo.attach(SERVO_PIN, SERVO_PULSE_WIDTH_MIN, SERVO_PULSE_WIDTH_MAX);
}

void zingle() {

  ledcWriteTone(BUZZER_CHANEL, 262); // ド
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 294); // レ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 330); // ミ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 349); // ファ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 392); // ソ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 440); // ラ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 494); // シ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 523); // ド
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 587); // レ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 659); // ミ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 698); // ファ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 784); // ソ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 880); // ラ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 988); // シ
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 1049); // ド
  delay(PERIOD) ;
  ledcWriteTone(BUZZER_CHANEL, 0);    // 消音
}

void beep(float coef) {
  ledcWriteTone(BUZZER_CHANEL, 1049 * coef); // ド
  delay(10) ;
  ledcWriteTone(BUZZER_CHANEL, 0);    // 消音
  // myservo.setPeriodHertz(50);
}
int angle = 90;
int speed = 1;
void loop() {
  Dabble.processInput();



  if (GamePad.isStartPressed())
  {
    Serial.print("Circle");
    zingle();
  }
  if (GamePad.isCrossPressed())
  {
    Serial.print("Circle");
    beep(0.5);
  }
  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    beep(1);
  }
  if (GamePad.isUpPressed())
  {
    angle = 90;
    beep(1);
  }
  if (GamePad.isLeftPressed())
  {
    angle = 0;
    beep(1);
  }
  if (GamePad.isRightPressed())
  {
    angle = 180;
    beep(1);
  }
  myservo.write(angle);
  delay(20);
}
