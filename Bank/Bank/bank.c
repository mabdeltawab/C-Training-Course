

#include <stdio.h>


#define cust_record 3
#define min_balance 100
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
    FILE * Ptrans,*Ptemp;
    long int s,e;

    int recsize;
    //int stat  = 0;
    int count = 0,count2=0;

    recsize = sizeof(cust);

    Pcust = fopen("CUSTOMER.DAT", "r+");
    Ptemp = fopen("aa.DAT", "w");
    if(Pcust == NULL)


    {
        puts("no c file");
        exit(0);
    }
    Ptrans = fopen("TRANSACTION.DAT", "r");
    if(Ptrans == NULL)
    {
        puts("no transaction file");
        exit(0);
    }

    //stat= ;
    while ((count<cust_record)&&((fscanf(Ptrans,"%d %c %f",&trans.accno,&trans.trans_type,&trans.amount)) != 0))
    {
            count++;
            s = 0;//ftell(Pcust);
            count2 = 0;
        while((count2<cust_record)&&((fscanf(Pcust,"%d %s %f",&cust.accno,cust.name,&cust.balance)) != 0))//
        {
            count2++;
            e=ftell(Pcust);///(Ptemp);//

            if(cust.accno == trans.accno)
            {
                switch(trans.trans_type)
                {
                    case'D':
                    {
                        cust.balance +=trans.amount;
                        if(fseek(Pcust,(s-e+count2-1), SEEK_CUR) == 0)
                        //if (fscanf(Pcust,"%d %s %f",&cust.accno,cust.name,&cust.balance) != NULL)
                        fprintf(Pcust,"%d %s  %2.0f",(cust.accno),cust.name,cust.balance);
                        //printf("%d %s %3.0f",(cust.accno),cust.name,cust.balance);
                        rewind(Pcust);
                        break;

                    }
                    case'W':
                    {
                        if ((cust.balance-trans.amount)>=100)
                            cust.balance -=trans.amount;
                        break;
                    }
                }
break;
            }
            s =e;
        }
    //stat= fscanf(Ptrans,"%d %s %f",&trans.accno,trans.name,&trans.balance);
    }
    fclose(Pcust);
    fclose(Ptrans);
    return(1);

}

