#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class supermarket
{
private:
	char name[50],no[15],mfg[10],price[5];
public:
	char *getname()
	{
		return name;
	}
	char *getph()
	{
		return no;
	}
	void getdata();
	void display();
	void remove();
	void update(char *n,char *num,char *m,char *pr)
	{
 	strcpy(name,n);
 	strcpy(no,num);
 	strcpy(mfg,m);
 	strcpy(price,pr);
	}
	void displaybill();
};

void supermarket::getdata()
{
	cout<<"Enter item name: ";
	cin>>name;
	cout<<"Enter item Number: ";
	cin>>no;
	cout<<"Enter item mfg date: ";
	cin>>mfg;
	cout<<"Enter item price: ";
	cin>>price;
}

void supermarket::display()
{
	cout<<name<<"\t\t"<<no<<"\t\t"<<mfg<<"\t\t"<<price<<"\t\t"<<endl;
}

void supermarket::displaybill()
{
	cout<<no<<"\t\t\t"<<name<<"\t\t\t"<<price<<endl;
}

int main()
{
	supermarket obj;
	fstream file;
	int c,flag,k;
	char ch,n[50],num[15],m[10],pr[5];
	file.open("item.txt",ios::ate | ios::in | ios::out | ios::binary);
	while(1)
	{
		cout<<"\n1.ENTER ITEM\n2.DISPLAY ITEM DETAILS\n3.EXIT\n4.REMOVE ITEM\n5.UPDATE\n6.DISPLAY BILL\n7.EXIT\n";
		cout<<"ENTER YOUR CHOICE: ";
		cin>>c;
		switch(c)
		{
			case 1:
			{
				obj.getdata();
				cin.get(ch);
				file.write((char *) &obj,sizeof(obj));
				break;
			}
			case 2:
			{
				file.seekg(0,ios::beg);
				cout<<"\nNAME\t\tNUMBER\t\tMFG DATE\tPRICE\n";
				while(file)
				{
					file.read((char *) &obj,sizeof(obj));
					if(!file.eof())
					{
						obj.display();
					}
				}
				file.clear();
				getchar();
				break;
			}
			case 3:
			{
				exit(0);
			}
			case 4:
			{
				cout<<"ENTER ITEM NAME: ";
				cin>>n;
				file.seekg(0,ios::beg);
				flag=0;
				k=0;
				while(file.read((char *) &obj,sizeof(obj)))
				{
					k++;
					if(strcmp(n,obj.getname())==0)
					{
						flag = 1;
						break;
					}
				}
				file.clear();
				if(flag==0)
				{
					cout<<"NAME NOT IN FILE!\n";
				}
				else
				{
					int l = (k-1) * sizeof(obj);
					cin.get(ch);
					if(file.eof())
					file.clear();

					strcpy(n,"");
					strcpy(num,"");
					strcpy(m,"");
					strcpy(pr,"");
					file.seekp(l);
					obj.update(n,num,m,pr);
					file.write((char *) &obj,sizeof(obj));
					file.flush();
				}	
				break;

			}
			case 5:
			{
				cout<<"ENTER ITEM NAME: ";
				cin>>n;
				file.seekg(0,ios::beg);
				flag=0;
				k=0;
				while(file.read((char *) &obj,sizeof(obj)))
				{
					k++;
					if(strcmp(n,obj.getname())==0)
					{
						flag = 1;
						break;
					}
				}
				file.clear();
				if(flag==0)
				{
					cout<<"NAME NOT IN FILE!\n";
				}
				else
				{
					int l = (k-1) * sizeof(obj);
					cin.get(ch);
					if(file.eof())
					file.clear();

					cout<<"Enter item Number: ";
					cin>>num;
					cout<<"Enter item mfg date: ";
					cin>>m;
					cout<<"Enter item price: ";
					cin>>pr;
					file.seekp(l);
					obj.update(n,num,m,pr);
					file.write((char *) &obj,sizeof(obj));
					file.flush();
				}	
			break;
			}
			case 6:
			{
				file.seekg(0,ios::beg);
				cout<<"==================================BILL====================================\n";
				cout<<"ITEM NUMBER\t\tITEM NAME\t\tITEM PRICE\n";
				cout<<"--------------------------------------------------------------------------\n";
				while(file)
				{
					file.read((char *) &obj,sizeof(obj));
					if(!file.eof())
					{
						obj.displaybill();	
					}
				}
				cout<<"==================================END=====================================\n";
				file.clear();
				getchar();
				
			break;
			}
			case 7:
			{
				exit(0);
			break;
			}
		}
	}
	file.close();
	return 0;
}
/*
OUTPUT:


1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 1
Enter item name: Rice
Enter item Number: 1
Enter item mfg date: N/A
Enter item price: 250

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 1
Enter item name: Sugar
Enter item Number: 2
Enter item mfg date: N/A
Enter item price: 150

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 1
Enter item name: Salt
Enter item Number: 3
Enter item mfg date: 2/1
Enter item price: 20

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 1
Enter item name: Milk
Enter item Number: 4
Enter item mfg date: 5/10
Enter item price: 20

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 1
Enter item name: Butter
Enter item Number: 5
Enter item mfg date: 12/9
Enter item price: 50

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 2

NAME            NUMBER          MFG DATE        PRICE
Rice            1               N/A             250
Sugar           2               N/A             150
Salt            3               2/1             20
Milk            4               5/10            20
Butter          5	            12/9            50

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 4
ENTER ITEM NAME: Butter

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 2

NAME            NUMBER          MFG DATE        PRICE
Rice            1               N/A             250
Sugar           2               N/A             150
Salt            3               2/1             20
Milk            4               5/10            20


1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 5
ENTER ITEM NAME: Sugar
Enter item Number: 6
Enter item mfg date: 2/4
Enter item price: 200

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 2

NAME            NUMBER          MFG DATE        PRICE
Rice            1               N/A             250
Sugar           6               2/4             200
Salt            3               2/1             20
Milk            4               5/10            20


1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 6
==================================BILL====================================
ITEM NUMBER             ITEM NAME               ITEM PRICE
--------------------------------------------------------------------------
1                       Rice                    250
6                       Sugar                   200
3                       Salt                    20
4                       Milk                    20

==================================END=====================================

1.ENTER ITEM
2.DISPLAY ITEM DETAILS
3.EXIT
4.REMOVE ITEM
5.UPDATE
6.DISPLAY BILL
7.EXIT
ENTER YOUR CHOICE: 7

*/
