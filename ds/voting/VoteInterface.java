import java.rmi.*;

public interface VoteInterface extends Remote {
	void castVote(int candidate) throws RemoteException;
}
