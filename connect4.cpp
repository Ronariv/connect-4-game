#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//row 6 
//col 10
struct data{
    char name[101];
    int move = 0;
};

char jp[7][11];
int kotak = 99, kotak2 = 99;
int nomor = 0;
int step = 0;

void fillBoard(){
    for(int i = 0; i < 6; i++){
        for(int j = 0;j < 10;j++){
            jp[i][j] = ' ';
        }
    }
}
void board(){
    puts(" ___ ___ ___ ___ ___ ___ ___ ___ ___ ___");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++){
            printf("| %c ", jp[i][j]);
        }
        puts("|");
        puts("|___|___|___|___|___|___|___|___|___|___|");
    }
    puts("| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |");
    puts("|___|___|___|___|___|___|___|___|___|___|");
}

void isiKotak(){
    for(int i = 6 - 1; i >= 0; i--){
        if(jp[i][kotak] == ' '){
            jp[i][kotak] = 'J';
            break;
        }
    }
}
void player2(){
    kotak2 = rand() % 9;
    for(int i = 6 - 1; i >= 0; i--){
        if(jp[i][kotak2] == ' '){
            jp[i][kotak2] = 'P';
            break;
        }
    }
}

void choose(){
    int choice;

    while(1){
        puts("Input col to fill(0 - 9)");
        printf(">> ");
        scanf("%d",&choice); getchar();

        switch(choice){
            case 0:
                kotak = 0;
                break;
            case 1:
                kotak = 1;
                break;
            case 2:
                kotak = 2;
                break;
            case 3:
                kotak = 3;
                break;
            case 4:
                kotak = 4;
                break;
            case 5:
                kotak = 5;
                break;
            case 6:
                kotak = 6;
                break;
            case 7:
                kotak = 7;
                break;
            case 8:
                kotak = 8;
                break;
            case 9:
                kotak = 9;
                break;
            default:
                kotak = 99;
        }

        if(kotak >= 0 && kotak < 11 && jp[0][kotak] == ' '){
            isiKotak();
            // step++;
            player2();
            break;
        }
    }
}

int connect(char a){
//	column 10
//	row 6
    int horizontal = 7;
    int flag;

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < horizontal; ++j){
            flag = 0;
            for(int k = 0; k < 4; ++k){
                if(jp[i][j+k] == a) flag++;
            }
            if(flag == 4) {
                return 1;
            }
        }
    }

    int vertical = 3;

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < vertical; j++){
            flag = 0;
            for(int k = 0; k < 4; k++){
                if(jp[j + k][i] == a) flag++;
            }
            if(flag == 4) {
                return 1;
            }
        }
    }
	
	int diai, diaj;
    for (int i = 1; i < 5; i++){
        for (int j = 1; j < 9; j++){
            flag = 0;
            
//          check kiri
            for (diai = i, diaj = j; (diai >= 0) || (diaj >= 0); diai--, diaj--){
                if (jp[diai][diaj] == a){
                    flag++;
                    if (flag == 4) {
                        return 1;   
                    } 
                }
                else{
                    break;
                }
                    
            }
            for (diai = i+1, diaj = j+1; (diai <= 5) || (diaj <= 9); diai++, diaj++){
                if (jp[diai][diaj] == a){
                    flag++;
                    if (flag == 4) return 1;
                }
                else{
                    break;
                }
                    
            }
            
            flag = 0;
            // check kanan
            for (diai = i, diaj = j; (diai <= 5) || (diaj >= 0); diai++, diaj--)
            {
                if (jp[diai][diaj] == a)
                {
                    flag++;
                    if (flag == 4) return 1;    
                }
                else{
                    break;
                }
                    
            }
            for (diai = i-1, diaj = j+1; (diai >= 0) || (diaj <= 9); diai--, j++)
            {
                if (jp[diai][diaj] == a){
                    flag++;
                    if (flag == 4) {
                        return 1;
                    }
                }
                else{
                    break;
                }
                    
            }
            
        }
    }
    return 0;
}

int main(){
    data player[101];
    int home;
    // int choice;
    do{
        system("cls");
        puts("Welcome to Connect JP, what do you want to do?");
        puts("1. Play");
        puts("2. How to Play");
        puts("3. Scoreboard");
        puts("4. Exit");
        printf(">> ");
        scanf("%d", &home); getchar();

        switch(home){
            case 1:
                fillBoard();
                step = 0;
                while(1){
                    step++;
                    system("cls");
                    puts("\nConnect map");
                    board();
                    choose();
                    int lose = connect('P');
                    int win = connect('J');
                    if(win == 1){
                        board();
                        puts("Congratulation, you win! Press enter to continue...");
                        getchar();
                        do{
                            printf("(Input Name (5 - 90 chars|may not only contain whitespace))>>> ");

                            scanf("%[^\n]",player[nomor].name); getchar();
                            player[nomor].move = step;
                        }while(strlen(player[nomor].name) < 5 || strcmp(player[nomor].name,"!") < 0);
                        
                        
                        step = 0;
                        nomor++;
                        break;
                    }
                    else if(lose == 1){
                        board();
                        puts("You lose press enter to continue!");
                        getchar();
                        break;
                    }
                }
                break;
                
            case 2:
                system("cls");
                puts("Connect JP is a board game, in which the you will play with 'J'");
                puts("and bot(your opponent) will play with 'P', and then take turns");
                puts("dropping 'J' and 'P' tokens into the grid. The pieces fall");
                puts("straight down, occupying the lowest available space within the");
                puts("column. The objective of the game is to be the first to form");
                puts("a horizontal, vertical, or diagonal line of 4 of one's own tokens.");
                printf("Press enter to continue...");
                getchar();
                break;
            case 3:
                system("cls");
                if(nomor == 0){
                    puts("There is no score yet.");
                    printf("Press enter to continue...");
                    getchar();
                    break;
                }
                puts(" ____________________________________________________________ _____");
                puts("|Player's Name                                               |Moves|");
                puts("|____________________________________________________________|_____|");
                for(int i = 0;i < nomor; i++){
                    printf("|%-60s|%-5d|\n",player[i].name,player[i].move);
                }
                puts("|____________________________________________________________|_____|");
                getchar();
                break;
            case 4:
                printf("Thank you for playing!");
                getchar();
                break;
        }
    }while(home > 0 && home < 4);
}
