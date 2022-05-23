package chat;

import java.io.*;
import java.net.*;

public class client1 {

	public static void main(String[] args) throws UnknownHostException, IOException {
        Socket s = new Socket("Localhost", 777);
        System.out.println("Client Started");
        // Take input from user
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // To send the msg to server
        DataOutputStream d = new DataOutputStream(s.getOutputStream());
        // To receive msg from server
        BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

        String msg, msg1;
        while (!(msg = br.readLine()).equals("exit")) {
            // send to server
            d.writeUTF(msg);
            msg1 = br1.readLine();
            System.out.println("Server Message is : " + msg1);
        }
        s.close();
        br1.close();
        br.close();
        d.close();
    }
}