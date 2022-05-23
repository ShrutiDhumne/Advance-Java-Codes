package net.DemoSpring._Grocery_hibernate;

import java.util.List;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.hibernate.query.Query;



/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        System.out.println( "Hello World!" );
        SessionFactory f= new Configuration().configure().buildSessionFactory();
        
        System.out.println(f);
        
//        Grocery g = new Grocery();
//        g.setProduct_id(1);
//        g.setCategory("Cloth");
//        g.setPrice_per_quantity(1100);
//        g.setProduct_name("Kurti");
//        g.setQuantity_left(30);
//        g.setQuantity_sold(30);
//        g.setTotal_price(20000);
//        g.setTotal_quantity(60);
//        g.setTotal_sales(600000);
//        
//        Session session= f.openSession();
//        session.beginTransaction();
//        session.save(g);
//        session.getTransaction().commit();
//        session.close();
//        
//        
//        Grocery g1 = new Grocery();
//        g1.setProduct_id(2);
//        g1.setCategory("food");
//        g1.setPrice_per_quantity(1100);
//        g1.setProduct_name("rice");
//        g1.setQuantity_left(30);
//        g1.setQuantity_sold(30);
//        g1.setTotal_price(20000);
//        g1.setTotal_quantity(60);
//        g1.setTotal_sales(2000);
//        
//        
//        session = f.openSession();
//        session.beginTransaction();
//        session.save(g1);
//        session.getTransaction().commit();
//        session.close();
//        
//     
        //Select Query//
		  
		  Session session= f.openSession();
		  String selectQuery = "from Grocery G where G.total_sales > 50000";
		  
		  Query q1 = session.createQuery(selectQuery);
		  
		  //List Multiple rec
		  List <Grocery> l = q1.list();
		  
		  for(Grocery g2:l)
		  {
			  System.out.println(g2.getProduct_id()+" : "+g2.getProduct_name()+" : "+g2.getTotal_sales());
		  }
        
        
    }
}
