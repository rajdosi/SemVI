import java.rmi.*;

public interface FileServerInterface extends Remote { 
	String getString() throws RemoteException;
}
