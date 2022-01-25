#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user user,usr;
	char filename[50],phone[50],password[50],phone2[50];
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] REGISTER YOUR ACCOUNT                    |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [2] SIGN-IN TO AN EXISTING ACCOUNT           |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [3] EXIT                                     |\n\t\t\t\t________________________________________________\n\t\t\t\t\t\t\t\t");

printf("\n\t\t\t\tPLEASE SELECT A NUMBER OF YOUR REQUIRED FUNCTION FROM THE BOX:");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	if(opt == 1){
		system("cls");
		printf("\nEnter your account number:\t");
		scanf("%s",user.phone);
		printf("Enter your phone number:\t");
		scanf("%s",user.ac);
		printf("Enter your new password:\t");
		scanf("%s",user.password);
		user.balance=0;
		stpcpy(filename,user.phone);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Successfully registered");
		}
	}
	else if(opt == 2){
		system("cls");
		printf("\nAccount No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".dat"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				system("clear");
				printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] INQUIRY FOR BALANCE                      |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [2] ADD FUNDS                                |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [3] WITHDRAW CASH                            |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [4] ONLINE TRANSFER                          |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [5] CHANGE PASSWORD                          |\n\t\t\t\t________________________________________________\n\t\t\t\t\t\t\t\t");
    printf("\n\t\t\t\tPLEASE CHOOSE A NUMBER IN THE BOX ABOVE:");

				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("Your current balance is Rs. %.2f",user.balance);
						break;

					case 2:
						system("clear");
						printf("Enter amount to be added:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have deposited Rs.%d",amount);
						fclose(fp);
						break;

					case 3:
						system("clear");
						printf("Enter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						else if(amount>user.balance) printf("\nSorry insufficient balance");
						else {
							user.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
						break;

					case 4:
						printf("Please enter the account number to transfer balance:\t");
						scanf("%s",phone);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > user.balance) printf("\nSorry insufficient balance");
						else {
							fptr = fopen(strcat(phone,".dat"),"r");
							if(fptr==NULL) printf("Sorry account not registered");
							else {
								fread(&usr,sizeof(struct user),1,fptr);
								fclose(fptr);

								usr.balance += amount;

								fptr = fopen(phone,"w");
								fwrite(&usr,sizeof(struct user),1,fptr);
								if(fwrite != 0){
								// 	printf("Account:%s",usr.ac);
								// printf("\npassword%s",usr.password);
								// printf("\nphone%s",usr.phone);
								// printf("\nbalance%f",usr.balance);
									printf("Your transfer is completed. You have transfered Rs.%d to %s",amount,usr.phone);
									fclose(fptr);
									user.balance -= amount;
									strcpy(filename,user.phone);
									fp = fopen(strcat(filename,".dat"),"w");
									fwrite(&user,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					case 5:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp = fopen(strcat(filename,".dat"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);
							printf("\nPassword successfully changed");
						}else printf("\nSorry your password is wrong");

					default:
					break;
				}//switch ends here
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("Invalid password");
			}
		}
		printf("\n\n***Thank you for banking with ABC bank***\n\n");
	}

	return 0;
}
