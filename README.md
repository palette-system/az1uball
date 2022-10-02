# AZ1UBALL (1Uサイズのトラックボールモジュール)

<img src="/images/top.jpg" width="400">

<br><br>

## 商品ページ

https://booth.pm/ja/items/4202085

## 接続方法（ProMicro、Raspberry Pi Pico）

VCC、GND、SDA、SCLの接続と、SDA、SCLにプルアップ抵抗が必要です。<br>
キーボード側に実装してある必要があります。<br>
<br>
※ 抵抗は 10kΩ ～ 2kΩ 程度<br>
<br>
<img src="/images/conn_promicro_1.png" width="700"><br>

<br><br>
キーボード側にプルアップ抵抗が実装されていない場合は接続しない側のピンに抵抗を実装して下さい。
<br>
<img src="/images/conn_promicro_2.png" width="700"><br>

<br><br>

## 設定方法（QMK）
<br>
PIM447と同じ方法で使えるようになります。<br>
takashicompany さんのPIM447のブログがあるのでこの辺りを参考にして頂けたらです。<br>
<br>
https://zenn.dev/takashicompany/articles/aed80d4eaff308

<br><br>


## 接続方法（AZ-CORE、えむごっち）

TRRSのジャックから直接接続できます<br>
<br>
※ プルアップ抵抗は必要ありません。<br><br>
<img src="/images/conn_az_1.png" width="700"><br>

<br><br>
panda_micro越しに接続する事も出来ます。<br>
<img src="/images/conn_az_2.png" width="700"><br>

<br><br>

## 設定方法（AZ-CORE、えむごっち）
<br>
AZTOOLのI2C設定から追加するだけで使用できます。<br>
<br>
https://twitter.com/4py1/status/1568249131805835266

<br><br>

## 寸法
<br>
トッププレート<br>
<img src="/images/top_plate.png" width="400"><br>

<br>

断面<br>
<img src="/images/danmen.png" width="700"><br>

