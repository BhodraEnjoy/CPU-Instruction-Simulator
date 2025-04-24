#include <bits/stdc++.h>
using namespace std;

// Memory and registers
vector<string> memory(256);
int registers[8] = {0};
int PC = 0;
bool halted = false;

int get_register_index(const string& reg) {
    return reg[1] - '0'; // "R2" -> 2 //0-->48
}

void execute(const string& opcode, const vector<string>& operands) {
    if (opcode == "ADD") {
        int r1 = get_register_index(operands[0]);
        int r2 = get_register_index(operands[1]);
        int r3 = get_register_index(operands[2]);
        registers[r1] = registers[r2] + registers[r3];
        PC++;
    } else if (opcode == "SUB") {
        int r1 = get_register_index(operands[0]);
        int r2 = get_register_index(operands[1]);
        int r3 = get_register_index(operands[2]);
        registers[r1] = registers[r2] - registers[r3];
        PC++;
    } else if (opcode == "AND") {
        int r1 = get_register_index(operands[0]);
        int r2 = get_register_index(operands[1]);
        int r3 = get_register_index(operands[2]);
        registers[r1] = registers[r2] & registers[r3];
        PC++;
    } else if (opcode == "LOAD") {
        int r1 = get_register_index(operands[0]);
        int addr = stoi(operands[1].substr(1, operands[1].length() - 2));
        registers[r1] = stoi(memory[addr]);
        PC++;
    } else if (opcode == "STORE") {
        int r1 = get_register_index(operands[0]);
        int addr = stoi(operands[1].substr(1, operands[1].length() - 2));
        memory[addr] = to_string(registers[r1]);
        PC++;
    } else if (opcode == "MOV") {
        int r1 = get_register_index(operands[0]);
        int val = stoi(operands[1].substr(1));
        registers[r1] = val;
        PC++;
    } else if (opcode == "JMP") {
        PC = stoi(operands[0]);
    } else if (opcode == "JZ") {
        int r1 = get_register_index(operands[0]);
        if (registers[r1] == 0) PC = stoi(operands[1]);
        else PC++;
    } else if (opcode == "HLT") {
        halted = true;
    }
}

void run_cpu() {
    while (!halted) {
        string instr = memory[PC];
        istringstream iss(instr);
        string opcode;
        iss >> opcode;
        vector<string> operands;
        string operand;
        while (iss >> operand) operands.push_back(operand);

        cout << "PC: " << PC << " | Executing: " << instr << " | Registers: ";
        for (int r : registers) cout << r << " ";
        cout << endl;

        execute(opcode, operands);
    }
}

int main() {
    vector<string> program = {
        "MOV R1, #1",
        "MOV R2, #0",
        "ADD R2, R2, R1",
        "MOV R0, #1",
        "ADD R1, R1, R0",
        "MOV R3, #11",
        "SUB R4, R3, R1",
        "JZ R4, 10",
        "JMP 2",
        "STORE R2, [100]",
        "HLT"
    };

    for (int i = 0; i < program.size(); ++i) {
        memory[i] = program[i];
    }

    run_cpu();
    cout << "\nFinal Memory State at [100]: " << memory[100] << endl;
    return 0;
}

