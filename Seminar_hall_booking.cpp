#include<iostream>
#include<string>
#include<fstream>
using namespace std;
char fname1[30]="seminar_hall_1.txt";
char fname2[30]="seminar_hall_2.txt";
char fname3[30]="seminar_hall_3.txt";
char fname4[30]="seminar_hall_4.txt";
char fname5[30]="seminar_hall_5.txt";
char fname6[30]="seminar_hall_6.txt";
char fname7[30]="RajLaxhmin_seminar_hall.txt";
char fname8[30]="auditorium.txt";
struct record
{
	char date[15],time[15],branch[10],discription[100];
};
class seminar1
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar1::pack(record r)
{
	fstream fp;
	fp.open(fname1,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar1::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar1::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar1::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname1,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar1::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname1,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname1,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar1::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname1,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}

class seminar2
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar2::pack(record r)
{
	fstream fp;
	fp.open(fname2,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar2::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar2::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar2::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname2,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar2::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname2,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname2,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar2::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname2,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}
class seminar3
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar3::pack(record r)
{
	fstream fp;
	fp.open(fname3,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar3::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar3::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar3::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname3,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar3::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname3,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname3,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar3::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname3,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}
class seminar4
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar4::pack(record r)
{
	fstream fp;
	fp.open(fname4,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar4::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar4::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar4::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname4,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar4::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname4,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname4,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar4::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname4,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}

class seminar5
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar5::pack(record r)
{
	fstream fp;
	fp.open(fname5,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar5::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar5::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar5::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname5,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar5::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname5,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname5,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar5::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname5,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}
class seminar6
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar6::pack(record r)
{
	fstream fp;
	fp.open(fname6,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar6::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar6::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar6::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname6,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar6::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname6,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname6,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar6::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname6,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}
class seminar7
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar7::pack(record r)
{
	fstream fp;
	fp.open(fname7,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar7::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar7::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar7::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname7,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar7::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname7,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname7,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar7::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname7,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}
class seminar8
{
public: void pack(record r);
		record unpack(char a[]);
		void writedata();
		void display();
		void search();
		void modify();
};
void seminar8::pack(record r)
{
	fstream fp;
	fp.open(fname8,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char buff[45];
	strcpy(buff,r.date);
	strcat(buff,"|");
	strcat(buff,r.time);
	strcat(buff,"|");
	strcat(buff,r.branch);
	strcat(buff,"|");
	strcat(buff,r.discription);
	strcat(buff,"|*");
	fp<<buff<<endl;
	fp.close();
}
record seminar8::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
		r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.time[i++]=buff[j++];
	r.time[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.branch[i++]=buff[j++];
	r.branch[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
		r.discription[i++]=buff[j++];
	r.discription[i]='\0';
	return(r);
}
void seminar8::writedata()
{
	record r;
	cout<<"\nEnter Date (DD/MM/YYYY):";
	cin>>r.date;
	cout<<"\nEnter Time Slot (From - To):";
	cin>>r.time;
	cout<<"\nEnter Branch:";
	cin>>r.branch;
	cout<<"\nEnter Discription:";
	cin>>r.discription;
	pack(r);
}
void seminar8::display()
{
	fstream fp;
	char buff[45];
	record r;
	fp.open(fname8,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\n#\tDate\tTime Slot\tBranch\tDiscription\n";
	int c=1;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())break;
		r=unpack(buff);
		cout<<c++<<"\t"<<r.date<<"\t"<<r.time<<"\t"<<r.branch<<"\t"<<r.discription<<endl;
	
	}
	fp.close();
	return;
}
void seminar8::modify()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s[100];
	fp.open(fname8,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be modified:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].date,date)==0)
		{
			cout<<"\nvalues of the record are:\n";
			cout<<"\nDate:"<<s[j].date;
			cout<<"\nTime Slot:"<<s[j].time;
			cout<<"\nBranch:"<<s[j].branch;
			cout<<"\nDiscription:"<<s[j].discription;
			cout<<"\nenter the new values:\n";
			cout<<"\nDate:";
			cin>>s[j].date;
			cout<<"\nTime Slot:";
			cin>>s[j].time;
			cout<<"\nBranch:";
			cin>>s[j].branch;
			cout<<"\nDiscription:";
			cin>>s[j].discription;
			break;
		}
	}
	if(j==i)
	{
		cout<<"\nrecord not found";
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname8,ios::out|ios::trunc);
	if(fd==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	for(j=0;j<i;j++)
		pack(s[j]);
	fd.close();
}
void seminar8::search()
{
	fstream fp;
	char date[15],buff[45];
	int i,j;
	record s;
	fp.open(fname8,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	cout<<"\nenter the Date (DD/MM/YYYY) to be searched:";
	cin>>date;
	i=0;
	while(1)
	{
		fp.getline(buff,45,'*');
		if(fp.eof())
			break;
		s=unpack(buff);
		if(strcmp(s.date,date)==0)
		{
			cout<<"\nrecord found\n";
			cout<<"\nDate:"<<s.date;
			cout<<"\nTime Slot:"<<s.time;
			cout<<"\nBranch:"<<s.branch;
			cout<<"\nDiscription:"<<s.discription;
			return;
		}
	}
	cout<<"\nrecord not found";
	return;
}

void main()
{
	int ch;
	int hall;
	seminar1 obj1;
	seminar2 obj2;
	seminar3 obj3;
	seminar4 obj4;
	seminar5 obj5;
	seminar6 obj6;
	seminar7 obj7;
	seminar8 obj8;

	cout<<"Select Seminar Hall:\n"<<"\n-----------------------------------------------------------------------------------------\n";
	cout<<"1.Seminar Hall 1\n2.Seminar Hall 2\n3.Seminar Hall 3\n4.Seminar Hall 4\n5.Seminar Hall 5\n6.Seminar Hall 6\n7.Raj Laxhmi Seminar Hall\n8.Auditorium\n";
	cout<<"\n------------------------------------------------------------------------------------------\n";
	cin>>hall;
	switch(hall)
	{
	case 1:cout<<" \nSeminar Hall 1\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj1.writedata();
			break;
		case 2: obj1.display();
			break;
		case 3: obj1.search();
			break;
		case 4: obj1.modify();
			break;
		default: exit(0);
		}
	}
	break;
	case 2: 
		cout<<" \nSeminar Hall 2\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj2.writedata();
			break;
		case 2: obj2.display();
			break;
		case 3: obj2.search();
			break;
		case 4: obj2.modify();
			break;
		default: exit(0);
		}
	}
	break;
	case 3: cout<<" \nSeminar Hall 3\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj3.writedata();
			break;
		case 2: obj3.display();
			break;
		case 3: obj3.search();
			break;
		case 4: obj3.modify();
			break;
		default: exit(0);
		}
	}
	break;
	case 4:cout<<" \nSeminar Hall 4\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj4.writedata();
			break;
		case 2: obj4.display();
			break;
		case 3: obj4.search();
			break;
		case 4: obj4.modify();
			break;
		default: exit(0);
		}
	}
	break;
	case 5:cout<<" \nSeminar Hall 5\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj5.writedata();
			break;
		case 2: obj5.display();
			break;
		case 3: obj5.search();
			break;
		case 4: obj5.modify();
			break;
		default: exit(0);
		}
	}
	break;
	case 6:cout<<" \nSeminar Hall 6\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj6.writedata();
			break;
		case 2: obj6.display();
			break;
		case 3: obj6.search();
			break;
		case 4: obj6.modify();
			break;
		default: exit(0);
		}
	}
	break;
	case 7:cout<<" \nSeminar Hall 7\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj7.writedata();
			break;
		case 2: obj7.display();
			break;
		case 3: obj7.search();
			break;
		case 4: obj7.modify();
			break;
		default: exit(0);
		}
	}
	break;
	case 8:cout<<" \nSeminar Hall 8\n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<"1.write data\n2.display\n3.search\n4.modify\n5.exit:"<<"\n-----------------------------------------------------------------------------------------\n";
		
	while(1)
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1: obj8.writedata();
			break;
		case 2: obj8.display();
			break;
		case 3: obj8.search();
			break;
		case 4: obj8.modify();
			break;
		default: exit(0);
		}
	}
	break;
	}


	
}



