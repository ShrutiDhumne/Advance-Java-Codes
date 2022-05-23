package com.spring._41_42_Grocery_SpringORM1.dao;



import java.util.List;

import org.springframework.orm.hibernate5.HibernateTemplate;
import org.springframework.transaction.annotation.Transactional;

import com.spring._41_42_Grocery_SpringORM1.entity.Grocery;





public class GroceryDao {
	public HibernateTemplate hibernateTemplate;
	public GroceryDao() {
		// TODO Auto-generated constructor stub
	}
	
	@Transactional
	public int insert(Grocery g)
	{
		Integer r = (Integer)hibernateTemplate.save(g);
		return r;
	}
	
	public Grocery getStudent(int studid)
	{
		Grocery student = this.hibernateTemplate.get(Grocery.class, studid);
		return student;
		
	}
	
	public List<Grocery> getAllStudent()
	{
		List<Grocery> allstud= this.hibernateTemplate.loadAll(Grocery.class);
		return allstud;
	}
	
	@Transactional
	public void deleteStudent(int studid)
	{
		Grocery delstudent = this.hibernateTemplate.get(Grocery.class, studid);
		this.hibernateTemplate.delete(delstudent);
	}
	
	@Transactional
	public void updateStudent(int id, String n , String c , String p  )
	{
		Grocery upst = this.hibernateTemplate.get(Grocery.class, id);
		
		upst.setId(id);
		upst.setCategory(c);
		upst.setName(n);
		upst.setPrice(p);
		
		this.hibernateTemplate.update(upst);
		
	}


	public HibernateTemplate getHibernateTemplate() {
		return hibernateTemplate;
	}

	public void setHibernateTemplate(HibernateTemplate hibernateTemplate) {
		this.hibernateTemplate = hibernateTemplate;
	}

}
