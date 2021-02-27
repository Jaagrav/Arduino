# IR Calculator
I have written the code in such a way so that this IR Calculator works just like a real calculator, there's no bugs in the 
code that other Arduino calculators I have seen have.

Check out the code in `index.ino` and use it to run your calculator.

## Circuit

|#|Arduino Pins|LCD RG1602A|
|-|------------|-----------|
| 1 |     GND     | VSS,V0 (With 2K ohm),RW,K |
| 2 |     5V      | VDD, A (With 220 ohm)     |
| 3 |     12      | RS                       |
| 4 |     11      | E                        |
| 5 |     5       | D4                       |
| 6 |     4       | D5      			      |
| 7 |     3       | D6                  |
| 8 |     2       | D7                  |   

|#|Arduino Pins|IR Transmitter|
|-|------------|--------------|
| 1 |     10      | Out                       |
| 2 |     GND     | GND                       |
| 3 |     5V      | Power                     |

Here's the link to a [Tinkercad simulation](https://www.tinkercad.com/things/8h02ju1j0Ls), remember the simulation may not be as accurate and smooth as a real Arduino board.
