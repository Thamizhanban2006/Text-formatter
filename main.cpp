/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// ---------- TextStyle ----------
class TextStyle {
public:
    bool bold;
    bool italic;
    bool underline;
    bool strike;
    int fontSize;
    string alignment;
    string color;

    TextStyle(bool b=false, bool i=false, bool u=false, bool s=false,
              int size=12, string align="left", string col="black")
        : bold(b), italic(i), underline(u), strike(s),
          fontSize(size), alignment(align), color(col) {}
};

// ---------- Paragraph ----------
class Paragraph {
private:
    string text;
    TextStyle style;

public:
    Paragraph(const string &t, const TextStyle &s) : text(t), style(s) {}

    string getText() const { return text; }
    TextStyle getStyle() const { return style; }
};

// ---------- Document ----------
class Document {
private:
    vector<Paragraph> paragraphs;
    string title;
    string author;
    string createdAt;

public:
    Document(string t="Untitled", string a="Anonymous") : title(t), author(a) {
        time_t now = time(0);
        createdAt = ctime(&now);
    }

    void addParagraph(const Paragraph &p) {
        paragraphs.push_back(p);
    }

    const vector<Paragraph>& getParagraphs() const {
        return paragraphs;
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getCreatedAt() const { return createdAt; }
};

// ---------- Exporter (abstract) ----------
class Exporter {
public:
    virtual void exportDocument(const Document &doc, const string &filename) = 0;
    virtual ~Exporter() {}
};

// ---------- HTMLExporter ----------
class HTMLExporter : public Exporter {
public:
    void exportDocument(const Document &doc, const string &filename) override {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: could not write file '" << filename << "'\n";
            return;
        }

        file << "<!DOCTYPE html>\n<html>\n<head>\n<meta charset='UTF-8'>\n";
        file << "<title>" << doc.getTitle() << "</title>\n</head>\n<body>\n";

        file << "<h1 style='text-align:center;'>" << doc.getTitle() << "</h1>\n";
        file << "<p style='text-align:center; font-style:italic;'>By "
             << doc.getAuthor() << " | Created: " << doc.getCreatedAt() << "</p>\n<hr>\n";

        for (const auto &p : doc.getParagraphs()) {
            const TextStyle &s = p.getStyle();
            file << "<p style='text-align:" << s.alignment
                 << "; font-size:" << s.fontSize << "px; color:" << s.color << ";";

            if (s.bold) file << " font-weight:bold;";
            if (s.italic) file << " font-style:italic;";
            if (s.underline) file << " text-decoration:underline;";
            if (s.strike) file << " text-decoration:line-through;";

            file << "'>" << p.getText() << "</p>\n";
        }

        file << "</body>\n</html>";
        file.close();

        cout << "Exported '" << filename << "'\n";
    }
};

// ---------- Main ----------
int main() {
    string title, author;
    cout << "=== SuperCool Text Formatter ===\n";
    cout << "Enter document title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);

    Document doc(title, author);

    string text;
    char bold, italic, underline, strike;
    int fontSize;
    string alignment, color;

    while (true) {
        cout << "\nEnter text (or type 'exit' to finish): ";
        getline(cin, text);
        if (text == "exit") break;

        cout << "Bold? (y/n): ";
        cin >> bold;
        cout << "Italic? (y/n): ";
        cin >> italic;
        cout << "Underline? (y/n): ";
        cin >> underline;
        cout << "Strike-through? (y/n): ";
        cin >> strike;
        cout << "Font Size (default 12): ";
        cin >> fontSize;
        cout << "Alignment (left/center/right/justify): ";
        cin >> alignment;
        cout << "Text Color (e.g. red, blue, green, #hex): ";
        cin >> color;
        cin.ignore(); // clear buffer

        TextStyle style((bold=='y'), (italic=='y'), (underline=='y'), (strike=='y'),
                        fontSize, alignment, color);
        Paragraph p(text, style);
        doc.addParagraph(p);

        cout << "✅ Paragraph added!\n";
    }

    HTMLExporter exporter;
    exporter.exportDocument(doc, "output.html");

    cout << "\n🎉 Document exported as 'output.html'. Open it in a browser!\n";
    return 0;
}
