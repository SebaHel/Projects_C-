#include <iostream>
#include <random>

class pass {
protected:
    std::string password;
public:
    pass(std::string Password) {
        password = Password;
    }
    bool isNumber() {
        char list[sizeof(password)];
        for (std::string::size_type i = 0; i < password.size(); i++) {
            if (isalnum(password[i])) {
                return true;
            }
            else {
                return false;
            }  
        }
    }
    bool IsCapital() {
        char list[sizeof(password)];
        for (std::string::size_type i = 0; i < password.size(); i++) {
            if (isupper(password[i])) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};
    int main()
    {
        std::string password, password1;
        int number_of_tries = 1;
        for (number_of_tries; number_of_tries <= 3; number_of_tries++) {
            std::cout << "Password" << std::endl;
            std::cin >> password;
            std::cout << "Repeat Password" << std::endl;
            std::cin >> password1;
            pass Password(password);
            if (password == password1) {
                if (size(password) > 14) {
                    if (Password.isNumber() && Password.IsCapital()) {
                        std::cout << "Good Job you type your password corectly." << std::endl;
                        break;

                    }
                    else {
                        std::cout << "your password must have one digit and one cappital letter" << std::endl;
                    }
                }


                if (number_of_tries >= 4) {
                    std::string question;
                    std::cout << "You typed wrong password too many times." << std::endl;
                    std::cout << "Would you like to generate password for you ?" << std::endl;
                    std::cout << "Y/N" << std::endl;
                    std::cin >> question;
                    if (question == "Y") {
                        std::string password;
                        for (int i = 0; i <= 14; i++) {
                            password += char((rand() % 60) + 30);

                        }
                        std::cout << "We created Password for you.";
                        pass Password(password);
                    }
                }
            }
            else {
                std::cout << "Password must match each other" << std::endl;
            }

    };
