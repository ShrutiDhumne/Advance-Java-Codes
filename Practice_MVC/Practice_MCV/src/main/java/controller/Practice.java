package controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class Practice {
	
	@RequestMapping("/home")
	public String home() {
		return "index";
	}
	
	@RequestMapping("/home/next")
	public String next() {
		return "success";
	}

}
