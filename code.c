#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct customer
{
    char name[101];
    char accNo[11];
    char mobileNo[12];
    double balance;
} customer;

int main()
{
    int numCustomers;
    printf("Enter the number of customers:");
    scanf("%d",&numCustomers);
    if(numCustomers>=1 && numCustomers<=100)
    {
        int i,opt,j;
        customer *customers;
        customer temp;
        customers=(struct customer*)malloc(numCustomers*sizeof(struct customer));
        for(i=0; i<=numCustomers-1; i++)
        {
            printf("Enter the information of customer : %d\n",i+1);
            printf("Name:");
            scanf("%s",(*(customers+i)).name);
            printf("AccNo:");
            scanf("%s",(customers+i)->accNo);
            printf("MobileNo:");
            scanf("%s",(customers+i)->mobileNo);
            printf("Balance:");
            scanf("%lf",&(customers+i)->balance);
        }
        while(1)
        {
            printf("\n");
            printf("Please select an option-\nChoose 1 to deposit money.\nChoose 2 to withdraw money.\nChoose 3 to sort all customers by using their balance.\n");
            printf("Choose 4 to search customers by using their mobileNo.\nChoose 5 to print all the customers.\nChoose 6 to print the sum of all customer balances.\n");
            printf("Choose 0 to exit.\nEnter you option:");
            scanf("%d",&opt);
            if(opt==0)
            {
                free(customers);
                break;
            }
            else if(opt==1)
            {
                int c=0;
                double deposite;
                char *accountNo;
                accountNo=(char*)malloc(10*sizeof(char));
                printf("Enter an account No and the amount:");
                scanf("%s %lf",accountNo,&deposite);
                for(i=0; i<10; i++)
                {
                    if(strcmp(accountNo,(customers+i)->accNo)==0)
                    {
                        c=1;
                        break;
                    }
                }
                if(c==1)
                {
                    (customers+i)->balance+=deposite;
                    printf("The updated balance is : %lf\n",(customers+i)->balance);
                }
                free(accountNo);
            }
            else if(opt==2)
            {
                int c=0;
                double withdrawal;
                char *accountNo;
                accountNo=(char*)malloc(10*sizeof(char));
                printf("Enter an account No and the amount:");
                scanf("%s %lf",accountNo,&withdrawal);
                for(i=0; i<10; i++)
                {
                    if(strcmp(accountNo,(customers+i)->accNo)==0)
                    {
                        c=1;
                        break;
                    }
                }
                if(c==1)
                {
                    (customers+i)->balance-=withdrawal;
                    printf("Your balance is now : %lf\n",(customers+i)->balance);
                }
                free(accountNo);
            }
            else if(opt==3)
            {
                for(i=0; i<numCustomers-1; i++)
                {
                    for(j=i+1; j<numCustomers; j++)
                    {
                        if((customers+i)->balance < (customers+j)->balance)
                        {
                            temp=*(customers+i);
                            *(customers+i)=*(customers+j);
                            *(customers+j)=temp;
                        }
                        else if(((customers+i)->balance==(customers+j)->balance) && (strcmp((customers+i)->accNo,(customers+j)->accNo) >0) )
                        {
                            temp=*(customers+i);
                            *(customers+i)=*(customers+j);
                            *(customers+j)=temp;
                        }
                    }
                }

            }
            else if(opt==4)
            {
                int c=0;
                char *mobino;
                mobino=(char*)malloc(12*sizeof(char));
                printf("Enter a mobile No:");
                scanf("%s",mobino);
                for(i=0; i<10; i++)
                {
                    if(strcmp(mobino,(customers+i)->mobileNo)==0)
                    {
                        c=1;
                        break;
                    }
                }
                if(c==1)
                {
                    printf("Name: <%s>, Account No: <%s>, Mobile No: <%s>, Balance: <%lf>\n",(*(customers+i)).name,(*(customers+i)).accNo,(*(customers+i)).mobileNo,(*(customers+i)).balance);
                }
                else
                {
                    printf("Customer Not Found\n");
                }
                free(mobino);
            }
            else if(opt==5)
            {
                for(i=0; i<numCustomers; i++)
                {
                    printf("Name: <%s>, Account No: <%s>, Mobile No: <%s>, Balance: <%lf>\n",(*(customers+i)).name,(*(customers+i)).accNo,(*(customers+i)).mobileNo,(*(customers+i)).balance);
                }
            }
            else if(opt==6)
            {
                double sum=0;
                for(i=0; i<numCustomers; i++)
                {
                    sum+=(*(customers+i)).balance;
                }
                printf("Total balance of all customers: %lf\n",sum);
            }
        }
    }
    else
    {
        printf("Invalid number of customers!");
        return 0;
    }
}
