#AC-Circuit-Solver

This application solves AC Circuit given in Splice Netlist format and generate a corresponding SVG image of the circuit.

##Instructions to Use the Application.

###Software/Package Requirement
1. Eigen Library of C++ (To install it: sudo apt install libeigen3-dev)
2. Flex for C++ (To install it:sudo apt-get install flex)
3. Firefox
4. Linux based Operating System (Preferably Ubuntu)
5. GNU g++ compiler with support for C++11.

###Instructions
1. Execute "make" command in terminal.
2. ./ac_circuit_solver <input-circuit> <output-html-file> <result-file>
3. If there are any Error in the Input or If Circuit is incomplete then it will be shown on the Terminal and also you can see your circuit's image.
4. To display the circuit "firefox <output-html-file>".
5. <result-file> will contain the analysis of the AC circuit which will also be shown on terminal.
6. <output-html-file> this page will show the SVG image Generated for the AC circuit. You can zoom the image with mouse and with buttons given at the Bottom-Left corner of the page.
7. To See AC analysis of any Element click on the Element, this will generate a Dialog box which will have Voltage across that element and Current flowing through that element. Until the Dialog box is open,Element that generated it will be red in color.

##Tools Used

1. Functionality: C++
Parsing of the Netlist file , generation of SVG image for AC circuit and
Solving the AC circuit is done in C++.
2. Image Rendering: SVG
Scalable Vector Graphics are used for generating of AC circuit’s image.
3. Interactivity in Image: JavaScript
Adding Functionallity in Image is done using Javascript. It isused
to provide interactivity in the image as if you click on any component
of the circuit,voltage across that component and more information will
be displayed. Also it will provide Zooming facility to the image.
4. Styling: CSS
To make the page containing the SVG image looks stylish.
5. Layout: HTML and XML
For Designing the page containing SVG image.
6. Scripting: Bash
It is used in the makefile.

##SVG Image
Blue Dots on the Image represents connections, other overlapping lines means nothing.

##Class

*Component Class:* This class abstracts information about resistor, inductor and capacitor used in the circuit.

*Source Class:* This class abstracts information about Voltage and current source used in the circuit.

*Net Class:* This class abstracts information about which components or Source are connected to a particular net.

##Sample Input

R1 Net3 0 10K 
C1 Net2 Net3 100NF 
L1 Net1 Net2 10NH 
V1 Net1 0 SINE ( 0.0 1.0 10Khz 0.0S 0.0 )                        
Take a note over spaces given above.

##NOTE:
For the purpose of Zooming we have used an open source Javascript library svg-pan-zoom.js from https://github.com/ariutta/svg-pan-zoom  
