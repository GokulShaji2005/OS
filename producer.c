#include <stdio.h>
#include <stdlib.h>
int mutex=1,full=0,x=0,s;
void producer(){
if(mutex==1&&s!=0){
mutex=0;
full++;
x++;
printf("producer produces %d\n",x);
s--;
mutex=1;
}
else{
printf("the buffer is full:");
}
}
void consumer(){
if(mutex==1 && full!=0){
mutex=0;
full--;
printf("consumer consumes %d\n",x);
x--;
s++;
mutex=1;
}
else{
printf("buffer is empty");
}
}
int main(){
int n,i;
printf("Enter the size:");
scanf("%d",&s);

printf("Enter 1 For Producer, 2 for Consumer, 3 for Exit");
printf("\n");
while(1){
printf("enter the choice");
scanf("%d",&n);
switch(n){
case 1:producer();
break;
case 2:consumer();

break;
case 3:exit(0);
}
}
}


