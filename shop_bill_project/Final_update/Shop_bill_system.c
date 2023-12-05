#include<stdio.h>    // libraries.
#include<windows.h>  // using file handling
#include <string.h>
#include <time.h>    // time libraries
#include <stdlib.h>


struct purchase_list {    // data struct, save data in the "purchase_data.txt" file.
    int bill_no;
    char itemName[10];
    int quantity;
    int price;
    int amount;
    int total;
};

void main_menu();        //functions
void viewPurList();
void item_list();
void save_bills();
void print_bill_list();

int op;                 // global variable..
int bill_check = 0;
int bill_no;

 //   global variable arrays -- (10-item_name array) ,(10-item_pries array).
char item_names[10][100] = {"1.Books", "2.pens", "3.pencils", "4.Bottle", "5.Ruler", "6.Eraser", "7.cutter",
                            "8.Glue", "9.A4 Sheet", "10.File"};
int item_pries[10] = {100, 20, 10, 150, 20, 15, 25, 50, 5, 20};

int main() {

    main_menu();        // call main_menu function.
    return 0;
}

void main_menu() {     // main menu function..

    int ch;           // local variables.
    system("cls");    // clear cmd...
    printf("\n\t     ==========  Main Menu  =========\n ");
    printf("\n\t\t   [1.]__ Creat A Bill __");
    printf("\n\t\t   [2.]__ View Bills ____");
    printf("\n\t\t   [3.]__ Exit __________");
    printf("\n\n\t    ================================= \n");
    printf("\t\t Input your Choice:-");
    scanf("%d", &ch);                                       //  save user input in the variable.
    printf("\t    =================================\n\n");

    // select user input , using switch cse.

    switch (ch) {       // buy items and creat a new bill
        case 1:
            item_list();
            print_bill_list();
            break;

        case 2:
            viewPurList();
            break;

        case 3:            // Exit the program and print, thank you.
            printf("\t\t ..!! Thank You !!..");
            printf("\n\t    =================================");
            break;

        default:           // user input no valid input
            printf("\n\n\t\t..!! Invalid Input !!..");
            printf("\n\t\t..!! Try Again !!......");
            printf("\n\t    =================================");
            break;
    }
}

void save_bills() {

    int check;             // local variable
    FILE *pur_item;        // pointer variable
    struct purchase_list p_list;                 // data struct creat in line number 6-13
    pur_item = fopen("purchase_data.txt", "a");  // purchase_data.txt file open in the "pur_item" pointer variable.

    if (pur_item == NULL) {                      // file is "NULL or empty" print "could n,t open"..
        printf("Couldn't open\n");
        exit(0);
    } else {
        printf("Input quantity    :- ");
        scanf("%d", &p_list.quantity);       // input quantity and save data in the data struct.
        if (bill_check != 1) {
            printf("Enter Bill Number :- ");
            scanf("%d", &bill_no);           // input bill number,and save it.
        }
        p_list.bill_no = bill_no;                            // declare bill number in to the "p_list.bill_no"
        strncpy(p_list.itemName, item_names[op - 1], 10);
        p_list.price = item_pries[op - 1];                    //declare p_list.pries in the "item_pries" array.
        p_list.amount = p_list.price * p_list.quantity;      // calculate amount (pries * quantity).
        p_list.total = p_list.amount;                        // calculate total amount
        fwrite(&p_list, sizeof(p_list), 1, pur_item);
        printf("...save successfully...\n\n");               // save bill and print "save successfully"
        printf("---------------------------------\n");
        printf("Do you want to buy other Items-\n");         // give another chance to buy other items.
        printf("\t..yes..[ Enter-(1) ]\n");
        printf("\t..N0...[ Enter-(0) ]\n");
        scanf("%d", &check);
        printf("\n\n\n\t\t--------------------------------------\n");

        if (check == 1) {
            bill_check = 1;
            item_list();        //  call aging item_ list function ..
        } else {
            bill_check = 0;
        }
    }
    fclose(pur_item);           // close file and close pointer variable.
}

void item_list() {

    system("cls");
    printf("\t__ Items List __\n");
    printf("---------------------------------\n");
    for (int x = 0; x <= 9; x++) {                       // print items list and print pries list.
        printf("%-10s", item_names[x]);                  // "%-10s" left allin prise list.
        printf("\t\t%.2f\n", (float) item_pries[x]);
    }
    printf("---------------------------------\n");
    printf("Input your Choice :- ");
    scanf("%d", &op);       // save  input number.

    switch (op) {          // select  the item using switch.
        case 1:
            save_bills();  // call save_bills function..
            break;
        case 2:
            save_bills();
            break;
        case 3:
            save_bills();
            break;
        case 4:
            save_bills();
            break;
        case 5:
            save_bills();
            break;
        case 6:
            save_bills();
            break;
        case 7:
            save_bills();
            break;
        case 8:
            save_bills();
            break;
        case 9:
            save_bills();
            break;
        case 10:
            save_bills();
            break;
        default:        // user input is not valid..
            printf("\t     !! Invalid Input !! \n");
            break;
    }
}

void print_bill_list() {
    FILE *file;                             // creat pointer variable..
    struct purchase_list p_list;            // data struct
    int total_amount = 0;                   // local variables.
    file = fopen("purchase_data.txt", "r"); // open file reading mode (purchase_data.txt)

    time_t tm;
    time(&tm);
    system("cls");
    printf("\t--BOOK__SHOP--\n");
    printf("--------------------------\n");
    printf("Bill N0:- %d\n", bill_no);       // print bill number
    printf("--------------------------\n");
    printf("%s", ctime(&tm));                // print date and  time.
    printf("--------------------------\n");

    while (fread(&p_list, sizeof(p_list), 1, file)) {    // file read in the while loop

        if (p_list.bill_no == bill_no) {                                   // find same bill number in file
            printf("\nItem_Names   :- %-15s\t", p_list.itemName);          // print buy items
            printf("\nQuantity     :- %-15d\t", p_list.quantity);          // print quantity
            printf("\nAmount       :- Rs %-15.2f\t",(float) p_list.amount);// print amount
            total_amount = total_amount + p_list.total;                    //  calculate total amount
        }
    }
    printf("\nTotal_Amount :- Rs %-15.2f", (float) total_amount);     // print total amount
    printf("\n\n--------------------------");
    fclose(file);                                                     // close file
    int x;
    printf("\n\n\n\t\t--------------------------------------\n");
    printf("\t\t  Do You Want To Got To Main Menu\n\n");
    printf("\t\t\t..yes...[1]\n\n");
    printf("\t\t\t..Exit..[0]\n");
    scanf("%d",&x);
    printf("\n\n\n\t\t--------------------------------------\n");
    if(x==1){
        main_menu();
    }
    else{
        system("cls");
        printf("\n\t\t  ..!! Thank You !!..");
        printf("\n\t=====================================");
    }
}

void viewPurList() {    // view all Bills

    FILE *file;
    struct purchase_list p_list;
    file = fopen("purchase_data.txt", "r");
    system("cls");                            // clear cmd..
    printf("|\tItems\t|\tQty\t|\tTotal|\n");
    while (fread(&p_list, sizeof(p_list), 1, file)) {
        printf("%-20s\t%-d\t\t%-5d\t\n",p_list.itemName,p_list.quantity,p_list.amount);
    }
    int x;
    printf("\n\n\n\t\t--------------------------------------\n");    // Go to Main Menu..
    printf("\t\t  Do You Want To Got To Main Menu\n\n");
    printf("\t\t\t..yes...[1]\n\n");
    printf("\t\t\t..Exit..[0]\n");
    scanf("%d",&x);
    printf("\n\n\n\t\t--------------------------------------\n");
    if(x==1){
        main_menu();
    }
    else{                  // Exit..
        system("cls");
        printf("\n\t\t  ..!! Thank You !!..");
        printf("\n\t=====================================");
    }
}
