#include "stdafx.h"
#include "Util.h"



/*���ַ�������߽�ȡn���ַ�*/  
char * left(char *dst,char *src, int n)  
{  
	char *p = src;  
	char *q = dst;  
	int len = strlen(src);  
	if(n>len) n = len;  
	while(n--) *(q++) = *(p++);  
	*(q++)='\0'; /*�б�Ҫ�𣿺��б�Ҫ*/  
	return dst;  
}  

void wcharTochar(const wchar_t *wchar, char *chr, int length)  
{  
	WideCharToMultiByte( CP_ACP, 0, wchar, -1,  
		chr, length, NULL, NULL );  
}  

void UTF_8ToUnicode(WCHAR* pOut,char *pText)
{
	char* uchar = (char *)pOut;

	uchar[1] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);
	uchar[0] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x3F);

	return;
}

void UnicodeToUTF_8(char* pOut,WCHAR* pText)
{
	// ע�� WCHAR�ߵ��ֵ�˳��,���ֽ���ǰ�����ֽ��ں�
	char* pchar = (char *)pText;

	pOut[0] = (0xE0 | ((pchar[1] & 0xF0) >> 4));
	pOut[1] = (0x80 | ((pchar[1] & 0x0F) << 2)) + ((pchar[0] & 0xC0) >> 6);
	pOut[2] = (0x80 | (pchar[0] & 0x3F));

	return;
}

void MySplit(char *src, const char *separator, char **dest, int *num)
{
	char *pNext;
	int count = 0;

	if (src == NULL || strlen(src) == 0) return;
	if (separator == NULL || strlen(separator) == 0) return; 

	pNext = strtok(src,separator);

	while(pNext != NULL)
	{
		*dest++ = pNext;
		++count;
		pNext = strtok(NULL,separator);
	}

	*num = count;
}

int MyRand(int max)
{
	srand( (unsigned)time( NULL ) );
	int num = rand()%max+1;
	return num;
}