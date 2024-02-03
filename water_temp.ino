#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2     // データ(黄)で使用するポート番号
#define ONE_WIRE_BUS_2 3   // 新しい温度センサのデータ(黄)で使用するポート番号
#define SENSER_BIT 10      // 精度の設定bit

OneWire oneWire(ONE_WIRE_BUS);
OneWire oneWire2(ONE_WIRE_BUS_2);  // 新しい温度センサのワイヤーライブラリの初期化
DallasTemperature sensors(&oneWire);
DallasTemperature sensors2(&oneWire2);  // 新しい温度センサのDallasTemperatureライブラリの初期化

void setup(void) {
  Serial.begin(9600); // 温度表示確認用
  sensors.setResolution(SENSER_BIT);
  sensors2.setResolution(SENSER_BIT);  // 新しい温度センサの精度の設定
}

void loop(void) {
  sensors.requestTemperatures();              // 既存の温度センサから温度取得要求
  Serial.print("Sensor 1: ");
  Serial.println(sensors.getTempCByIndex(0)); // 既存の温度センサの温度の取得&シリアル送信

  sensors2.requestTemperatures();             // 新しい温度センサから温度取得要求
  Serial.print("Sensor 2: ");
  Serial.println(sensors2.getTempCByIndex(0));// 新しい温度センサの温度の取得&シリアル送信

  delay(1000);  // 適宜調整
}
