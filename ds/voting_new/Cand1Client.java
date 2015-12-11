import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;
import java.rmi.*;
import java.rmi.registry.*;

public class Cand1Client extends Applet implements ActionListener {
	public Button btn;
	public TextField txtDisp;

	public void init() {
		setLayout(new FlowLayout());
		setBackground(Color.lightGray);
		btn = new Button("Vote");
		add(btn);
		btn.addActionListener(this);
		txtDisp = new TextField(30);
		txtDisp.setEditable(false);
		add(txtDisp);
	}

	public void actionPerformed(ActionEvent ae) {
		VoteInterface vobj;
		try {
			Registry r1 = LocateRegistry.getRegistry("localhost", 49101);
			vobj = (VoteInterface)r1.lookup("Candidate2_Server");
			vobj.castVote(2);
			txtDisp.setText("Vote kar diya!");
			repaint();
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}
}
