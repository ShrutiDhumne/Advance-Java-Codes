package controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HomeController {
	
	@RequestMapping ("/home")
	public String home() {
		return "index";
	}
	
	@RequestMapping ("/hello")
	public String hello(@RequestParam("username") String name, @RequestParam("password") String pass, Model m) {
		System.out.println("hello world");
		if (name.equals("abhi") && pass.equals("abhi")) {
			return "index2";
		}
		else {
			return "index";
		}
	}
}

