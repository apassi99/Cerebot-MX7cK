# Cerebot-MX7cK

Mini projects on Digilent Cerebot MX7cK microcontroller board.

<img src="https://cloud.githubusercontent.com/assets/6227984/12051780/10391e18-aed6-11e5-8c51-1c44f10bb44f.png" width=350>

# Compiler Toolchain
- For all the example above I am using XC32 (v1.00) Compiler Toolchains set.
- Family is set to PIC32.
- Device is set to PIC32MX795F512L.

# ADC
- This project is a simple tutorial demonstrating using the Analog to Digital Convertor on the board. An ADC interrupt is generated whenever a value is sampled. This value is then displayed on a OLED module. The API to write to the OLED is available in mylib. Following is the higher level diagram:

<img width="483" alt="screen shot 2015-12-31 at 12 12 30 am" src="https://cloud.githubusercontent.com/assets/6227984/12070777/d4cd4eee-b056-11e5-83ab-c3cd6b2e807f.png">
