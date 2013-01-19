// tttttt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std; 

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*苹果市场构造方法一
	int number;
	cout<<"输入苹果市场的个数"<<endl;
	cin>>number;
	int* B=new int[number+1];
	int* S=new int[number+1];
	for(int i=0;i<number;i++)
	{
		cout<<"输入当前城市的苹果买卖价格"<<endl;
		cin>>B[i];
		cin>>S[i];
	}
	B[number]=0;
	S[number]=0;
	*/

	//苹果市场构造方法二
	int number=10;
	int B[]={7,2,3,4,3,6,3,1,4,3,0};
	int S[]={4,5,6,2,4,7,4,2,3,9,0};
	
	//初始化程序变量
	int Bmin=B[0];//一个阶段内的最小买入价
	int Smax=S[0];//一个阶段内的最大卖出价
	int* BuyIndex=new int[number];//用于记录一个阶段内的最小买入价
	int* SaleIndex=new int[number];//用于记录一个阶段内的最大买出价
	int* Balance=new int[number];//用于记录一个阶段内的盈利
	BuyIndex[0]=0;
	SaleIndex[0]=0;
	int iterator=0;
	int balance=0;
	int times=0;

	//算法关键部分
	for(int i=0;i<number+1;i++)
	{
		//当前苹果市场卖出价格大于一个阶段内最大卖出价
		if(S[i]>Smax)
		{
			SaleIndex[iterator]=i;
			Smax=S[i];
			balance=Smax-Bmin;
		}
		//当前苹果市场买入价格小于一个阶段内最小买入价
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


	//最后从Balance数组里面选出前两大的阶段即为买卖地点
	int maxTwo[2]={0,0};
	int temp;
	int record[2]={0,0};//用于记录哪两个阶段能获取最大利润
	int recordTemp;
	for(int i=0;i<times;i++)
	{
		//将maxTwo[0]与Balance[i]之间的大数放在maxTwo[0]里，小数放在temp里
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
	cout<<"输入的苹果市场买入价格为：";
	for(int i=0;i<number;i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
	cout<<"输入的苹果市场卖出价格为：";
	for(int i=0;i<number;i++)
	{
		cout<<S[i]<<" ";
	}
	cout<<endl;
	if(record[0]<record[1])
	{
		cout<<"从第"<<BuyIndex[record[0]]+1<<"这个市场买,"<<"从第"<<SaleIndex[record[0]]+1<<"这个市场卖,得到利润"<<Balance[record[0]]<<"。"<<endl;
		cout<<"再从第"<<BuyIndex[record[1]]+1<<"这个市场买,"<<"从第"<<SaleIndex[record[1]]+1<<"这个市场卖,得到利润"<<Balance[record[1]]<<"。"<<endl;
		cout<<"买卖两次的最大总利润为"<<Balance[record[0]]+Balance[record[1]]<<"。"<<endl;
	}
	else
	{
		cout<<"从第"<<BuyIndex[record[1]]+1<<"这个市场买,"<<"从第"<<SaleIndex[record[1]]+1<<"这个市场卖,得到利润"<<Balance[record[1]]<<"。"<<endl;
		cout<<"再从第"<<BuyIndex[record[0]]+1<<"这个市场买,"<<"从第"<<SaleIndex[record[0]]+1<<"这个市场卖,得到利润"<<Balance[record[0]]<<"。"<<endl;
		cout<<"买卖两次的最大总利润为"<<Balance[record[0]]+Balance[record[1]]<<"。"<<endl;
	}
}


