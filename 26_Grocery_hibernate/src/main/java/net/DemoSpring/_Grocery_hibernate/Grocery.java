package net.DemoSpring._Grocery_hibernate;

import javax.persistence.*;

@Entity
public class Grocery {

	@Id
	private int product_id;
	private String product_name,category;
	private long price_per_quantity;
	private long total_quantity,quantity_sold,quantity_left,total_price,total_sales;
	
	public Grocery(int product_id, String product_name, String category, long price_per_quantity, long total_quantity,
			long quantity_sold, long quantity_left, long total_price, long total_sales) {
		super();
		this.product_id = product_id;
		this.product_name = product_name;
		this.category = category;
		this.price_per_quantity = price_per_quantity;
		this.total_quantity = total_quantity;
		this.quantity_sold = quantity_sold;
		this.quantity_left = quantity_left;
		this.total_price = total_price;
		this.total_sales = total_sales;
	}

	
	public Grocery() {
		// TODO Auto-generated constructor stub
	}


	public int getProduct_id() {
		return product_id;
	}


	public void setProduct_id(int product_id) {
		this.product_id = product_id;
	}


	public String getProduct_name() {
		return product_name;
	}


	public void setProduct_name(String product_name) {
		this.product_name = product_name;
	}


	public String getCategory() {
		return category;
	}


	public void setCategory(String category) {
		this.category = category;
	}


	public long getPrice_per_quantity() {
		return price_per_quantity;
	}


	public void setPrice_per_quantity(long price_per_quantity) {
		this.price_per_quantity = price_per_quantity;
	}


	public long getTotal_quantity() {
		return total_quantity;
	}


	public void setTotal_quantity(long total_quantity) {
		this.total_quantity = total_quantity;
	}


	public long getQuantity_sold() {
		return quantity_sold;
	}


	public void setQuantity_sold(long quantity_sold) {
		this.quantity_sold = quantity_sold;
	}


	public long getQuantity_left() {
		return quantity_left;
	}


	public void setQuantity_left(long quantity_left) {
		this.quantity_left = quantity_left;
	}


	public long getTotal_price() {
		return total_price;
	}


	public void setTotal_price(long total_price) {
		this.total_price = total_price;
	}


	public long getTotal_sales() {
		return total_sales;
	}


	public void setTotal_sales(long total_sales) {
		this.total_sales = total_sales;
	}
	

}
