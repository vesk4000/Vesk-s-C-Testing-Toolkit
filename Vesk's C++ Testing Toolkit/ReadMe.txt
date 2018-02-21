Vesk's C++ Testing Toolkit
--------------------------
A simple testing toolkit to help you test your
c++ console applications.
==============================================

Basic Instructions
------------------
1. Get the inputs and the correct outputs for
   the problem
2. Add the necessary code to your program
3. Run your program to get your outputs
4. Run the comparator program to compare your
   outputs to the correct outputs
==============================================

Get the inputs and the correct outputs for the
problem
----------------------------------------------
All the inputs should be named
"[problemName].[testNumber].in" and the
correct outputs "[problemName].[testNumber].out".
Of course you can just change the appropriate
code to fit the names of your inputs and outputs.
Then just put them in the same folder. To be
clear the correct outputs are the outputs that
are expected to be outputted from your program
if it were given the corresponding input.
==============================================

Add the necessary code to your program
---------------------------------------
Open "/codeToAdd/code.cpp" and follow the
instructions on the comment lines. Also rememeber
to replace all input commands with "veskinput" and 
outputs with "veskoutput". For example replace
"cin>>" with "veskinput>>" and "cout<<" with
"veskoutput<<". All the variables have the prefix
"vesk" before them, so that they don't interfere
with your variables. You can also get each of the
parts of the code as one line from
"/codeToAdd/codeOneLines.cpp" if you prefer to do
so. In "/codeToAdd/exampleBefore.cpp" and
"/codeToAdd/exampleAfter.cpp" you can see the before
and after adding the code on an example program.
==============================================

Run your program to get your outputs
------------------------------------
Compile your program and run it, it will ask you
for the number of tests, then the name of the
problem which should be [problemName] in the name
of your file. Finally it will ask you for the
number of digits in the number of the