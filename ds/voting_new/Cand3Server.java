import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.io.IOException;

public class Cand3Server extends UnicastRemoteObject implements VoteInterface {
	public int numberOfVotes = 1;
	public int leader = 3;

	protected Cand3Server() throws RemoteException {
		super();
	}

	public void castVote(int candidate) throws RemoteException {
		this.numberOfVotes = 1;

		if (this.leader > candidate) {
			this.leader = candidate;
		}

		System.out.println("Current Leader : 3");
	}

	public static void main(String args[]) {
		try {
			Cand1Server candidate3 = new Cand1Server();
			Registry r1 = LocateRegistry.createRegistry(49100);
			r1.rebind("Candidate3_Server", candidate3);
		} catch (Exception e) {
			System.out.println("Error creating server");
		}
	}
}
