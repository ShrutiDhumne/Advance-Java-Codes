
import java.util.concurrent.*;
class Runable implements Runnable{
	public String name;
	public Runable (String temp){
		name=temp;
	}
	@Override
	public void run() {
		System.out.println("Thread "+Thread.currentThread().getId()+" Started to execute "+name);
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("Thread "+Thread.currentThread().getId()+" Stopped");
	}
	
}
public class ThreadPool {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ExecutorService ex = Executors.newFixedThreadPool(2);
		for (int i=0;i<10;i++){
		Runnable r = new Runable("MyJob_"+i); //MyJob_0
		ex.execute(r);
		}
		ex.shutdown();

	}

}
