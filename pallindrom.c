


//This function is necessary
int main()
{
	struct string x;	
	struct vector pal;
	init_vector(&pal);
	printf("Enter\n");
	x.x=getstring(&x);
	int cnt[x.n];
	int check[x.n];
	int i;
	//Intializes the frequency of letters in the string
	for(i=0;i<x.n;i++)
	{
		cnt[i]=0;
		check[i]=0;
	}
	int j; //This is int j;
	//Counts the frequency of letters in the string
	for(j=0;j<x.n;j++)
	{
		for(i=0;i<x.n;i++)
		{
			
			if(x.x[j]==x.x[i])
			{
				cnt[j]++;
			}
		}	
	}
	int u=0;
	//Finds the number of unique characters in the string
	for(i=1;i<x.n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(x.x[j]==x.x[i])
			{
				check[i]=1;
				u++;
				break;
			}
		}
	}
	
	int cnt2[x.n-u];
	struct string h;
	initialse(&h);
	//Finds the unique characters in the string
	for(i=0,j=0;i<x.n;i++)
	{
		if(!check[i])
		{
			cnt2[j]=cnt[i];
			char hel;
			insert(&h,x.x[i]);
			j++;
		}
	}
	int l=h.n;
	int n=0,k;
	//forms the basic pallindromes and stores them in pal vector
	for(i=0;i<l;i++)
	{	
		struct string s;
		initialse(&s);
		for(j =0 ;j<cnt2[i];j++)
		{	
			insert(&s,h.x[i]);
			push_back(&pal,s);
			
			n++;
		}
		
	}

	int cnt3[l];
	printf("\n\nHERE WE GO\n\n");
	/*iteratively finds the rest of the pallindromes from the basic 
	pallindromes and stores them in the vector pal.
	*/
	for(i=0;i<n;i++)
	{
		struct string t;
		initialse(&t);
		equal(&t,&pal.p[i]);
		print(t);
		printf("\n");
		for(j=0;j<l;j++)
		{
			cnt3[j]=cnt2[j];
		}
		for(j=0;j<l;j++)
		{
			for(k=0;k<t.n;k++)
			{
				if(h.x[j]==t.x[k])
				{
					cnt3[j]--;
				}
			}
		}
		
		for(j=0;j<l;j++)
		{
			int check=1;
			if(cnt3[j]>1)
			{
				struct string t2;
				initialse(&t2);
				insert(&t2,h.x[j]);
				insert_string(&t2,&t);
				insert(&t2,h.x[j]);
				for(k=0 ;k<pal.n;k++)
				{
					if(equality(t2, pal.p[k])==0)
					//if(*pal.p[k].x==*t2.x)
					{	
						check=0;
					}
				}
				if(check==1)
				{	
					push_back(&pal,t2);
					n++;
				}
			}
			
		}
	}
	printf("No. of Palindromes: %d",pal.n);
	
	return 0;
}


