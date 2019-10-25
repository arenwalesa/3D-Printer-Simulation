#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

int selection, gender, job, x, printtype, printmat, highScore[100], count; 
char name[100], score[100], product[100];
float random, jobD, genderD, printtypeD, printmatD, printHour, printHourD, printDayD, money,moneyC, FINAL;
float endbonusD=0; 

int main(){
	printf("3D Print Simulator Version Alpha\n");
	printf("Press Enter, or input any key (excluding arrow keys) to continue\n\n");
	system("pause");
 	mainMenu();
	return 0;
}

int mainMenu(){ // menampilkan main menu
	system("cls");
	printf("Welcome To 3D Printer Simulator: \n1. Play \n2. Help \n3. Highscore \n4. Credits \n5. Exit\n");
	
	selection=checkInput(5);
	menuSelect(selection);
}

int menuSelect(int x){ //eksekusi pilihan submenu dari main menu
    switch(x){
     	
    case 1:
        system("cls");
		playMenu();
	
    case 2:
        system("cls");
		printf("This is a 3D Printer Simulation, where users: \n-Simulate the chance of a successful printing products from their customized inputs. \n-Receive a bonus successful chance with each try as the simulator tries to increase efficiency. \n-Notes the Lowest and Highest budgets received from previously simulated products. \n\nInstructions: \n1.Enter your Gender and Job, these WILL affect the success chance, and the fixated factors that will not change in value until the user decides to exit the program. \n2.Enter the name of the product (Ex: Miniature Tower). Product names doesn't affect success chances. \n3.Enter the afformated parameters that WILL affect the success chance. These will be: \n-Printer Type \n-Printer Material Condition \n-Printer Daily Work Time (Up to 24 Hours Max) \n-Printer Work Duration (Measured in Days, up to 30 Days Max) \n4.The Simulator will show the final measured chance of success, and the user will be asked to return to step number 2. \nDoing so will note the last budget the user received to the highscore.txt file.\n5.The User will repeat step 4 until they exit the program.\n");
		printf("\nPress Enter, or input any key (excluding arrow keys) to continue \n");
		getchar();
		mainMenu();
	
    case 3:
        system("cls");
        printf("Highscore Menu adalah tampilan data score dari File External, menggunakan Array untuk menyimpan dan menunjukkan value\n ");
		showScore();
		printf("\n\n\n\nPress Enter, or input any key (excluding arrow keys) to continue");
		getchar();
		mainMenu();
	
    case 4:
        system("cls");
		printf("Lead Programmer: \nTristan Ardhika\n\nSecondary Programmer: \nMuhammad Arendio Walesa\n\nSpecial Thanks to: \nAlfan Presekal, S.T., M.Sc.\nAs lecturer and consultant\n");
		printf("\nPress Enter, or input any key (excluding arrow keys) to continue");
		getchar();
		mainMenu();
	break;
	
    case 5:
        system("cls");
    	printf("Bye, come again! :)");
	exit(0);
	return;
}
}


int playMenu(){ //menu yang muncul pertama kali user masuk ke play menu
	system("cls");
	printf("1. New game\n2. Continue\n3. Back to main menu\n");
	
	selection=checkInput(3);
	if (selection==1){ //new game gitu
		system("cls");
		printf("Initializing a new game, please fill your data\n\n\n");
		printf("Enter your name >>>");
		fgets(name, 100, stdin);
	    remove_newline_ch(name);
		system("cls");
		printf("Hello %s, what is your profession?\n1.Student \n2.Engineer \n3.Programmer \n4.Unemployed\n ",name,selection);
		selection=checkInput(4);
		if (selection==1){
		jobD = 1.02 ;
		money = 100 ;
		}
		else if (selection==2){
		jobD = 1.03 ;
		money = 150 ;	
		}
		else if (selection==3){
		jobD = 1.04 ;
		money = 200 ;	
		}
		else if (selection==4){
		jobD = 1 ;
		money = 75 ;	
		}
		printf("Your budget will be: %f \n", money) ;
		printf("Are you a Male or a Female?\n1.Male \n2.Female\n ");
		selection=checkInput(2) ;
		if (selection==1){
		genderD = 1.02 ;	
		}
		else if (selection==2){
		genderD = 1.01 ;	
		}
		game();
		//getchar();
	}
	else if (selection==2){ 
		system("cls"); 
		if (money <= 0){
		printf("Please select new game first.\nPress Enter, or input any key (excluding arrow keys) to continue");	
		getchar();
		mainMenu();
	    }
		else if (money >= 0){
		gameS();	
		}
		

	}
	else if (selection==3){
	mainMenu();
	}
}

int game(){
	    endbonusD=0;
		while(1){
		system("cls");
		printf("What do you want to build: ");
	    fgets(product, 100, stdin);
	    remove_newline_ch(product);
		printf("\nPick a printer type: \n1.Cheap \n2.Affordable \n3.Expensive\n ");
		selection=checkInput(3) ;
		if (selection==1){
		printtypeD = 1.05 ;
		money = money - 5 ;
		moneyC= moneyC+5;	
		}
		else if (selection==2){
		printtypeD = 1.07 ;	
		money = money - 10 ;
		moneyC= moneyC+10;
		}
		else if (selection==3){
		printtypeD = 1.1 ;
		money = money - 20 ;		
		moneyC= moneyC+20;
		}
		
	    
	    printf("\nPick the printer material: \n1.Used \n2.Ready \n3.Factory Day 1\n ");
		selection=checkInput(3) ;
		if (selection==1){
		printmatD = 1.02 ;
		money = money - 5 ;	
		moneyC= moneyC+5;
		}
		
		else if (selection==2){
		printmatD = 1.05 ;
		money = money - 10 ;	
		moneyC= moneyC+10;
		}
		
		else if (selection==3){
		printmatD = 1.1 ;
		money = money - 20 ;		
		moneyC= moneyC+20;
		}
		
		
		printf("\nSet the printer work hour (value must range between 1 - 24): ");
		selection=checkInput(24);
		printHourD = selection*0.0458;
		money = money - (selection*0.0167) ;		
		moneyC= moneyC + (selection*0.0167) ;
		
		printf("\nSet how long the printer will work  (valued in days, must range between 1 - 30): ");
		selection=checkInput(30);
		printDayD = selection*0.367 ;
		money = money - (selection*0.11) ;
		moneyC= moneyC + (selection*0.11);		
	
	random=rand() % 100;
	printf("rand = %f\n", random);
	FINAL = (random*jobD*genderD*printtypeD*printmatD*printHourD*printDayD) + endbonusD ;
	if (FINAL > 100) {
	FINAL = 100 ;	
	}
	printf("Congratulations, your '%s' have %f chance of printing success. \n\n",product,FINAL) ;
	if(FINAL <= 50) {
        printf("Product is Flawed\n ");
    	endbonusD = endbonusD + 0.25 ;
    	printf("endbonus: %f\n",endbonusD);
    	}
    else if (FINAL > 50) {
    	printf("Product is Well Constructed\n ");
        endbonusD = endbonusD + 0.25 ;
        endbonusD = endbonusD*1.5 ;
        printf("endbonus: %f\n",endbonusD);
        money = money + (moneyC*1.4) ;
		}
	printf("You have %f budget left. \n\n ",money) ;		
	printf("Try again by pressing 1, or return to menu by pressing 2 \n");
	selection=checkInput(2) ;
	if (selection==2){
		count++;
		highScore[count]=money;
		sort(highScore,count);
		save(highScore,count);
	break;	
	}
}
	playMenu() ;
	system("pause");
}


int gameS(){
		while(1){
		system("cls");
		printf("What do you want to build: ");
	    fgets(product, 100, stdin);
	    remove_newline_ch(product);
		printf("\nPick a printer type: \n1.Cheap \n2.Affordable \n3.Expensive\n ");
		selection=checkInput(3) ;
		if (selection==1){
		printtypeD = 1.05 ;
		money = money - 5 ;
		moneyC= moneyC+5;	
		}
		else if (selection==2){
		printtypeD = 1.07 ;	
		money = money - 10 ;
		moneyC= moneyC+10;
		}
		else if (selection==3){
		printtypeD = 1.1 ;
		money = money - 20 ;		
		moneyC= moneyC+20;
		}
		
	    
	    printf("\nPick the printer material: \n1.Used \n2.Ready \n3.Factory Day 1\n ");
		selection=checkInput(3) ;
		if (selection==1){
		printmatD = 1.02 ;
		money = money - 5 ;	
		moneyC= moneyC+5;
		}
		
		else if (selection==2){
		printmatD = 1.05 ;
		money = money - 10 ;	
		moneyC= moneyC+10;
		}
		
		else if (selection==3){
		printmatD = 1.1 ;
		money = money - 20 ;		
		moneyC= moneyC+20;
		}
		
		
		printf("\nSet the printer work hour (value must range between 1 - 24): ");
		selection=checkInput(24);
		printHourD = selection*0.0458;
		money = money - (selection*0.0167) ;		
		moneyC= moneyC + (selection*0.0167) ;
		
		printf("\nSet how long the printer will work  (valued in days, must range between 1 - 30): ");
		selection=checkInput(30);
		printDayD = selection*0.367 ;
		money = money - (selection*0.11) ;
		moneyC= moneyC + (selection*0.11);		
	
	random=rand() % 100;
	printf("rand = %f\n", random);
	FINAL = (random*jobD*genderD*printtypeD*printmatD*printHourD*printDayD) + endbonusD ;
	if (FINAL > 100) {
	FINAL = 100 ;	
	}
	printf("Congratulations, your '%s' have %f chance of printing success. \n\n",product,FINAL) ;
	if(FINAL <= 50) {
        printf("Product is Flawed\n ");
    	endbonusD = endbonusD + 0.25 ;
    	printf("endbonus: %f\n",endbonusD);
    	}
    else if (FINAL > 50) {
    	printf("Product is Well Constructed\n ");
        endbonusD = endbonusD + 0.25 ;
        endbonusD = endbonusD*1.5 ;
        printf("endbonus: %f\n",endbonusD);
        money = money + (moneyC*1.4) ;
		}
	printf("You have %f budget left. \n\n ",money) ;		
	printf("Try again by pressing 1, or return to menu by pressing 2 \n");
	selection=checkInput(2) ;
	if (selection==2){
		count++;
		highScore[count]=money;
		sort(highScore,count);
		save(highScore,count);
	break;	
	}
}
	playMenu() ;
	system("pause");
}


int checkInput(int max){ //cek input user dimana max itu jumlah pilihan maksimumnya
		while(1){ 
		scanf("%d", &x);
	    if(x < 1 || x > max) {
        printf("\n\n\t Wrong input try again\n ");
    	}
    			fflush(stdin);
    	if(x >= 1 && x <= max){
    	break;
		}
	} //endwhile
	return x;
}

void remove_newline_ch(char *line)
{
	int new_line = strlen(line) - 1;
	if(line[new_line] == '\n')
		line[new_line] = '\0';
}

int sort(int x[],int n){
	int a, y, z;
	for (y = 0; y < n; ++y) {
            for (z = y + 1; z < n; ++z){
                if (x[y] < x[z]) {
                    a =  x[y];
                    x[y] = x[z];
                    x[z] = a;
                }
            }
        }
 
 return x;
}

int save(int x[],int i)
{
	int c;
	int u;
	FILE *fptr;
	fptr = fopen("C:\\Users\\ASUS\\Desktop\\highscore.txt","w+");
		fprintf(fptr, "          HIGH SCORES\n");
		fprintf(fptr, "No.        Net Worth\n");
	for (u=0;u<i;u++)
	{
    	fprintf(fptr, "%d          $%d\n",u+1, x[u]);
	}
		fclose(fptr);
	return 0;
}

int showScore()
{
	int c;
	FILE *fptr;
	fptr = fopen("C:\\Users\\ASUS\\Desktop\\highscore.txt","r");
	while ((c = getc(fptr)) != EOF) putchar(c); //print isi text file
	fclose(fptr);
}
