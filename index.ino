#include <LiquidCrystal.h>
// LCD Kütüphanesini bağlanan pin’ler ile başlat.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int SicaklikPin = A0; // LM35 sensöre bağlı pin (Analog 0)
int OkunanDeger; // Analog 0'dan okunacak değer (0-1023) LM35'in vereceğı en 
büyük okuma değeri 1V=205 olacak.
int Sicaklik; //
void setup() {
// LCD’yi 16 sütün, 2 satır olarak başlat
lcd.begin(16, 2);
// Birinci satıra “Oda Sıcaklığı:” yaz.
lcd.print("Oda sicakligi:");
}
void loop() {
OkunanDeger = analogRead(SicaklikPin);
Sicaklik = map (OkunanDeger, 0, 205, 0, 100); //(0-1v 0-205 okuma değerini, 0-100 sıcaklığa dönüştür.)
// İmleci 2. satıra getir.
// Not: Satır: 0, Satır 2: 1 olarak geçer. Satır sayıları 0'dan başlar.
lcd.setCursor(0, 1);
lcd.print(Sicaklik); // hesaplanan sıcaklığı yazdır.
lcd.print(" Derece"); // devamına birimi olan derecece yaz.
delay (1000); // Sonraki ölçümden önce 1 saniye bekle.
}
