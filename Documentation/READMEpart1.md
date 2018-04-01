# AC-Circuit-Display-
Parsing a Given Netlist to display corresponding SVG image of the circuit.

##Tools Used

For the purpose of Parsing information from the netlist flex is used. Flex generates tokens that are used to develop svg image of the circuit.

Language Used: C++
Image Format: SVG 

##Instructions
1. Execute "make" command in terminal.
2. ./ac_circuit_solver <input-circuit-file> <output-html-file>
3. firefox <output-html-file>

###Class

Component Class: This class abstracts information about resistor, inductor and capacitor used in the circuit.

Source Class: This class abstracts information about Voltage and current source used in the circuit.

###Viewing Circuit

Open top.html file to see circuit in web browser.

##Sample Input

R1 Net3 0 10K 
C1 Net2 Net3 100NF 
L1 Net1 Net2 10NH 
V1 Net1 0 SINE ( 0.0 1.0 10Khz 0.0S 0.0 )

Take Note of Parenthesis and Spaces.

##NOTE:
For the purpose of Zooming we have used an open source Javascript library svg-pan-zoom.js from https://github.com/ariutta/svg-pan-zoom  
