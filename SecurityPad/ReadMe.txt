:Author: dauntless75
:Email: {tristandermody@gmail.com}
:Date: 02/07/2022
:Revision: version 2.0
:License: Public Domain

= Project: {SecurityPad}

A DIY keypad and locking system for all your security needs!

== Step 1: Installation

1. Open this file
2. Edit as you see fit
3. Upload to your Arduino via USB

== Step 2: Assemble the circuit

Assemble the circuit following the diagram Schematic.png attached to the sketch

== Step 3: Load the code

Upload the code contained in this sketch on to your board

=== Folder structure

....
 SecurityPadSketch        => Arduino sketch folder
  âââ SecurityPad.ino     => main Arduino file
  âââ Schematics.png      => image of the required schematics
  âââ ReadMe.txt          => this file
....

=== Contributing
To contribute to this project please contact dauntless75 https://id.arduino.cc/dauntless75

=== BOM

|===
| ID:| Part name:     | Part number:| Quantity:
| R1 | 10k Resistor   | ROX1SJ120R  | 2
| L1 | Red LED        | UR502DC     | 1
| L2 | Green LED      | G502DC      | 1
| C1 | Electrolytic   | ESK107M016- | 1
| -- | 100uf capacitor| AE3KA       | --
| S1 | Servo motor    | SM-S2309S   | 1 
| K1 | 4x4 Keypad     | 4X428A      | 1
| A1 | Arduino Uno    | A000066     | 1
|===


=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents.
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
