IOTAB Library(R1.0)
                                            2019.06.22 TABrain Inc.

- 概要
　IoTAB(V2)を簡単に利用するためのArduino用のライブラリです。

- 提供するクラスとメソッド
　IoTABクラスのライブラリで、以下のメソッドを提供します。
	int	begin(void)			このライブラリを初期化して利用可能にします
	void setLed(int sw)		LED2を点灯または消灯します
	void turnOn3GIM(void)	3GIM/4GIMの電源をONにします
	void turnOff3GIM(void)	3GIM/4GIMの電源をOFFにします
	int getVIN(void)		電源電圧VBATを計測します

- 補足
　上記以外に、ピン番号等を定義したシンボルが利用できます。

　使い方は、IoTABのサンプルスケッチを参照ください。

　IoTABに搭載されている加速度センサMMA8451Qや温度センサSTTS751等の制御は、別途提供する各々のライブラリ
　mma8451qやstts751をご利用ください。使い方は、各ライブラリのサンプルを参照ください。

　IoTABに搭載可能な3G通信モジュール3GIM/4GIMの制御は、別途提供する3GIM用のライブラリa3gim2をご利用ください。

　IoTABに搭載されているマイコンATSAMD21G18には、RTCが搭載されています。このRTCを使えば、指定した時刻までスリープする
　等の省電力化が可能となります。このRTCの制御には、Arduino LCCが提供しているArduino Zero用の標準ライブラリ
　RTCZeroを利用することができます。
--
