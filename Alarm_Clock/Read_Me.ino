:Author: Tristan Dermody
:Email: tristandermody8@gmail.com
:Date: 08/07/2021
:Revision: version#2.0
:License: Public Domain

= Project: {Alarm_Clock}

A DIY LCD Alarm clock with custom characters, adjustable time and of course, an alarm! 
Note: Compatible with Arduino UNO Rev3

== Step 1: Installation

1. Open the code in the repository
2. Edit as you like! (the Alarm Time)
3. Enjoy!

== Step 2: Assemble the circuit

Assemble the circuit following the diagram schematics.fzz attached to the sketch

== Step 3: Load the code

Upload the code contained in this sketch on to your arduino UNO Rev3

=== Folder structure

....
  AlarmClock          => Arduino sketch folder
  Code.ino            => main Arduino file
  Schematics.png      => an image of the required schematics
  Libraries.zip       => required libaries download
  Layout.png          => an image of the layout
  ReadMe.ino         => this file
....

=== License
This project is released under a {GNU General Public License v3.0} License.

=== Contributing
To contribute to this project please contact me https://id.arduino.cc/dauntless75

=== BOM
Add the bill of the materials you need for this project.

|===
| ID | Part name      | Part number | Quantity
| R1 | 10k Resistor   | GS-0872     | 3
| P1 | Push Button    | 19614R.S    | 3
| A1 | Arduino Uno    | A000066     | 1
| B1 | Piezo Buzzer   | PKM22EPP-40 | 1
| A1 | LCD Display    | 1602A       | 1
| I1 | I2C Backpack   | LCM1602 II  | 1
|===


=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents.
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
