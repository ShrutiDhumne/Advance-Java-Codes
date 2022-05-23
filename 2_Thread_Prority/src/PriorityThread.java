
class Threadclass extends Thread{

	@Override
	public void run() {	 
		System.out.println("Child Thread --> "+Thread.currentThread().getPriority()+" "+Thread.currentThread().getName());
	}
	
}
public class PriorityThread {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Threadclass t= new Threadclass();
		Thread t1 = new Thread(t);
		Thread t2 = new Thread(t);
		Thread t3 = new Thread(t);
		
		t1.setPriority(10);
		t2.setPriority(2);
		t3.setPriority(5);
		t1.setName("Shruti");
		t1.start();
		t2.start();
		t3.start();
		
		//System.out.println("Currently Executing The Thread : " + Thread.currentThread().getName());  
		//System.out.println("Parent Thread --> "+Thread.currentThread().getPriority());
		
	}

}
