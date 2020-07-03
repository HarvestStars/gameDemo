#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define H 22
#define W 22

class Treasury
{
public:
    int goldenVolume,i,j,k;
    char qp[H][W];
    Treasury();
    void refresh();
};

Treasury::Treasury()
{
    goldenVolume = 10;
    for(i=1;i<=H-2;i++)
        for(j=1;j<=W-2;j++)
            qp[i][j]=' ';
    qp[H/2][W/2] = '@';
    for(i=0;i<=H-1;i++)
        qp[0][i] = qp[H-1][i] = '#';
    for(i=1;i<=H-2;i++)
        qp[i][0] = qp[i][W-1] = '#';
    for(k=0;k<10;k++){
        int x1=rand()%W-2+1;
        int y1=rand()%H-2+1;
        qp[x1][y1] = '$';
    }
}

void Treasury::refresh(){
    std::cout << std::endl;
    for(i = 0; i<H; i++){
        std::cout << "\t";
        for (j=0; j<W; j++)
        {
            std::cout << qp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

class Thief:public Treasury
{
private:
    int Life, Golden; 
    int X = H/2;
    int Y = W/2;
public:
    Thief();
    void Move();
};

Thief::Thief(){
    Life = 10;
    Golden = 0;
}

void Thief::Move()
{
    int direction;
    while(1){
        _getch();
        direction = _getch();
        switch(direction){
        case 72:
            // up
            qp[X][Y] = ' ';
            X -= 1;
            if (qp[X][Y] == '$'){
                Golden++;
                goldenVolume--;
            }
            qp[X][Y] = '@';
            break;
        case 80:
            // down
            qp[X][Y] = ' ';
            X += 1;
            if (qp[X][Y] == '$'){
                Golden++;
                goldenVolume--;
            }
            qp[X][Y] = '@';
            break;
        case 75:
            // left
            qp[X][Y] = ' ';
            Y -= 1;
            if (qp[X][Y] == '$'){
                Golden++;
                goldenVolume--;
            }
            qp[X][Y] = '@';
            break;
        case 77:
            // right 
            qp[X][Y] = ' ';
            Y += 1;
            if (qp[X][Y] == '$'){
                Golden++;
                goldenVolume--;
            }
            qp[X][Y] = '@';
            break;
        }
        system("cls");
        std::cout << "\tGolden get:" << Golden << std::endl;
        std::cout << "\tGolden left:" << goldenVolume << std::endl;
        refresh();
    }
}

int main()
{
    Treasury goldenPark;
    Thief cowBoy;
    cowBoy.Move();
}