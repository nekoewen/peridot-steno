# The Peridot
The Peridot is a simple QMK-powered mechanical keyboard for using the Plover open source software for steno. If you’re not familiar, check out [the Open Steno Project](http://www.openstenoproject.org/) for links to the free software, learning resources, and other info to help you get started.

There are a number of hobbyist steno keyboard designs out there, and my goal with the Peridot is to make one that’s easy to build (hence I used basic through-hole components throughout) and open source. How much it will cost will depend a lot on the specifics of the components you choose, but it’ll be vastly cheaper than a professional stenotype. Feel free to make, sell, remix, etc.; this is my attempt to give something back to the Plover community.

## Bill of Materials
- 1x Pro Micro or other compatible microcontroller (Elite-C, BIT-C, KB2040, etc.), with matching USB cable
- 8x M2 standoffs
- 16x M2 screws
- 27x MX or Choc key switches; for steno I recommend switches with lighter springs, such as Choc Pink (25gf), Choc Pro Red (35gf) or Gateron Clear (35gf)
- 21 1u keycaps; flatter keycaps that make it easier to press two keys with one finger are generally better, such as MBK or WRK keycaps for Choc switches or F10 keycaps for MX switches.
- 6x 2u keycaps; particularly for MX switches, stabilizers are recommended but not required
- 4 or more adhesive rubber feet
- 27x 1N4148 through-hole diodes
- 2-pin reset switch (optional; 3x6x2mm DIP-2P switch, the same kind used on the Corne keyboard)
- WS2182 LED strip (optional)

## Tools
- Soldering iron with solder
- Wire clippers
- Wire stripper (if including an LED strip)
- Screwdriver
- Diode bending tool (optional; I use [this one](https://www.thingiverse.com/thing:4332520))

## Build Guide
1. Begin with the diodes. Bend the leads, insert them through the holes (the cathode is marked with a black line and should go on the square pad, so that the line on the diode matches the one printed on the PCB). Solder each diode, then use clippers to remove the excess leads.
2. Take your Pro Micro and flash the firmware (see below). I recommend doing this before soldering it just in case you got a bad board.
3. Solder the Pro Micro and its header pins to the underside of the board, with the Pro Micro’s components facing the board. You may want to use your clippers to trim off the excess part of the headers. If you’re adding a reset switch, put it into the PCB and solder its pins.
4. From here you should be able to test the keyboard’s functionality. If you plug it in, it should register as a Peridot keyboard, and you can use tweezers or a similar metal object to make contact on the switch pads to create the equivalent of keystrokes. If you use the default keymap you'll need to have Plover running for your computer to do anything with the keystrokes; use the "keyboard" keymap instead if you prefer to test it with regular keystrokes. If any of the keys don’t work, check to make sure you have the diodes soldered and facing the right direction, and also that the Pro Micro’s pins are all soldered in.
5. Use screws to secure standoffs to the top plate. It's a bit easier to do it ahead of time.
6. Once you’re satisfied that the keyboard actually works, you can begin assembling it in earnest. If you’re using stabilizers, put them in place now. Then put the top plate in place, and start pushing switches in place, though the plate and into the PCB so that each switch’s two leads go through the corresponding holes in the PCB. I like to put switches in the corners, solder them in place, and then fill in the rest of the switches. Once you’ve soldered all of the switches, I recommend testing the keyboard again to be sure that you have in fact soldered all of them. Once that’s done you can go ahead and put on the keycaps.
7. If you’re including an LED strip for pretty lights, use 3 wires to solder the pads on the PCB to the corresponding ones on the strip. Be sure the DIn lead is going to LED DAT on the board, as they won’t work if you attach it to DOut on the LED strip. If you plug it into your computer now, it should light up!
8. Put the bottom plate in place, and use the remaining screws to secure it in place.
9. Finally, put some adhesive rubber feet on the bottom. You’re done!

## Firmware
You can find a .hex file of the default Peridot firmware in this repository. If you don’t have any need to customize the layout, you can just download this and flash it to your Pro Micro.
1. Install [QMK Toolbox](https://github.com/qmk/qmk_toolbox) if you haven’t already.
2. Open `peridot_default.hex`.
3. Click the “Auto-Flash” checkbox.
4. Connect the Pro Micro to your computer.
5. Bridge the GND and RST pins with a metal object (or if it’s already soldered in place, press the reset switch).
6. QMK Toolbox should automatically flash the firmware for you!

If you want to customize the firmware:
1. Copy the “peridot” folder from the firmware folder here into the “keyboards” folder of your [QMK installation](https://docs.qmk.fm/#/newbs_getting_started). You can modify the files in this folder as desired.
2. Open a terminal window (for your OS if you’re using macOS or Linux, or [QMK MSYS](https://msys.qmk.fm/) if you’re using Windows).
3. Navigate to the QMK folder (typically `cd qmk_firmware`).
4. Type “`make peridot:default`” (or replace “`default`” with the name of your new keymap) and it should compile.
5. Type "`make peridot:default:flash`" (or replace flash with “`dfu`”) to flash it.

If you're using a KB2040 or similar controller, you'll need to use QMK's [Converters](https://github.com/qmk/qmk_firmware/blob/4020674163fc80914059c4c9c3be5c0ae00bd150/docs/feature_converters.md) feature, so for example compiling and flashing for a KB2040 would go as follows:

`qmk flash -c -kb peridot -km default -e CONVERT_TO=kb2040`
