#include <iostream>
#include <cstdlib>

int value;
int matrices1[3][3];
int matrices2[3][3];

void start() {
    std::cout << "1-calculation of the determinant" << std::endl;
    std::cout << "2-Transposition" << std::endl;
    std::cout << "3-Multiplying" << std::endl;
    std::cout << "Chose operation which you want do on matirces:" << std::endl;
    std::cin >> value;
}
void det() {
    int sum = 0;
    sum += matrices1[0][0] * matrices1[1][1] * matrices1[2][2];
    sum += matrices1[1][0] * matrices1[2][1] * matrices1[0][1];
    sum += matrices1[2][0] * matrices1[0][1] * matrices1[1][2];

    sum -= matrices1[2][0] * matrices1[1][1] * matrices1[0][2];
    sum -= matrices1[2][1] * matrices1[1][2] * matrices1[0][0];
    sum -= matrices1[2][2] * matrices1[1][0] * matrices1[0][1];
    std::cout << sum;
}
void matrix1() {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << "type element:";
                std::cin >> matrices1[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            std::cout << "|";
            for (int j = 0; j < 3; j++) {
                if (matrices1[i][j] == matrices1[i][2]) {
                    std::cout << matrices1[i][j];
                }
                else {
                    std::cout << matrices1[i][j] << " ";
                }

            }
            std::cout << "|" << std::endl;
        }

    }
void matrix2() {
    matrix1();
    std::cout << "Matrix2:";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "type element:";
            std::cin >> matrices2[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            if (matrices2[i][j] == matrices2[i][2]) {
                std::cout << matrices2[i][j];
            }
            else {
                std::cout << matrices2[i][j] << " ";
            }

        }
        std::cout << "|" << std::endl;
    }
}
void transpozition() {
    std::cout << "After transpozition" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            if (matrices1[i][j] == matrices1[i][2]) {
                std::cout << matrices1[j][i];
            }
            else {
                std::cout << matrices1[j][i] << " ";
            }

        }
        std::cout << "|" << std::endl;
    }
}
void multi() {
    class Matrix {
    private:
        int value1, value;
    public:
        int matrix3[3][3];
        void setValue(int s) {
            value1 = s;
        }
        int getValue() {
            int sum = 0, sum1 = 0, sum2= 0;
            for (int i = 0; i < 3; i++) {

                sum += matrices1[i][0] * matrices2[0][i];
                sum1 += matrices1[i][1] * matrices2[1][i];
                sum2 += matrices1[i][2] * matrices2[2][i];
                    matrix3[value1][0] = sum;
                    matrix3[value1][1] = sum1;
                    matrix3[value1][2] = sum2;
                
            }
            return matrix3[value1][0];
            return matrix3[value1][1];
            return matrix3[value1][2];
           
          

           

        }
    };
    Matrix obj;
    for (int i = 0; i < 3; i++) {
        obj.setValue(i);
        std::cout << obj.getValue()<< std::endl;
    }
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            if (obj.matrix3[i][j] == obj.matrix3[i][2]) {
                std::cout << obj.matrix3[i][j];
            }
            else {
                std::cout << obj.matrix3[i][j] << " ";
            }

        }
        std::cout << "|" << std::endl;
    }
}
int main()
{
    start();
    switch (value)
    {
    case 1: {
        matrix1();
        det();
        break;
    }
    case 2: {
        matrix1();
        transpozition();
        break;
    }
    case 3: {
        matrix2();
        multi();
        break;
    }
    default:
        break;
    }
}
