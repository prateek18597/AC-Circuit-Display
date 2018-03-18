# AC-Circuit-Display-
Parsing a Given Netlist to display corresponding SVG image of the circuit.


Simplely enter "make" in terminal of AC-Circuit-Display Folder to run the application.
In order to change the input , Enter your problem in input.cir.

##Tools Used

For the purpose of Parsing information from the netlist flex is used. Flex generates tokens that are used to develop svg image of the circuit.

Language Used: C++
Image Format: SVG 

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
                ^                      ^
Space is compulsory here(^),after and before paranthesis.
