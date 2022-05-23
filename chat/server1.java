package chat;

import java.io.*;
import java.net.*;




public class server1 {

	public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(777);
        System.out.println("Server Started");
        Socket s = ss.accept();
        // To take input from keyboard
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // To take client msg
        DataInputStream din = new DataInputStream(s.getInputStream());

        // To send the msg to client

        PrintStream ps = new PrintStream(s.getOutputStream());

        while (true) {

            String msg, msg1;// msg store client msg and msg1 store server msg

            while ((msg = (String) din.readUTF()) != "null") {
                System.out.println("Message From client is : " + msg);
                msg1 = br.readLine();

                ps.println(msg1);// send to client

            }

            System.exit(0);
            
        }
        
    }
}