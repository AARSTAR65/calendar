/*calculate the day corresponding to the given day, print the calendar of corresponding month and the year*/
#include <iostream>
using namespace std;
int day(int,int,int);
void month(int,int);
int de(int);
void year(int);
int leap(int);
int main()
{
	int dd,mm,yy,i;
	cout<<"ENTER DATE AS DD/MM/YYYY \n";
	cin>>dd;
	cin>>mm;
	cin>>yy;
	char week[7][3]={{'S','u','n'},{'M','o','n'},{'T','u','e'},{'W','e','d'},{'T','h','u'},{'F','r','i'},{'S','a','t'}};
	cout<<week[day(dd,mm,yy)][0]<<week[day(dd,mm,yy)][1]<<week[day(dd,mm,yy)][2]<<"\n";
	month(mm,yy);
	year(yy);
	cout<<"Rishav Saini \n 1611981308 \n UCA-11-2";
}
int day(int dd,int mm,int yy)
{
	int C,y,f,k;
	C=yy/100;
	k=dd;
	int m[12]={11,12,1,2,3,4,5,6,7,8,9,10};
	if(mm==1||mm==2)
	{
		y=(yy%100)-1;
	}
	else
	{
		y=yy%100;
	}
	f=k+((13*(m[mm-1])-1)/5)+y+(y/4)+(C/4)+(2*C);
	if(f%7-3==-1)
	{
		return(6);
	}
	else
	{
		if(f%7-3==-2)
		{
			return(5);
		}
		else
		{
			if(f%7-3==-3)
			{
				return(4);
			}
			else
			{
				return(f%7-3);
			}
		}
	}
}
void month(int mm,int yy)
{
	int dd=1,i=0,z,c=1;
	int ly[2]={28,29};
	int days[12]={31,ly[leap(yy)],31,30,31,30,31,31,30,31,30,31};
	z=day(dd,mm,yy);
	cout<<"S\tM\tT\tW\tT\tF\tS\n";
	while(c<=days[mm-1])
	{
		if(z==i)
		{
			cout<<c<<"\t";
			z++;
			c++;
		}
		else
		{
			cout<<"0\t";
		}
		if(i==6||i==13||i==20||i==27||i==34||i==41)
		{
			cout<<"\n";
		}
		i++;
	}
	cout<<"\n\n";
}
void year(int yy)
{
	int i;
	char year[12][3]={{'J','a','n'},{'F','e','b'},{'M','a','r'},{'A','p','r'},{'M','a','y'},{'J','u','n'},{'J','u','l'},{'A','u','g'},{'S','e','p'},{'O','c','t'},{'N','o','v'},{'D','e','c'}};
	for(i=1;i<=12;i++)
	{
		cout<<year[i-1][0]<<year[i-1][1]<<year[i-1][2]<<"\n";
		month(i,yy);
	}
}
int leap(int yy)
{
	if(yy%4==0)
	{
		if(yy%100==0)
		{
			if(yy%400==0)
			{
				return(1);
			}
			else
			{
				return(0);
			}
		}
		else
		{
			return(1);
		}
	}
	else
	{
		return(0);
	}
}
