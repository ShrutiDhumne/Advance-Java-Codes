package net.DemoSpring._30_Banking_Hiberante;

import java.util.Date;
import java.util.List;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
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
        
        System.out.print(f);
        
   Banking b = new Banking();
//        b.setAccount_no(11);
//        b.setAccount_holder_name("Aishwarya");
//        b.setAddress("Aurangabad");
//        b.setBalance_amount(30000);
//        b.setBranch("b1");
//       // b.setDate_of_opening(new Date(2020,2,2));
//        b.setLoan_santioned(7000);
//        
Session s =f.openSession();
//        s.beginTransaction();
//        s.save(b);
//        s.getTransaction().commit();
//        s.close();
        
        
 
//        b.setAccount_no(22);
//        b.setAccount_holder_name("Shruti");
//        b.setAddress("pune");
//        b.setBalance_amount(500000);
//        b.setBranch("b1");
//      //  b.setDate_of_opening(new Date(2020,2,2));
//        b.setLoan_santioned(7000);
//        
//       Session  s =f.openSession();
//        s.beginTransaction();
//        s.save(b);
//        s.getTransaction().commit();
//        s.close();
//        
//       
//        b.setAccount_no(121);
//        b.setAccount_holder_name("Bhakti");
//        b.setAddress("Aurangabad");
//        b.setBalance_amount(400000);
//        b.setBranch("b1");
//      //  b.setDate_of_opening(new Date(2020,2,2));
//        b.setLoan_santioned(500000000);
//        
//        s =f.openSession();
//        s.beginTransaction();
//        s.save(b);
//        s.getTransaction().commit();
//        
//        s.close();
//        
        
        String select="from Banking b where b.balance_amount>50000";
        
        Query q = s.createQuery(select);
        
        List <Banking> l = q.list();
        
        for(Banking b1 : l)
        {
        //System.out.print(b1.getAccount_no()+" : "+b1.getAccount_holder_name()+" : "+b1.getBalance_amount());
        }
        
        
        select="from Banking b where b.loan_santioned >100000";
        
         q = s.createQuery(select);
        
        l = q.list();
        
        for(Banking b1 : l)
        {
        	//System.out.print(b1.getAccount_no()+" : "+b1.getAccount_holder_name()+" : "+b1.getLoan_santioned());
        }
//        
        
        select="select max(loan_santioned) from Banking";
        
        q = s.createQuery(select);
       
       l = q.list();
       System.out.print(l);

       
       select="from Banking b where b.loan_santioned = "+l.get(0);
       
       q = s.createQuery(select);
      
      l = q.list();
      
      for(Banking b1 : l)
      {
      	System.out.print(b1.getAccount_no()+" : "+b1.getAccount_holder_name()+" : "+b1.getLoan_santioned());
      }
      
      Transaction tx1= s.beginTransaction();
      String delete ="delete from Banking where account_no = 11";
      q=s.createQuery(delete);
      
      int r=q.executeUpdate();
      tx1.commit();
      
      System.out.print(r+" Records Deleted");
      
      
      tx1= s.beginTransaction();
      delete ="delete from Banking where account_no = :x";
      q=s.createQuery(delete);
      
      q.setParameter("x",22);
      r=q.executeUpdate();
      tx1.commit();
      
      System.out.print(r+" Records Deleted");
     
    }
}
