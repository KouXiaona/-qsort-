#include<stdio.h>
#include<Windows.h>

int compint(const void*xp, const void *yp)
{
	int *xp_ = (int*)xp;
	int *yp_ = (int*)yp;
	if (*xp_ > *yp_)
	{
		return 1;
	}
	else if (*xp_ < *yp_)
	{
		return -1;
	}
	else 
	{ 
		return 0; 
	}
}

void swap(char *xp, char *yp, int num)
{
	while (num--)
	{
		char tmp = *xp;
		*xp = *yp;
		*yp = tmp;
		xp++; yp++;
	}
}


void my_qsort(void* base, size_t num, size_t size, int(*compar)(const void*, const void*))
{
	size_t i = 0;
	int quit = 0;
	char* _base = (char*)base;
	for (; i < num - 1; i++)
	{
		size_t j = 0;
		for (; j < num - 1 - i; j++)
		{
			if (compar(_base+j*size,_base+(j+1)*size)>0)
			{
				swap(_base + j*size, _base + (j + 1)*size,size);
				quit = 1;
			}
		}
		if (quit == 0)
		{
			break;
		}
	}
}


int main()//Ä£Äâqsortº¯Êý
{
	int a[] = { 44,245,7,87,43,4367,-21,-6,767 };
	int num = sizeof(a) / sizeof(a[0]);
	my_qsort(a, num, sizeof(int), compint);

	system("pause");
	return 0;
}