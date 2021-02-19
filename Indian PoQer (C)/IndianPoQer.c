#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char num[10][7][5] = {
	{{32,'*','*','*',32}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*',32}},
	{{32,32,'*',32,32}, {32,'*','*',32,32}, {32,32,'*',32,32}, {32,32,'*',32,32}, {32,32,'*',32,32}, {32,32,'*',32,32}, {32,32,'*',32,32}},
	{{32,'*','*','*',32}, {'*',32,32,32,'*'}, {32,32,32,32,'*'}, {32,32,32,'*',32}, {32,'*','*',32,32}, {'*',32,32,32,32}, {'*','*','*','*','*'}},
	{{32,'*','*','*',32}, {'*',32,32,32,'*'}, {32,32,32,32,'*'}, {32,32,'*','*',32}, {32,32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*',32}},
	{{32,32,32,'*',32}, {32,32,'*','*',32}, {32,'*',32,'*',32}, {'*',32,32,'*',32}, {'*','*','*','*','*'}, {32,32,32,'*',32}, {32,32,32,'*',32}},
	{{'*','*','*','*','*'}, {'*',32,32,32,32}, {'*','*','*','*',32}, {32,32,32,32,'*'}, {32,32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*',32}},
	{{32,'*','*','*',32}, {'*',32,32,32,'*'}, {'*',32,32,32,32}, {'*','*','*','*',32}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*',32}},
	{{'*','*','*','*','*'}, {32,32,32,32,'*'}, {32,32,32,32,'*'}, {32,32,32,'*',32}, {32,32,'*',32,32}, {32,32,'*',32,32}, {32,32,'*',32,32}},
	{{32,'*','*','*',32}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*',32}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*',32}},
	{{32,'*','*','*',32}, {'*',32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*','*'}, {32,32,32,32,'*'}, {'*',32,32,32,'*'}, {32,'*','*','*',32}}
};

char chip[7][13] = {
	{32,32,32,'*','*','*','*','*',32,'*',32,32,32},
	{32,'*',32,32,'*','*','*',32,32,'*',32,'*',32},
	{'*',32,32,'*',32,32,32,'*',32,32,'*',32,'*'},
	{'*',32,32,'*',32,32,32,32,32,32,'*',32,'*'},
	{'*',32,32,'*',32,32,32,'*',32,32,'*',32,'*'},
	{32,'*',32,32,'*','*','*',32,32,'*',32,'*',32},
	{32,32,32,'*','*','*','*','*',32,'*',32,32,32}
};

char display[9][54] = {
	{32,32,32,32,32,'*','*','*','*','*','*','*','*','*','*','*','*','*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,'*','*',32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,'*','*',32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,'*','*',32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,'*','*',32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,'*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
	{32,32,32,32,32,'*','*','*','*','*','*','*','*','*','*','*','*','*',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32}
};

int mode;
int start_chip = 20;
int card1[10] = {0};
int card2[10] = {0};
int decknum;

typedef struct player{
	int chip;
	int card;
} player;

player pl, ai;

void Animation();
int Dealing();
void Betting(int* pot, int first_player);
void FirstAction_Player(int* bet, int** pot, int* end);
void Action_Player(int* bet, int** pot, int* end);
void FirstAction_AI(int* bet, int** pot, int* end, int* ai_totalbet);
void Action_AI(int* bet, int** pot, int* end, int* ai_totalbet);
void Show(int pot);

int main()
{
	int turn = 1;
	int bet;
	int pot;

	while(1){
		printf("Select a mode (1: Easy, 2: Difficult): ");
		scanf("%d", &mode);
		if (mode == 2)
			printf("Not Yet :(\n");
		else if (mode == 1)
			break;
	}

	pl.chip = start_chip;
	ai.chip = start_chip;
	decknum = 20;

	while (pl.chip > 0 && ai.chip > 0){
		if (decknum == 0){
			decknum = 20;
			for(int i=0; i<10; i++){
				card1[i] = 0;
				card2[i] = 0;
			}
		}

		char go1,go2;
		printf("Press any key to play next turn: ");
		scanf("%c%c", &go1, &go2);

		pot = 0;
		Animation();

		printf("#turn %d\n\n", turn);
		
		printf(" Ante: chip 1\n");
		pl.chip--;
		ai.chip--;
		pot += 2;

		pl.card = Dealing();
		ai.card = Dealing();

		Show(pot);

		//printf("ai's card is '%d'\n\n", ai.card);
		if (turn%2 == 1){
			printf("\n     first player: player\n");
			Betting(&pot, turn%2);
		}
		else{
			printf("\n     first player: ai\n");
			Betting(&pot, turn%2);
		}

		turn++;
	}
}

void Animation(){
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);
	printf("**************************************************\n");
	usleep(20000);

	system("clear");
}

int Dealing(){
	int card_num;
	decknum--;
	srand(time(NULL));

	while(1){

		card_num = rand()%10;
		if (card1[card_num] == 0){
			card1[card_num] = 1;
			card_num++;
			return card_num;
		}
		else if (card2[card_num] == 0){
			card2[card_num] = 1;
			card_num++;
			return card_num;
		}
		else
			continue;
	}
}

void Betting(int* pot, int first_player){
	int bet = 0;
	int end = 0;
	int ai_totalbet = 0;

	if (first_player == 1){
		FirstAction_Player(&bet, &pot, &end);
		if (end == 1)
			return;
		while(end == 0){
			Action_AI(&bet, &pot, &end, &ai_totalbet);
			if (end == 1)
				break;
			Action_Player(&bet, &pot, &end);
		}
	}

	if (first_player == 0){
		FirstAction_AI(&bet, &pot, &end, &ai_totalbet);
		if (end == 1)
			return;
		while(end == 0){
			Action_Player(&bet, &pot, &end);
			if (end == 1)
				break;
			Action_AI(&bet, &pot, &end, &ai_totalbet);
		}
	}
}

void FirstAction_Player(int* bet, int** pot, int* end){
	int action;
	int turnover = 0;

	while(turnover == 0){
		if (ai.chip == 0){
			printf("\n     AI's chip is 0! Open!!\n");
			printf("     your card is %d\n", pl.card);
			printf("     ai's card is %d\n", ai.card);
			if (pl.card > ai.card){
				printf("     You Win :) pot: %d\n", **pot);
				pl.chip += **pot;
			}
			else if (pl.card < ai.card){
				printf("     You Lose :( pot: %d\n", **pot);
				ai.chip += **pot;
			}
			else{
				printf("     Chop!! pot: %d\n", **pot);
				pl.chip += (**pot)/2;
				ai.chip += (**pot)/2;
			}
			Show(**pot);
			*end = 1;
			return;
		}

		printf("     your action (1: raise, 2: fold) : ");
		scanf("%d", &action);
		
		switch (action){
			case 1:
				printf("\n     Player: Raise!!\n");
				do{
					printf("     your betting: ");
					scanf("%d", bet);
				} while(*bet>pl.chip || *bet>ai.chip);
				pl.chip -= *bet;
				**pot += *bet;
				Show(**pot);
				turnover = 1;
				break;
			case 2:
				printf("\n     Player: Fold!!\n");
				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card == 10){
					printf("      Your card is 10!!!\n");
					pl.chip -= 10;
					**pot += 10;
				}
				printf("      You Lose :( pot: %d\n", **pot);
				ai.chip += **pot;
				Show(**pot);
				*end = 1;
				turnover = 1;
				break;
			default:
				printf("     please action again\n");
				continue;
		}
	}
}

void Action_Player(int* bet, int** pot, int* end){
	int action;
	int turnover = 0;

	while(turnover == 0){
		if (ai.chip == 0){
			printf("\n     AI's chip is 0! Open!!\n");
			printf("     your card is %d\n", pl.card);
			printf("     ai's card is %d\n", ai.card);
			if (pl.card > ai.card){
				printf("     You Win :) pot: %d\n", **pot);
				pl.chip += **pot;
			}
			else if (pl.card < ai.card){
				printf("     You Lose :( pot: %d\n", **pot);
				ai.chip += **pot;
			}
			else{
				printf("     Chop!! pot: %d\n", **pot);
				pl.chip += (**pot)/2;
				ai.chip += (**pot)/2;
			}
			Show(**pot);
			*end = 1;
			return;
		}

		printf("     your action (1: raise, 2: call, 3: fold) : ");
		scanf("%d", &action);
		
		switch (action){
			case 1:
				if (pl.chip == *bet){
					printf("     You can not raise. You have to call or fold.\n");
					continue;
				}
				printf("\n     Player: Raise!!\n");
				pl.chip -= *bet;
				**pot += *bet;
				do{
					printf("     your betting: ");
					scanf("%d", bet);
				} while(*bet>pl.chip || *bet>ai.chip);
				pl.chip -= *bet;
				**pot += *bet;
				Show(**pot);
				turnover = 1;
				break;
			case 2:
				printf("\n     Player: Call!!\n");
				pl.chip -= *bet;
				**pot += *bet;

				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
				turnover = 1;
				break;
			case 3:
				printf("\n     Player: Fold!!\n");
				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card == 10){
					printf("     Your card is 10!!!\n");
					pl.chip -= 10;
					**pot += 10;
				}
				printf("     You Lose :( pot: %d\n", **pot);
				ai.chip += **pot;
				Show(**pot);
				*end = 1;
				turnover = 1;
				break;
			default:
				printf("     please action again\n");
				continue;
		}
	}
}

void FirstAction_AI(int* bet, int** pot, int* end, int* ai_totalbet){
	int maxbet;

	if (mode == 1){
		if (pl.chip == 0){
			printf("\n     player's chip is 0! Open!!\n");
			printf("     your card is %d\n", pl.card);
			printf("     ai's card is %d\n", ai.card);
			if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
		}
		else if (1<=pl.card && pl.card<=3){
			maxbet = 10;
			printf("\n     AI: Raise!!\n");
			if (ai.chip >= 5){
				if (pl.chip < 5)
					*bet = pl.chip;
				else
					*bet = 5;
				*ai_totalbet += *bet;
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				**pot += *bet;
			}
			else{
				if (pl.chip < ai.chip)
					*bet = pl.chip;
				else
					*bet = ai.chip;
				*ai_totalbet += *bet;
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				**pot += *bet;
			}
			Show(**pot);
		}
		else if (4<=pl.card && pl.card<=5){
			maxbet = 7;
			printf("\n     AI: Raise!!\n");
			if (ai.chip >= 3){
				if (pl.chip < 3)
					*bet = pl.chip;
				else
					*bet = 3;
				*ai_totalbet += *bet;
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				**pot += *bet;
			}
			else{
				if (pl.chip < ai.chip)
					*bet = pl.chip;
				else
					*bet = ai.chip;
				*ai_totalbet += *bet;
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				**pot += *bet;
			}
			Show(**pot);
		}
		else if (6<=pl.card && pl.card<=7){
			maxbet = 3;
			if (ai.chip >= 5){
				printf("\n     AI: Raise!!\n");
				*bet = 1;
				*ai_totalbet += *bet;
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				**pot += *bet;
			}
			else{
				printf("\n     AI: Fold!!\n");
				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (ai.card == 10){
					printf("     AI's card is 10!!!\n");
					ai.chip -= 10;
					**pot += 10;
				}
				printf("     You Win :) pot: %d\n", **pot);
				pl.chip += **pot;
				*end = 1;
			}
			Show(**pot);
		}
		else{
			maxbet = 3;
			if (ai.chip >= 10){
				printf("\n     AI: Raise!!\n");
				*bet = 1;
				*ai_totalbet += *bet;
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				**pot += *bet;
			}
			else{
				printf("\n     AI: Fold!!\n");
				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (ai.card == 10){
					printf("     AI's card is 10!!!\n");
					ai.chip -= 10;
					**pot += 10;
				}
				printf("     You Win :) pot: %d\n", **pot);
				pl.chip += **pot;
				*end = 1;
			}
			Show(**pot);
		}
	}
}

void Action_AI(int* bet, int** pot, int* end, int* ai_totalbet){
	int maxbet;

	*ai_totalbet += *bet;

	if (mode == 1){
		if (pl.chip == 0){
			if (1<=pl.card && pl.card<=5){
				printf("\n     AI: Call!!\n");
				ai.chip -= *bet;
				**pot += *bet;

				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
			}

			else if (6<=pl.card && pl.card<=10){
				printf("\n     AI: Fold!!\n");
				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (ai.card == 10){
					printf("     AI's card is 10!!!\n");
					ai.chip -= 10;
					**pot += 10;
				}
				printf("     You Win :) pot: %d\n", **pot);
				pl.chip += **pot;
				Show(**pot);
				*end = 1;
			}
		}
		else if (1<=pl.card && pl.card<=3){
			maxbet = 10;
			if (*ai_totalbet >= maxbet){
				printf("\n     AI: Call!!\n");
				ai.chip -= *bet;
				**pot += *bet;

				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
			}
			else if (ai.chip == *bet){
				printf("\n     AI: Call!!\n");
				ai.chip -= *bet;
				**pot += *bet;

				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
			}
			else{
				printf("\n     AI: Raise!!\n");
				ai.chip -= *bet;
				**pot += *bet;
				if (ai.chip >= maxbet - *ai_totalbet){
					if (pl.chip < maxbet - *ai_totalbet)
						*bet = pl.chip;
					else
						*bet = maxbet - *ai_totalbet;
				}
				else{
					if (pl.chip < ai.chip)
						*bet = pl.chip;
					else
						*bet = ai.chip;
				}
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				*ai_totalbet += *bet;
				**pot += *bet;
				Show(**pot);
			}
		}

		else if (4<=pl.card && pl.card<=5){
			maxbet = 7;
			if (*ai_totalbet >= maxbet){
				printf("\n     AI: Call!!\n");
				ai.chip -= *bet;
				**pot += *bet;

				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
			}
			else if (ai.chip == *bet){
				printf("\n     AI: Call!!\n");
				ai.chip -= *bet;
				**pot += *bet;

				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
			}
			else{
				printf("\n     AI: Raise!!\n");
				ai.chip -= *bet;
				**pot += *bet;
				if (ai.chip >= maxbet - *ai_totalbet){
					if (pl.chip < maxbet - *ai_totalbet)
						*bet = pl.chip;
					else
						*bet = maxbet - *ai_totalbet;
				}
				else{
					if (pl.chip < ai.chip)
						*bet = pl.chip;
					else
						*bet = ai.chip;
				}
				printf("     AI's betting: %d\n", *bet);
				ai.chip -= *bet;
				*ai_totalbet += *bet;
				**pot += *bet;
				Show(**pot);
			}
		}

		else if (6<=pl.card && pl.card<=7){
			maxbet = 3;

			if (*bet >= maxbet){
				printf("\n     AI: Fold!!\n");
				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (ai.card == 10){
					printf("     AI's card is 10!!!\n");
					ai.chip -= 10;
					**pot += 10;
				}
				printf("     You Win :) pot: %d\n", **pot);
				pl.chip += **pot;
				Show(**pot);
				*end = 1;
			}
			else{
				printf("\n     AI: Call!!\n");
				ai.chip -= *bet;
				**pot += *bet;

				printf("     your card is %d\n", pl.card);
				printf("     ai's card is %d\n", ai.card);
				if (pl.card > ai.card){
					printf("     You Win :) pot: %d\n", **pot);
					pl.chip += **pot;
				}
				else if (pl.card < ai.card){
					printf("     You Lose :( pot: %d\n", **pot);
					ai.chip += **pot;
				}
				else{
					printf("     Chop!! pot: %d\n", **pot);
					pl.chip += (**pot)/2;
					ai.chip += (**pot)/2;
				}
				Show(**pot);
				*end = 1;
			}
		}

		else{
			printf("\n     AI: Fold!!\n");
			printf("     your card is %d\n", pl.card);
			printf("     ai's card is %d\n", ai.card);
			if (ai.card == 10){
				printf("     AI's card is 10!!!\n");
				ai.chip -= 10;
				**pot += 10;
			}
			printf("     You Win :) pot: %d\n", **pot);
			pl.chip += **pot;
			Show(**pot);
			*end = 1;
		}
	}
}

void Show(int pot){
	//Animation();
	//system("clear");
	printf("\n your chip: %d\n", pl.chip);
	printf(" ai's chip: %d\n\n", ai.chip);

	printf("     AI's card          pot\n");
	for(int i=0; i<7; i++){
		for(int j=0; j<13; j++){
			display[i+1][j+24] = chip[i][j];
		}
	}

	if (ai.card < 10){
		for(int i=0; i<7; i++){
			for(int j=0; j<5; j++){
				display[i+1][j+9] = num[ai.card][i][j];
			}
		}
	}
	else{
		for(int i=0; i<7; i++){
			for(int j=0; j<5; j++){
				display[i+1][j+6] = num[1][i][j];
			}
		}
		for(int i=0; i<7; i++){
			for(int j=0; j<5; j++){
				display[i+1][j+11] = num[0][i][j];
			}
		}
	}

	for(int i=0; i<7; i++){
		for(int j=0; j<5; j++){
			display[i+1][j+43] = num[pot/10][i][j];
			display[i+1][j+49] = num[pot%10][i][j];
		}
	}

	for(int i=0; i<9; i++){
		for(int j=0; j<54; j++)
			printf("%c", display[i][j]);
		printf("\n");
	}
}