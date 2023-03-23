#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void main(){
    int a;
    system("cls");
    printf("<=========================>\n");
    printf("    Tugas Stack & Queue  \n");
    printf("<=========================>\n");
    printf(" \n1. Stack String");
    printf(" \n2. Queue Interger");
    printf(" \n3. Exit Program");
    printf("\n<=========================>");
    printf("\nMasukan Pilihan :");
    scanf("%d",&a);
    switch(a) {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            keluar();
            break;
        default:
            system("cls");
            printf(" Tidak ada dalam pilihan \n");
            printf(" Tekan ENTER...");
            getch();
            fflush(stdin);
            main();
    }
}
void menu1(){
        inisialisasi();
        int choice;
        do{system("cls");
            printf("1.Push Stack\n");
            printf("2.Pop Stack\n");
            printf("3.Print Stack\n");
            printf("4.Clear Stack\n");
            printf("5.Return Main Menu\n");
            printf("Input pilihan:");
            scanf("%d",&choice);
            switch(choice)
                {
                case 1:
                    system("cls");
                    push();
                    break;
                case 2:
                    system("cls");
                    pop();
                    break;
                case 3:
                    system("cls");
                    printData();
                    break;
                case 4:
                    system("cls");
                    if(isEmpty())
                    {
                        printf("Data masih kosong!,tidak bisa reset\n");
                    }
                    else{
                          inisialisasi();
                    printf("Data telah di reset!\n");
                    }system("pause");
                    break;
                case 5:
                    main();
                    break;
                default:
                    system("cls");
                    printf("tidak ada dalam pilihan\n");
                    printf("Tekan ENTER...");
                    getch();
                    menu1();
                    break;
                }
        }while(choice >0 && choice < 6);
  return 0;
}
struct Tumpukan{
            char data[5][50];
            int top; //untuk menentukan data paling atas

        }tumpuk;
        //buat fungsi apakah tumpukan masih kosong
        int isEmpty()
        {
            if(tumpuk.top == -1)
            {
                return 1;
            }else{
                return 0;
            }
        }

        //buat fungsi apakah tumpukan sudah penuh
        int isFull()
        {
            if(tumpuk.top == MAX-1)
            {
                return 1;
            }
            else{
                return 0;
            }
        }

        void inisialisasi()
        {
            //decalare bahwa tumpukan masih kosong
            tumpuk.top = -1;
        }

void push(){
    system("cls");
    char temp[30];
    if(isFull() != 1){
        tumpuk.top++;
        printf("Masukkan data:");
        scanf("%s",&temp);
        strcpy(tumpuk.data[tumpuk.top],temp);
        printf("Data %s berhasil di input\n",tumpuk.data[tumpuk.top]);
        system("cls");
    }else{
            printf("Data sudah penuh");
            getch();
    }
}
void pop(){
    if(isEmpty() != 1)
    {
        printf("Data %s telah dibuang\n",tumpuk.data[tumpuk.top]);
        tumpuk.top--;
    }else{

        printf("Data masih kosong\n");
    }system("pause");
}

void printData(){
    system("cls");
        if(isEmpty() !=1)
    {
        for(int i=tumpuk.top;i>=0;i--)
    {
        printf("%s\n",tumpuk.data[i]);
    }
    }else{
        printf("Data masih kosong\n");
    }system("pause");
}
void menu2(){
        int dt;
        inisialisasi();
     int choice;
        do{system("cls");
            printf("1.Enqueue\n");
            printf("2.Dequeue\n");
            printf("3.Print Queue\n");
            printf("4.Clear Queue\n");
            printf("5.Return Main Menu\n");
            printf("Masukan pilihan :");
            scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    system("cls");
                    if(isFull() !=1)
                    {
                        printf("Masukkan data:");
                        scanf("%d",&dt);
                        enqueue(dt);
                    }else{
                        printf("data sudah penuh!\n");
                    }system("pause");
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                   print();
                    printf("\n");
                    break;
                case 4:
                   clear();
                    break;
                case 5:
                    main();
                    break;
                default:
                    printf("tidak ada dalam pilihan\n");
                    printf("Tekan ENTER...");
                    getch();
                    menu2();
                    break;
                }
        }while(choice>0 && choice <6);
        return 0;
    }
struct Antrian{
        int head;
        int tail;
        int data[MAX];
    }antrian;
    int isempty()
    {
    if(antrian.tail == -1)
    {
        return 1;
    }else{
        return 0;
    }
}
    int isfull()
    {
        if(antrian.tail == MAX -1)
        {
            return 1;
        }else{
            return 0;
        }
    }
void inisial(){
    antrian.head=antrian.tail = -1;
}

void enqueue(int data){
    system("cls");
    if(isempty()==1)
    {
        antrian.head=antrian.tail = 0;
        antrian.data[antrian.tail] = data;
        printf("Data %d berhasil diinput!\n",antrian.data[antrian.tail]);
    }
    else{
        if(isfull() == 0)
    {
        antrian.tail++;
        antrian.data[antrian.tail] = data;
        printf("data %d berhasil di input\n",antrian.data[antrian.tail]);
    }
    }
}
int dequeue(){
        system("cls");
        if(isempty() == 1)
        {
            printf("Data masih kosong!\n");
        }
        else{
            int i;
            int e = antrian.data[antrian.head];
            printf("data %d telah dikeluarkan dari antiran\n",antrian.data[antrian.head]);
            for(i=antrian.head;i<=antrian.tail-1;i++)
            {
                antrian.data[i] = antrian.data[i+1];
            }
            antrian.tail--;
                 return e;
        }system("pause");
    }
void clear(){
    system("cls");
        antrian.head = antrian.tail = -1;
        printf("Data telah di reset!\n");
    system("pause");
    }
void print(){
    system("cls");
        if(isempty() == 0)
        {
            for(int i=antrian.head+1;i<=antrian.tail;i++)
            {
                printf("%d %d\n",i-1,antrian.data[i]);

            }
        }else{
            printf("Data masih kosongg!\n");
        }system("pause");
}
void keluar(){
    system("cls");
    printf(" <=====================================>\n");
    printf("  =       Semoga Hari mu NT terus     =\n");
    printf(" <=====================================>\n\n");
    printf(" Tekan ENTER...");
    getch();
    system("exit");
}










