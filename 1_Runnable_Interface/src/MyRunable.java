
class Runable implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		//Thread.yield();
//		 try {
//             // thread to sleep for 1000 milliseconds
//             //Thread.sleep(1000);
//			 
//         }
//         catch (Exception e) {
//             System.out.println(e);
//         }
		for(int i=0;i<=50;i++) {
			System.out.println("@clild thread"+i);
		}
	}
	
}
public class MyRunable {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		Runable r = new Runable();
		Thread t = new Thread(r);
		t.start();
		System.out.println("Is alive? " + t.isAlive());
		t.join(10000);
		System.out.println("Is alive? " + t.isAlive());
	
		for(int i=0;i<5;i++){
			System.out.println("#ParentThread"+i);
		}
	}	

}
