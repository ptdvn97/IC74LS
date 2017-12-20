#include <IC74LS.h>

#define IN_1 PIN_B0
#define IN_2 PIN_B1
#define IN_3 PIN_B2
#define IN_4 PIN_B3

#define col_1  PIN_B4
#define col_2  PIN_B5
#define col_3  PIN_B6
#define col_4  PIN_B7

int8 i;
void Quetcot(char number)
{
   switch(number)
   {
      case 0:
      {
         output_bit(col_1,1);
         output_bit(col_2,1);
         output_bit(col_3,1);
         output_bit(col_4,1);
         break;
      }
      case 1:
      {
         output_bit(col_1,0);
         output_bit(col_2,1);
         output_bit(col_3,1);
         output_bit(col_4,1);
         break;
      }
      case 2:
      {
         output_bit(col_1,1);
         output_bit(col_2,0);
         output_bit(col_3,1);
         output_bit(col_4,1);
         break;
      }
      case 3:
      {
         output_bit(col_1,1);
         output_bit(col_2,1);
         output_bit(col_3,0);
         output_bit(col_4,1);
         break;
      }
      case 4:
      {
         output_bit(col_1,1);
         output_bit(col_2,1);
         output_bit(col_3,1);
         output_bit(col_4,0);
         break;
      }
   }
}


void NhapData(char Dulieu)
{
   switch(Dulieu)
   {
      case 0:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,0);
         output_bit(IN_2,0);
         output_bit(IN_1,0);
         break;
      }
      case 1:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,0);
         output_bit(IN_2,0);
         output_bit(IN_1,1);
         break;
      }
      case 2:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,0);
         output_bit(IN_2,1);
         output_bit(IN_1,0);
         break;
      }
      case 3:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,0);
         output_bit(IN_2,1);
         output_bit(IN_1,1);
         break;
      }
      case 4:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,2);
         output_bit(IN_2,0);
         output_bit(IN_1,0);
         break;
      }
      case 5:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,1);
         output_bit(IN_2,0);
         output_bit(IN_1,1);
         break;
      }
      case 6:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,1);
         output_bit(IN_2,1);
         output_bit(IN_1,0);
         break;
      }
      case 7:
      {
         output_bit(IN_4,0);
         output_bit(IN_3,1);
         output_bit(IN_2,1);
         output_bit(IN_1,1);
         break;
      }
      case 8:
      {
         output_bit(IN_4,1);
         output_bit(IN_3,0);
         output_bit(IN_2,0);
         output_bit(IN_1,0);
         break;
      }
      case 9:
      {
         output_bit(IN_4,1);
         output_bit(IN_3,0);
         output_bit(IN_2,0);
         output_bit(IN_1,1);
         break;
      }
   }
}

void Tachso(int8 So, char Data[])
{
   Data[3] = So%10;
   So = So/10;
   
   Data[2] = So%10;
   So = So/10;
   
   Data[1] = So%10;
   So = So/10;
   
   Data[0] = So%10;
}

void Quetled(char Data[])
{
char i;
   for(i=0;i<4;i++)
   {
      NhapData(Data[i]);
      Quetcot(i+1);
      delay_ms(2);
      Quetcot(0);
   }
}

void Hienthi(char Data[],int time)
{
   while(time>1)
   {
      time=time-1;
      delay_ms(10);
      Quetled(Data);
   }
}
void main()
{
int i;
char Data[4]={1,2,3,4};
   while(TRUE)
   {
         for(i=0;i<10000;i++)
         {
            Tachso(i,Data);
            Hienthi(Data,10);
         }
   }

}
