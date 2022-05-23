package com.spring._41_42_Grocery_SpringORM1.entity;

import javax.persistence.*;

@Entity
public class Grocery {

	@Id
	private int id;
	private String name,category,price;
	
	public Grocery() {
		// TODO Auto-generated constructor stub
	}

	public Grocery(int id, String name, String category, String price) {
		super();
		this.id = id;
		this.name = name;
		this.category = category;
		this.price = price;
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

	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}

	public String getPrice() {
		return price;
	}

	public void setPrice(String price) {
		this.price = price;
	}

}
