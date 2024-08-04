# TICK_TALK
An experimental 8-bit, bit serial computer.

TICK is an experimental 8-bit, serial arithmetic CPU designed around the commonly available 74HCxx logic series.

TICK uses 26 74HXxx ICs, plust a 32K byte RAM and a 64K x 16-bit ROM - or a ROM emulator.

TICK fits into a 4-layer PCB, sized 100mm x 110mm. It has 5 principal connectors that allow you to access all of the main signals and buses.

PCB Headers are included that will allow a very low-cost Raspberry Pi Pico (clone) to be plugged in, providing emulation of the ROM and also implementing a simple serial interface to a laptop or PC.

TICK has evolved slowly over several months, and this repo reflects the most recent design files, manufacturing data and BOM. The earlier repo "TICK" is purely reserved for earlier work. All current and future developments will be documented here.

TICK started life a few months ago and is highly influenced by the the developments I did on "MITE" its 16-bit Cousin. Here the basics of the timing pulse generator and ALU were thashed out to the point that I am happy to utilise them in a new design.

Much of the combinational logic has been rationalised, and short of implementing the ALU and control logic in a ROM, I believe that I have reached a point where the logic is stable, and not reduced to a blackbox ROM.

TICK is 26 74HCxx ICs plus a ROM and RAM.

The ICs are utilised in 5 main sub-circuits:

1. Clock Sequencer and Timing Pulse Generator.

2. Instruction Decoder

3. ALU and PC Incrementer, plus Jump logic.

4. Memory Control Hardware.

5. GPIO and ROMulator interfaces.

In an ideal world,  TICK would be a BlackBox with just 2 wires for power, and 2 wires for data in and data out. If you look at a landline telephone or broadband modem, they only have 2 wires or 4 wires. However for the purposes of this project we reqire syncronous data transfer - and that needs a clock that is shared between all nodes.

In general terms, TICK communicates with external devices via an SPI compatible interface.


## Architecture

TICK is highly influenced by Marcel van Kervinck's 8-bit Gigatron TTL Computer. The Gigatron used ten ICs in its ALU, I can do it serially in two. However a bit-serial design needs additional ICs to implement the clock sequencer, the timing pulse generator and the SRAM and Jump logic.

It is very marginal whether an 8-bit serial architecture will have fewer ICs than an 8-bit parallel design. Bit Serial really comes into fruition when you have a wordsize of 16 or more bits.

So the motivation for developing TICK was to make an intelligent node that can interface to SPI serial peripherals and other intelligent nodes. It won't be the fastest computer on the planet - but it should be able to compete with 1970s/80s 8-bit workhorses, like the 6502, Z80, 8051, 6309 etcand even older machines that predate the microprocessor - such as the  PDP-8 (1965) and the EDUC8 (1974).

TICK is a modified Harvard architecture.  Address and data from the ROM are conveyed on separate buses to those of the RAM. Simple shift registers are used to convert between the serial and parallel domains. A task that they can do very efficiently.

### Registers

TICK has a single 8-bit accumulator AC. AC may be loaded with an 8-bit literal direct from the lower 8 ROM data lines, or AC can be loaded with data addressed from the 32K x 8-bit SRAM.

As well as the Accumulator AC, TICK has a 16-bit wide general purpose register known as the B-Register. The B-Reg is 16-bits wide, in order to accept a 16-bit word, in parallel from the ROM and either use that as a indirect RAM address, or load it into the ROM Program Counter (PC) to perform a Conditional Branch or a 16-bit Long Jump.

The PC mentioned above is also 16-bits wide and can cover the full 16 bits of the ROM addressing range. A 16-bit jump is non-conditional, but an 8-bit "page" branch is conditional on the ZERO and SIGN flags or the Accumulator.






