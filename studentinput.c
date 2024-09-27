#include <stdio.h>
#include <string.h>
struct info {
    char name[50];
    char auther[50];
    int years;
    float price;
};
void find(struct info *bk, int a,char searchName[]){
    for (int i = 0 ; i < a ; i ++ ){
        if(strcmp(bk[i].name,searchName)==0){
            printf("Find :D");
        }
        else{
            printf("valid");
        }
    }
}
void cheap(struct info *bk, int a){
    for (int i = 0 ; i < a ; i++){
        for (int j = i + 1 ; j < a ; j ++){
            if (bk[i].price > bk[j].price){
                struct info temp = bk[i];
                bk[i] = bk[j];
                bk[j] = temp;
                printf("%s is cheapest",bk[i]);
            }
        }
    }
}
void display(struct info *bk, int a){
    for (int i = 0 ; i < a ; i++){
        printf("%s\n",bk[i].name);
        printf("%s\n",bk[i].auther);
        printf("%d\n",bk[i].years);
        printf("%0.2f\n",bk[i].price);
    }
}
int main(){
    int a;
    printf("จำนวน:"); scanf("%d",&a);
    struct info book1[a];
    struct info *bk = book1;
    for (int i = 0 ; i < a ; i++){
        getchar();
        printf("Name-Book:");
        fgets(bk[i].name,sizeof(bk[i].name),stdin);
        bk[i].name[strcspn(bk[i].name, "\n")] = 0;
        printf("Name-auther:");
        fgets(bk[i].auther,sizeof(bk[i].auther),stdin);
        bk[i].auther[strcspn(bk[i].auther, "\n")] = 0;
        printf("Enter years:"); 
        scanf("%d",&bk[i].years);
        printf("Enter price:"); 
        scanf("%f",&bk[i].price);
    }
    getchar();
    char searchName[50];
    printf("กรุณาใส่ชื่อหนังสือที่ต้องการค้นหา: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    display(bk,a);
    cheap(bk,a);
    find(bk,a,searchName);
}
