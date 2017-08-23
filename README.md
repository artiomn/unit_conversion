# Unit conversion

This is modularized unit converter in C, running under Linux and other Unix-like.
Program was written in the 2006.


## Compile

$ make


## Install

$ make install

Program will be installed in the "${PREFIX}/bin" (/usr/bin by default).


## Uninstall

$ make uninstall


## Run

Usage: `uc [-f{from_units}] [-t{to_units}] [-q] [-v] [value_1 value_2 ... value_n]`

- -f - from units.
- -t - to units.
- -h - this help.
- -q - quiet mode.
- -v - verbose (cancelling -q).
- -V - version.

If values are not specified, program will works as a filter.


### Supported conversion units

- dec - decimal numbers.
- bin - binary numbers.
- hex - hexadecimal numbers.
- oct - octal numbers.
- rome - Rome digits.
- cels - Celsius degrees.
- farg - Fahrenheit degrees.
- kalv - Kelvin degrees.
- mkm - micrometres.
- mm - millimetres.
- cm - centimetres.
- m - meters.
- km - kilometers.
- inch - inches.
- foot - foots.
- yard - yards.
- mile - miles.
- trer - English-Russian transliteration.
- trre - Russian-English transliteration.


### Examples

Run as a filter with default conversions:

`$ uc`


Convert 10 and 20, using default conversions and exit:

`$ uc 10 20`


Convert 1024 from decimal to binary, then quietly convert 30 to Rome numbers, enable verbosity, convert -0xA77 from hexadecimal to decimal:

`$ uc -fdec -tbin 1024 -q 30 -trome 13 -v -fhex -tdec -0A77`


Transliterate string "Сегодня на улице: -25C" to latin, convert -25 from Celsius to Fahrenheit, print `F` symbol:

`$ uc -q -ftrre -ttrer "Сегодня на улице: -25C" -fcels -tfarg -25 -ftrre -ttrre F`


## Notes

This is an old program (since 2006), but it was compiled and worked in the end of 2017.
This is wonderful.
Original file encoding was koi8-r, but I have recoded source in UTF-8.
I don't want to change anything. This is my museum exhibit.

