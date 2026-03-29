<link rel="stylesheet" href="style.css">

# Atmega168


## AVR 8-bit microcontroller.  
### Questions
1. What is a microcontroller?  
2. What does it mean by the phrase `8-bit microcontroller`?  
3. Are there other `x-bit microcontrollers`?  

### Answers
A microcontroller is compact integrated circuit designed to perform a specific task inside an embedded system.  

A microcontroller at minimum, combines three core components on a single chip.  
1. CPU
2. Memory: Flash, RAM
3. IO peripherals: GPIO, Counter, Com interfaces

An 8-bit CPU can work with 8 bit data at a time.  
A Raspberry Pi Pico 2 might be a 64-bit microcontroller.  

## Advanced RISC architecture.  
- 131 powerful instructions - most single clock
- 32 8-bit general purpose registers.
- Fully static operation
- Up to 16 MIPS throughput at 16MHz
- On-chip 2-cycle multiplier

### Questions
1. What is an single clock or multiclock instruction?
2. How many types of registers does a computer have?
3. What is static and dynamic operation?
4. MIPS ? Throughput ? What are those things?
5. What is a multiplier?

### Answers
Add value of two registers: single clock
Fetch data from RAM: multi clock

So many types of registers
1. GPRs
2. Special Function Regsiters
3. Status Registers
4. Program Counter
6. Stack Pointer
7. MAR, MDR, IR

Dynamic operations means, CPU can not pause indefinitely without losing data in normal mode. The sleep mode is special case.

MIPS = Million Instructions Per Second
Throughput = Rate at which useful work is done.

A dedicated section for multiplication that can multiply two 8-bit integer in just 2 clock cycles.

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
3. So, EEPROM is not part of the flash memory, right?
4. Can there be any external SRAM?
5. How do I know the programming lock works?

### Answers
The flash memory can be reprogrammed without taking it off from the chip. Moreover, the cpu can erase and write new data or program on the flash. But for important runtime data, use EEPROM. Flash's read/write cycle is less than that of EEPROM.

Flash can be divided into bootloader and firmware. Firmware can be updated by the bootloader while the program is running.

Flash and EEPROM are different hardware things.

Some MCU supports external RAM. But not this one. Although there are ways to use external RAM with SPI or similar interfaces.

If locked, that firmware will be erased if I try to read or write.


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
