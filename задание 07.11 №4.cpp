#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

bool isValidPassword(const std::string& password) {
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasSpecialChar = false;

    for (char c : password) {
        if (isupper(c)) {
            hasUpperCase = true;
        }
        else if (islower(c)) {
            hasLowerCase = true;
        }
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '+' || c == '?') {
            hasSpecialChar = true;
        }
    }

    return (hasUpperCase && hasLowerCase && hasSpecialChar && password.length() >= 6);
}

std::string generatePassword(int length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%&*+?";
    std::string password;
    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        password.push_back(characters[index]);
    }
    return password;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(NULL)));

    int passwordLength;
    std::cout << "Введите длину пароля: ";
    std::cin >> passwordLength;

    std::string password = generatePassword(passwordLength);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    if (isValidPassword(password)) {
        std::cout << "пароль допустимый." << std::endl;
    }
    else {
        std::cout << "пароль недопустимый." << std::endl;
    }

    return 0;
}