package bg.elsys.ip.socket.echo;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class EchoClient {
	private static final String HOST_NAME = "localhost";
	private static final int PORT = 31114;

	public static void main(String[] args) throws UnknownHostException, IOException {
		try(Socket echoSocket = new Socket(HOST_NAME, PORT)){
			PrintStream out = new PrintStream(echoSocket.getOutputStream());
			Scanner in = new Scanner(echoSocket.getInputStream());
			Scanner stdIn = new Scanner(System.in);
			
			String userInput;
			while((userInput = stdIn.nextLine()) != null){
				out.println(userInput);
				System.out.println("Echo: " + in.nextLine());
			}
		}
	}

}
