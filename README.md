# Cerebot-MX7cK

Mini projects on Digilent's [Cerebot MX7cK microcontroller board] (https://www.digilentinc.com/Products/Detail.cfm?NavPath=2,398,1244&Prod=CEREBOT-MX7CK).

<img src="https://cloud.githubusercontent.com/assets/6227984/12051780/10391e18-aed6-11e5-8c51-1c44f10bb44f.png" width=350>

# Compiler Toolchain
- For all the example above I am using XC32 (v1.00) Compiler Toolchains set.
- Family is set to PIC32.
- Device is set to PIC32MX795F512L.

# ADC
- This project is a simple tutorial demonstrating using the Analog to Digital Convertor on the board. An ADC interrupt is generated whenever a value is sampled. This value is then displayed on a OLED module. The API to write to the OLED is available in mylib. Following is the higher level diagram:

<img width="483" alt="screen shot 2015-12-31 at 12 12 30 am" src="https://cloud.githubusercontent.com/assets/6227984/12073883/2fce3b08-b103-11e5-8ba5-0c9a41900a49.png">
