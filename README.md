🧠 Simple CPU Instruction Set Simulator
This project is a C++-based simulation of a simplified CPU instruction execution system. It demonstrates the fetch-decode-execute cycle for a minimal instruction set. The CPU uses virtual memory and register storage, supporting basic operations like MOV, ADD, SUB, AND, branching (JMP, JZ), memory operations (LOAD, STORE), and HLT.

🚀 Features
Minimal instruction set for learning purposes

Simulated memory and 8 general-purpose registers

Instruction execution logging with program counter (PC) tracking

Demonstrates looping and conditional jumps

Final memory state output

🧾 Instruction Set

Instruction | Description
MOV Rx, #val | Moves an immediate value to register Rx
ADD Rx, Ry, Rz | Adds contents of Ry and Rz, stores in Rx
SUB Rx, Ry, Rz | Subtracts Rz from Ry, stores in Rx
AND Rx, Ry, Rz | Bitwise AND between Ry and Rz, stores in Rx
LOAD Rx, [addr] | Loads value from memory at address into Rx
STORE Rx, [addr] | Stores value from Rx to memory at address
JMP addr | Jumps to instruction at memory index addr
JZ Rx, addr | Jumps to addr if Rx equals 0
HLT | Halts execution
🧠 Sample Program
This example calculates the sum of numbers from 1 to 10, stores the result in memory at address 100.
vector<string> program = {
    "MOV R1, #1",         // Start with R1 = 1
    "MOV R2, #0",         // R2 will store the sum
    "ADD R2, R2, R1",     // R2 += R1
    "MOV R0, #1",         // Constant 1
    "ADD R1, R1, R0",     // R1++
    "MOV R3, #11",        // Limit (11 for sum 1-10)
    "SUB R4, R3, R1",     // R4 = 11 - R1
    "JZ R4, 10",          // If R4 == 0, jump to STORE
    "JMP 2",              // Loop
    "STORE R2, [100]",    // Store sum at memory[100]
    "HLT"                 // Stop
};
📦 Output Example
PC: 0 | Executing: MOV R1, #1 | Registers: 0 0 0 0 0 0 0 0
...
Final Memory State at [100]: 55
📚 How to Run
Clone this repo:
Compile and run:
git clone https://github.com/your-username/cpu-simulator.git
cd cpu-simulator

bash
Copy
Edit
g++ -o simulator simulator.cpp
./simulator
🤖 Use Cases
Learning low-level CPU operation concepts

Simulating instruction pipelines

Understanding register and memory interactions
