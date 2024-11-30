#include<iostream>
#include<chrono>

#define RESET   "\033[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"


bool compile(const std::string& input_file){
    const std::string exe_file = input_file.substr(0, input_file.size() - 4);
    const std::string compile_command = "g++ -std=c++20 " + input_file + " -o " + exe_file;
    auto start_time = std::chrono::high_resolution_clock::now();
    if(system(compile_command.c_str()) == 0){
        auto finish_time = std::chrono::high_resolution_clock::now();
        auto compilation_time = std::chrono::duration_cast<std::chrono::milliseconds>(finish_time - start_time);
        return printf(">>" " %s [" GREEN "SUCCESSFULL COMPILATION" RESET "]" " Elapsed Time: %dms\n", input_file.c_str(), compilation_time.count());
    }
    return false;
}

void run(const std::string& input_file){
    const std::string output_file = input_file.substr(0, input_file.size() - 4) + ".exe";
    const std::string exe_file = "./" + input_file.substr(0, input_file.size() - 4);
    const std::string run_command = exe_file + '<' + "inputf.in" + '>' + "outputf.out";
    auto start_time = std::chrono::high_resolution_clock::now();
    if(system(run_command.c_str()) == 0){
        auto finish_time = std::chrono::high_resolution_clock::now();
        auto execution_time = std::chrono::duration_cast<std::chrono::milliseconds>(finish_time - start_time);
        printf(">>" " %s [" GREEN "SUCCESSFULL EXECUTION" RESET "]" " Elapsed Time: %dms\n", output_file.c_str(), execution_time.count());
    }else{
        printf(">>" " %s [" RED "EXECUTION FAILED (Possible Runtime Error)" RESET "]\n", output_file.c_str());
    }
    
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Invalid arguments!\n");
    }else{
        if(compile(argv[1])){
            run(argv[1]);
        }
    }
    return 0;
}