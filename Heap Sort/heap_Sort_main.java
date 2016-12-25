import java.io.*;
import java.util.*;
class Heap_Sort
{
	int heap[]=new int[1001];
	int size, no_of_comp;
	public Heap_Sort(){
		size = 0;
		no_of_comp = 0;
	}
	public void insert_heap(int item,int n)
	{
		int ptr,par;
		if(n==1)
		{
		heap[n]=item;
		//no_of_comp++;
		}
		else
		{
		ptr=n;
			while(ptr>1)
			{
			par=ptr/2;
				if(item<=heap[par])
				{
				heap[ptr]=item;
				size++;
				no_of_comp++;
				return;
				}
				heap[ptr]=heap[par];
				ptr=par; //ptr=ptr/2 same thing
			no_of_comp++;
			}
			heap[ptr]=item;
		
		}
		size++;	
		return;
	}
	/*public void display()
	{
	
	for(int i=1;i<=size;i++)
	System.out.print(heap[i]+" ");
	
	}*/
	public int del_heap()
	{
	int item,lst,left=2,right=3,ptr=1;
	item=heap[1];
	lst=heap[size];
	//System.out.println("last="+lst);
	size--;
		while(right<=size)
		{
			if(lst>=heap[left] && lst>=heap[right])
			{
			heap[ptr]=lst;
			no_of_comp+=2;
			return item;
			}
			if(heap[left]>=heap[right])
			{
			heap[ptr]=heap[left];
			ptr=left;
			}
			else
			{
			heap[ptr]=heap[right];
			ptr=right;
			}
			left=2*ptr;
			right=left+1;
			no_of_comp++;
		}
		//System.out.println("Left="+lst);
		
		if(left==size && lst<heap[left])
		{
		heap[ptr]=heap[left];
		//System.out.println("Left="+left);
		ptr=left;
		no_of_comp++;
		}
		heap[ptr]=lst;
		no_of_comp++;
	return item;
	}

}
class heap_Sort_main
{
	static Scanner sc=new Scanner(System.in);
		public static void main(String[] args)
		{
		int ch;
		System.out.println("\n****MENU****\n1)Give the array Manually\n2)Take the array Randomly\n");
		ch=sc.nextInt();
		Heap_Sort hp=new Heap_Sort();
			switch(ch)
			{
			case 1:
			int size,i=1,n=0,j=1;
			System.out.println("Enter the number of elements of the array\n");
			size=sc.nextInt();
			int[] arr=new int[size+1];
			System.out.println("Enter the elements of the array\n");
				while(i<=size)
				{
				arr[i]=sc.nextInt();
				hp.insert_heap(arr[i],i);
				i++;
				}
				//hp.display();
				System.out.println("Sorted Array is:");
				while(j<=size)
				{
				System.out.print(hp.del_heap()+" ");
				j++;
				}
				System.out.println("\nNo. of comparisons="+hp.no_of_comp);
			break;
			case 2:
			Random rc=new Random();
	int size1=100;
	while(size1<=1000)
	{
			int arr1[]=new int[size1];
			for(int k=0;k<size1;k++)
			{
			arr1[k]=rc.nextInt(size1);
			hp.insert_heap(arr1[k],k);
			}
			int arr2[]=new int[size1];
			for(int r=0;r<size1;r++)
			{
			arr2[r]=hp.del_heap();
			}
			System.out.println("No. of comparisons when array size is "+size1+" ="+hp.no_of_comp+"\n");
		size1+=100;
	}
			break;
			}
		}

}