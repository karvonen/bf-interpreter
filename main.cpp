#include <iostream>
#include <stack>
#include <fstream>



int run(std::string program) {
    char tape[1000] = {0};
    char* ptr = tape;
    std::stack<int> stack;
    for (int i = 0; program[i] != '\0'; i++) {
        switch (program[i]) {
            case '+': (*ptr)++; break;
            case '-': (*ptr)--; break;
            case '>': ptr++; break;
            case '<': ptr--; break;
            case '.': std::putchar(*ptr); break;
            case ',': *ptr = std::getchar(); break;
            case '[': stack.push(i); break;
            case ']':
                if (*ptr == 0) {
                    stack.pop();
                    continue;
                } else {
                    i = stack.top();
                    break;
                }
        }
    }
    return 0;
}

std::string read_file(const char* filename) {
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        return contents;
    }
    throw(errno);
}


int main(int argc, const char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    std::string program = read_file(argv[1]);
    run(program);

    return 0;
}