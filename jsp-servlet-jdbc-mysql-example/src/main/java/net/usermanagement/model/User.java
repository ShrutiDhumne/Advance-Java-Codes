package net.usermanagement.model;

public class User {
	
    protected int id;
    protected String name;
    protected String city;
    protected String blood_group;
    protected String address;
    protected int phno;
    
    
    
	public User() {
		super();
		// TODO Auto-generated constructor stub
	}
    
 
	public User(int id, String name, String city, String blood_group,int phno,String address) {
		super();
		this.id = id;
		this.name = name;
		this.city = city;
		this.blood_group = blood_group;
		this.phno = phno;
		this.address = address;
	}
	
	
	public User( String name, String city, String blood_group,int phno,String address) {
		super();
		this.name = name;
		this.city = city;
		this.blood_group = blood_group;
		this.phno = phno;
		this.address = address;
	}


	public int getId() {
		return id;
	}


	public void setId(int id) {
		this.id = id;
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public String getCity() {
		return city;
	}


	public void setCity(String city) {
		this.city = city;
	}


	public String getBlood_group() {
		return blood_group;
	}


	public void setBlood_group(String blood_group) {
		this.blood_group = blood_group;
	}


	public String getAddress() {
		return address;
	}


	public void setAddress(String address) {
		this.address = address;
	}


	public int getPhno() {
		return phno;
	}


	public void setPhno(int phno) {
		this.phno = phno;
	}


	
    
    
    
	
	

}
