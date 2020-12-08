#include <stdio.h>
#include <windows.h>
#include <conio.h>

int high,width;
int bird_x,bird_y;
int bar_y,bar_xTop,bar_xDown;
int score;

void gotoxy(int x, int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void startup(){
    high=15;
    width=25;

    bird_x = 0;
    bird_y = width/3;

    bar_y = width;
    bar_xTop = high/4;
    bar_xDown = high/2;
    score = 0;
}
void show(){
    gotoxy(0,0);
    int i,j;
    for(i=0;i<=high+1;i++){
        for(j=0;j<=width;j++){
            if(i==bird_x&&j==bird_y){
                printf("@");//
            }
            else if(j==bar_y&&(i<=bar_xTop||i>=bar_xDown)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("ตรทึ:%d\n",score);
}
void updateWithOutInput(){
    if(bar_y==bird_y){
        if(bird_x>bar_xTop&&bird_x<bar_xDown){
            score++;
        }else{
            exit(0);
        }
    }
    bird_x++;
    if(bar_y>0){
        bar_y--;
    }else{
        bar_y = width;
        int randPosition = rand()%(high-5);
        bar_xTop = randPosition; 
        bar_xDown = randPosition+high/4;
    }
}
void updateWithInput(){
    char input;
    if(kbhit()){
        input = getch();
        if(input==' '){
            bird_x = bird_x-2;
        }
    }
    Sleep(150);
}
int main(){
    startup();
    while(1){
        show();
        updateWithOutInput();
        updateWithInput();
    }
    return 0;
}