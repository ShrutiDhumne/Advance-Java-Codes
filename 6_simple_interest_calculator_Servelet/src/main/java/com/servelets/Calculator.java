package com.servelets;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.*;

public class Calculator implements Servlet{

		ServletConfig conf;
		public void init(ServletConfig conf) {
			this.conf = conf;
			System.out.println("Creating Object ...");
			
		}

		
		public void destroy() {
			System.out.println("Servlets is Destroyed ....");
		}
		public ServletConfig getServletConfig() {
			return this.conf;
		}
		
		public String getServletInfo() {
			return "Servlets  by Shruti";
		}
		@Override
		public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
			System.out.println("Servlet Running........");
			res.setContentType("text/html");
			PrintWriter out=res.getWriter();
			out.print("<link rel=\'stylesheet\' href=\'https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css\'>");
			out.print("<div style=\"text-align: center;\">");
			out.print("<h2>Simple Interest Calculator</h2>");
			out.print("<h6>Date:"+java.time.LocalDate.now()+"		Time:"+java.time.LocalTime.now()+" </h6>");
			out.print("<div style=\"width: 50%; margin:auto\">");
			out.print("<form><table><tr><td>Principal:</td>"+
						"<td><input type='text' name='principal'></td></tr>"
					+ "<tr><td>Rate:</td><td><input type='text' name='rate'></td></tr>"
					+ "<tr><td>Time(years):</td><td><input type='number' name='time'></td></tr>"
					+ "<tr><td colspan='2' style='text-align:center'><input class='waves-effect waves-light btn' type='submit' value='Submit'></td></tr></table></form>");
			out.print("</div>");
			float principal=Float.parseFloat(req.getParameter("principal"));
			float rate=Float.parseFloat(req.getParameter("rate"));
			float time=Float.parseFloat(req.getParameter("time"));
			
			float interest = principal*(1+rate*time);
			
			
			out.print("<h4> Simple Interest = "+ interest +"</h4>");
			out.print("</div>");
			out.close();
		}
}
