/*----------------------------------------------------
�ۑ�Pa�@IEEE754�ϊ��v���O�����̉���

2014/05/19
4I31�@�����J�l
----------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

/*		16�i����2�i���ɕϊ�����֐�(henkan)
				�߂�l�Ȃ��̈���p					*/
void henkan(unsigned int x)
{
	int k = 0;					//�]�������
	int h[32];					//IEEE754��32�r�b�g

	printf(" 2�i�� : ");

	/*  �v�Z  */
	for (int i = 0; i < 32; i++)
	{

		if (k==0)				//�]�肪0
		{
			h[i]=0;				//�z���0�i�[
		}
		else					//�]�肪1(�����ɂ͗]��0�ȊO)
		{
			h[i] = 1;			//�z���1�i�[
		}
		x = x / 2;				//2�Ŋ�����������
		k = x % 2;				//2�Ŋ������]�����
	}

	/*  �\��  */
	for (int j = 0; j < 32; j++)
	{
		printf("%d",h[31-j]);	//�i�[�������Ƌt�����ŕ\��
		if ((j % 4) - 3 == 0){	//���₷���悤��4�r�b�g���Ƃɋ󔒕\��
			printf(" ");		//���p��
		}
	}
}

//��������main�֐�
int main (void) {
    float	a=5.0F;				//F:�L��7��
	unsigned int	*p;
	unsigned int x;				//p�̃|�C���^����Ȃ����
	
	printf("IEEE754�ϊ��v���O����\n\n");

	printf("����������\n");
	scanf_s("%f",&a);
	printf("(float)a�̃T�C�Y : %li[byte]\n",sizeof(float));
	printf("( int )p�̃T�C�Y : %li[byte]\n",sizeof(unsigned int));
	p = (unsigned int *)&a;
	printf("10�i�� : %13.10e\n",a);	//10�i����1.***(13�P�^)�~10^**(10�P�^)
	printf("16�i�� : %X\n", *p);	//16�i��

	x = (unsigned int)*p;			//�|�C���^�����������畁�ʂ̂ɂ����D
	/*����t���������Ƃ��ł�*/
	henkan(x);						//������*p�̒l
	getch();						//�����Ɏ��s���ʂ������Ȃ��悤�ɂ�������
	return 0;
}