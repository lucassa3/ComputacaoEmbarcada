#include <stdio.h>

void main() {

	char str1[20], str2[20], str3[20];
	float pre1, pre2, pre3;
	float qtd1, qtd2, qtd3, total1, tota2, total3;


   printf("Entre produto 1:");
   scanf("%s", str1);

   printf("Entre preço 1:");
   scanf("%d", pre1);

   printf("Entre quantidade 1:")
   scanf("%d", qtd1);

   printf("Entre produto 2:");
   scanf("%s", str2);

   printf("Entre preço 2:");
   scanf("%d", pre2);

   printf("Entre quantidade 1:")
   scanf("%d", qtd2);

   printf("Entre produto 3:");
   scanf("%s", str3);

   printf("Entre preço 3:");
   scanf("%d", pre3);
   printf("Entre quantidade 3:");
   scanf("%d", qtd3);

   total1 = pre1*qtd1;
   total2 = pre2*qtd2;
   total3 = pre3*qtd3;

   printf("--NOME--|--PRECO--|--QTD--|--TOTAL--\n");
   printf("--%s--|--%d--|--%d----|--%d--\n", str1[20], pre1, qtd1, total1);
   printf("--%s--|--%d--|--%d--|--%d--\n", str2[20], pre2, qtd2, total2);
   printf("--%s--|--%d--|--%d--|--%d--\n", str3[20], pre3, qtd3, total3);

}