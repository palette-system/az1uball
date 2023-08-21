# AZ1UBALL (1Uサイズのトラックボールモジュール)

<img src="/images/top.jpg" width="400">

<br><br>

## 商品ページ

https://booth.pm/ja/items/4202085

<br><br>

## 組み立て方

<br>
<img src="/images/build.jpg" width="700"><br>

<br><br>

## 接続方法（ProMicro、Raspberry Pi Pico）

VCC、GND、SDA、SCLの接続と、SDA、SCLにプルアップ抵抗が必要です。<br>
キーボード側に実装してある必要があります。<br>
<br>
※ 2023/5/23 以降のロットではプルアップ抵抗は必要ありません。<br>
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
ブログがあるのでこの辺りを参考にして頂けたらです。<br>

<br><br>

takashicompany 様（PIM447）<br>
https://zenn.dev/takashicompany/articles/aed80d4eaff308

<br><br>

@74thの制作ログ 様（CircuitPython）（AZ1UBALL）<br>
https://74th.hateblo.jp/entry/2022/10/09/181609

<br><br>

taka8aru 様（AZ1UBALL）<br>
https://taka8aru.blogspot.com/2023/07/az1uballpro-microqmk-firmware-34.html

<br><br>

Yuta Sakai 様（AZ1UBALL）
https://qiita.com/unbosoms/items/e58f12502115bfb7c303

<br><br>


## 接続方法（AZ-CORE、えむごっち）

TRRSのジャックから直接接続できます<br>
<br>
※ プルアップ抵抗は必要ありません。<br>
　　　（ケーブルが長くて反応しない場合は2kΩ程度の抵抗でプルアップして下さい）<br><br>

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
<a href="/hardware/plate_top/">トッププレート KiCadデータ</a>

<br><br>

断面<br>
<img src="/images/danmen.png" width="700"><br>

<br><br>

## フットプリント
<br>

<img src="/kicad/footprint.png" width="500"><br>
<a href="/kicad/">AZ1UBALL.kicad_mod</a>
<br><br>

## ファームウェアの開発環境の作り方
<br>
１．このサイトの手順で書込み機や、ArduinoIDEのインストールを行う<br>
https://ameblo.jp/pta55/entry-12654450554.html
<br>
<br>
２．tiny424_trackball.inoをArduinoIDEで開く。<br>
<a href="/firmware/tiny424_trackball/tiny424_trackball.ino">tiny424_trackball.ino</a>
<br>
<br>
３．ボード設定を開き Chip を ATiny424 にして、Clock を 10MHz internal にして、書込みを実行する。<br>
　　(ボード設定のその他の項目はデフォルトのままでOKです)<br><br>
<img src="/images/board_set.png" width="500"><br>
<br>
<br>

## その他情報
<br>
動作電圧：　3.3V or 5V （どちらでも動作します）<br>
消費電力：　約 8mA<br>
I2Cアドレス：　0x0A<br>

<br><br>
