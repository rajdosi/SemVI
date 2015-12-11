import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.util.Date;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class FileServer extends UnicastRemoteObject implements FileServerInterface {
	protected FileServer() throws RemoteException {
		super();
	}
	
	public String getString() throws RemoteException {
		String s1 = "";
		File file = new File("filetoread.txt");
		FileInputStream fis = null;
		
		try {
			fis = new FileInputStream(file);
			System.out.println("Total file size to read (in bytes) : " + fis.available());
			int content;
			while ((content = fis.read()) != -1) {
				s1 += (char)content;
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (fis != null)
					fis.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		return s1;
	}

	public static void main(String a[]) {
		try {
			FileServer obj = new FileServer();
			Registry r1 = LocateRegistry.createRegistry(49100);
			r1.rebind("Server", obj);
		} catch (Exception e) {
			System.out.println("Error");
		}
	}
}
