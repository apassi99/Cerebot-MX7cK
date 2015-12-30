#include <plib.h>

#include "../mylib/PmodOLED.h"
#include "../mylib/OledChar.h"
#include "../mylib/OledGrph.h"
#include "../mylib/delay.h"

#pragma config ICESEL       = ICS_PGx1  // ICE/ICD Comm Channel Select
#pragma config DEBUG        = OFF       // Debugger Disabled Kit

#pragma config FNOSC		= PRIPLL	// Oscillator selection
#pragma config POSCMOD		= XT		// Primary oscillator mode
#pragma config FPLLIDIV 	= DIV_2		// PLL input divider
#pragma config FPLLMUL		= MUL_20	// PLL multiplier
#pragma config FPLLODIV 	= DIV_1		// PLL output divider
#pragma config FPBDIV		= DIV_8		// Peripheral bus clock divider
#pragma config FSOSCEN		= OFF		// Secondary oscillator enable

// Globals Variables
unsigned int VoltageADC = 0x1234; // Voltage from ADC is stored here

#pragma interrupt InterruptHandler ipl1 vector 0
void InterruptHandler( void) {
    mAD1ClearIntFlag();
    VoltageADC = ReadADC10(0);
}

int main()
{
    DelayInit();
    OledInit();

    // Timer 3 will trigger ADC conversion
    OpenTimer3(T3_ON | T3_IDLE_CON | T3_SOURCE_INT | T3_PS_1_16 | T3_GATE_OFF,
             12500);  // set frequency to 50 Hz (= one sample every 20 ms)

    // Ensure the ADC is off before configuring it
    CloseADC10();

    
    // Configure to measure voltage between AN2 and NVREF
    SetChanADC10(ADC_CH0_POS_SAMPLEA_AN2 | ADC_CH0_NEG_SAMPLEA_NVREF);

    OpenADC10(ADC_MODULE_OFF
            |ADC_FORMAT_INTG16      // Unsigned 16-bit integer
            |ADC_CLK_TMR            // Use Timer3 as trigger for conversion
            |ADC_AUTO_SAMPLING_ON,
        ADC_VREF_AVDD_AVSS
            |ADC_SCAN_OFF
            |ADC_SAMPLES_PER_INT_1 	// Generate interrupt after every sample
            |ADC_BUF_16
            |ADC_ALT_INPUT_OFF,
        ADC_CONV_CLK_PB
            |ADC_CONV_CLK_Tcy2,
            ENABLE_AN2_ANA ,        // Enable AN2 as analog input
        SKIP_SCAN_ALL);

    EnableADC10();

    // Enable interrupts from ADC
    mAD1SetIntPriority(1);
    INTEnableSystemSingleVectoredInt();
    mAD1IntEnable(1);

    char buf[13];
	while (1) {
        OledClearBuffer();
        OledSetCursor(1, 0);
        sprintf(buf, "V ADC = %4X", VoltageADC);
        OledPutString(buf);
        OledUpdate();
    }

  return 0;
}
