import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.util.Date;

public class FileServer extends UnicastRemoteObject implements FileServerInterface {

	protected FileServer() throws RemoteException {
		super();
	}

	public String getString() throws RemoteException {
		String s1;
		s1 = "Hello World!";
		System.out.println("In Remote");
		return s1;
	}

	public static void main(String a[]) {
		try {
			FileServer obj = new FileServer();
			Registry r1 = LocateRegistry.createRegistry(49111);
			r1.rebind("FileServer", obj);
		} catch (Exception e) {	
			System.out.println("Error");
		}
	}
}
