/*----------------------------------------------------
課題１a　IEEE754変換プログラムの改良

2014/05/19
4I31　福嶋開人
----------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

/*		16進数を2進数に変換する関数(henkan)
				戻り値なしの引数p					*/
void henkan(unsigned int x)
{
	int k = 0;					//余りを入れる
	int h[32];					//IEEE754は32ビット

	printf(" 2進数 : ");

	/*  計算  */
	for (int i = 0; i < 32; i++)
	{

		if (k==0)				//余りが0
		{
			h[i]=0;				//配列に0格納
		}
		else					//余りが1(厳密には余り0以外)
		{
			h[i] = 1;			//配列に1格納
		}
		x = x / 2;				//2で割った商を代入
		k = x % 2;				//2で割った余りを代入
	}

	/*  表示  */
	for (int j = 0; j < 32; j++)
	{
		printf("%d",h[31-j]);	//格納した順と逆向きで表示
		if ((j % 4) - 3 == 0){	//見やすいように4ビットごとに空白表示
			printf(" ");		//半角空白
		}
	}
}

//ここからmain関数
int main (void) {
    float	a=5.0F;				//F:有効7桁
	unsigned int	*p;
	unsigned int x;				//pのポインタじゃないやつ
	
	printf("IEEE754変換プログラム\n\n");

	printf("数字を入れて\n");
	scanf_s("%f",&a);
	printf("(float)aのサイズ : %li[byte]\n",sizeof(float));
	printf("( int )pのサイズ : %li[byte]\n",sizeof(unsigned int));
	p = (unsigned int *)&a;
	printf("10進数 : %13.10e\n",a);	//10進数で1.***(13ケタ)×10^**(10ケタ)
	printf("16進数 : %X\n", *p);	//16進数

	x = (unsigned int)*p;			//ポインタが嫌いだから普通のにした．
	/*今回付け足したとこです*/
	henkan(x);						//引数は*pの値
	getch();						//すぐに実行結果が消えないようにしただけ
	return 0;
}