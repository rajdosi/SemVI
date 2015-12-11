import java.rmi.*;

public interface TimeServerInterface extends Remote {
	String getTime() throws RemoteException;
}
