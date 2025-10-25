
// Automatic Software Clock And Calendar (A.S.C.A.C.) version 1.0.0

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int akt = 1,tim;
int sec,min,hr,md,mon,yr,wd;
int seca;
char n_wd[2];

void wdy()
{
	if (wd == 0)
	{
		n_wd[0] = 'S';
		n_wd[1] = 'U';
	}
	else if (wd == 1)
	{
		n_wd[0] = 'M';
		n_wd[1] = 'O';
	}
	else if (wd == 2)
	{
		n_wd[0] = 'T';
		n_wd[1] = 'U';
	}
	else if (wd == 3)
	{
		n_wd[0] = 'W';
		n_wd[1] = 'E';
	}
	else if (wd == 4)
	{
		n_wd[0] = 'T';
		n_wd[1] = 'H';
	}
	else if (wd == 5)
	{
		n_wd[0] = 'F';
		n_wd[1] = 'R';
	}
	else if (wd == 6)
	{
		n_wd[0] = 'S';
		n_wd[1] = 'A';
	}
	else
	{
		n_wd[0] = 'E';
		n_wd[1] = '!';
	}
}

void test_td()
{
	if (seca == sec) sec = sec;
	else
	{
		system("cls");
		printf("\n\nT: %d:%d:%d",hr,min,sec);
		printf("\nD: %d.%d.%d",md,mon,yr);
		printf("\nWD: %s",n_wd);
		seca = sec;
	}
}

void ex_td()
{
	time_t tim = time(NULL);
	struct tm *now = localtime(&tim);
	sec = now->tm_sec;
	min = now->tm_min;
	hr = now->tm_hour;
	md = now->tm_mday;
	mon = now->tm_mon + 1;
	yr = now->tm_year;
	wd = now->tm_wday;
	yr += 1900;
}

int main()
{
	printf("\n A.S.C.A.C. - Automatic Software Clock And Calendar");
	printf("\n version 1.0.0");
	printf("\n PUBLIC DOMAIN SOFTWARE");
	ex_td();
	wdy();
	seca = sec;
	do
	{
		ex_td();
		wdy();
		test_td();
	}
	while (akt != 0);
	return 0;
}