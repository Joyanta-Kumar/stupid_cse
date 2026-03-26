# Atmega168


## AVR 8-bit microcontroller.  
### Question:
1. What is a microcontroller?  
2. What does it mean by the phrase `8-bit microcontroller`?  
3. Are there other `x-bit microcontrollers`?  

## Advanced RISC architecture.  
- 131 powerful instructions - most single clock
- 32 x 8 general purpose registers.
- Fully static operation
- Up to 16 MIPS throughput at 16MHz
- On-chip 2-cycle multiplier

### Questions
1. What is an single clock or multiclock instruction?
2. How many types of registers does a computer have?
3. What is static and dynamic operation?
4. MIPS ? Throughput ? What are those things?
5. What is a multiplier? Why is it called cycle multiplier?

## Non-volatile program and memories
- 4/8/16 KB of __in-system-self-programmable__ flash.
    - Endurance: 10,000 write/erase cycle.
- Optional boot code section with independent lock bits.
    - In-system programming by on-chip boot program.
    - True read-while-write operation
- 256/512 B EEPROM
    - Endurance: 50,000 write/erase cycle.
- 512/1024 KB internal SRAM
- Programming lock for software security.

### Questions
1. What is 'in-system-self-programmable' flash?
2. What is boot code section? What does it do?
3. Why is independent lock bit special?
4. So, EEPROM is not part of the flash memory, right?
5. Can there be any external SRAM?
6. How do I know the programming lock works?

## Peripheral features
- Two 8-bit counter with separate prescaler and compare mode.
- One 16-bit counter with separate prescaler and compare mode and captuure mode.
- Real time counter with separate oscillator.
- Six PWM channel.
- 8-channel 10-bit ADC.
- Programmable serial USART.
- Master-slave SPI serial interface.
- Byte-oriented 2 wire serial interface.
- Programmable watchdog timer with separate on-chip oscillator.
- On-chip analog comparator.
- IInterrupt and wake-up on pin change.

### Questions
1. what is counter and prescaler and compare mode?
2. What is capture mode?
3. What does the RTC do?
4. What is USART? Is there any unprogrammable version of it?
5. What is BO2W?
6. How many types of timer and how many oscillator in a computer!
7. Does all computer have analog comparator?
8. What does it mean by the phrase, 'pin-change'?

## Spericla microcontroller features
- Power-on reset and programmble brown-out detection.
- Internal calibrated oscillator.
- External and internal interrupt source.
- Five sleept modes: idle, ADC noise reduction, power-save, power-down, standbly.

### Quesitons
1. How does a computer brown-out?
2. Can it differentiate between poweroff->poweron and reboot?
3. How many oscillator does a computer need and why?
4. What is difference between external and internal interrupt?
5. Oooo. I only knew 'sleep'.

## IO and packages
- 23 programmable IO lines
- Green/ROHS 32-lead TQFP and 32-pad QFN

No idea what those are.

## Operation voltage
- 2.7V - 5.5V

## Temperature range
- -40C to 150C

## Speed grade
- 0 - 8MHz at 2.7 to 5.5 V
- 0 - 16MHz at 4.5 to 5.5 V

### Questions
1. How do I select one 

## Lower power consumption
- Active mode: 4MHz, 3.0V 1.8mA
- Power-down mode: 5 micro Ampere at 3.0V

### Questions
1. How do I switch?

## AEC-Q100 Grade 0 qualified
