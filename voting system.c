#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct voter_details
{
	char surname[10];
	char name[10];
	int age;
	char gender[10];
	char address[10];
    char nativity[10];
	long long int mobile_num;
	long long int aadhar_num;
}v;
struct votescounthnk
{
	int votescount1;
	int votescount2;
	int votescount3;
	int votescount4;
}v2;
struct votescountwgl
{
	int votescountA;
	int votescountB;
	int votescountC;
	int votescountD;
}v3;
void read(struct voter_details);
void display(struct voter_details);
void update(struct voter_details);
void searchname(struct voter_details);
void searchaadhar(struct voter_details);
void eligibility(struct voter_details);
void eligibilitydisplay(struct voter_details);
void castvote(struct voter_details);
void votescounthnk(struct voter_details);
void votescountwgl(struct voter_details);
void leadingcandidatehnk(struct voter_details);
void leadingcandidatewgl(struct voter_details);
int c,n,i,o,q,t,u,b,e,f,g,h,ela1,s1,s2,s3,z2,po,z3,z1;
int flag1=0,flag2=0,flag3=0,F=0,G=0,H=0,flag5=0;
char ch,p[10],r[10],a[10],d[10],l[10],ela[10],ch1,r1,r2,r3;
FILE *m,*e1,*v5,*v6;
main()
{
	struct voter_details v;
	struct votescounthnk v2;
	struct votescountwgl v3;
	do
	{
		printf("\nenter \n1.SURVEY_RECORD\n2.ELIGIBILITY_RECORD\n3.VOTING_PROCESS\n");
		printf("\nenter your choice");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("\nSURVEY_RECORD\n");
			       do
			       {
			       printf("\npress \n1.read_the_survey_record\n2.display_the_survey_record\n3.update_the_survey_record\n4.search_by_name_in_survey_record\n5.search_by_aadhar_in_survey_record\n");
			       printf("\nenter the choice\n");
			       scanf("%d",&s1);
			       switch(s1)
			       {
			        case 1:read(v);
			        break;
		            case 2:display(v);
			        break;
			        case 3:update(v);
			        break;
			        case 4:searchname(v);
			        break;
	                case 5:searchaadhar(v);
			        break;
			       }
			       printf("\npress a to continue to go with SURVEY_RECORD\n");
			       scanf(" %c",&r1);
			       }while(r1=='a');
			       break;
			case 2:printf("\nELIGILIBILITY_RECORD\n");
			       do
			       {
			       printf("\npress \n1.eligibility_record\n2.displaying_eligibility_record\n");
			       printf("\nenter the choice\n");
			       scanf("%d",&s2);
			       switch(s2)
			       {
			       	case 1:eligibility(v);
			        break;
			        case 2:eligibilitydisplay(v);
			        break;
				   }
				   printf("\npress b to continue to go with ELIGIBILITY_RECORD\n");
			       scanf(" %c",&r2);
			       }while(r2=='b');
				   break;
			case 3:printf("\nVOTING_PROCESS\n");
			       do
			       {
			       printf("\npress \n1.cast_the_vote\n2.votescount_hnk\n3.votescount_wgl\n4.leading_candidate_hnk\n5.leading_candidate_wgl\n");
				   printf("\nenter the choice\n");
				   scanf("%d",&s3);
				   switch(s3)
				   { 
			        case 1:castvote(v);
			        break;
			        case 2:votescounthnk(v);
			        break;
			        case 3:votescountwgl(v);
			        break;
			        case 4:leadingcandidatehnk(v);
			        break;
			        case 5:leadingcandidatewgl(v);
			        break;
			       }
			       printf("\npress c to continue to go with VOTING_PROCESS\n");
			       scanf(" %c",&r3);
			       }while(r3=='c');
			       break;
		}
		printf("\nenter s to continue to go with other RECORDS\n");
		scanf(" %c",&ch);
	}while(ch=='s');
}
void read(struct voter_details v)
{
	FILE *m;
	m=fopen("C:/Users/91967/Desktop/PSP PROJECT/records","w");
	printf("\nenter num of records\n");
	scanf("%d",&n);
	printf("\nenter data in records\n");
	printf("\nsurname\nname\nage\ngender\naddress\nnativity\nmobile_num\naadhar_num\n");
	for(i=0;i<n;i++)
	{
		fscanf(stdin,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num);	
		fprintf(m,"\n%s\t%s\t%d\t%s\t%s\t%s\t%lld\t%lld\n",v.surname,v.name,v.age,v.gender,v.address,v.nativity,v.mobile_num,v.aadhar_num);	
	}
	fclose(m);
}
void display(struct voter_details v)
{
	FILE *m;
	m=fopen("C:/Users/91967/Desktop/PSP PROJECT/records","r");
	printf("\n-------------------------------------------------SURVEY LIST----------------------------------------------------\n");
	printf("\nSURNAME   NAME   AGE   GENDER  ADDRESS NATIVITY MOBILE_NUM AADHAR_NUM\n");
    while(fscanf(m,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num)!=EOF)
	{	
		fprintf(stdout,"\n%s \t %s \t %d \t %s \t %s \t %s \t %lld \t %lld\n",v.surname,v.name,v.age,v.gender,v.address,v.nativity,v.mobile_num,v.aadhar_num);		
    }
	fclose(m);
}
void update(struct voter_details v)
{
	FILE *m;
	m=fopen("C:/Users/91967/Desktop/PSP PROJECT/records","a");
	printf("\nenter num of records to be recorded\n");
	scanf("%d",&o);
	printf("\nenter data in updated records\n");
	printf("\nsurname\nname\nage\ngender\naddress\nnativity\nmobile_num\naadhar_num\n");
	for(i=0;i<o;i++)
	{
		fscanf(stdin,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num);
		fprintf(m,"\n%s\t%s\t%d\t%s\t%s\t%s\t%lld\t%lld\n",v.surname,v.name,v.age,v.gender,v.address,v.nativity,v.mobile_num,v.aadhar_num);
    }
    fclose(m);
}
void searchname(struct voter_details v)
{
	FILE *m;
	m=fopen("C:/Users/91967/Desktop/PSP PROJECT/records","r");
	printf("\nenter the data to search\n");
	scanf("%s",p);
	while(fscanf(m,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num)!=EOF)
	{
	     q=strcmp(v.name,p);
	     if(q==0)
		{
			fprintf(stdout,"\n%s \t %s \t %d \t %s \t %s \t %s \t %lld \t %lld\n",v.surname,v.name,v.age,v.gender,v.address,v.nativity,v.mobile_num,v.aadhar_num);
			flag1=1;
		}
	}
	if(flag1==1)
	{
		printf("\nrecord is found\n");
	}
	else
	{
		printf("\nrecord is not found\n");
	}
	fclose(m);
}
void searchaadhar(struct voter_details v)
{
	FILE *m;
	m=fopen("C:/Users/91967/Desktop/PSP PROJECT/records","r");
	printf("\nenter data to search (name)\n");
	scanf("%s",r);
	printf("\nenter data to search(aadhar num)\n");
	scanf("%lld",&t);
	while(fscanf(m,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num)!=EOF)
	{
		u=strcmp(v.name,r);
	    if((u==0)&&(t==v.aadhar_num))
    	{
		fprintf(stdout,"\n%s\t%s\t%d\t%s\t%s\t%s\t%lld\t%lld\n",v.surname,v.name,v.age,v.gender,v.address,v.nativity,v.mobile_num,v.aadhar_num);
		flag2=1;
	    }
    }
	if(flag2==1)
	{
		printf("\nrecord is found\n");
	}
	else
	{
		printf("\nrecord is not found\n");
	}
	fclose(m);
}
void eligibility(struct voter_details v)
{
	FILE *m,*el;
	m=fopen("C:/Users/91967/Desktop/PSP PROJECT/records","w");
	el=fopen("C:/Users/91967/Desktop/PSP PROJECT/eligibility","a");
	if(G!=1)
	{
	while(fscanf(m,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num)!=EOF)
	{
	if(v.age>=18)
	{	
		fprintf(el,"\n%s\t%s\t%d\t%s\t%s\t%s\t%lld\t%lld\n",v.surname,v.name,v.age,v.gender,v.address,v.nativity,v.mobile_num,v.aadhar_num);		
    }
    }
    }
    G=1;
	fclose(m);
	fclose(el);
}
void eligibilitydisplay(struct voter_details v)
{
	FILE *el;
	el=fopen("C:/Users/91967/Desktop/PSP PROJECT/eligibility","r");
	printf("\n--------------------------------------------------ELIGIBILITY LIST------------------------------------------------\n");
	printf("\nSURNAME   NAME   AGE   GENDER  ADDRESS NATIVITY MOBILE_NUM AADHAR_NUM\n");
    while(fscanf(el,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num)!=EOF)
	{	
		fprintf(stdout,"\n%s\t%s\t%d\t%s\t%s\t%s\t%lld\t%lld\n",v.surname,v.name,v.age,v.gender,v.address,v.nativity,v.mobile_num,v.aadhar_num);		
    }
	fclose(el);
}
void castvote(struct voter_details v)
{
	FILE *el;
	FILE *v5;
	FILE *v6;
    el=fopen("C:/Users/91967/Desktop/PSP PROJECT/eligibility","r");
    v5=fopen("C:/Users/91967/Desktop/PSP PROJECT/votescounthnk","a");
    v6=fopen("C:/Users/91967/Desktop/PSP PROJECT/votescountwgl","a");
    printf("\nenter name\n");
    scanf("%s",ela);
    printf("\nenter aadhar num\n");
    scanf("%lld",&ela1);
    if(F==1)
    {
    	printf("\n-----------------VOTING PROCESS COMPLETED--------------\n");
	}
	else
	{
    while(fscanf(el,"%s%s%d%s%s%s%lld%lld",v.surname,v.name,&v.age,v.gender,v.address,v.nativity,&v.mobile_num,&v.aadhar_num)!=EOF)
	{
        if(ela1==v.aadhar_num)
        {
		flag3=1;
        }
    }
    if(flag3==1)
    {
	printf("\n*-------------------------------VOTING IS NOT ONLY RIGHT, BUT ITS OUR DUTY---------------------------------------------*\n");
	printf("\n------------------------------------------------WELCOME TO VOTING-----------------------------------------------------\n");
	printf("\n--------------------------------------------------VOTING 2022---------------------------------------------------\n");
	printf("\n----------------------------------------------PLEASE CAST YOUR VOTE------------------------------------------------\n");
	int f;
	printf("\npress\n1. for hanamkonda\n2 for warangal\n");
	scanf("%d",&z1);
	switch(z1)
	{
		case 1:
		printf("\nthe following are the candidates from hanamkonda:\n");
	    printf("\n1.CANDIDATE 1\n2.CANDIDATE 2\n3.CANDIDATE 3\n4.NOTA\n");
	    printf("\nenter your choice\n");
	    scanf("%d",&f);
	    switch(f)
	    {
		case 1:
	    v2.votescount1++;
	    break;
	    case 2:
	    v2.votescount2++;
	    break;
	    case 3:
	    v2.votescount3++;
	    break;
	    case 4:
	    v2.votescount4++;
	    break;	
	    }
	    break;
	    case 2:
	    printf("\nthe following are the candidates from warangal:\n");
	    printf("\n1.CANDIDATE A\n2.CANDIDATE B\n3.CANDIDATE C\n4.NOTA\n");
	    printf("\nenter your choice\n");
	    scanf("%d",&z2);
	    switch(z2)
	    {
		case 1:
	    v3.votescountA++;
	    break;
	    case 2:
	    v3.votescountB++;
	    break;
	    case 3:
	    v3.votescountC++;
	    break;
	    case 4:
	    v3.votescountD++;
	    break;	
	    }
	    break;
	}
	printf("\n-------------------------------------------------THANKS FOR VOTING------------------------------------------------\n");
	F=1;
    }
    else
    {
    	printf("\nnot eligible to vote\n");
	}
    }
	fprintf(v5,"\n%d\t%d\t%d\t%d\n",v2.votescount1,v2.votescount2,v2.votescount3,v2.votescount4);
	fprintf(v6,"\n%d\t%d\t%d\t%d\n",v3.votescountA,v3.votescountB,v3.votescountC,v3.votescountD);
	fclose(v5);
	fclose(v6);
	fclose(el);
}
void votescounthnk(struct voter_details v)
{
    FILE *v5;
    v5=fopen("C:/Users/91967/Desktop/PSP PROJECT/votescounthnk","r");
    printf("\n------------VOTING STATISTICS----------------\n");
    printf("\nCANDIDATE1     CANDIDATE2     CANDIDATE3     NOTA\n");
    while(fscanf(v5,"%d%d%d%d",&v2.votescount1,&v2.votescount2,&v2.votescount3,&v2.votescount4)!=EOF)
    {
    	fprintf(stdout,"\n%d\t\t%d\t\t%d\t\t%d\n",v2.votescount1,v2.votescount2,v2.votescount3,v2.votescount4);    		
	}
	fclose(v5);
}
void votescountwgl(struct voter_details v)
{
    FILE *v6;
    v6=fopen("C:/Users/91967/Desktop/PSP PROJECT/votescountwgl","r");
    printf("\n------------VOTING STATISTICS----------------\n");
    printf("\nCANDIDATEA     CANDIDATEB     CANDIDATEC     NOTA\n");
    while(fscanf(v6,"%d%d%d%d",&v3.votescountA,&v3.votescountB,&v3.votescountC,&v3.votescountD)!=EOF)
    {
    	fprintf(stdout,"\n%d\t\t%d\t\t%d\t\t%d\n",v3.votescountA,v3.votescountB,v3.votescountC,v3.votescountD);    		
	}
	fclose(v6);
}
void leadingcandidatehnk(struct voter_details v)
{
	FILE *v5;
    v5=fopen("C:/Users/91967/Desktop/PSP PROJECT/votescounthnk","r");
    int i=0;
    while(fscanf(v5,"%d%d%d%d",&v2.votescount1,&v2.votescount2,&v2.votescount3,&v2.votescount4)!=EOF)
    {
        if(v2.votescount1>v2.votescount2&&v2.votescount1>v2.votescount3&&v2.votescount1>v2.votescount4)   		
    	fprintf(stdout,"\nCANDIDATE 1 WON THE ELECTIONS\n",v2.votescount1);
    	else if(v2.votescount2>v2.votescount1&&v2.votescount2>v2.votescount3&&v2.votescount2>v2.votescount4)    		
    	fprintf(stdout,"\nCANDIDATE 2 WON THE ELECTIONS\n",v2.votescount2);
    	else if(v2.votescount3>v2.votescount1&&v2.votescount1>v2.votescount2&&v2.votescount3>v2.votescount4)    		
        fprintf(stdout,"\nCANDIDATE 3 WON THE ELECTIONS\n",v2.votescount3);
    	else    		
    	fprintf(stdout,"\nNOTA WON THE ELECTIONS\n",v2.votescount4);
    }
	fclose(v5);
}
void leadingcandidatewgl(struct voter_details v)
{
	FILE *v6;
    v6=fopen("C:/Users/91967/Desktop/PSP PROJECT/votescountwgl","r");
    int i=0;
    while(fscanf(v6,"%d%d%d%d",&v3.votescountA,&v3.votescountB,&v3.votescountC,&v3.votescountD)!=EOF)
    {
        if(v3.votescountA>v3.votescountB&&v3.votescountA>v3.votescountC&&v3.votescountA>v3.votescountD)   		
    	fprintf(stdout,"\nCANDIDATE A WON THE ELECTIONS\n",v3.votescountA);
    	else if(v3.votescountB>v3.votescountA&&v3.votescountB>v3.votescountC&&v3.votescountB>v3.votescountD)    		
    	fprintf(stdout,"\nCANDIDATE B WON THE ELECTIONS\n",v3.votescountB);
    	else if(v3.votescountC>v3.votescountA&&v3.votescountC>v3.votescountB&&v3.votescountC>v3.votescountD)    		
        fprintf(stdout,"\nCANDIDATE C WON THE ELECTIONS\n",v3.votescountC);
    	else    		
    	fprintf(stdout,"\nNOTA WON THE ELECTIONS\n",v3.votescountD);
    }
	fclose(v6);
}
