import java.io.*;
import java.util.*;
import java.lang.*;

public class Hashing{
	
	public static void main(String args[]) throws IOException{
		
		int tablesize, recnum, i, j, key, address;
		
		InputStreamReader read = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(read);
		
		System.out.println("Enter the size of the table: ");
		tablesize = Integer.parseInt(in.readLine());
		int table[] = new int[tablesize];
		for(i=0;i<tablesize;i++)
			table[i] = -1;
			
		System.out.println("Enter the number of records: ");
		recnum = Integer.parseInt(in.readLine());
		if(recnum>tablesize){
			System.out.println("Error!! Number of records exceed memory locations.");
			System.exit(0);
			}
		
		System.out.println("Enter "+recnum+" keys: ");
		for(i=0;i<recnum;i++){
			key = Integer.parseInt(in.readLine());
			address = (key%tablesize);
			System.out.println("Hash Value= "+address);
			if(table[address]==-1)
				table[address] = key;
			else{
				System.out.print("Collision occured!!");
				j=1;
				int temp;
				do{
					temp = address;
					temp = temp+(j*j);
					while(temp>=tablesize)
					temp = temp-tablesize;
					j++;
				}while(table[temp]!=-1);
				System.out.println("\tNew Hash Value= "+temp);
				table[temp] = key;
				}
			}
			
		System.out.println("\nHash Map Table:");
		for(i=0;i<tablesize;i++){
			if(table[i]!=-1)
			System.out.println(i+" => "+table[i]);
			else
			System.out.println(i+" => -");
		}
	}
}