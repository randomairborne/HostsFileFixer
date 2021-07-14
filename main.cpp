#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    int current_line = 0;
    std::string LineText;

    // Open hosts file
    std::string env_p = std::getenv("WINDIR");
    std::string path = env_p.append(R"(\system32\drivers\etc\hosts)");
    std::ifstream HostsFile(path);
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(HostsFile, LineText)) {
        current_line++;
        if (LineText.find("mojang.com") != std::string::npos) {
            // send output if we find a line with the word mojang
            std::cout << "found: " << LineText << " at line " << current_line << ", fixing." << std::endl;
        }
        if (LineText.find("mojang.com") == std::string::npos) {
            // Open temporary file
            std::ofstream TempFile;
            TempFile.open((path + ".save"), std::ofstream::app);
            TempFile << LineText << std::endl;
            // closing input file
            TempFile.close();
        }

    }

    if (HostsFile.is_open()) {
        HostsFile.close();
    }
    std::remove(path.c_str());

    // rename the file
    std::rename((path + ".save").c_str(), path.c_str());
    std::cout << "Fixed host file! Press enter to exit...";
    std::cin.ignore();

}
