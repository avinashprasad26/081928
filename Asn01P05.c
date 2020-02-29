#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int num,X,count=0,temp,i,flag=1,nd,steps = 0,step=0;

int isprime(int number)
{
    for (i = 2; i <= sqrt(number) ; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
        steps += 1;
    }
    return 1;
}

void rotate(nd,X)
{
    int rem = nd%10;
    int quo = nd/10;
    temp = rem*pow(10,X-1)+quo;
    nd = temp;
    step++;
    return;
}

int main(int argc, char *argv[])
{
    num = atoi(argv[1]);
    nd = num;
    while(num!=0)
    {
        num/=10;
        ++count;
    }
    X = count;
    int temp1=count;
    while(temp1!=0)
    {
        rotate(nd,X);
        if(!isprime(nd))
        {
            flag = 0;
            break;
        }
        temp1--;
    }
    printf("\n The basic operation for this program is DIVISION. \n");
    printf("\n %d steps are used for checking prime number. \n",steps);
    printf("\n %d rotation take place for given digit. \n",step);
    if(flag) {
        printf("\n %d is Circular prime.\n",nd);
    } else {
        printf("\n %d not a Circular prime.\n",nd);
    }
    return 0;
}


