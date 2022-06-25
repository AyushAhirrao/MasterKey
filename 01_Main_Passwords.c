// Password_Manager_V1.1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <ayush.h>

char *strrev(char *s);
void add_password();
void click_img();
void timer(int time);
void display_passwords();
char change_password(char *list_pin);
void display_menu();
char read_password(char *main_password);
void view_suspect_img();
void install_packs();
void set_new_password();
void reset();
int forgot_password(int *r);
void reset_password();

int main()
{
system("clear");
    // choose_menu
    // char decrypt_code;
    // attempts
    int menu_attempts = 3;
    // setted pins for program execution in .password.txt file
    char main_password[100];
    read_password(main_password);
     // printf("%s\n", main_password);
    // int new_pin;

    // user entered pins
    char entered_password[100];

    // char developer_key[100];
    // system("cd /home/$USER/Downloads/passwords");
    // system("chmod 600 .dev_key.txt");
    // FILE *dtr;
    // dtr = fopen(".dev_key.txt", "r");
    // // fflush(stdin);
    // // fscanf(" %s", developer_key);
    // fgets(developer_key, sizeof(developer_key), dtr);
    // getchar();
    // // decrypt_string(developer_key);
    // printf("\n**********%s********\n", developer_key);
    // fclose(dtr);
    // system("chmod 000 .dev_key.txt");
    // char entered_developer_key[100];

    // choices
    int choose_menu;
    char go_back;
    char ch_reset, ch_forgot, choice;
    int ch_1, ch_4;

    // suspect warning
    system("chmod 600 .suspect.txt");
    FILE *suspect;
    suspect = fopen(".suspect.txt", "r");
    int suspect_bool;
    fscanf(suspect, "%d", &suspect_bool);
    fclose(suspect);
    system("chmod 000 .suspect.txt");

    // printf("%s\n", main_password);
    system("chmod 600 .password.txt");
    FILE *fp;
    fp = fopen(".password.txt", "r");

    if (NULL != fp)
    {
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);

        if (0 == size)
        {
        startup:
            set_new_password();
	    system("chmod 000 .password.txt");        }
        else
        {	
	    system("echo -THE PASSWORD MANAGER APP-");
            sleep(1);
            system("clear");
            system("echo -THE PASSWORD MANAGER APP-");
            system("echo .");
            sleep(1);
            system("clear");
            system("echo -THE PASSWORD MANAGER APP-");
            system("echo ..");
            sleep(1);
            system("clear");
            system("echo -THE PASSWORD MANAGER APP-");
            system("echo ...");
            sleep(1);
            system("clear");
            while (menu_attempts != 0)
            {

                printf("Enter the password: ");
                fflush(stdin);
                scanf(" %[^\n]s", entered_password);
                getchar();
                system("clear");

              //   printf("\n******%d*******\n",strcmp(entered_password, main_password));
                if (strcmp(entered_password, main_password) == 0)
                {
                    if (suspect_bool == 1)
                    {
                        char sus_ch;
                        printf("Warning: Someone tried to open the app without permission, View Suspect's Image?\n");
                        printf("Continue [Y/n] : ");
                        scanf(" %c", &sus_ch);
                        getchar();
                        sus_ch = tolower(sus_ch);
                        if (sus_ch == 'y')
                        {
				system("cd /home/$USER/Documents/.program-files/.password-manager && chmod 600 .image.jpeg;");
				system("cd /home/$USER/Documents/.program-files/.password-manager && if [ -f .image.jpeg ]; then chmod 600 .image.jpeg; feh .image.jpeg; else echo Error: image not captured; echo There was no invalid login attempt yet or you might not have a camera configured to your system; echo ; fi;");
				view_suspect_img();

                            system("chmod 600 .suspect.txt");
                            suspect_bool = 0;
                            suspect = fopen(".suspect.txt", "w");
                            fprintf(suspect, "%d", suspect_bool);
                            fclose(suspect);
                            system("chmod 000 .suspect.txt");

                            system("clear");
                            goto menu;
                        }
                        else
                        {
                            system("clear");
                            suspect_bool = 0;
                            system("chmod 600 .suspect.txt");
                            FILE *suspect;
                            suspect = fopen(".suspect.txt", "w");
                            fprintf(suspect, "%d", suspect_bool);
                            fclose(suspect);
                            system("chmod 000 .suspect.txt");

                            goto menu;
                        }
                    }
                    else
                    {

                        // 3 attempts for entering start pin{entered_code_pi}

                    menu:
                        display_menu();
                        printf("Enter your choice [0-4]: ");
                        scanf("%d", &choose_menu);
                        // system("clear");

                        switch (choose_menu)
                        {
                        case 0:
                            printf("exiting...\n");
			    system("chmod 000 .password.txt");
                            sleep(2);
                            system("clear");
                            exit(1);
                            break;

                        case 1:
                        menu_1:
                            system("clear");
                            printf("Edit Dictionary\n\n");
                            printf("  [0] <-- Go back to menu!\n\n");
                            printf("  [1] View Password Dictionary\n");
                            printf("  [2] Add Password\n");
                            printf("  [3] Remove Password\n");
                            printf("\nEnter your choice [0-3]: ");
                            scanf("%d", &ch_1);

                            switch (ch_1)
                            {
                            case 0:
                                system("clear");
                                goto menu;
                                break;

                            case 1:
                                system("clear");

                                display_passwords();
                                break;
                            case 2:
                                system("clear");
                                add_password();
                                break;
                            case 3:
                                system("clear");
                                system("chmod 600 .passwords_list.txt");
                                system("nano .passwords_list.txt");
                                system("chmod 000 .passwords_list.txt");
                                break;
                        
                            default:
                                printf("\nInvalid Input!\n");
                                sleep(2);
                                system("clear");
                                goto menu_1;
                                break;
                            }

                            printf("<-- Go back! [Y] : ");
                            fflush(stdin);
                            scanf("%c", &go_back);
                            getchar();
                            // printf("%c", go_back);
                            system("clear");
                            goto menu_1;
                            break;

                        case 2:
                            system("clear");
                            char code[100];
                            printf("Enter the encrypted password: ");
                            scanf("%s", code);
                            getchar();

                            decrypt_string(code);

                            printf("The decrypted password is: ");
                            puts(code);
                            printf("\n");

                            break;

                        case 3:
                            system("clear");
			    system("cd /home/$USER/Documents/.program-files/.password-manager && chmod 600 .image.jpeg;");
			    system("cd /home/$USER/Documents/.program-files/.password-manager && if [ -f .image.jpeg ]; then chmod 600 .image.jpeg; feh .image.jpeg; else echo Error: image not captured; echo There was no invalid login attempt yet or you might not have a camera configured to your system; echo ; fi;");
                            view_suspect_img();
                            goto menu;
                            break;

                        case 4:
                        menu_4:
                            system("clear");
                            printf("Settings:\n\n");
                            printf("  [0] <-- Go back to menu!\n\n");
                            printf("  [1] Change Password\n");
                            printf("  [2] Display Current Password\n");
                            printf("  [3] Reset App\n");
                            printf("  [4] Update\n");
                            printf("  [5] Developer Mode\n");
                            printf("\nEnter your choice [0-5]: ");
                            scanf("%d", &ch_4);

                            switch (ch_4)
                            {
                            case 0:
                                system("clear");
                                goto menu;
                                break;

                            case 1:
                                system("clear");
                                change_password(main_password);
                                break;

                            case 2:
                                system("clear");
                                system("chmod 400 .password.txt");

                                FILE *ptr;
                                ptr = fopen(".password.txt", "r");
                                fscanf(ptr, " %[^\n]s", main_password);
                                decrypt_string(main_password);
                                printf("Your current password is: %s\n", main_password);
                                fclose(ptr);
                                system("chmod 000 .password.txt");

                                break;

                            case 3:
                                system("clear");
                                printf("Note: Resetting the app will delete all your data like stored passwords, cashed images, etc.");
                                printf("\n\nAre you sure you want to continue? [Y/n] : ");
                                scanf(" %c", &ch_reset);
                                getchar();
                                ch_reset = tolower(ch_reset);

                                if (ch_reset == 'y')
                                {
                                    printf("Reseting...\n");
                                    sleep(3);
                                    system("clear");
                                    sleep(2);
                                    system("echo \"Hi $USER, Welcome to the Password Manager App\"");
                                    printf("\n");
                                    sleep(1);
                                    printf("THE PASSWORD MANAGER APP\n");
                                    printf("\"One Password for All Your Passwords...\"");
                                    printf("\n\n");
                                    sleep(4);
                                    system("echo ""© 2022 Ayush Ahirrao");
                                    sleep(5);
                                    system("clear");
                                    reset();
                                    printf("Done\n");
                                    system("clear");
                                    goto startup;
                                }
                                else
                                {
                                    printf("\nAbort!\n");
                                }
                                break;

                            case 4:
                               system("clear");
                                system("chmod 700 .password_manager.out");
                                system("chmod 700 .password_manager.c");
                                system("echo Note:");
				system("echo   1. Do not close the program while updating.");
				system("echo   2. Make sure you have a stable internet connection.");
				printf("Continue [Y/n] : ");
				scanf(" %c", &choice);
                                system("clear");

                                if (choice == 'y')
                                {
                                    system("cd ~ && cd /home/$USER/Documents/.program-files/.password-manager/ && wget https://github.com/ayush2030/password_manager/blob/main/01_Main_Passwords.c?raw=true");
                                    system("echo please wait...");
                                    sleep(20);
                                    FILE *upd;
                                    upd = fopen("01_Main_Passwords.c?raw=true", "r");
                                    if (upd == NULL)
                                    {
                                        system("clear");
                                        printf("Warning: Error while updating\n");
                                        printf("Please check your internet connection!\n");
					 
                                    }
                                    else
                                    {

                                        system("cd ~ && cd /home/$USER/Documents/.program-files/.password-manager/ && rm .password_manager.c");
                                        system("cd ~ && cd /home/$USER/Documents/.program-files/.password-manager/ && mv 01_Main_Passwords.c?raw=true .password_manager.c");
                                        system("cd ~ && cd /home/$USER/Documents/.program-files/.password-manager/ && rm .password_manager.out");
                                        system("cd ~ && cd /home/$USER/Documents/.program-files/.password-manager/ && gcc .password_manager.c -o .password_manager.out");
                                        system("cd ~ && cd /home/$USER/Documents/.program-files/.password-manager/ && chmod 700 .password_manager.out");
                                        system("cd ~ && cd /home/$USER/Documents/.program-files/.password-manager/ && chmod 000 .password_manager.c");
                                        system("clear");
                                        printf("App successfully updated!\n");
                                        system("chmod 700 .password_manager.out");
                                        system("chmod 100 .password_manager.c");
                                        sleep(3);
                                        system("pkill terminal");
                                    }
                                }
                                else
                                {
                                    goto menu_4;
                                }
                                break;

                            case 5:
                                system("clear");
                                system("chmod 400 /home/$USER/Documents/.program-files/.password-manager/.password_manager.c");
                                system("nano /home/$USER/Documents/.program-files/.password-manager/.password_manager.c");
                                system("chmod 100 /home/$USER/Documents/.program-files/.password-manager/.password_manager.c");
                                break;

                            default:
                                printf("\nInvalid Input!\n");
                                sleep(2);
                                system("clear");
                                goto menu_4;
                                break;
                            }

                            printf("<-- Go back! [Y] : ");
                            fflush(stdin);
                            scanf("%c", &go_back);
                            getchar();
                            // printf("%c", go_back);
                            system("clear");
                            goto menu_4;

                            break;

                        default:
                            printf("\nInvalid Input!\n");
                            sleep(2);
                            system("clear");
                            goto menu;
                            break;
                        }

                        printf("<-- Go back to menu! [Y] : ");
                        fflush(stdin);
                        scanf("%c", &go_back);
                        getchar();
                        // printf("%c", go_back);
                        system("clear");

                        goto menu;

                        menu_attempts = 0;
                    }
                    system("clear");
                }
                else
                {
                    click_img(); // clicking image of user in he/she enters wrong password

                    suspect_bool = 1;
                    system("chmod 600 .suspect.txt");
                    FILE *suspect;
                    suspect = fopen(".suspect.txt", "w");
                    fprintf(suspect, "%d", suspect_bool);
                    fclose(suspect);
                    system("chmod 000 .suspect.txt");
                    printf("Wrong password!!! %d attempts left\n\n", menu_attempts - 1); // for user convience subtracting 1 from menu_attempts

                    menu_attempts--; // decrementing the attempts when pin is incorrect

                    if (menu_attempts == 0)
                    {
                        printf("Forgot password? [Y/n] : ");
                        scanf(" %c", &ch_forgot);
                        ch_forgot = tolower(ch_forgot);
                        if (ch_forgot == 'y')
                        {
                            int r;
                            forgot_password(&r);

                            if (r == 1)
                            {
                                reset_password();
                            }
                            else
                            {
                                printf("\nFailed to reset password!\n");
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    system("chmod 000 .password.txt");
    return 0;
}

// Functions


// Adds the new password to .passwords_list
void add_password()
{
    char choose_menu = 'y';
    while (choose_menu == 'y')
    {
        system("clear");
        system("chmod 600 .passwords_list.txt");
        FILE *ptr;
        ptr = fopen(".passwords_list.txt", "a");
        char name[100];
        char password[100];
        int i = 0;

        printf("Note: Name will be stored as ( <name> --> <password> );\n\n");
        printf("Enter name for the password: ");
        scanf(" %[^\n]s", name);
        getchar();
        sleep(1);

        printf("Enter the password for %s: ", name);
        fflush(stdin);
        scanf(" %[^\n]s", password);

        // char *str = password;

        encrypt_string(password);

        fputs(name, ptr);
        fprintf(ptr, " --> ");
        fputs(password, ptr);
        fprintf(ptr, "\n");

        printf("\nPassword successfully added to the dictionary!\n");
		sleep(3);
		system("clear");
        fclose(ptr);
        system("chmod 000 .passwords_list.txt");
        printf("Do you want to add new password? [Y/n]: ");
        scanf("%s", &choose_menu);
    }
}

// clicks the image with opening new another window
void click_img()
{
    // system("sudo apt install streamer");
    system("streamer -f jpeg -o .image.jpeg -q");
    //system("mv .image.jpeg /home/$USER/Documents/.program-files/.password-manager/");
    system("clear");
}

// sets given timer
void timer(int time)
{
    time = time + 2;
    while (time >= 0)
    {
        if (time == 0)
        {
            break;
            system("clear");
        }
        else
        {

            printf("\nTry again in: %d sec", (time - 2));
            time--;
            sleep(1);
            system("clear");
        }
    }
    system("clear");
}

void display_passwords()
{
    system("chmod 444 .passwords_list.txt");
    FILE *ptr;
    ptr = fopen(".passwords_list.txt", "r");
    // ptr = fopen(".passwords_list.txt", "r");

    char whole_string[1000], c;
    int i = 0;
    // fgets(read_all_passwords, 100, ptr);
    // puts(read_all_passwords);

    while ((c = fgetc(ptr)) != EOF)
    {
        whole_string[i] = c;
        i++;
    }
    whole_string[i] = '\0';
    printf("**********************************************************************\n");
    puts(whole_string);
    printf("**********************************************************************\n");
    system("chmod 000 .passwords_list.txt");
}

char change_password(char *list_pin)
{
    system("chmod 600 .password.txt");
    // int *list_pin;
    char new_password[100];
    int attempt = 3;
    char current_password[100];

    FILE *ptr;
    ptr = fopen(".password.txt", "w");

    printf("Warning: Do not close the program while resetting a new password, else the password will set as 0 by default!\n");
password:

    printf("\nEnter the current password: ");
    // ff/lush(stdin);
    scanf(" %[^\n]s", current_password);
    getchar();
    // puts(current_password);
    // puts(list_pin);

    // printf("\n********%d********\n", strcmp(current_password, list_pin));
    if (strcmp(current_password, list_pin) == 0)
    {
        printf("Enter the new password:");
        fflush(stdin);
        scanf(" %[^\n]s", new_password);
        getchar();
        printf("\nPassword successfully changed to: %s\n", new_password);
        encrypt_string(new_password);
        fprintf(ptr, "%s", new_password);
        attempt = 0;
    }
    else
    {
        click_img();
        printf("Warning: Wrong password! %d attempts left!\n\n", attempt - 1);
        attempt--;
        if (attempt > 0)
        {
            goto password;
        }
        else
        {
            encrypt_string(list_pin);
            fprintf(ptr, "%s", list_pin);
        }
    }

    system("chmod 000 .password.txt");
    fclose(ptr);
}

void display_menu()
{
    printf("**************************************************************************\n");
    printf("Menu:\n");
    printf("[1] Edit Dictionary \n");
    printf("[2] Decrypt password\n");
    printf("[3] View Suspect's Picture\n");
    printf("[4] Settings\n");
    printf("[0] Exit\n");
    printf("**************************************************************************\n");
}

char read_password(char *main_password)
{
    system("chmod 600 .password.txt");
    FILE *ptr;
    ptr = fopen(".password.txt", "r");
    fscanf(ptr, " %[^\n]s", main_password);
    fclose(ptr);
    decrypt_string(main_password);
    // printf("%d\n", main_password);
    return main_password;
    system("chmod 000 .password.txt");
}

void view_suspect_img()
{
system("cd /home/$USER/Documents/.program-files/.password-manager && if [ -f .image.jpeg ]; then chmod 600 .image.jpeg; fi;");
}

void install_packs()
{
    printf("Installing necessary packages for program\n");
    sleep(2);
    system("sudo apt install streamer");
    sleep(2);
    system("sudo apt install feh");
    // printf("\nsuccessfully installed necessary packages\n");
}

void set_new_password()
{
    system("clear");
    // system("cd /home/$USER/Downloads/passwords");
    system("chmod 600 .password.txt");
    FILE *ptr;
    char new_pin[100];
    ptr = fopen(".password.txt", "w");
    printf("Setting Password Required !\n\n");
    printf("Enter a password: ");
    scanf(" %[^\n]s", new_pin);
    encrypt_string(new_pin);
    fprintf(ptr, "%s", new_pin);
    sleep(1);
    fclose(ptr);
    system("chmod 000 .password.txt");

    // system("chmod 600 .dev_key.txt");
    // FILE *dtr;
    // char developer_key[100];
    // dtr = fopen(".dev_key.txt", "w");
    // printf("\nSetting Developer Key Required!\n");
    // printf("\nSet Developer Key:");
    // scanf(" %[^\n]s", developer_key);
    // getchar();
    // encrypt_string(developer_key);
    // fprintf(dtr, "%s", developer_key);
    // printf("\nDone\n");
    // sleep(1);
    // fclose(dtr);
    // system("chmod 000 .dev_key.txt");

    system("chmod 600 .forgot_password.txt");
    FILE *fp;
    fp = fopen(".forgot_password.txt", "w");

    char question1[100];
    char question2[100];
    char question3[100];
    system("clear");

    printf("Password Recovery Questions;\n\n");

    printf("1. What was your favorite subject in high school?\n");
    printf("-> ");
    fflush(stdin);
    scanf(" %[^\n]s", question1);
    getchar();
    int i, len = 0, j;

    // Calculating length of the array
    len = sizeof(question1) / sizeof(question1[0]);

    // Checks for space character in array if its there then ignores it and swap input1[i] to input1[i+1];
    for (i = 0; i < len; i++)
    {
        if (question1[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                question1[j] = question1[j + 1];
            }
            len--;
        }
    }
    encrypt_string(question1);
    fputs(question1, fp);
    fputs("\n", fp);

    printf("\n2. What was the name of your primary school?\n");
    printf("-> ");
    fflush(stdin);
    scanf(" %[^\n]s", question2);
    getchar();
    len = 0;

    // Calculating length of the array
    len = sizeof(question2) / sizeof(question2[0]);

    // Checks for space character in array if its there then ignores it and swap input1[i] to input1[i+1];
    for (i = 0; i < len; i++)
    {
        if (question1[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                question2[j] = question2[j + 1];
            }
            len--;
        }
    }
    encrypt_string(question2);
    fputs(question2, fp);
    fputs("\n", fp);

    printf("\n3. What is the name of the town where you were born?\n");
    printf("-> ");
    fflush(stdin);
    scanf(" %[^\n]s", question3);
    getchar();
    len = 0;

    // Calculating length of the array
    len = sizeof(question3) / sizeof(question3[0]);

    // Checks for space character in array if its there then ignores it and swap input1[i] to input1[i+1];
    for (i = 0; i < len; i++)
    {
        if (question3[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                question3[j] = question3[j + 1];
            }
            len--;
        }
    }
    encrypt_string(question3);
    fputs(question3, fp);
    fputs("\n", fp);

    fclose(fp);
    system("chmod 000 .forgot_password.txt");
    printf("\nDone!\nexiting....\n");
    sleep(1);
    exit(1);
}

void reset()
{
    system("chmod 600 .passwords_list.txt");
    FILE *list;
    list = fopen(".passwords_list.txt", "w");
    fclose(list);
    system("chmod 000 .passwords_list.txt");

    system("chmod 600 .password.txt");
    FILE *pin;
    pin = fopen(".password.txt", "w");
    fclose(pin);
    system("chmod 000 .password.txt");
}

int forgot_password(int *r)       
{
    system("clear");
    system("chmod 600 .forgot_password.txt");
    FILE *ptr;
    ptr = fopen(".forgot_password.txt", "r");

    char ans[100];
    int k = 0;

    char input1[100];
    char input2[100];
    char input3[100];

    char answer1[100];
    char answer2[100];
    char answer3[100];
    // // char answer2[50];
    // // char answer3[50];

    // printf("\nPassword Recovery Questions;\n\n");
    printf("1. What was your favorite subject in high school?\n");
    printf("-> ");
    fflush(stdin);
    scanf(" %[^\n]s", input1);
    getchar();
    int i, len = 0, j;

    // Calculating length of the array
    len = sizeof(input1) / sizeof(input1[0]);

    // Checks for space character in array if its there then ignores it and swap input1[i] to input1[i+1];
    for (i = 0; i < len; i++)
    {
        if (input1[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                input1[j] = input1[j + 1];
            }
            len--;
        }
    }

    encrypt_string(input1);
    // printf("\n%s\n", input1);

    printf("\n2. What was the name of your primary school?\n");
    printf("-> ");
    fflush(stdin);
    scanf(" %[^\n]s", input2);
    getchar();
    len = 0;

    // Calculating length of the array
    len = sizeof(input2) / sizeof(input2[0]);

    // Checks for space character in array if its there then ignores it and swap input1[i] to input1[i+1];
    for (i = 0; i < len; i++)
    {
        if (input2[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                input2[j] = input2[j + 1];
            }
            len--;
        }
    }

    encrypt_string(input2);
    // printf("\n%s\n", input2);

    printf("\n3. What is the name of the town where you were born?\n");
    printf("-> ");
    fflush(stdin);
    scanf(" %[^\n]s", input3);
    getchar();
    len = 0;

    // Calculating length of the array
    len = sizeof(input3) / sizeof(input3[0]);

    // Checks for space character in array if its there then ignores it and swap input1[i] to input1[i+1];
    for (i = 0; i < len; i++)
    {
        if (input3[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                input3[j] = input3[j + 1];
            }
            len--;
        }
    }

    encrypt_string(input3);
    // printf("\n%s\n", input3);

    while (fgets(ans, sizeof(ans), ptr))
    {
        if (k == 0)
        {
            strcpy(answer1, ans);
        }
        else if (k == 1)
        {
            strcpy(answer2, ans);
        }
        else if (k == 2)
        {
            strcpy(answer3, ans);
        }

        k++;
    }

    // printf("\n********%d*********\n", strcmp(answer1, input1));
    // printf("\n********%d*********\n", strcmp(answer2, input2));
    // printf("\n********%d*********\n", strcmp(answer3, input3));

    if (strcmp(answer1, input1) == 10 && strcmp(answer2, input2) == 10 && strcmp(answer3, input3) == 10)
    {
        *r = 1;
    }
    else
    {
        *r = 0;
    }

    fclose(ptr);
    system("chmod 000 .forgot_password.txt");
}

void reset_password()
{
    system("clear");
    // system("cd /home/$USER/Downloads/passwords");
    system("chmod 600 .password.txt");
    FILE *ptr;
    char new_pin[100];
    ptr = fopen(".password.txt", "w");
    printf("Setting Password Required !\n\n");
    printf("Enter the new password: ");
    scanf(" %[^\n]s", new_pin);
    encrypt_string(new_pin);
    fprintf(ptr, "%s", new_pin);
    printf("Setting new password...\n");
    sleep(1);
    system("echo Done!");
    printf("\n");
    system("echo exiting...");
    sleep(2);
    system("clear");
    fclose(ptr);
    system("chmod 000 .password.txt");
}
