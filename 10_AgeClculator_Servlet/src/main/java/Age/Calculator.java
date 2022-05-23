package Age;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.util.Date;

import javax.servlet.ServletException;
//import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Calculator
 */
//@WebServlet("/Calculator")
public class Calculator extends HttpServlet {
	private static final long serialVersionUID = 1L;

    /**
     * Default constructor. 
     */
    public Calculator() {
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
		// TODO Auto-generated method stub
		res.setContentType("text/html");
		PrintWriter out=res.getWriter();
		
		out.print("<link rel=\'stylesheet\' href=\'https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css\'>");
		out.print("<div style=\"text-align: center;\">");
		out.print("<h2>Age Calculator</h2>");
		out.print("<h6>Date:"+java.time.LocalDate.now()+"		Time:"+java.time.LocalTime.now()+" </h6>");
		out.print("<div style=\"width: 50%; margin:auto\">");
		out.print("<form><table><tr><td>Name:</td>"+
					"<td><input type='text' name='Name'></td></tr>"
				+ "<tr><td>Age:</td><td><input type='date' name='date'></td></tr>"
				+ "<tr><td colspan='2' style='text-align:center'><input class='waves-effect waves-light btn' type='submit' value='Submit'></td></tr></table></form>");
		out.print("</div>");
		String name=req.getParameter("Name");
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		String date = req.getParameter("date");
		
		LocalDate dob = LocalDate.parse(date);
		
		//float time=Float.parseFloat(req.getParameter("time"));
		LocalDate present =java.time.LocalDate.now();
		int age = Period.between(dob, present).getYears();  ;
		
		
		out.print("<h4>"+ name +" your age is "+age+"</h4>");
		out.print("</div>");
		out.close();
		res.getWriter().append("Served at: ").append(req.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(req, res);
		
	}

}
