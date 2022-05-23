package com.spring._41_42_Grocery_SpringORM1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.spring._41_42_Grocery_SpringORM1.dao.GroceryDao;
import com.spring._41_42_Grocery_SpringORM1.entity.Grocery;



/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) throws IOException
    {
        System.out.println( "Hello World!" );
        ApplicationContext context= new ClassPathXmlApplicationContext("config.xml");
        GroceryDao d= context.getBean("grocerydao",GroceryDao.class);
        
        
//        Grocery g = new Grocery(1,"bhv","bdjk","11");
//        System.out.print("Records inserted "+d.insert(g));
        
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String ans;
        
        do
        {
        
        	System.out.println("1- Insert a record");
        	System.out.println("2- View a record");
        	System.out.println("3- View all record");
        	System.out.println("4- Delete a record");
        	System.out.println("5- Update a record");
        	System.out.println("6- Exit");
         	
        	try
        	{
        		Integer ch=Integer.parseInt(br.readLine());
        		
        		
        		switch(ch)
        		{
        		case 1://insert 
        			
        			System.out.println("Enter Id->");
        			Integer uid=Integer.parseInt(br.readLine());
        			
        			System.out.println("Enter Name->");
        			String uname=br.readLine();
        			
        			System.out.println("Enter category->");
        			String uclass=br.readLine();
        			
        			System.out.println("Enter price->");
        			String b=br.readLine();
        		      	
        			
        			Grocery insertst= new Grocery(uid,uname,uclass,b);
        			
        			int i= d.insert(insertst);
        		    System.out.println("Record inserted.."+i);
        			
        			break;
        			
        		case 2://view a record
        			
        			System.out.println("Eneter Student Id ->");
        			Integer id=Integer.parseInt(br.readLine());
        			
        			Grocery viewst=d.getStudent(id);
        			
        			System.out.println(" Details are--->");
         			System.out.println("Id->"+viewst.getId());
         			System.out.println("Name->"+viewst.getName());
         			System.out.println("category->"+viewst.getCategory());
         			System.out.println("price->"+viewst.getPrice());
         		//	System.out.println("Email->"+viewst.getEmail());
   
        			break;
        			
        		case 3://view all record
        			List<Grocery> viewall=d.getAllStudent();
        			System.out.println("Students Details are--->");
        			for(Grocery rec:viewall)
        			{
        				System.out.println(" )__())");
             			System.out.println("Id->"+rec.getId());
             			System.out.println("Name->"+rec.getName());
             			System.out.println("category->"+rec.getCategory());
             			System.out.println("price->"+rec.getPrice());
        			}
        			break;
        			
        		case 4://delete
        			System.out.println("Eneter  Id ->");
        			Integer userid=Integer.parseInt(br.readLine());
        			d.deleteStudent(userid);
        			break;
        			
        		case 5://update
        			System.out.println("Enter which record ID do you want to update-> ");
        			Integer useid=Integer.parseInt(br.readLine());
        			
        			System.out.println("Enter Updated  Name->");
        			String name=br.readLine();
        			
        			System.out.println("Enter Updated Category->");
        			String usclass=br.readLine();
        			
        			System.out.println("Enter Updated price->");
        			String b1=br.readLine();
        			
        	
        
        			
        			d.updateStudent(useid, name, usclass,b1);
        			break;
        			
        		case 6:
        			System.exit(0);
        			break;
        			
        		default:
        			System.out.println("Enter valid Input");
        			break;
        		}
        	
        	}
        
        catch(Exception e)
       	{
       		System.out.println("Enter Correct Input");
       		System.out.println(e.getMessage());
       	}
        
        System.out.println("Do you want to continue ? (Y/N)");
    	ans=br.readLine();	
        }while(ans.equalsIgnoreCase("Y"));
        
    }
}
