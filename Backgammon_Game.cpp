#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#define f(i,a,b) for(i=a;i<b;i++)
#define ff(i,n) for(i=0;i<n;i++)
#define sin(n) scanf("%d",&n)
#define slin(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define pins(n) printf("%d ",n)
#define plin(n) printf("%lld\n",n)
#define plins(n) printf("%lld ",n)
#define gc getchar_unlocked
using namespace std;
typedef struct data
{
	int i1,f1,i2,f2,moved,value,hit;
}data;
data states[5000];data states2[5000];data bstates[1000];
int b[25],b1[25],b2[25];
int it=0,it2=0,bit=0,z,z1,r1,r2;
int br_flag=1;
char str[10];
bool myfunc(data a,data b)
{
	if(a.moved!=b.moved)
		return a.moved>b.moved;
	else if(a.value!=b.value)
		return a.value>b.value;
	else 
		return a.i1<b.i1;
}
int heuristic2(int arr[],int bear,int hit)
{
	int c=0,i;
	for(i=19;i<=24;i++)
	{
		if(arr[i]==1)
			c-=10;
		else if(arr[i]>=2)
			c+=10;
	}
	if(hit>0)
		c+=(9*hit);
	if(bear>0)
		c+=(bear*9);
	return c;
}
void do_this(int b[],int r1,int r2)
{
	b[25]=0;b[26]=0;b[27]=0;b[28]=0;b[29]=0;b[30]=0;b[31]=0;
	int b1[33],b2[33],i,j,k,x,y,hit,beared,c=0,m,flag1,flag2;
	for(i=19;i<=24;i++)
	{
		flag1=0;c=0;
		beared=0;hit=0;c=0;
		if(r1>0 and b[i]>=1 and b[i+r1]>=-1 and i+r1<=30)
		{
			flag1=1;c++;
			for(k=1;k<=32;k++)
				b1[k]=b[k];
			if(i+r1>=25)
			{
				beared++;
				b1[i]--;
			}
			else if(b[i+r1]==-1)
			{
				hit=1;
				b1[i]--;
				b1[i+r1]+=2;
			}
			else
			{
				b1[i]--;
				b1[i+r1]++;
			}
		}
		x=hit;y=beared;m=c;
		{
			for(j=19;j<=25;j++)
			{
				flag2=0;
				hit=x;beared=y;c=m;
				if(r2>0 and b1[j]>=1 and b1[j+r2]>=-1 and j+r2<=30)
				{
					flag2=1;c++;
					for(k=1;k<=32;k++)
						b2[k]=b1[k];
					if(j+r2>=25)
						beared++;
					else if(b1[j+r2]==-1)
					{
						hit++;
						b2[j+r2]+=2;
					}
					else
						b2[j+r2]++;
					b2[j]--;

				}
				if(flag1==1 and i>0 and i<25)
				{
				//	printf("FLAG1: %d\n",flag1 );
					bstates[bit].i1=i;bstates[bit].f1=i+r1;
				}
				if(flag2==1 and j>0 and j<25)
				{
				//	printf("FLAG2: %d\n",flag2 );
					bstates[bit].i2=j;bstates[bit].f2=j+r2;
				}
				bstates[bit].hit=beared;bstates[bit].moved=c;
				bstates[bit].value=heuristic2(b2,beared,hit);bit++;
			}
		}
	}
	swap(r1,r2);
	for(i=19;i<=24;i++)
	{
		flag1=0;c=0;
		beared=0;hit=0;c=0;
		if(r1>0 and b[i]>=1 and b[i+r1]>=-1 and i+r1<=30)
		{
			flag1=1;c++;
			for(k=1;k<=32;k++)
				b1[k]=b[k];
			if(i+r1>=25)
			{
				beared++;
				b1[i]--;
			}
			else if(b[i+r1]==-1)
			{
				hit=1;
				b1[i]--;
				b1[i+r1]+=2;
			}
			else
			{
				b1[i]--;
				b1[i+r1]++;
			}
		}
		x=hit;y=beared;m=c;
		{
			for(j=19;j<=25;j++)
			{
				flag2=0;
				hit=x;beared=y;c=m;
				if(r2>0 and b1[j]>=1 and b1[j+r2]>=-1 and j+r2<=30)
				{
					flag2=1;c++;
					for(k=1;k<=32;k++)
						b2[k]=b1[k];
					if(j+r2>=25)
						beared++;
					else if(b1[j+r2]==-1)
					{
						hit++;
						b2[j+r2]+=2;
					}
					else
						b2[j+r2]++;
					b2[j]--;

				}
				if(flag1==1 and i>0 and i<25)
				{
			//		printf("FLAG1: %d\n",flag1 );
					bstates[bit].i1=i;bstates[bit].f1=i+r1;
				}
				if(flag2==1 and j>0 and j<25)
				{
			//		printf("FLAG2: %d\n",flag2 );
					bstates[bit].i2=j;bstates[bit].f2=j+r2;
				}
				bstates[bit].hit=beared;bstates[bit].moved=c;
				bstates[bit].value=heuristic2(b2,beared,hit);bit++;
			}
		}
	}
	/////


	sort(bstates,bstates+bit,myfunc);
	int t=0;
/*	for(i=0;i<bit;i++)
	{
		//if(states[i].hit>1)
		{
			printf("################################################\n\n");
			printf("Move 1:  From: %d To: %d \n",bstates[i].i1,bstates[i].f1);
			printf("Move 2:  From: %d To: %d \n",bstates[i].i2,bstates[i].f2);
			printf("heuristic : %d  Dice Moved %d  beared: %d\n",bstates[i].value,bstates[i].moved,bstates[i].hit );
			printf("################################################\n\n");
			t++;
		}
	}
	printf("%d\n",bit );
	printf("%d\n",t );*/
	int from1=bstates[0].i1,to1=bstates[0].f1,from2=bstates[0].i2,to2=bstates[0].f2,mov=bstates[0].moved,fl=0;
	if(to1==0 and from1==0)
	{
		fl++;
		printf("pass\n");
	}
	else if(to1>=25 and from1>0 and from1<25)
	{
		fl++;
		printf("%d O\n",from1);
	}
	else if(from1>0 and from1<25)
	{
		fl++;
		printf("%d %d\n",from1,to1);
	}
	else
	{
		fl++;
		printf("pass\n");
	}
	if(to2==0 and from2==0)
	{
		fl++;
		printf("pass\n");
	}
	else if(to2>=25 and from2>0 and from2<25)
	{
		fl++;
		printf("%d O\n",from2);
	}
	else if(from2>0 and from2<25)
	{
		fl++;
		printf("%d %d\n",from2,to2);
	}
	else
	{
		fl++;
		printf("pass\n");
	}
//	printf("MOV: %d FLG: %d\n",mov,fl );
	if(fl<=1)
	{
		if(fl==1 and mov==2)
			printf("pass\n");
		else if(fl==0 and mov==2)
			printf("pass\npass\n");
		else if(fl==0 and mov==1)
			printf("pass\n");
	}
}
int heuristic(int arr[],int hit)
{
	int pipccount=0,c=0,i;
	for(i=1;i<=24;i++)
	{
		if(arr[i]>=1)
			pipccount+=(arr[i]*(25-i));
	}
	if(pipccount<=110)
	{
		for(i=1;i<=24;i++)
		{
			if(arr[i]==1)
			{
				if(i>=1 and i<=4)
					c+=3;
				else if(i>=5 and i<=12)
					c+=2;
				else if(i>=13 and i<=16)
					c-=1;
				else if(i>=17 and i<=20)
					c-=2;
				else
					c-=3;
			}
			else if(arr[i]>1)
			{
				if(i>=1 and i<=4)
					c+=4;
				else if(i>=5 and i<=8)
					c+=5;
				else if(i>=9 and i<=12)
					c+=7;
				else if(i>=13 and i<=16)
					c+=7;
				else if(i>=17 and i<=20)
					c+=9;
				else
					c+=12;
			}
		}
		for(i=1;i<=24;i++)
		{
			if(arr[i]>=3)
				c++;
		}
		for(i=1;i<=20;i++)
		{
			if(arr[i]>=2 and arr[i+1]>=2 and arr[i+2]>=2 and arr[i+3]>=2 and arr[i+4]>=2 and arr[i+5]>=2 and arr[i+6]>=2 and i+6<=24)
			{
				c+=26;
			}
			else if(arr[i]>=2 and arr[i+1]>=2 and arr[i+2]>=2 and arr[i+3]>=2 and arr[i+4]>=2 and arr[i+5]>=2 and i+5<=24)
			{
				c+=23;
			}
			else if(arr[i]>=2 and arr[i+1]>=2 and arr[i+2]>=2 and arr[i+3]>=2 and arr[i+4]>=2 and i+4<=24)
			{
				c+=20;
			}
			else if(arr[i]>=2 and arr[i+1]>=2 and arr[i+2]>=2 and arr[i+3]>=2 and i+3<=24)
			{
				if(i>=1 and i<=4)
					c+=8;
				else if(i>=5 and i<=12)
					c+=16;
				else if(i>=13 and i<=16)
					c+=20;
				else if(i>=17 and i<=20)
				{
					if(hit>0)
						c+=28;
					else
						c+=18;
				}
				else if(i>=21 and i<=24)
				{
					if(hit>0)
						c+=36;
					else
						c+=15;
				}

			}
			else if(arr[i]>=2 and arr[i+1]>=2 and arr[i+2]>=2 and i+2<=24)
			{
				if(i>=1 and i<=4)
					c+=6;
				else if(i>=5 and i<=12)
					c+=9;
				else if(i>=13 and i<=16)
					c+=14;
				else if(i>=17 and i<=20)
				{
					if(hit>0)
						c+=21;
					else
						c+=15;
				}
				else if(i>=21 and i<=24)
				{
					if(hit>0)
						c+=28;
					else
						c+=12;
				}

			}
		}
		if(hit>0)
		{
			c+=(hit*10);
		}
		return c;
	}
	else
	{
		for(i=1;i<=24;i++)
		{
			if(arr[i]==1)
			{
				if(i>=1 and i<=4)
					c+=3;
				else if(i>=5 and i<=12)
					c+=2;
				else if(i>=13 and i<=16)
					c-=1;
				else if(i>=17 and i<=20)
					c-=2;
				else
					c-=3;
			}
			else if(arr[i]>1)
			{
				if(i>=1 and i<=4)
					c+=6;
				else if(i>=5 and i<=12)
					c+=12;
				else if(i>=13 and i<=16)
					c+=18;
				else if(i>=17 and i<=20)
					c+=22;
				else
					c+=25;
			}
		}
		if(hit!=0)
		{
			if(hit>0)
				c+=(hit*25);
		}
		return c;
	}
}
void fastRead_int(int &x)
{
	register int c=gc();
	x=0;int neg=0;
	for(;((c<48 || c>57) && c != '-');c=gc());
	if(c=='-')
	{
		neg=1;c=gc();
	}	
	for(; c>47 && c<58 ; c = getchar_unlocked())
	{
		x=(x<<1)+(x<<3)+c-48;
	}
	if(neg)
		x=-x;
}
int bear_off_condition(int check[])
{
	int flag=1,k,z=0;
	for(k=1;k<=18;k++)
	{
		if(check[k]>=1 or z>=1)
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return 1;
	else
		return 0;

}
void bear_off(int b[],int roll1,int roll2,int dice_count)
{
	int dice_roll=dice_count,pos1=0,pos2=0,c=0;
	int bear=0,flag1=0,flag2=0;int opp_flag=0,i,a[7];

	for(i=19;i<=24;i++)
	{
		if(b[i]==0)
			a[i-18]=0;
		else if(b[i]>0)
			a[i-18]=1;
		else
			a[i-18]=-1;
	}
	for(i=1;i<=6;i++)
	{
		if(a[i]==-1 and c>0)
		{
			opp_flag=1;
			break;
		}
		else if(a[i]==1)
			c++;
	}
	if(opp_flag==0)
	{
		if(b[24-roll1+1]>0 && dice_roll<2)
		{
			b[24-roll1+1]-=1;
			pos1=24-roll1+1;
			cout<<pos1<<" "<<"O"<<"\n";
			dice_roll++;
			flag1=1;
		}
		if(b[24-roll2+1]>0 && dice_roll<2)
		{
			b[24-roll2+1]-=1;
			pos2=24-roll2+1;
			cout<<pos2<<" "<<"O"<<"\n";
			dice_roll++;
			flag2=1;
		}
		if(dice_roll==2)
		{
			return;
		}
		else
		{
			if(flag2==0 && flag1==0)
			{
				for(int i=19;i<=24;i++)
				{
					if(b[i]>0)
					{
						if(i+roll1<24)
						{
							b[i]-=1;
							b[i+roll1]++;
							cout<<i<<" "<<i+roll1<<"\n";
							dice_roll++;
							break;
						}
						else
						{
							b[i]-=1;
							cout<<i<<" "<<"O"<<"\n";
							dice_roll++;
							break;
						}
					}
				}
				if(dice_roll==2)
				{
					return;
				}
				for(int i=19;i<=24;i++)
				{
					if(b[i]>0)
					{
						if(i+roll2<24)
						{
							b[i]-=1;
							b[i+roll2]++;
							cout<<i<<" "<<i+roll2<<"\n";
							dice_roll++;
							break;
						}
						else
						{
							b[i]-=1;
							cout<<i<<" "<<"O"<<"\n";
							dice_roll++;
							break;
						}
					}
				}
			}
			else if(flag1==1 && flag2==0)
			{
				for(int i=19;i<=24;i++)
				{
					if(b[i]>0)
					{
						if(i+roll2<24)
						{
							b[i]-=1;
							b[i+roll2]++;
							cout<<i<<" "<<i+roll2<<"\n";
							dice_roll++;
							break;
						}
						else
						{
							b[i]-=1;
							cout<<i<<" "<<"O"<<"\n";
							dice_roll++;
							break;
						}
					}
				}
			}
			else if(flag1==0 && flag2==1)
			{
				for(int i=19;i<=24;i++)
				{
					if(b[i]>0)
					{
						if(i+roll1<24)
						{
							b[i]-=1;
							b[i+roll1]++;
							cout<<i<<" "<<i+roll1<<"\n";
							dice_roll++;
							break;
						}
						else
						{
							b[i]-=1;
							cout<<i<<" "<<"O"<<"\n";
							dice_roll++;
							break;
						}
					}
				}
			}
		}
	}
	else
	{
//		printf("MUAHAHAHHA\n");
//		printf("%d %d\n",roll1,roll2 );
		do_this(b,roll1,roll2);
		return;
	}
}
int main()
{
	int i,j,k,c,x,y,hit,t=0;
	z=0;z1=0;
	f(i,1,25)
		fastRead_int(b[i]);
//	printf("BOARD DONE\n");	
	scanf("%[^\n]s",str);
	for(k=0;k<strlen(str);k++)
	{
		if(str[k]=='a')
			z++;
		else if(str[k]=='b')
			z1++;
	}
//	printf("%d %d\n",z,z1 );
	fastRead_int(r1);
	fastRead_int(r2);
	if(r2>r1)
		swap(r1,r2);
//	for(k=1;k<=24;k++)
//		printf("%d ",b[k] );
//	printf("\n");
	for(k=1;k<=18;k++)
	{
		if(b[k]>=1 or z>=1)
		{
			br_flag=0;
			break;
		}
	}
	if(br_flag==0)
	{
		if(z<=0)
		{
		//	printf("Enter\n");
			for(i=1;i<=24;i++)
			{
				c=0;hit=0;

				if(r1>0 and i+r1<=24 and b[i]>=1 and b[i+r1]>=-1)
				{
					for(k=1;k<=24;k++)
					{
						b1[k]=b[k];
					}
					c+=2;
					if(b[i+r1]==-1)
					{
						hit=1;
						b1[i]=b[i]-1;
						b1[i+r1]=b[i+r1]+2;
					}
					else
					{
						b1[i]=b[i]-1;
						b1[i+r1]=b[i+r1]+1;
					}
					br_flag=bear_off_condition(b1);
					if(br_flag)
					{
						printf("%d %d\n",i,i+r1);
						bear_off(b1,0,r2,1);
						break;
					}
				}
				x=c;y=hit;
				for(j=1;j<=24;j++)
				{
					if(br_flag)
						break;
					hit=y;
					c=x;
					if(r2>0 and j+r2<=24 and b1[j]>=1 and b1[j+r2]>=-1)
					{
						for(k=1;k<=24;k++)
							b2[k]=b1[k];
						c++;
						if(b1[j+r2]==-1)
						{
							hit++;
							b2[j]--;b2[j+r2]+=2;
						}
						else
						{
							b2[j]--;b2[j+r2]++;
						}
						br_flag=bear_off_condition(b2);
						if(br_flag)
						{
							printf("%d %d\n",j,j+r2);
							bear_off(b2,r1,0,1);
							break;
						}
						if(c>=2)
							states[it].i1=i;states[it].f1=i+r1;
						states[it].i2=j;states[it].f2=j+r2;
						states[it].moved=c;states[it].hit=hit;states[it].value=heuristic(b2,hit);
						it++;
					}

				}
			}

			/////////////////

			for(i=1;i<=24;i++)
			{
				if(br_flag)
					break;
				c=0;hit=0;

				if(r2>0 and i+r2<=24 and b[i]>=1 and b[i+r2]>=-1)
				{
					for(k=1;k<=24;k++)
					{
						b1[k]=b[k];
					}
					c+=1;
					if(b[i+r2]==-1)
					{
						hit=1;
						b1[i]=b[i]-1;
						b1[i+r2]=b[i+r2]+2;
					}
					else
					{
						b1[i]=b[i]-1;
						b1[i+r2]=b[i+r2]+1;
					}
					br_flag=bear_off_condition(b1);
					if(br_flag)
					{
						printf("%d %d\n",i,i+r2);
						bear_off(b1,r1,0,1);
						break;
					}
				}
				x=c;y=hit;
				for(j=1;j<=24;j++)
				{
					if(br_flag)
						break;
					hit=y;
					c=x;
					if(r1>0 and j+r1<=24 and b1[j]>=1 and b1[j+r1]>=-1)
					{
						for(k=1;k<=24;k++)
							b2[k]=b1[k];
						c+=2;
						if(b1[j+r1]==-1)
						{
							hit++;
							b2[j]--;b2[j+r1]+=2;
						}
						else
						{
							b2[j]--;b2[j+r1]++;
						}
						br_flag=bear_off_condition(b2);
						if(br_flag)
						{
							printf("%d %d\n",j,j+r1);
							bear_off(b2,0,r2,1);
							break;
						}
						if(c>=1)
							states[it].i1=i;states[it].f1=i+r2;
						states[it].i2=j;states[it].f2=j+r1;
						states[it].moved=c;states[it].hit=hit;states[it].value=heuristic(b2,hit);
						it++;
					}

				}
			}

			/////////////////////////

			for(i=1;i<=24;i++)
			{
				if(br_flag)
					break;
				c=0;hit=0;
				if(r1>0 and i+r1<=24 and b[i]>=1 and b[i+r1]>=-1)
				{
					for(k=1;k<=24;k++)
					{
						b1[k]=b[k];
					}
					c+=2;
					if(b[i+r1]==-1)
					{
						hit=1;
						b1[i]=b[i]-1;
						b1[i+r1]=b[i+r1]+2;
					}
					else
					{
						b1[i]=b[i]-1;
						b1[i+r1]=b[i+r1]+1;
					}
					br_flag=bear_off_condition(b1);
					if(br_flag)
					{
						printf("%d %d\n",i,i+r1);
						bear_off(b1,0,r2,1);
						break;
					}
					states[it].i1=i;states[it].f1=i+r1;
					states[it].i2=0;states[it].f2=0;
					states[it].moved=c;states[it].hit=hit;states[it].value=heuristic(b1,hit);
					it++;
				}
			}

			//////////////////////

			for(i=1;i<=24;i++)
			{
				if(br_flag)
					break;
				c=0;hit=0;
				if(r2>0 and i+r2<=24 and b[i]>=1 and b[i+r2]>=-1)
				{
					for(k=1;k<=24;k++)
					{
						b1[k]=b[k];
					}
					c+=1;
					if(b[i+r2]==-1)
					{
						hit=1;
						b1[i]=b[i]-1;
						b1[i+r2]=b[i+r2]+2;
					}
					else
					{
						b1[i]=b[i]-1;
						b1[i+r2]=b[i+r2]+1;
					}
					br_flag=bear_off_condition(b1);
					if(br_flag)
					{
						printf("%d %d\n",i,i+r2);
						bear_off(b1,r1,0,1);
						break;
					}
					states[it].i1=i;states[it].f1=i+r2;
					states[it].i2=0;states[it].f2=0;
					states[it].moved=c;states[it].hit=hit;states[it].value=heuristic(b1,hit);
					it++;
				}
			}
			//////SORTING//////////////////
			sort(states,states+it,myfunc);


		}
		else
		{
			for(k=1;k<=24;k++)
			{
				b1[k]=b[k];
			}
			if(z>=2)
			{
				hit=0;
				c=0;
				if(r1>0 and b1[r1]>=-1)
				{
					c+=2;
					if(b1[r1]==-1)
					{
						hit=1;
						b1[r1]+=2;//z--;
					}
					else
					{
						b1[r1]++;//z--;
					}
				}
				if(c>=2)
				{
					states2[it2].i1=-1;
					states2[it2].f1=r1;
				}

				if(r2>0 and b1[r2]>=-1)
				{
					c++;
					if(b1[r2]==-1)
					{
						hit++;
						b1[r2]+=2;
					}
					else
						b1[r2]++;

					states2[it2].i2=-1;states2[it2].f2=r2;
				}
				states2[it2].hit=hit;
				states2[it2].moved=c;
				states2[it2].value=heuristic(b1,hit);
				it2++;
			}
			else
			{
				for(k=1;k<=24;k++)
				{
					b1[k]=b[k];
				}
				hit=0;
				c=0;
				if(r1>0 and b1[r1]>=-1)
				{
					c+=2;
					if(b1[r1]==-1)
					{
						hit=1;
						b1[r1]+=2;
					}
					else
					{
						b1[r1]++;
					}
					//		z--;
					x=c;

					for(i=1;i<=24;i++)
					{
						c=x;
						for(k=1;k<=24;k++)
						{
							b2[k]=b1[k];
						}
						if(r2>0 and i+r2<=24 and b1[i]>=1 and b1[i+r2]>=-1)
						{
							c+=1;
							if(b1[i+r2]==-1)
							{
								hit++;
								b2[i+r2]+=2;
							}
							else
								b2[i+r2]++;
							b2[i]--;
							states2[it2].i2=i;
							states2[it2].f2=i+r2;
						}
						states2[it2].i1=-1;
						states2[it2].f1=r1;
						states2[it2].hit=hit;
						states2[it2].moved=c;
						states2[it2].value=heuristic(b2,hit);
						it2++;
					}
				}


				for(k=1;k<=24;k++)
					b1[k]=b[k];
				hit=0;c=0;
				if(r2>0 and b1[r2]>=-1)
				{
					c+=1;
					if(b1[r2]==-1)
					{
						hit=1;
						b1[r2]+=2;
					}
					else
						b1[r2]++;
					//		z--;
					x=c;
					for(i=1;i<=24;i++)
					{
						c=x;
						for(k=1;k<=24;k++)
							b2[k]=b1[k];
						if(r1>0 and i+r1<=24 and b1[i]>=1 and b1[i+r1]>=-1)
						{
							c+=2;
							if(b1[i+r1]==-1)
							{
								hit++;
								b2[i+r1]+=2;
							}
							else
								b2[i+r1]++;
							b2[i]--;
							states2[it2].i2=i;states2[it2].f2=i+r1;
						}
						states2[it2].i1=-1;states2[it2].f1=r2;
						states2[it2].hit=hit;states2[it2].moved=c;states2[it2].value=heuristic(b2,hit);it2++;
					}
				}		
			}
			sort(states2,states2+it2,myfunc);
		}
	}
	else
	{
		bear_off(b,r1,r2,0);
	}
/*	if(z<=0)
	{
		for(i=0;i<it;i++)
		{

			//if(states[i].hit>1)
			{
				printf("################################################\n\n");
				printf("Move 1:  From: %d To: %d \n",states[i].i1,states[i].f1);
				printf("Move 2:  From: %d To: %d \n",states[i].i2,states[i].f2);
				printf("Hit : %d  Dice Moved %d\n",states[i].value,states[i].moved );
				printf("################################################\n\n");
				t++;
			}
		}
		printf("%d\n",it );
		printf("%d\n",t );
	}
	else
	{
		t=0;
		for(i=0;i<it2;i++)
		{

			//if(states[i].hit>1)
			{
				printf("################################################\n\n");
				printf("Move 1:  From: %d To: %d \n",states2[i].i1,states2[i].f1);
				printf("Move 2:  From: %d To: %d \n",states2[i].i2,states2[i].f2);
				printf("Hit : %d  Dice Moved %d\n",states2[i].value,states2[i].moved );
				printf("################################################\n\n");
				t++;
			}
		}
		printf("%d\n",it2 );
		printf("%d\n",t );

	}*/
	if(br_flag==0)
	{	
	if(z<=0)
		{
			int from1=states[0].i1,from2=states[0].i2,to1=states[0].f1,to2=states[0].f2;
			if(from1==-1)
				printf("Z %d\n",to1);
			else if(from1==0 or to1==0)
				printf("pass\n");
			else
				printf("%d %d\n",from1,to1);
			if(from2==-1)
				printf("Z %d\n",to2);
			else if(from2==0 or to2==0)
				printf("pass\n");
			else
				printf("%d %d\n",from2,to2);
		}
		else
		{
			int from1=states2[0].i1,from2=states2[0].i2,to1=states2[0].f1,to2=states2[0].f2;
			if(from1==-1)
				printf("Z %d\n",to1);
			else if(from1==0 or to1==0)
				printf("pass\n");
			else
				printf("%d %d\n",from1,to1);
			if(from2==-1)
				printf("Z %d\n",to2);
			else if(from2==0 or to2==0)
				printf("pass\n");
			else
				printf("%d %d\n",from2,to2);
		}
	}
	return 0;
}