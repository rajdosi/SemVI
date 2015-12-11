import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.io.IOException;

public class Cand2Server extends UnicastRemoteObject implements VoteInterface {
	public int numberOfVotes = 1;
	public int leader = 2;

	protected Cand2Server() throws RemoteException {
		super();
	}

	public void castVote(int candidate) throws RemoteException {
		this.numberOfVotes = 1;

		if (this.leader > candidate) {
			this.leader = candidate;
		}

		System.out.println("Current Leader : 2");
	}

	public static void main(String args[]) {
		try {
			Cand1Server candidate2 = new Cand1Server();
			Registry r1 = LocateRegistry.createRegistry(49101);
			r1.rebind("Candidate2_Server", candidate2);
		} catch (Exception e) {
			System.out.println("Error creating server");
		}
	}
}
