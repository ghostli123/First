// tttttt.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std; 

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*ƻ���г����췽��һ
	int number;
	cout<<"����ƻ���г��ĸ���"<<endl;
	cin>>number;
	int* B=new int[number+1];
	int* S=new int[number+1];
	for(int i=0;i<number;i++)
	{
		cout<<"���뵱ǰ���е�ƻ�������۸�"<<endl;
		cin>>B[i];
		cin>>S[i];
	}
	B[number]=0;
	S[number]=0;
	*/

	//ƻ���г����췽����
	int number=10;
	int B[]={7,2,3,4,3,6,3,1,4,3,0};
	int S[]={4,5,6,2,4,7,4,2,3,9,0};
	
	//��ʼ���������
	int Bmin=B[0];//һ���׶��ڵ���С�����
	int Smax=S[0];//һ���׶��ڵ����������
	int* BuyIndex=new int[number];//���ڼ�¼һ���׶��ڵ���С�����
	int* SaleIndex=new int[number];//���ڼ�¼һ���׶��ڵ���������
	int* Balance=new int[number];//���ڼ�¼һ���׶��ڵ�ӯ��
	BuyIndex[0]=0;
	SaleIndex[0]=0;
	int iterator=0;
	int balance=0;
	int times=0;

	//�㷨�ؼ�����
	for(int i=0;i<number+1;i++)
	{
		//��ǰƻ���г������۸����һ���׶������������
		if(S[i]>Smax)
		{
			SaleIndex[iterator]=i;
			Smax=S[i];
			balance=Smax-Bmin;
		}
		//��ǰƻ���г�����۸�С��һ���׶�����С�����
		if(B[i]<Bmin)
		{
			Balance[iterator++]=balance;
			BuyIndex[iterator]=i;
			Bmin=B[i];
			SaleIndex[iterator]=i;
			Smax=S[i];
			balance=Smax-Bmin;
			times++;
		}
	}


	//����Balance��������ѡ��ǰ����Ľ׶μ�Ϊ�����ص�
	int maxTwo[2]={0,0};
	int temp;
	int record[2]={0,0};//���ڼ�¼�������׶��ܻ�ȡ�������
	int recordTemp;
	for(int i=0;i<times;i++)
	{
		//��maxTwo[0]��Balance[i]֮��Ĵ�������maxTwo[0]�С������temp��
		if(Balance[i]>maxTwo[0])
		{
			temp=maxTwo[0];
			maxTwo[0]=Balance[i];
			recordTemp=record[0];
			record[0]=i;
			maxTwo[1]=temp;
			record[1]=recordTemp;
		}
		else if(Balance[i]>maxTwo[1])
		{
			maxTwo[1]=Balance[i];
			record[1]=i;
		}
	}
	cout<<"�����ƻ���г�����۸�Ϊ��";
	for(int i=0;i<number;i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
	cout<<"�����ƻ���г������۸�Ϊ��";
	for(int i=0;i<number;i++)
	{
		cout<<S[i]<<" ";
	}
	cout<<endl;
	if(record[0]<record[1])
	{
		cout<<"�ӵ�"<<BuyIndex[record[0]]+1<<"����г���,"<<"�ӵ�"<<SaleIndex[record[0]]+1<<"����г���,�õ�����"<<Balance[record[0]]<<"��"<<endl;
		cout<<"�ٴӵ�"<<BuyIndex[record[1]]+1<<"����г���,"<<"�ӵ�"<<SaleIndex[record[1]]+1<<"����г���,�õ�����"<<Balance[record[1]]<<"��"<<endl;
		cout<<"�������ε����������Ϊ"<<Balance[record[0]]+Balance[record[1]]<<"��"<<endl;
	}
	else
	{
		cout<<"�ӵ�"<<BuyIndex[record[1]]+1<<"����г���,"<<"�ӵ�"<<SaleIndex[record[1]]+1<<"����г���,�õ�����"<<Balance[record[1]]<<"��"<<endl;
		cout<<"�ٴӵ�"<<BuyIndex[record[0]]+1<<"����г���,"<<"�ӵ�"<<SaleIndex[record[0]]+1<<"����г���,�õ�����"<<Balance[record[0]]<<"��"<<endl;
		cout<<"�������ε����������Ϊ"<<Balance[record[0]]+Balance[record[1]]<<"��"<<endl;
	}
}


