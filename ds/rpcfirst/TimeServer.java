import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.util.Date;

public class TimeServer extends UnicastRemoteObject implements TimeServerInterface {
	public String getTime() {
		Date d = new Date();
		String s1;
		s1 = d.toString();
		System.out.println("in remote function");
		return s1;
	}
	public TimeServer() throws RemoteException {
		super();
	}
	public static void main(String a[]) {
		try {
			TimeServer obj = new TimeServer();
			Registry r1 = LocateRegistry.createRegistry(49111);
			r1.rebind("TimeService", obj);
		} catch (Exception e) {
			System.out.println("Error");
		}
	}
}
