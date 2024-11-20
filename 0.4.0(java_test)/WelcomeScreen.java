import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WelcomeScreen extends JFrame {

    public WelcomeScreen() {
        setTitle("Welcome");
        setSize(800, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JLabel welcomeLabel = new JLabel("Welcome to Text Search App", SwingConstants.CENTER);
        welcomeLabel.setFont(new Font("Arial", Font.BOLD, 48));

        JButton continueButton = new JButton("Continue");
        continueButton.setPreferredSize(new Dimension(100, 30));
        continueButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                onContinueButtonClicked();
            }
        });

        JLabel madeByLabel = new JLabel("made by 252", SwingConstants.CENTER);
        madeByLabel.setFont(new Font("Arial", Font.PLAIN, 12));

        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(welcomeLabel, BorderLayout.CENTER);
        panel.add(continueButton, BorderLayout.SOUTH);
        panel.add(madeByLabel, BorderLayout.NORTH);

        add(panel);
    }

    private void onContinueButtonClicked() {
        // 关闭欢迎界面并打开主程序
        dispose();
        new TextSearchApp().setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new WelcomeScreen().setVisible(true);
            }
        });
    }
}