package com.cookies;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.*;  

public class Cookies extends HttpServlet{

	 public void doGet(HttpServletRequest request, HttpServletResponse response){  
		    try{  
		  
		    response.setContentType("text/html");
		    
		    PrintWriter out = response.getWriter(); 
		    out.print("<link rel=\'stylesheet\' href=\'https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css\'>");
			out.print("<div style=\"text-align: center;\">");
		    out.print("<form><h1> Cookies </h1><br>"+
		    "<label>Enter Cookie Name : </label><input type='text' name='name'><br>"+
		    "<label>Enter Cookie Value : </label><input type='text' name='value'><br>"+
		    "<input type='submit'><br></form>");      
		    String n=request.getParameter("name");
		    String v = request.getParameter("value");
		    
		  
		    Cookie ck=new Cookie(n,v);//creating cookie object  
		    response.addCookie(ck);//adding cookie in the response  
		    
		    
		  
		    //creating submit button  
		    out.print("<h3>Cookie created for "+ck.getName()+" and value is "+ck.getValue()+"<h3><br>");  
		    ck=new Cookie(n,"");
		          
		    out.print("<h3>Cookie deleted for "+ck.getName()+" and value is "+ck.getValue()+"<h3>");  
		    out.close();  
		  
		        }catch(Exception e){System.out.println(e);}  
		  }  
	

}
