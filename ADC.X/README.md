# ADC10 FUNCTIONS 

The PIC32MX has an ADC with multiple mode and configuration options. The ADC library functions are available to allow high-level control of the ADC. The following ofunctions and macros are available:

| Function Name              | Functionality           |
| -------------------------- |:------------------------|
| AcquireADC10()             |  Starts sample acquisition for the currently select channel |
| BusyADC10()                |  Returns the status of the conversion done bit.             |
| CloseADC10()               |  Disables and turns off the ADC.                            |
| ConfigIntADC10()           |  Configures the priorty and sub-priority for the ADC interrupt and enables the interrupt. |
| ConvertADC10()             |  Starts a conversion for the acquired sample.               |
| EnableADC10()              |  Turns the ADC on.                                          |
| OpenADC10()                |  Configures and enables the ADC module.                     |
| ReadActiveBufferADC10()    |  Returns the buffer that is being written when Dual Buffer mode is in use.                |
| ReadADC10()                |  Returns the vaule in the specified location of the ADC result buffer.                    |
| SetChanADC10()             |  Configures the ADC input multiplexers.                     |
