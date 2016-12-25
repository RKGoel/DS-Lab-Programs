import java.io.*;
import java.lang.*;

class binary
{
	public static void main (String args[]) throws IOException
	{
		int size;
		
		InputStreamReader read = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(read);
		
		System.out.println("Enter number of nos. in the list: ");
		size = Integer.parseInt(in.readLine());
		
		int list[] = new int[size];
		int element, index = -1, i;
		char ch = 'y';
		System.out.println("Enter nos. of the list in sorted manner");
		for(i=0;i<size;i++)
		{
			list[i] = Integer.parseInt(in.readLine());
		}
		
		
		
		
		while(ch== 'y' || ch== 'Y')
		{
			System.out.println("Enter element to be searched: ");
			element = Integer.parseInt(in.readLine());
			int lower = 0, upper = size-1, mid;
		
			do
			{
			mid = (lower+upper)/2;
			if(list[mid] == element)
			{
				index = mid;
				break;
			}

			else if(list[mid] > element)
			upper = mid-1;
			else if(list[mid] < element)
			lower = mid+1;
			}while(lower <= upper);
			
			if(lower > upper)
			index = -1;
		
			if(index == -1)
			System.out.println("Not Found!!");
			else
			System.out.println("Found at position "+(index+1));
			
			System.out.println("Do you want to search for another element? Y/N");
					ch = in.readLine().charAt(0);
		}
	}
	

}	
