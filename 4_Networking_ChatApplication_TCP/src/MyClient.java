import java.io.*;  
import java.net.*;
import java.util.Scanner;  
public class MyClient {  
	public static void main(String[] args) {  
		try{      
				Socket s=new Socket("localhost",6666);  
				DataOutputStream dout=new DataOutputStream(s.getOutputStream()); 
				Scanner sc = new Scanner(System.in);
				System.out.println("Enter msg for Server --> ");
				String str1 = sc.nextLine();
				dout.writeUTF(str1); 
				
				DataInputStream dis=new DataInputStream(s.getInputStream());  
				String  str=(String)dis.readUTF();  
				System.out.println("Message from Server -->  "+str); 
				
				 
				dout.flush();  
				dout.close();  
				s.close();  
			}catch(Exception e){System.out.println(e);
			}  
	}  
} 