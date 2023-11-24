#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <linux/limits.h>
#include <unistd.h>
#include <sstream>

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

bool isUnderDebugger()
{
    bool result = false;
    /*
     * /proc/self/stat has PID of parent process as fourth parameter.
     */
    std::string stat;
    std::ifstream file("/proc/self/stat");

    for(int i = 0; i < 4; ++i)
        file >> stat;

    std::string parent_path = std::string("/proc/") + stat + "/exe";
    char path[PATH_MAX + 1];
    memset(path, 0, PATH_MAX + 1);
    readlink(parent_path.c_str(), path, PATH_MAX);

    std::vector<std::string> debuggers = {"gdb", "lldb-server", "radare2"};

    for (auto &p: debuggers)
    {
        if (hasEnding(std::string(path), p))
        {
            result = true;
            break;
        }
    }

    return result;
}


bool isDebuggingPresent()
{
    bool result = false;

    std::string line;
    std::ifstream file("/proc/self/status");

    while (std::getline(file, line))
    {
        std::istringstream _stream(line);
        std::string tag, value;
        _stream >> tag >> value;
        
        if (tag == "TracerPid:" && value != "0")
            result = true;
    }

    return result;
}

int main() {
    char password[100];
    const char *secretPassword = "SuperSecret123"; // Le mot de passe attendu

    if(isUnderDebugger) {
        std::cout << "I am being debugged." << std::endl;
        return 1;
    }

    if(isDebuggingPresent) {
        std::cout << "I am being debugged." << std::endl;
        return 1;
    }

    std::cout << "Entrez le mot de passe : ";
    std::cin.getline(password, sizeof(password));

    // Supprime le caractère de saut de ligne s'il existe
    password[strcspn(password, "\n")] = 0;

    if (strcmp(password, secretPassword) == 0) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Mot de passe incorrect !" << std::endl;
    }

    return 0;
}