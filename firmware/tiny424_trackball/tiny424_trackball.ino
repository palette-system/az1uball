// 1Uトラックボールユニットのホイールセンサーの入力をI2Cに流す

// 開発環境の作り方
// https://ameblo.jp/pta55/entry-12654450554.html

#include <Wire.h>
#include <avr/pgmspace.h>

// ATTiny202 本体のアドレス
#define I2C_SLAVE_ADD 0x0A

// カウントの方式(0=通常 / 1=AZ用)
uint8_t count_type = 0;

// 送信バッファ
uint8_t send_input[5];

// 最後にホールセンサからデータを受け取ったミリ秒
unsigned long last_time[4];

// I2Cイベント
void receiveEvent(int data_len); // データを受け取った
void requestEvent(); // データ要求を受け取った

// ホールセンサー読み込み用割り込み関数
void attachLeft();
void attachRight();
void attachUp();
void attachDown();

void setup() {
    // ロータリーエンコーダ読み込みピンの初期化
    pinMode(A4, INPUT); // 左
    pinMode(A1, INPUT); // 右
    pinMode(A5, INPUT); // 上
    pinMode(A3, INPUT); // 下
    pinMode(A6, INPUT_PULLUP);

    // バッファの初期化
    memset(send_input, 0x00, 5);
    memset(last_time, 0x00, 4 * sizeof(unsigned long));

    // I2C スレーブ初期化
    Wire.begin(I2C_SLAVE_ADD);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    // ホールセンサーの回転健知時のイベント登録
    attachInterrupt(A4, attachLeft, CHANGE);
    attachInterrupt(A1, attachRight, CHANGE);
    attachInterrupt(A5, attachUp, CHANGE);
    attachInterrupt(A3, attachDown, CHANGE);
}

// コマンドを受け取った
void receiveEvent(int data_len) {
  // 最初の1バイトだけ取得
  uint8_t d = Wire.read();
  if (d == 0x90) {
    count_type = 0;
  } else if (d == 0x91) {
    count_type = 1;
  }
  // 残りは空読み
  while (Wire.available()) {
    Wire.read();
  }
}

// I2Cデータ要求を受け取った時の処理
void requestEvent() {
  // トラックボール操作の情報を送る
  Wire.write(send_input, 5);
  // バッファをリセット
  memset(send_input, 0x00, 4);
}

// ホールセンサーの回転を検知した時のイベント 0=左 / 1=右 / 2=上 / 3=下
void attachExec(int i) {
  unsigned long n = millis(); // 現在の時間
  unsigned long t = (n - last_time[i]); // 前回実行時からどれくらい時間が経ったか
  last_time[i] = n; // 最後に実行した時間を更新
  if (send_input[i] > 250) return; // 250超えをMAX値とする
  if (count_type == 0) {
    // 通常モードは常に１ずつ移動
    if (t > 1) {
      send_input[i] += 1;
    }
  } else if (count_type == 1) {
    // 経過時間別に移動距離加算
    if (t > 50) {
      send_input[i] += 1;
    } else if (t > 30) {
      send_input[i] += 2;
    } else if (t > 1) {
      send_input[i] += 3;
    }
  }
}

// 左ホイール回転検知
void attachLeft() {
  attachExec(0);
}

// 右ホイール回転検知
void attachRight() {
  attachExec(1);
}

// 上ホイール回転検知
void attachUp() {
  attachExec(2);
}

// 下ホイール回転検知
void attachDown() {
  attachExec(3);
}

void loop() {
  // タクトスイッチの状態を送信バッファに反映
  if (!digitalRead(A6)) {
    send_input[4] = 0x80;
  } else {
    send_input[4] = 0x00;
  }
  delay(2);
}
