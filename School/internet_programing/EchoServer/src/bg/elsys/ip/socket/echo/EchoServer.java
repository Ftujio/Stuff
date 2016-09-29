package bg.elsys.ip.socket.echo;

import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class EchoServer {
	public static final int PORT = 31114;
	public static void main(String[] args) throws IOException {
		try(ServerSocket serverSocket = new ServerSocket(PORT)){
			Socket clientSocket = serverSocket.accept();
			PrintStream out = new PrintStream(clientSocket.getOutputStream());
			Scanner in = new Scanner(clientSocket.getInputStream());
			
			String inputLine;
			while((inputLine = in.nextLine()) != null){
				out.println("Recieved: " + inputLine);
			}
		}
	}
}
