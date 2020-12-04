#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu();
void napoveda();
void hra();
void navigation();
void text_color(int cas);
void stlacene_klavesy(char pole_stlacenych[]);
void nickname();
void statistiky(int cas);

char meno[50] = {'P', 'l', 'a', 'y', 'e', 'r'};

int main() {
	
	menu();
	
	navigation();
	
	return 0;
	
}

void hra() {
	
	system("cls");
	
	clock_t start_t, end_t, total_t;
	
	srand(time(NULL));
	
	int znak_hry, mil_sekundy = 0, i = 0, j;
	
	char pole_znakov[31] = {'a', 'b', 'c','d', 'e', 'f','g', 'h', 'i','j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char pole_stlacenych[100];
		
	int random = rand() % 26;
		
	printf("Napis pismeno \033[93m%c\033[0m co najrychlejsie ", pole_znakov[random]);

	start_t = clock();
	
	do {
		znak_hry = getch();	
		pole_stlacenych[i] = znak_hry;
		i++;
		if(znak_hry == 27 || znak_hry == 68)
			exit(0);
	}
	while(znak_hry != pole_znakov[random]);
	
	end_t = clock();
	
	total_t = (double)(end_t - start_t);
	
	text_color(total_t);	
	
	stlacene_klavesy(pole_stlacenych);
	
	printf("\n");
	
	statistiky(total_t);
	
	menu();
	navigation();
}

void stlacene_klavesy(char pole_stlacenych[]) {
	int i;
	
	(strlen(pole_stlacenych) == 1) ? printf("\nStlacili ste: ") : printf("\nPostupne ste stlacili: ");
	
	for(i = 0; i < strlen(pole_stlacenych); i++) {
		printf("%c ", pole_stlacenych[i]);
	}
}


void navigation() {
	int znak;
	while(1) {
		znak = getch();
	
		switch(znak) {
			case 27: //vypnutie hry
				exit(0);
			case 68: //vypnutie hry
				exit(0);
			case 59:
				napoveda(); //napoveda
			case 60: //start restart
				hra();
			case 61:
				nickname();
		}
	}
}

void menu() {
	printf("F1 - napoveda\n");
	printf("F2 - start/restart\n");
	printf("F3 - zmena mena\n");
	printf("F10/ESC - koniec\n");
}

void napoveda() {
	system("cls");
	printf("Meranie bude spocivat v tom, ze program vygeneruje nahodny znak, zobrazi ho a spusti meranie casu. Meranie sa zastavi v okamihu, ked uzivatel stlaci rovnaku klavesu. Ak uzivatel stlaci nieco ine, program to ma ignorovat. Napokon program vypise zmerany cas, ktory uplynie od vypisania po stlacenie rovnakej klavesy.\n" );
	menu();
	navigation();
}

void text_color(int cas) {
	if(cas <= 1000) {
		printf("\nTvoj reakcny cas bol: ");
		printf("\033[32m %ld \033[0m ms", cas);
	}
	if(cas > 1000 && cas <= 1500) {
		printf("\nTvoj reakcny cas bol: ");
		printf("\033[96m %ld \033[0m ms", cas);
		
	}
	if(cas > 1500) {
		printf("\nTvoj reakcny cas bol: ");
		printf("\033[31m %ld \033[0m ms", cas);
	}
}

void nickname() {
	system("cls");
	
	printf("Teraz mas meno %s\n", meno);
	printf("Nastav si nove meno: ");
	scanf("%s", &meno);

	system("cls");
	menu();
	navigation();
}

void statistiky(int cas) {
	FILE *fptr;
	fptr = (fopen("vysledky.txt", "a"));
	
	if(fptr == NULL)
	{
       printf("Error!");
       exit(1);
	}
	
   	
	fprintf(fptr,"meno: %s\tdoba=%ldms \n", meno, cas);
   	
   	fclose(fptr);
}



