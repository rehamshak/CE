
import javax.swing.JFrame;
import javax.swing.JOptionPane;
public class ModernClocktest {

	
	public static void main(String[] args) {
		JOptionPane.showMessageDialog(null, "Welcome to the Modern Clock!\n This program will allow you view the currently set date and time,and set the clock to a new date and time.\n Click the set button to be prompted for a new date and time.\n Once you have finished entering the data, the new date and time will be displayed.\n");
		ModernClock modernclock=new ModernClock();
		modernclock.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		modernclock.setSize(270,110);
		modernclock.setVisible(true);

	}

}
