#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#define memory_size 30000 // 30_000

char* program_memory = new char[memory_size];
int current_memory = 0;
size_t loop_begin = -1;




std::string readFile(std::string filename) {
    std::fstream file(filename);

    if(!file.good() || !file.is_open()) {
        std::cout << "failed reading " << filename;
        exit(0);
    }


    std::string line;
    std::string out;


    while (std::getline(file, line)) {
        out += line;
    }
    
    return out;

}

void loadProgram(std::string data) {
    for(size_t i = 0; i < data.size(); i++) {
        char operation = data[i];

        switch(operation) {
            case '>':
                current_memory++;
                break;
            case '<':
                current_memory--;
                break;
            case '+':
                program_memory[current_memory]++;
                break;
            case '-':
                program_memory[current_memory]--;
                break;
            case '[':
                loop_begin = i;
                break;
            case ']':
                if(program_memory[current_memory] != 0) {
                    if(loop_begin != -1) {
                        i = loop_begin;
                    }
                } else {loop_begin = -1;}
                break;
            case '.':
                std::cout << program_memory[current_memory];
                break;
        }


    }

}


int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "usage: bf <file>\n";
        exit(0);
    }


    std::string data = readFile(argv[1]);

    memset(program_memory, 0, memory_size * sizeof(*program_memory));

    loadProgram(data);

    delete[] program_memory;
}
