package net.DemoSpring._30_Banking_Hiberante;

import java.util.Date;

import javax.persistence.*;

@Entity
public class Banking {

	@Id
	private int account_no;
	private String account_holder_name,branch , address;
	private long balance_amount,loan_santioned;
	private Date date_of_opening;
	
	
	public Banking() {
		// TODO Auto-generated constructor stub
	}


	public Banking(int account_no, String account_holder_name, String branch, String address, long balance_amount,
			long loan_santioned, Date date_of_opening) {
		super();
		this.account_no = account_no;
		this.account_holder_name = account_holder_name;
		this.branch = branch;
		this.address = address;
		this.balance_amount = balance_amount;
		this.loan_santioned = loan_santioned;
		this.date_of_opening = date_of_opening;
	}


	public int getAccount_no() {
		return account_no;
	}


	public void setAccount_no(int account_no) {
		this.account_no = account_no;
	}


	public String getAccount_holder_name() {
		return account_holder_name;
	}


	public void setAccount_holder_name(String account_holder_name) {
		this.account_holder_name = account_holder_name;
	}


	public String getBranch() {
		return branch;
	}


	public void setBranch(String branch) {
		this.branch = branch;
	}


	public String getAddress() {
		return address;
	}


	public void setAddress(String address) {
		this.address = address;
	}


	public long getBalance_amount() {
		return balance_amount;
	}


	public void setBalance_amount(long balance_amount) {
		this.balance_amount = balance_amount;
	}


	public long getLoan_santioned() {
		return loan_santioned;
	}


	public void setLoan_santioned(long loan_santioned) {
		this.loan_santioned = loan_santioned;
	}


	public Date getDate_of_opening() {
		return date_of_opening;
	}


	public void setDate_of_opening(Date date_of_opening) {
		this.date_of_opening = date_of_opening;
	}
	
	

}
