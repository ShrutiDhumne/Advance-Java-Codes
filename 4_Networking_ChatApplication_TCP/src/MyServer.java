import java.io.*;  
import java.net.*;
import java.util.Scanner;  
public class MyServer {  
	public static void main(String[] args){  
		try{  
			ServerSocket ss=new ServerSocket(6666);  
			Socket s=ss.accept();//establishes connection   
			DataInputStream dis=new DataInputStream(s.getInputStream());  
			String  str=(String)dis.readUTF(); 
			System.out.println("Message from Client --> "+str);
			DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter msg for Client --> ");
			String str1 = sc.nextLine();
			dout.writeUTF(str1);
			
			//System.out.println("message= "+str);  
			ss.close();  
		}catch(Exception e){System.out.println(e);}  
	}  
}  