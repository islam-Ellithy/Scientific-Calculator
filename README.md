# Scientific-Calculator
it is a scientific calculator in C++ with use any built in function in cmath library it is implemented based on math rules and theories  that use sine , cosin , tan , ln , log , exponent , another functions 

Initially the console shows number 0 and a cursor waiting for user to input (like the windows calculator) note that when user enters a value it overrides the current value .
2- If the user enters a unary operation (takes one parameter) it performs the operation on the current value and update the current value with the result of this operation. 
3- If the user enters a binary operation (takes two parameters) it waits for a second input from the user then after user inputs the second parameter it updates the current value with the result.
4- Provide the calculator memory functions (M+, M-, MC(Clear), MR(Result), MS(Memory Store))
5- The calculator must be able to alter its state between degrees and radians, when user inputs "degrees" or "radians", the initial calculator state is radians. 

Example:
User wants to calculate sin(30), first user must inputs the word "degrees" so the calculator changes its state to degrees, after user presses enter, the program must only show the initial 0 and the pointer waiting for user to enter value, user enters  30, then enter, this will update the current value shown on screen with 30, and waits for user to input the operation,  sin, then overrides the current value with the result 0.5.
if the user wants to multiply the result by 2, he can write * then press enter, input 2, then press enter, and the result 1 will be shown on the screen. 
