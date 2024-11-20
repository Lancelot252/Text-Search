import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class TextSearchApp extends JFrame {

    private JTextField keywordField;
    private JTextArea originalTextArea;
    private JTextArea resultArea;
    private TextSearch textSearch;

    public TextSearchApp() {
        textSearch = new TextSearch();

        setTitle("Text Search App");
        setSize(1280, 720); // 设置窗口大小
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        keywordField = new JTextField(20);
        JButton searchButton = new JButton("Search");
        searchButton.setPreferredSize(new Dimension(80, 30)); // 设置按钮大小

        originalTextArea = new JTextArea();
        originalTextArea.setEditable(false);
        resultArea = new JTextArea();
        resultArea.setEditable(false);

        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                onSearchButtonClicked();
            }
        });

        JPanel topPanel = new JPanel();
        topPanel.setLayout(new BorderLayout());
        topPanel.add(keywordField, BorderLayout.CENTER);
        topPanel.add(searchButton, BorderLayout.EAST);

        JPanel textPanel = new JPanel();
        textPanel.setLayout(new GridLayout(1, 2)); // 左右分布
        textPanel.add(new JScrollPane(originalTextArea));
        textPanel.add(new JScrollPane(resultArea));

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());
        mainPanel.add(topPanel, BorderLayout.NORTH);
        mainPanel.add(textPanel, BorderLayout.CENTER);

        add(mainPanel);

        // 加载并显示原文
        loadAndDisplayOriginalText();
    }

    private void loadAndDisplayOriginalText() {
        String filePath = "D:/project/github/Text-Search/0.4.0(java_test)/text.txt"; // 请替换为你的文件路径
        String text = textSearch.loadTextFromFile(filePath);
        if (text.isEmpty()) {
            originalTextArea.setText("Failed to open " + filePath);
        } else {
            List<String> sentences = textSearch.splitIntoSentences(text);
            StringBuilder formattedText = new StringBuilder();
            for (String sentence : sentences) {
                formattedText.append(sentence).append("\n");
            }
            originalTextArea.setText(formattedText.toString());
        }
    }

    private void onSearchButtonClicked() {
        String keyword = keywordField.getText();
        if (keyword.isEmpty()) {
            return;
        }

        String filePath = "D:/project/github/Text-Search/0.4.0(java_test)/text.txt"; // 请替换为你的文件路径
        String text = textSearch.loadTextFromFile(filePath);
        if (text.isEmpty()) {
            resultArea.setText("Failed to open " + filePath);
            return;
        }

        List<String> sentences = textSearch.splitIntoSentences(text);
        Map<String, Set<String>> hashTable = textSearch.buildHashTable(sentences);
        Set<String> results = textSearch.searchKeyword(hashTable, keyword);

        StringBuilder resultText = new StringBuilder();
        for (String sentence : results) {
            resultText.append(sentence).append("\n");
        }

        if (resultText.length() == 0) {
            resultText.append("No sentences found containing the keyword: ").append(keyword);
        }

        resultArea.setText(resultText.toString());
    }
}