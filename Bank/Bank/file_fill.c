#include <stdio.h>
#define cust_record 10
#define min_balance 100
/*
int main(void)
{
    typedef struct customer
                {
                    int accno ;
                    char name[30] ;
                    float balance ;
                } customer1;
    typedef struct trans
                {
                    int accno ;
                    char trans_type ;
                    float amount ;
                } trans1;

    customer1 cust;
    trans1 trans;
    FILE * Pcust;
    FILE * Ptrans;

    int recsize;
    char another;
    int count = 0;
    recsize = sizeof(cust);

    Pcust = fopen("CUSTOMER1.DAT", "r+");
    if(Pcust == NULL)
    {
        puts("no CUSTOMER file");
        exit(0);
    }
    Ptrans = fopen("TRANSACTION.DAT", "r+");
    if(Ptrans == NULL)
    {
        puts("no transaction file");
        exit(0);
    }
    //stat= ;
    //scanf(Ptrans,"%d %c %f",&trans.accno,&trans.trans_type,&trans.amount) != NULL

    while (count < 10)//another != 'n' && another != 'N')
    {
        puts("enter account #, Name , balance\n");
        scanf("%d %s %f",&cust.accno,cust.name,&cust.balance);
        fprintf(Pcust,"   %d %s %8.2f     \n",cust.accno,cust.name,cust.balance);

        //fscanf(Pcust,"%d %s %f",&cust.accno,cust.name,&cust.balance);
        fprintf(Ptrans,"   %d %c %8.2f     \n",cust.accno,'D',((cust.balance)/(count+1)));
        //fwrite(&cust,recsize,1,Pcust);
       //* fflush(stdin);
        //puts("you need another record\n");
        //another= getche();
        count++;
        printf("%d\n", count);
    }
    fclose(Pcust);
    fclose(Ptrans);

    return(1);

}
*/
