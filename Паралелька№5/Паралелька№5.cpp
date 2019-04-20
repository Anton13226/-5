// Proga№1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "pthread.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>
#include "semaphore.h"
using namespace std;


sem_t S0, S1, S2, S3, S4;

void *f(void *arg);





int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "rus");

	sem_init(&S0, 0, 1);
	sem_init(&S1, 0, 1);
	sem_init(&S2, 0, 1);
	sem_init(&S3, 0, 1);
	sem_init(&S4, 0, 1);

		pthread_t *p;
		p = new pthread_t[5];
		int *arg = new int[5];

		for (int i = 0; i < 5; i++)
		{
			arg[i] = i;
			pthread_create(&p[i], NULL, f, (void*)&arg[i]);
		}

		for (int i = 0; i < 5; i++)
		{
			pthread_join(p[i], NULL);
		}



	getchar();
	getchar();
	return 0;
}


///////////////////////////////////////////////////////////////



void *f(void *arg)
{

	int n = *(int*)arg;
	switch (n)
	{
	case 0:
	{
		if (n == 0)
		{
			sem_wait(&S0);
			sem_wait(&S1);
			cout << n + 1 << ": Филосов поел!!! " << endl;
			sem_post(&S0);
			sem_post(&S1);
		}
		else
			cout << n + 1 << ": Филосов не поел:( " << endl;
	}
	case 1:
	{
		if (n == 1)
		{
			sem_wait(&S1);
			sem_wait(&S2);
			cout << n + 1 << ": Филосов поел!!! " << endl;
			sem_post(&S1);
			sem_post(&S2);
		}
		else
			cout << n + 1 << ": Филосов не поел:( " << endl;
	}
	case 2:
	{
		if (n == 2)
		{
			sem_wait(&S2);
			sem_wait(&S3);
			cout << n + 1 << ": Филосов поел!!! " << endl;
			sem_post(&S2);
			sem_post(&S3);
		}
		else
			cout << n + 1 << ": Филосов не поел:( " << endl;
	}
	case 3:
	{
		if (n == 3)
		{
			sem_wait(&S3);
			sem_wait(&S4);
			cout << n + 1 << ": Филосов поел!!! " << endl;
			sem_post(&S3);
			sem_post(&S4);
		}
		else
			cout << n + 1 << ": Филосов не поел:( " << endl;
	}
	case 4:
	{
		if (n == 4)
		{
			sem_wait(&S4);
			sem_wait(&S0);
			cout << n + 1 << ": Филосов поел!!! " << endl;
			sem_post(&S4);
			sem_post(&S0);
		}
		else
			cout << n + 1 << ": Филосов не поел:( " << endl;
	}

	default:
		break;
	}

	return NULL;
}
