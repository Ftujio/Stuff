package bg.elsys.ip.socket.echo;

import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class EchoServer {
	
	public static final int PORT = 31114;

	public static void main(String[] args) throws IOException {
		/*
		 * Try with resources to open the socket and get the input and output
		 * streams of the socket.
		 */
		try (ServerSocket serverSocket = new ServerSocket(PORT);
				Socket clientSocket = serverSocket.accept();
				PrintStream out = new PrintStream(clientSocket.getOutputStream());
				Scanner in = new Scanner(clientSocket.getInputStream())) {
			String inputLine;
			/*
			 * While there is incoming content, we send it back as output.
			 */
			while ((inputLine = in.nextLine()) != null) {
				out.println("Received: " + inputLine);
			}
		}
	}
}
