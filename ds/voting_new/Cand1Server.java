import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.io.IOException;

public class Cand1Server extends UnicastRemoteObject implements VoteInterface {
	public int numberOfVotes = 1;
	public int leader = 1;

	protected Cand1Server() throws RemoteException {
		super();
	}

	public void castVote(int candidate) throws RemoteException {
		this.numberOfVotes = 1;

		if (this.leader > candidate) {
			this.leader = candidate;
		}

		System.out.println("Current Leader : 1");
	}

	public static void main(String args[]) {
		try {
			Cand1Server candidate1 = new Cand1Server();
			Registry r1 = LocateRegistry.createRegistry(49102);
			r1.rebind("Candidate1_Server", candidate1);
		} catch (Exception e) {
			System.out.println("Error creating server");
		}
	}
}
