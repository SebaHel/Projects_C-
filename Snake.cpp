#include <iostream>
#include <conio.h>
#include <Windows.h> 

bool isgameover; 
const int width = 20; //Map Width
const int height = 20; //Map height
int X_position, Y_position, X_fruit, Y_fruit, score; //Position of snake,fruit and score
int tailX[50], tailY[50]; //Tables wchich storing position X,Y of snake tail segments
int nTail = 2; //size of tail at start.
enum eDiretion {Left, Right, Up, Down};
eDiretion dir; 
void start() {
    std::cout << R"(
                         
                          ______                           ______                    __
                         /      \                         /      \                  /  |
                         /$$$$$$  | ______  ______        /$$$$$$  |_______   ______ $$ |   __  ______
                         $$ | _$$/ /      \/      \       $$ \__$$//       \ /      \$$ |  /  |/      \
                         $$ |/    /$$$$$$  $$$$$$  |      $$      \$$$$$$$  |$$$$$$  $$ |_/$$//$$$$$$  |
                         $$ |$$$$ $$ |  $$//    $$ |       $$$$$$  $$ |  $$ |/    $$ $$   $$< $$    $$ |
                         $$ \__$$ $$ |    /$$$$$$$ |      /  \__$$ $$ |  $$ /$$$$$$$ $$$$$$  \$$$$$$$$/
                         $$    $$/$$ |    $$    $$ |      $$    $$/$$ |  $$ $$    $$ $$ | $$  $$       |
                          $$$$$$/ $$/      $$$$$$$/        $$$$$$/ $$/   $$/ $$$$$$$/$$/   $$/ $$$$$$$/
    
)" << '\n';

    std::cout << "Press 1 to play\n";
    std::cout << "Press diffrent numer if you want exit\n";
    system("pause>0");
}
void end() {
    std::cout << R"(
                                 
                                                  *             )            (
                                  (       (     (  `         ( /(            )\ )
                                  )\ )    )\    )\))(  (     )\())(   (  (  (()/(
                                 (()/( ((((_)( ((_)()\ )\   ((_)\ )\  )\ )\  /(_))
                                  /(_))_)\ _ )\(_()((_((_)    ((_((_)((_((_)(_))
                                 (_)) __(_)_\(_|  \/  | __|  / _ \ \ / /| __| _ \
                                   | (_ |/ _ \ | |\/| | _|  | (_) \ V / | _||   /
                                    \___/_/ \_\|_|  |_|___|  \___/ \_/  |___|_|_\
                                                                                   
      

)" << '\n';
    std::cout << "Your Score is:" << score;
    system("pause>0");
}
void keyboard() {
    if (_kbhit()) {
        switch (_getch()) {
        case char(72): if (dir != Down) { dir = Up; }; break; //assigning Upper arrow to up direction.
        case char(80): if (dir != Up) { dir = Down; }; break;//assigning bottom arrow to down direction.
        case char(77): if (dir != Left) { dir = Right; }; break;//assigning right arrow to right direction.
        case char(75): if (dir != Right) { dir = Left; }; break;//Passigning left arrow to left direction.
        }
    }
}
void mechanics() {
    // Ogon podążający za głową
    for (int i = nTail - 1; i > 0; i--)
    {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    tailX[0] = X_position;
    tailY[0] = Y_position;

    switch (dir) //Movement
    {
    case Left:X_position--; break;
    case Right: X_position++; break;
    case Up:Y_position--; break;
    case Down: Y_position++; break;
    default: break;
    }
    if (X_position > width || X_position < 0 || Y_position > height || Y_position < 0) // Checking that player didn't touch walls.
        isgameover = true;

    for (int i = 2; i < nTail; i++) { //Checking that player didn't touch his own tail.
        if (tailX[i] == X_position && tailY[i] == Y_position)
            isgameover = true;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (X_fruit == tailX[i] && Y_fruit == tailY[i]) // Checking position of player and fruit if they are same increasing tail and score.
        {   
            score += 1;
            X_fruit = rand() % width; //Defining New X position of fruit.
            Y_fruit = rand() % height; //Defining New Y position of fruit.
            nTail++;
        }
        
    }  
}
void draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++) //Drawing Upper edge of map
        std::cout << "*";
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) //Drawing Left edge of map.
                std::cout << "*";
            if (i == Y_position && j == X_position) //Drawing Head of snake.
                std::cout << "@";
            else if (i == Y_fruit && j == X_fruit) // Drawing Fruits.
                std::cout << "%";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) //Drawing Tail.
                {
                    if (tailX[k] == j && tailY[k] == i) {
                        std::cout << "#";
                        print = true;
                    }
                }
                if (!print)
                    std::cout << " ";
            }
            if (j == width - 1) //Drawing Right edge of map.
                std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++) //Drawing bottom edge of map.
        std::cout << "*";
    std::cout << std::endl;
    std::cout << "Your Score is:" << score << std::endl; //Current Score under map.
}
int main()
{   
    isgameover = false;
    dir = Up; // Deffining the first movement after game started.
    X_position = width / 2; // centred Snake started position X
    Y_position = height / 2; // centred Snake started position Y.
    X_fruit = rand() % width; //Asigning first X position to fruit
    Y_fruit = rand() % height; //Asigning first Y position to fruit
    score = 0; // Beginning Score
    int z;
    start();
    std::cin >> z;
    
    if (z == 1)
    {
        while (!isgameover) {
            keyboard();
            mechanics();
            draw();
            Sleep(50);

        }
        system("cls");
        end();
        
    }
    return 0;

}
