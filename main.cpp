#include <iostream>
#include <fstream>
#include <string>
// This is valkyrie_pilot#2707's hosts file fixer. It looks for URLs that have been blocked that could break minecraft login.


int main(int argc, char *argv[]) {
    // program name!
    std::cout << "Hosts file fixer 1.0.0 by valkyrie_pilot#2707" << "\n\n\n";
    int current_line = 0;
    std::string LineText;
    // Find hosts file
    std::string env_p = std::getenv("WINDIR");
    std::string path = env_p.append(R"(\system32\drivers\etc\hosts)");
    // open readstream for hosts file
    std::ifstream HostsFile(path);
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(HostsFile, LineText)) {
        // increment line number being read
        current_line++;
        if (LineText.find("mojang") != std::string::npos) {
            // send output if we find a line with the word mojang
            std::cout << "found: " << LineText << " at line " << current_line << ", fixing." << std::endl;
        }
        if (LineText.find("mojang") == std::string::npos) {
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
