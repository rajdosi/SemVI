import java.rmi.*;

public interface fileserverinterface extends Remote

{ String readit(int off,int numbytes) throws RemoteException; }
