// Memasukkan Libary yang dibutuhkan
#include <Wire.h>
#include <Adafruit_TCS3200.h>
#include <Servo.h>


// Pin konektor TCS3200 color sensor
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define outPin 6

// Pin motor servo
#define servoPin 9
// inisialisasi sensor warna
Adafruit_TCS3200 tcs = Adafruit_TCS3200(S2, S3, S0, S1, outPin);

// Inisialisasi motor servo
Servo servo;

void setup() {
  Serial.begin(9600);
  tcs.begin();
  servo.attach(servoPin);
}

void loop() {
  // Membaca nilai RGB dari sensor warna
  uint16_t red, green, blue;
  tcs.getRawData(&red, &green, &blue);

  // Print nilai RGB dari sensor warna
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.println(blue);

  // Pendeteksi warna buah kakao (bergantung nilai RGB)
  if (red > 200 && green > 200 && blue < 100) {
    // Servo bergerak memotong, jika kuning (bergerak 90 derajat)
    servo.write(90);
    delay(1000); // Delay untuk menstabilkan posisi servo
  } else {
    // posisi servo kembali normal
    servo.write(0);
  }

  // Delay untuk pengecekan selanjutnya
  delay(1000);
}
