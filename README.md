📄 SuperCool Text Formatter

A simple cross-platform text formatter written in C++ that lets you create styled text documents interactively and export them to a beautiful HTML file.

This project runs easily on OnlineGDB or any local C++ compiler.

✨ Features

📝 Interactive Paragraph Input – type text and format it as you go.

🔤 Font Styling – Bold, Italic, Underline, Strike-through.

🎨 Custom Colors – pick named colors (red, blue, etc.) or hex (#ff5733).

↔️ Alignment Options – left, center, right, justify.

🔠 Font Size Control – set size per paragraph.

👤 Metadata – Title, Author, Creation Date automatically added.

🌐 HTML Export – outputs a neat output.html file viewable in browsers.

🚀 Getting Started
1. Run Online (Recommended)

Go to OnlineGDB
.

Paste the code from main.cpp.

Click Run.

Enter your text and formatting options.

When finished, type exit.

Open the Files tab in OnlineGDB → download output.html.

Open in your browser 🎉.

2. Run Locally (Optional)
Requirements

A C++ compiler (g++, clang, or MSVC`).

Steps
g++ main.cpp -o formatter
./formatter

🖥️ Example Session
=== SuperCool Text Formatter ===
Enter document title: My Notes
Enter author name: Alex

Enter text (or type 'exit' to finish): Hello World!
Bold? (y/n): y
Italic? (y/n): n
Underline? (y/n): y
Strike-through? (y/n): n
Font Size (default 12): 20
Alignment (left/center/right/justify): center
Text Color (e.g. red, blue, green, #hex): blue
✅ Paragraph added!

Enter text (or type 'exit' to finish): exit


👉 Exports output.html:

<h1 style='text-align:center;'>My Notes</h1>
<p style='text-align:center; font-size:20px; color:blue; font-weight:bold; text-decoration:underline;'>
Hello World!
</p>

📂 Project Structure
.
├── main.cpp      # Source code
├── README.md     # Documentation
└── output.html   # Generated after export

🔮 Future Enhancements

Console preview with colors before export.

Support for lists (ordered/unordered).

Export to Markdown and PDF.

Save/load previous documents.